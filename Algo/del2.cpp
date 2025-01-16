#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm> // För std::any_of

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
    // Getter-metoder markerade som const
    SensorType GetSensorType() const { return sensorType; }
    float GetValue() const { return value; }
    time_t GetTime() const { return time; }

    // Setter-metod
    void SetValue(float v) { value = v; }

    // Konstruktor
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

    // Kontrollera om någon SpeedInKmh-registrering överstiger 99.9
    bool maxSpeedReached = std::any_of(sensorData.begin(), sensorData.end(), [](const SensorData& data) {
        return data.GetSensorType() == SensorType::SpeedInKmh && data.GetValue() > 99.9f;
    });

    // Skriv ut resultatet
    if (maxSpeedReached) {
        cout << "Maxhastighet uppnådd" << endl;
    } else {
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
        // Slumpa sensortyp
        SensorType type = static_cast<SensorType>(rand() % 3);

        // Slumpa värde baserat på typ
        float value = 0.0f;
        if (type == SensorType::Altitude)
            value = rand() % 1000;
        else if (type == SensorType::FuelConsumption)
            value = static_cast<float>(rand()) * 3.0f;
        else if (type == SensorType::SpeedInKmh)
            value = rand() % 110;

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
