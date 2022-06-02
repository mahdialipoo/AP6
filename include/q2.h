#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <regex>
#include <string>
#ifndef Q2_H
#define Q2_H
namespace q2
{
    struct Patient;
    void sort(std::vector<Patient> &);
    std::vector<Patient> read_file(std::string);
}
struct q2::Patient
{
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};
std::vector<q2::Patient> q2::read_file(std::string filename)
{
    std::vector<Patient> v{};
    Patient x{};
    std::ifstream indata;
    std::string s{};
    std::regex pattern(R"(\s?\w+\s?,\w+\s?,\d+,\d+,\d+,\d+\s?)");
    indata.open(filename);
    do
    {
        std::getline(indata, s);
        if (std::regex_match(s, pattern))
        {
            std::string s1{s.substr(s.find(',') + 1)};
            std::string s2{s1.substr(s1.find(',') + 1)};
            std::string s3{s2.substr(s2.find(',') + 1)};
            std::string s4{s3.substr(s3.find(',') + 1)};
            std::string s5{s4.substr(s4.find(',') + 1)};
            std::string s6{s5.substr(s5.find(',') + 1)};
            x.name = s.substr(0, s.find(','));
            if (*(x.name.end() - 1) != ' ' && s1[0] != ' ')
                x.name += " ";
            x.name += s1.substr(0, s1.find(','));
            x.age = std::stoi(s2.substr(0, s2.find(',')));
            x.smokes = std::stoi(s3.substr(0, s3.find(',')));
            x.area_q = std::stoi(s4.substr(0, s4.find(',')));
            x.alkhol = std::stoi(s5);
            v.push_back(x);
        }

    } while (!indata.eof());
    indata.close();
    return v;
}
void q2::sort(std::vector<q2::Patient> &v)
{
    std::sort(v.begin(), v.end(), [](const Patient &a, const Patient &b)
              { return 3 * a.age + 5 * a.smokes + 2 * a.area_q + 4 * a.alkhol > 3 * b.age + 5 * b.smokes + 2 * b.area_q + 4 * b.alkhol; });
}
// namespace q2

#endif // Q2_H