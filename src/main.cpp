#include <iostream>
#include <gtest/gtest.h>

//#include "q1.h"
//#include "q2.h"
//#include "q3.h"
//#include "q4.h"
//******
#include <cmath>
#include <fstream>
#include <regex>
#include <vector>
//*****
int main(int argc, char **argv)
{
    if (0) // make false to run unit-tests
    {
        std::cout << 5 << "dsaa" << 45 << std::endl;
        // auto v{q2::read_file("lung_cancer.csv")};
        // std::cout << v[0].smokes << std::endl;
        //   std::regex pattern(R"(\w+\s?,\w+\s?,\d+,\d+,\d+,\d+)");
        //   std::cout << std::regex_match("Gregory ,Peck,43,30,3,8", pattern);
        //     debug section
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