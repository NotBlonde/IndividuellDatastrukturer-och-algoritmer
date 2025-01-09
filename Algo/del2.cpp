#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

enum class SensorType
{
    Altitude,
    SpeedInKmh,
    FuelConsumption
};

class SensorData
{
    float value;
    SensorType sensorType;
    time_t time;
public:
    SensorType GetSensorType() { return sensorType; }
    float GetValue() { return value; }
    void SetValue(float v) { value = v; }
    time_t GetTime() { return time; }
    SensorData(SensorType sensorType, float value, time_t time)
    {
        this->value = value;
        this->sensorType = sensorType;
        this->time = time;
    }
};

void FillData(vector<SensorData>& v);
time_t CreateTime(int year, int month, int day, int hour, int minute, int second);

int main()
{
    vector<SensorData> sensorData;
    FillData(sensorData);

    // Variabel för att hålla koll på maxhastighet
    bool maxSpeedReached = false;

    // Klassisk loop för att iterera över vektorn
    for (size_t i = 0; i < sensorData.size(); ++i)
    {
        SensorData data = sensorData[i]; // Explicit skapa en kopia av objektet
        if (data.GetSensorType() == SensorType::SpeedInKmh && data.GetValue() > 99.9f)
        {
            maxSpeedReached = true;
            break; // Avsluta loopen om vi hittar en match
        }
    }

    // Skriv ut resultatet
    if (maxSpeedReached)
    {
        cout << "Maxhastighet uppnådd" << endl;
    }
    else
    {
        cout << "Ingen maxhastighet uppnådd" << endl;
    }

    return 0;
}

void FillData(vector<SensorData>& v)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    // Skapa initial tidsstämpel
    time_t tid = CreateTime(2012, 1, 1, 1, 1, 1);

    for (int i = 0; i < 100000; i++)
    {
        SensorType type = static_cast<SensorType>(rand() % 3);
        float value = 0.0f;
        if (type == SensorType::Altitude)
            value = rand() % 1000;
        else if (type == SensorType::FuelConsumption)
            value = static_cast<float>(rand()) * 3.0f;
        else if (type == SensorType::SpeedInKmh)
            value = rand() % 110;
        v.push_back(SensorData(type, value, tid));
        tid += rand() % 10 + 1;
    }
}

time_t CreateTime(int year, int month, int day, int hour, int minute, int second)
{
    struct tm timeInfo = { 0 };
    timeInfo.tm_year = year - 1900;
    timeInfo.tm_mon = month - 1;
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = minute;
    timeInfo.tm_sec = second;
    return mktime(&timeInfo);
}
