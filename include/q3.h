#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <queue>
#include <string>
#include <numeric>
#include <iostream>
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
    auto f{
        [](const Flight &a, const Flight &b)
        {
            return (a.duration + a.connection_times + 3 * a.price) > (b.duration + b.connection_times + 3 * b.price);
        }};
    std::priority_queue<Flight, std::vector<Flight>, decltype(f)> gather_flights(std::string filename)
    {
        std::priority_queue<Flight, std::vector<Flight>, decltype(f)>
            result{f};
        std::ifstream indata(filename);
        do
        {
            Flight x{};
            std::string s{};
            std::getline(indata, s);
            std::regex pattern_duration(R"(duration:(\d+)h(\d+)*m*)");
            std::smatch match1{};
            std::regex pattern_price(R"(price:(\d+))");
            std::smatch match2{};
            std::regex pattern_connections(R"(connections:(\d+))");
            std::smatch match3{};
            std::regex pattern_time_h(R"((\d+)h)");
            std::smatch matchtime_h{};
            std::regex pattern_time_m(R"((\d+)m)");
            std::smatch matchtime_m{};
            std::string s1{s.substr(s.find(':') + 1)};
            x.flight_number = s1.substr(0, s1.find(' '));
            std::regex_search(s, matchtime_h, pattern_time_h);
            std::regex_search(s, matchtime_m, pattern_time_m);
            std::regex_search(s, match2, pattern_price);
            std::regex_search(s, match1, pattern_duration);
            std::regex_search(s, match3, pattern_connections);
            x.duration = 60 * std::stoi(match1[1].str());
            if (match1[2].str() != "")
                x.duration += std::stoi(match1[2].str());
            x.connections = std::stoi(match3[1].str());
            s = match1.suffix().str();
            do
            {
                x.connection_times += 60 * std::stoi(matchtime_h[1].str());
                if (matchtime_m[1].str() != "")
                    x.connection_times += std::stoi(matchtime_m[1].str());
                s = matchtime_h.suffix().str();
            } while (std::regex_search(s, matchtime_h, pattern_time_h));
            x.price = std::stoi(match2[1].str());
            result.push(x);
        } while (!indata.eof());

        indata.close();
        return result;
    }
} // namespace q3

#endif // Q3_H