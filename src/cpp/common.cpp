#include "common.hpp"

/* Return "YYYY_MM_DD_HH:MM:SS" */
string
getCurrTime () {
    time_t timeObj = time(NULL);
	struct  tm* tm = localtime(&timeObj);
    std::string currTime, temp;
	currTime += std::to_string (tm->tm_year+1900);
    temp = std::to_string (tm->tm_mon+1);
    if (temp.length() == 1) temp = "0" + temp;
	// currTime += ("_" + temp);
    temp = std::to_string (tm->tm_mday);
    if (temp.length() == 1) temp = "0" + temp;
    // currTime += ("_" + temp);
	temp = std::to_string (tm->tm_hour);
    if (temp.length() == 1) temp = "0" + temp;
	// currTime += ("_" + temp);
	temp = std::to_string (tm->tm_min);
	if (temp.length() == 1) temp = "0" + temp;
	// currTime += (":" + temp);
	temp = std::to_string (tm->tm_sec);
    if (temp.length() == 1) temp = "0" + temp;
	// currTime += (":" + temp);
    return currTime;
}

io_data::io_data (int camera_num) {
    this->imgs.reserve (camera_num);
    this->nums.reserve (camera_num);
    this->total_people_num = 0;
    this->inference_time = 0;
}

io_data::~io_data () {
    this->imgs.clear();
    this->nums.clear();
}