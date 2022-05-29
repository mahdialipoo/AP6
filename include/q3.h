#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <regex>
#include <queue>
#include <string>
#ifndef Q3_H
#define Q3_H
namespace q3
{
    struct Flight
    {
        std::string flight_number;
        size_t duration;
        size_t connections;
        size_t connection_times;
        size_t price;
    };
    std::priority_queue<Flight> gather_flights(std::string filename)
    {
    }
} // namespace q3

#endif // Q3_H