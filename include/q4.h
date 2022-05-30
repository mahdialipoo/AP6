#include <algorithm>
#include <functional>
#include <vector>
#include <fstream>
#include <regex>
#include <queue>
#include <string>
#include <numeric>
#include <initializer_list>
#ifndef Q4_H
#define Q4_H
namespace q4
{
    struct Vector2D
    {
        double x{};
        double y{};
        Vector2D operator*(const double &a)
        {
            Vector2D s{a * x, a * y};
            return s;
        }
        Vector2D operator+(Vector2D a)
        {
            Vector2D s{x + a.x, y + a.y};
            return s;
        }
    };

    struct Sensor
    {
        Vector2D pos;
        double accuracy;
    };
    Vector2D kalman_filter(std::vector<Sensor> sensors)
    {
        auto s{std::accumulate(sensors.begin(), sensors.end(), Sensor{{0.0, 0.0}, 0.0}, [](Sensor a, Sensor b)
                               {Sensor s{{(a.pos * a.accuracy + b.pos * b.accuracy)*(1/(a.accuracy + b.accuracy))}, a.accuracy + b.accuracy};
                               //std::cout<<s.pos.x<<","<<s.pos.y<<std::endl;
        return s; })};
        Vector2D v{s.pos};
        return v;

    } // namespace q4

}
#endif // Q4_H