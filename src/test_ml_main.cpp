/*
    ml.hpp, ml.cpp 를 테스트하기 위해 컴파일되는 main.
    'make dnn' 으로 컴파일, 출력은 dnn.out
*/

#include "ml.hpp"

int main (void) {
    struct protocol* dummyptr = NULL;
	MachineLearning (dummyptr);
    return 0;
}
