#include <iostream>
#include <gtest/gtest.h>
/*
#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
*/
//******
#include <cmath>
#include <fstream>
#include <regex>
#include <vector>
#include <iomanip>
//*****
int main(int argc, char **argv)
{
    if (0) // make false to run unit-tests
    {
        /* std::vector<q4::Sensor> sensors{{{1, 0.3}, 0.5},
                                         {{0.92, 0.5}, 0.2},
                                         {{0.84, 0.65}, 0.4},
                                         {{1.23, 0.46}, 0.8},
                                         {{2.01, 0.101}, 0.1}};
         auto kalman{q4::kalman_filter(sensors)};
         std::cout << kalman.x << ", " << kalman.y << std::endl;*/
        //      debug section
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