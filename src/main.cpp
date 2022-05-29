#include <iostream>
#include <gtest/gtest.h>

#include "q1.h"
//#include "q2.h"
//#include "q3.h"
//#include "q4.h"
//******
#include <cmath>
#include <fstream>
// using namespace q1;
//*****
int main(int argc, char **argv)
{
    if (1) // make false to run unit-tests
    {
        std::ifstream indata;
        std::string p;
        indata.open("lung_cancer.csv");
        indata >> p;
        indata >> p;
        indata.close();
        std::cout << p << std::endl;
        // debug section
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}