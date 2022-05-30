#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <sstream>
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
    auto f{
        [](const Flight &a, const Flight &b)
        {
            return (a.duration + a.connection_times + 3 * a.price) < (b.duration + b.connection_times + 3 * b.price);
        }};
    std::priority_queue<Flight, std::vector<Flight>, decltype(f)> gather_flights(std::string filename)
    {
        Flight x{};
        std::ifstream indata(filename);
        std::stringstream sb{};
        sb << indata.rdbuf();
        std::string s{sb.str()};
        std::regex pattern_duration(R"(duration:(\d)+h((\d+)m)?)");
        std::smatch match1{};
        std::regex pattern_price(R"(price:(\d+))");
        std::smatch match2{};
        std::regex pattern_connections(R"(connections:(\d))");
        std::smatch match3{};
        std::regex pattern_connection_times(R"(connection_times:(\dh(\d+m)?,?)+)");
        std::smatch match4{};
        std::string s1{s.substr(s.find(':') + 1)};
        x.flight_number = s1.substr(0, s1.find(' '));
        std::priority_queue<Flight, std::vector<Flight>, decltype(f)>
            result{f};
        do
        {
            std::regex_search(s, match2, pattern_price);
            std::regex_search(s, match1, pattern_duration);
            std::regex_search(s, match3, pattern_connections);
            std::regex_search(s, match4, pattern_connection_times);
            x.duration = 60 * std::stoi(match1[1].str()) + std::stoi(match1[3].str());
            x.connections = std::stoi(match3[1].str());
            // x.connection_times=[]
            x.price = std::stoi(match2[1].str());
            s = match2.suffix().str();
            result.push(x);
        } while (std::regex_search(s, match2, pattern_price));
        /*
          std::regex pattern_duration(R"(duration:\d+h(\d+m)?)");
          std::regex pattern_price(R"(price:\d+)");
          std::regex pattern_connections(R"(connections:\d)");
          std::regex pattern_connection_times(R"(connection_times:(\dh(\d+m)?(,)?)+)");
          auto priorty{[](const Flight &a, const Flight &b)
                       { return a.duration + a.connection_times + 3 * a.price > b.duration + b.connection_times + 3 * b.price; }};
          std::priority_queue<Flight, std::vector<Flight>, priorty> v{};
          indata.open(filename);
          do
          {
              //*****

                          std::getline(indata, s);
                          std::string s1{s.substr(s.find(':') + 1)};
                          std::string s2{s1.substr(s1.find(':') + 1)};
                          std::string s3{s2.substr(s2.find(':') + 1)};
                          std::string s4{s3.substr(s3.find(':') + 1)};
                          std::string s5{s4.substr(s4.find(':') + 1)};

                          x.flight_number = s1.substr(0, s1.find(' '));
                          x.duration = std::stoi(s2.substr(0, s2.find('m')));
                          x.connections = std::stoi(s3.substr(0, s3.find(' ')));
                          x.connection_times = std::stoi(s4.substr(0, s4.find(' ')));
                          x.price = std::stoi(s5);

              //************
              std::string s1{s.substr(s.find(':') + 1)};
              x.flight_number = s1.substr(0, s1.find(' '));
              x.price = std::stoi(regex_match(s, pattern_price).substr(6));
              std::string s2{regex_match(s, pattern_price).substr(9)};
              x.duration = 60 * std::stoi(s2.substr(0, s2.find('h')));
              if (*(s2.end() - 1) == "m")
                  x.duration += std::stoi(s2.substr(s2.find('h') + 1, s2.find('m')));
              x.connections = std::stoi(regex_match(s, pattern_connections).substr(12));
              std::string s3{regex_match(s, pattern_connection_times).substr(17)};
              v.push(x);

          } while (!indata.eof());*/
        indata.close();
        return result;
    }
} // namespace q3

#endif // Q3_H