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

        Flight x{};
        std::ifstream indata{};
        std::string s{};
        std::priority_queue<Flight, std::vector<Flight>, [](const Flight &a, const Flight &b)
                            { return a.duration + a.connection_times + 3 * a.price > b.duration + b.connection_times + 3 * b.price; }>
            v{};
        indata.open(filename);
        do
        {
            std::getline(indata, s);

            std::string s1{s.substr(s.find(':') + 1)};
            std::string s2{s1.substr(s1.find(':') + 1)};
            std::string s3{s2.substr(s2.find(':') + 1)};
            std::string s4{s3.substr(s3.find(':') + 1)};
            std::string s5{s4.substr(s4.find(':') + 1)};
            // std::string s6{s5.substr(s5.find(',') + 1)};
            x.flight_number = s1.substr(0, s1.find(' '));
            x.duration = std::stoi(s2.substr(0, s2.find('m')));
            x.connections = std::stoi(s3.substr(0, s3.find(' ')));
            x.connection_times = std::stoi(s4.substr(0, s4.find(' ')));
            x.price = std::stoi(s5);
            v.push(x);

        } while (!indata.eof());
        indata.close();
    }
} // namespace q3

#endif // Q3_H