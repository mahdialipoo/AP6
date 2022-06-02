#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#ifndef Q1_H
#define Q1_H

namespace q1
{
    template <typename T = double, typename C>
    T gradient_descent(const T &, const T &, C = C{});
}
template <typename T, typename C>
T q1::gradient_descent(const T &init_val, const T &step, C func)
{
    T x1{init_val};
    T x2{init_val};
    do
    {
        if (func(x1) > func(x1 + step))
            x1 += step;
        else
            break;
    } while (true);
    do
    {
        if (func(x2) > func(x2 - step))
            x2 -= step;
        else
            break;
    } while (true);
    return func(x1) < func(x2) ? x1 : x2;
}
// namespace q1

#endif // Q1_H