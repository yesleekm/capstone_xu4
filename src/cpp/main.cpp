#include "socket.hpp"
#include "ml.hpp"
#include "uploader.hpp"
#include "admin.hpp"

/* 어플 최초 실행시 conf_data를 웹에서 입력받은 뒤에 이 C++ 프로그램이 실행되어야 config data를 초기화할 수 있음 */
int
main (int argc, char* argv[]) {
    printf ("start program\n");
    config_data _conf_data;
    printf ("conf sync!\n");
    _conf_data.sync(); // 서비스 최초 실행시 제일 먼저 conf_data를 읽어온다.
    printf ("conf sync done!\n");
    OpenCV_DNN dnn (_conf_data.resize_res, _conf_data.confThreshold, _conf_data.nmsThreshold);
    printf ("dnn done !\n");
    Uploader ups;

    io_data _io_data (_conf_data.camera_number);

    int MODE_FLAG = BASIC_MODE;
    int WORK_FLAG = GO_TAKE_PICTURE;

    std::mutex m;
    std::thread cam_thr (camera_handler, std::ref(_io_data), std::ref(_conf_data),
                        std::ref(WORK_FLAG), std::ref(MODE_FLAG), std::ref(m)); // 소켓통신 시작
    int dummy = 0;
    while (true) {
        if (_conf_data.sync()) // prev==ADMIN && now==BASIC 이면 config 갱신
            dnn.update (_conf_data);
        if (WORK_FLAG == DONE_TAKE_PICTURE) { // 사진촬영을 모두 완료하였다면
            printf (" WORK_FLAG: DONE_TAKE_PICTURE --> GO_INFERENCE\n");
            m.lock();
            WORK_FLAG = GO_INFERENCE;
            ups.upload_input (_io_data);
            dnn.inference(_io_data);
            ups.upload_output (_io_data);
            WORK_FLAG = GO_TAKE_PICTURE; // 다시 사진촬영 요청
            m.unlock();
            printf (" WORK_FLAG: DONE_TAKE_PICTURE --> GO_TAKE_PICTURE\n");
        }
        else// 사진촬영중이므로 대기
            dummy++;
    }
    return 0;
}