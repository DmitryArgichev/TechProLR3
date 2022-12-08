#include <iostream>
#include <cstdlib> // для system
#include <random>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;
using namespace literals;

class Profiler
{
public:
    steady_clock::time_point start;
    steady_clock::time_point end_time_;

    Profiler()
    {
        steady_clock::time_point start_time_ = steady_clock::now();
        this->start = start_time_;
    }

    ~Profiler()
    {
        steady_clock::time_point end_time_ = steady_clock::now();
        cout << " длительность выполнения: " << duration_cast<milliseconds>(end_time_ - start).count() << "ms ";
        cout << endl;
    }
};

class dat
{
public:
    string name;
    string measure_unit;
    double min_measure_range, max_measure_range;
    virtual double measure()
    {
        return 0;
    }
};
