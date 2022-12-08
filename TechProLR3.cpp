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
        //---------------------------
        Profiler  Seven;
        cout << "Метод measure";
        //---------------------------
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
        //---------------------------
        Profiler  Eight;
        cout << "Метод measure";
        //---------------------------
        std::random_device rd;
        std::mt19937 e2(rd());
        std::uniform_real_distribution<> dist(min_measure_range, max_measure_range);
        return dist(e2);
    }
};

class GPS_System {
public:
    string name;
    vector <dat*> vec;
    void add_sensor(dat* obj)
    {
        //---------------------------
        Profiler  One;
        cout << "Метод add_sensor";
        //---------------------------
        
        vec.push_back(obj);
  
        
    }
    void measure_acc()
    {
        //---------------------------
        Profiler  Two;
        //---------------------------
        for (long long unsigned int i = 0; i < vec.size(); ++i)
        {
            if (vec[i]->measure_unit == "g")
            {
                cout << "Acceleration = " << vec[i]->measure() << " g" << endl;
            }
        }
        //---------------------------
        cout << "Метод measure_acc";
        //---------------------------
    }

    void measure_gyro()
    {
        //---------------------------
        Profiler  Three;
        //---------------------------
        for (long long unsigned int j = 0; j < vec.size(); j++)
        {
            if (vec[j]->measure_unit == "gradus")
            {
                cout << "Angle = " << vec[j]->measure() << " gradus" << endl;
            }
        }
        //---------------------------
        cout << "Метод measure_gyro";
        //---------------------------
    }

    void measure_position()
    {
        //---------------------------
        Profiler  Four;
        //---------------------------
        for (long long unsigned int k = 0; k < vec.size(); ++k)
        {
            if (vec[k]->measure_unit == "km")
            {
                cout << "Position = " << vec[k]->measure() << " km" << endl;
            }
        }
        //---------------------------
        cout << "Метод measure_position";
        //---------------------------
    }

    void list_sensors()
    {
        //---------------------------
        Profiler  Five;
        //---------------------------
        for (long long unsigned int k = 0; k < vec.size(); ++k) {
            cout << vec[k]->name << " ";
        }
        cout << endl;
        //---------------------------
        cout << "Метод list_sensors ";
        //---------------------------
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
        //---------------------------
        Profiler  Six;
        cout << "Метод measure";
        //---------------------------
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
        cout << "To connect the Accelerometer, press - 1" << endl;
        cout << "To connect the Gyroscope, press - 2 " << endl;
        cout << "To connect the Position, press - 3 " << endl;
        cout << "To write all name, press - 4 " << endl;
        cout << "To end the program, press - 5 " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            A.add_sensor(&B);
            A.measure_acc();
            break;
        case 2:
            A.add_sensor(&D);
            A.measure_gyro();
            break;
        case 3:
            A.add_sensor(&C);
            A.measure_position();
            break;
        case 4:
            A.list_sensors();
            break;
        case 5:
            break;
        default: continue;
        }

    } while (n != 5);
    return 0;
}
