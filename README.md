# Sensor Data Processing

## Beskrivning

Det här projektet hanterar och analyserar sensordata från en fabrik. Projektet är uppdelat i tre delar och implementerat i C++.

### Sensorer som hanteras:

- **Altitude**: Mäter höjd i meter.
- **SpeedInKmh**: Mäter hastighet i km/h.
- **FuelConsumption**: Mäter bränsleförbrukning.

---

## Funktionalitet

### **Del 1: Räkna registreringar av höjd (Altitude)**

Programmet räknar hur många registreringar av sensortypen `Altitude` som skedde den **2 januari 2012**.

#### Funktionalitet:

- Itererar genom sensordata och räknar alla `Altitude`-registreringar som har tidsstämpeln **2012-01-02**.
- Skriver ut antalet registreringar till konsolen.

#### Konsolutskrift:

```
Antal höjdregistreringar den 2 januari 2012: [antal]
```

---

### **Del 2: Kontrollera hastighetsgräns (SpeedInKmh)**

Programmet kontrollerar om någon registrering av `SpeedInKmh` överstiger **99.9 km/h**.

#### Funktionalitet:

- Itererar genom sensordata och letar efter registreringar av typen `SpeedInKmh` med värden över **99.9**.
- Skriver ut om maxhastigheten har uppnåtts eller inte.

#### Konsolutskrift:

- Om maxhastigheten uppnåtts:
  ```
  Maxhastighet uppnådd
  ```
- Om inte:
  ```
  Ingen maxhastighet uppnådd
  ```

---

### **Del 3: Uppdatera bränsleförbrukning (FuelConsumption)**

Programmet korrigerar alla registreringar av sensortypen `FuelConsumption` genom att öka deras värde med **75%**.

#### Funktionalitet:

- Itererar genom sensordata och identifierar poster av typen `FuelConsumption`.
- Uppdaterar värdet för varje registrering genom att multiplicera det med **1.75**.
- Bekräftar uppdateringen genom att skriva ut ett meddelande till konsolen.

#### Konsolutskrift:

```
Alla FuelConsumption-poster har uppdaterats med 75%.
```

---

## Hur man kör projektet

### Förkrav:

- En C++-kompilator (t.ex. GCC, Clang eller Visual Studio).
- Projektet använder standardbiblioteket och kräver inga externa beroenden.

### Bygga och köra:

1. Klona projektet från GitHub:
   ```bash
   git clone [URL]
   cd [project-folder]
   ```
2. Kompilera koden:
   ```bash
   g++ -std=c++11 -o sensor_app main.cpp
   ```
3. Kör programmet:
   ```bash
   ./sensor_app
   ```

---

## Struktur

- **`main.cpp`**: Huvudfilen som innehåller implementationen för alla tre delar.
- **`README.md`**: Dokumentationen för projektet (den här filen).

---

## Licens

Detta projekt är licensierat under MIT-licensen. Se [LICENSE](LICENSE) för mer information.

---

## Författare

Projektet är utvecklat av NotBlonde.



