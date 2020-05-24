#include "admin.hpp"

config_data::config_data () {
    this->prev_flag = ADMIN_MODE;
    this->confThreshold = 0.4;
    this->nmsThreshold = 0.5;
}

/* Returns true when it's basic mode. */
bool
config_data::sync () {
    int now_flag = read_mode_flag();
    ASSERT (now_flag != -1);
    if (prev_flag == ADMIN_MODE && now_flag == BASIC_MODE) {
        this->read_all_config();
        prev_flag = now_flag;
        return true;
    }
    else if (prev_flag == ADMIN_MODE && now_flag == ADMIN_MODE) {
        return false;        
    }
    else if (prev_flag == BASIC_MODE && now_flag == ADMIN_MODE) {
        prev_flag = now_flag;
        return false;
    }
    else if (prev_flag == BASIC_MODE && now_flag == BASIC_MODE) {
        return true;
    }
    else {
        return -1;
    }
}

int
config_data::read_mode_flag () {
    char buf[20];
    FILE* fp = fopen (path, "r");
    const char* path = (CONFIG_PATH + "/mode.txt").c_str();
    ASSERT (fp == NULL);
    fgets (buf, sizeof(buf), fp);
    fclose (fp);
    string str (buf);
    if (str == "admin")
        return ADMIN_MODE;
    else if (str == "basic")
        return BASIC_MODE;
    else
        return -1;
}

void
config_data::read_all_config () {
    /* 주어진 경로로부터 텍스트파일을 읽어서 모든 멤버변수에 저장하기 */
    char buf[20];
    FILE* fp;

    // Read admin_input.txt
    const char* path = (CONFIG_PATH + "/admin_input.txt").c_str();
    fp = fopen (path, "r");
    fgets(buf, sizeof(buf), fp);
    this->camera_number = atoi(buf);
    fgets(buf, sizeof(buf), fp);
    this->capture_res.width = atoi(buf);
    fgets(buf, sizeof(buf), fp);
    this->capture_res.height = atoi(buf);
    fgets(buf, sizeof(buf), fp);
    this->resize_res.width = atoi(buf);
    fgets(buf, sizeof(buf), fp);
    this->resize_res.height = atoi(buf);
    fclose (fp);

    // Read ROI.txt

}