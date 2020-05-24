#ifndef COMMON
#define COMMON

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>

#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <thread>
#include <mutex>

#include <opencv2/core/mat.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>


#define ASSERT assert

#define ADMIN_MODE 0
#define BASIC_MODE 1
#define TERMINATE_MODE 2

using std::string;

string ROOT_PATH = "../..";
string CONFIG_PATH = ROOT_PATH + "/config";
string BIN_PATH = ROOT_PATH + "/bin";
string ROI_DIR_PATH = CONFIG_PATH + "/images";
string RESULT_DIR_PATH = ROOT_PATH + "/resources/images";

string 
getCurrTime ();

class io_data {
public:

    std::vector<cv::Mat> imgs; // output images
    std::vector<int> nums; // each outp's people number
    int total_people_num; // all outp's total people number 
    double inference_time; // inference time

public:

    io_data (int camera_num);

    ~io_data ();
    
};

#endif