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
        cout << "time: " << duration_cast<milliseconds>(end_time_ - start).count() << "ms ";
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


class GPS_System {
public:
    string name;
    vector <dat*> vec;
    void add_sensor(dat* obj)
    {
        vec.push_back(obj);
    }
    void measure_acc()
    {
        for (long long unsigned int i = 0; i < vec.size(); ++i)
        {
            if (vec[i]->measure_unit == "g")
            {
                vec[i]->measure();
            }
        }
    }

    void measure_gyro()
    {
        for (long long unsigned int j = 0; j < vec.size(); j++)
        {
            if (vec[j]->measure_unit == "gradus")
            {
                vec[j]->measure();
            }
        }
    }

    void measure_position()
    {
        for (long long unsigned int k = 0; k < vec.size(); ++k)
        {
            if (vec[k]->measure_unit == "km")
            {
                vec[k]->measure();
            }
        }
    }

    void list_sensors()
    {
        for (long long unsigned int k = 0; k < vec.size(); ++k) {
             vec[k]->name;
        }
    }
};

//////////////////////датчики///////////////////////////////////////////////
class Acceleration : public dat
{
public:
    Acceleration() :dat()
    {
        name = "Acceleration";
        measure_unit = "g";//единица измерения g-перегрузка
        min_measure_range = 0.0;
        max_measure_range = 500.0;
    }
    double measure()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(min_measure_range, max_measure_range);
        return dist(e2);
    }
};

class Gyroscop : public dat
{
public:
    Gyroscop() :dat()
    {
        name = "Gyroscop";
        measure_unit = "gradus";
        min_measure_range = 0;
        max_measure_range = 90;
    }
    double measure()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(min_measure_range, max_measure_range);
        return dist(e2);
    }

};

class Position : public dat
{
public:
    Position() :dat()
    {
        name = "Position";
        measure_unit = "km";
        min_measure_range = 0;
        max_measure_range = 1000;
    }
    double measure()
    {
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(min_measure_range, max_measure_range);
        return dist(e2);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    GPS_System A;
    Acceleration B;
    Gyroscop D;
    Position C;
    cout << "Welcome GPS_System" << endl;
    cout << "Which sensor do you want to connect?" << endl;
    do {
        cout << "Runtime method add_sensor to Acceleration , press - 1" << endl;
        cout << "Runtime method measure_acc, press - 2 " << endl;
        cout << "Runtime method add_sensor to Gyroscop, press - 3 " << endl;
        cout << "Runtime method measure_gyro, press - 4 " << endl;
        cout << "Runtime method add_sensor to Position , press - 5" << endl;
        cout << "Runtime method measure_position, press - 6 " << endl;
        cout << "Runtime method list_sensors, press - 7 " << endl;
        cout << "To end the program, press - 8 " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
        {
            Profiler One;
            for (int i = 0;i < 100000;++i)
            {
                A.add_sensor(&B);
            }
            break;
        }
        case 2:
        {
            Profiler Two;
            A.measure_acc();
            break;
        }
        case 3:
        {
            Profiler Three;
            for (int i = 0;i < 100000;++i)
            {
                A.add_sensor(&D);
            }
            break;
        }
        case 4:
        {
            Profiler Four;
            A.measure_gyro();
            break;
        }
        case 5:
        {
            Profiler Five;
            for (int i = 0;i < 100000;++i)
            {
                A.add_sensor(&C);
            }
            break;
        }
        case 6:
        {
            Profiler Six;
            A.measure_position();
            break;
        }
        case 7:
        {
            Profiler Seven;
            for (int i = 0;i < 1000;++i)
            {
                A.list_sensors();
            }
            break;
        }
        case 8:
            break;
        default: continue;
        }

    } while (n != 8);
    return 0;
}

