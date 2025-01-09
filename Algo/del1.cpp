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

    // Definiera start- och sluttid för 2 januari 2012
    time_t startTime = CreateTime(2012, 1, 2, 0, 0, 0);
    time_t endTime = CreateTime(2012, 1, 3, 0, 0, 0);

    // Räknare för antalet registreringar
    int count = 0;

    // Iterera genom sensordata och räkna höjdregistreringar för 2 januari 2012
    for (SensorData data : sensorData)
{
    if (data.GetSensorType() == SensorType::Altitude &&
        data.GetTime() >= startTime && data.GetTime() < endTime)
    {
        count++;
    }
}

    // Skriv ut resultatet
    cout << "Antal höjdregistreringar den 2 januari 2012: " << count << endl;

    return 0;
}

void FillData(vector<SensorData>& v)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    // Skapa initial tidsstämpel
    time_t tid = CreateTime(2012, 1, 1, 1, 1, 1);

    for (int i = 0; i < 100000; i++)
    {
        // Slumpa sensortyp
        SensorType type = static_cast<SensorType>(rand() % 3);

        // Slumpa värde baserat på typ
        float value = 0.0f;
        if (type == SensorType::Altitude)
            value = rand() % 1000; // Höjd i meter
        else if (type == SensorType::FuelConsumption)
            value = static_cast<float>(rand()) * 3.0f; // Bränsleförbrukning
        else if (type == SensorType::SpeedInKmh)
            value = rand() % 110; // Hastighet i km/h

        // Lägg till ny data i vektorn
        v.push_back(SensorData(type, value, tid));

        // Öka tid för nästa data
        tid += rand() % 10 + 1;
    }
}

time_t CreateTime(int year, int month, int day, int hour, int minute, int second)
{
    struct tm timeInfo = { 0 };
    timeInfo.tm_year = year - 1900; // år från 1900
    timeInfo.tm_mon = month - 1;   // månader från 0
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = minute;
    timeInfo.tm_sec = second;
    return mktime(&timeInfo);
}
