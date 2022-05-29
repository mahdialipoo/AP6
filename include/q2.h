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
    struct Patient
    {
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };
    std::vector<Patient> read_file(std::string filename)
    {
        std::vector<Patient> v{};
        Patient x{};
        std::ifstream indata;
        std::string s{};
        indata.open(filename);
        do
        {
            indata >> s;
            if (std::regex_match(s, "\w+\s?,\w+\s?,\d+,\d+,\d+,\d+"))
            {
            }

        } while (!indata.eof());
        indata.close();
        return v;
    }
    void sort(std::vector<Patient> &v)
    {
        std::sort(v.begin(), v.end(), [](const Patient &a, const Patient &b)
                  { return 3 * a.age + 5 * a.smokes + 2 * a.area_q + 4 * a.alkhol > 3 * b.age + 5 * b.smokes + 2 * b.area_q + 4 * b.alkhol; });
    }
} // namespace q2

#endif // Q2_H