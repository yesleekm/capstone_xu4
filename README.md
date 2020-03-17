## 웹서버 구조
    /
> 출력된 이미지 및 사람 계수값을 시간 역순으로 출력 (index.php)   
> 현재 테스트머신에서 루트는 /home/html/ws/www/

    /inputs
> 입력된 이미지(.jpeg)를 저장하는 디렉토리

    /outputs
> 출력된 이미지(.jpeg) 및 results.txt를 저장하는 디렉토리

**프로그램 실행 시 /home/html/ws/www/* 초기화**

#### 프로토콜 (인코딩된 이미지)
    std::vector<unsigned char>

---------------------------------------------------------------
## 사용법

* make clean
> 모든 실행파일 제거

* make all
> 릴리즈버전

* make debug
> 디버깅버전, 소스코드에서 DEBUG 매크로 사용   
> 소켓통신 없이 **"로컬 이미지 입력 --> 딥러닝 출력 --> 입력 및 출력이미지 웹서버 업로드"** 만 진행   
> 로컬 이미지 경로: debug/test_images/*.jpeg   
> ./server_debug.out <처음: 테스트할 이미지 파일> <끝: 테스트할 이미지 파일>   

#### debug 사용법
1. 테스트할 .jpeg 이미지파일을 debug/test_images/ 디렉토리에 순차적인 숫자로 저장.   
  (ex. 1.jpeg 2.jpeg 3.jpeg 4.jpeg)
2. 테스트할 이미지파일의 시작번호와 끝번호를 인자로 server_debug.out 실행.   
  (ex. ./server_debug.out 1 4  -->  1.jpeg, 2.jpeg, 3.jpeg, 4.jpeg 파일 입력)
3. 결과는 웹서버의 uploads 폴더에서 확인.   

--------------------------------------------------------------
