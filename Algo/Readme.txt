Sensor Data Processing
Beskrivning
Det här projektet är uppdelat i tre delar och hanterar sensordata från en fabrik. Genom att använda C++-koden kan vi analysera, kontrollera och modifiera sensordata enligt specifika krav.

Sensorer som hanteras:
Altitude: Mäter höjd i meter.
SpeedInKmh: Mäter hastighet i km/h.
FuelConsumption: Mäter bränsleförbrukning.
Delar av projektet
Del 1: Räkna registreringar av höjd (Altitude)
I den första delen räknar programmet hur många registreringar av sensortypen Altitude som skedde under ett specifikt datum: den 2 januari 2012.

Funktionalitet:
Itererar genom sensordata och räknar alla Altitude-registreringar där tidpunkten ligger inom 2012-01-02.
Skriver ut antalet registreringar i konsolen.
Konsolutskrift:
less
Copy code
Antal höjdregistreringar den 2 januari 2012: [antal]
Del 2: Kontrollera hastighetsgräns (SpeedInKmh)
I den andra delen kontrollerar programmet om någon registrering av SpeedInKmh överstiger 99.9 km/h.

Funktionalitet:
Itererar genom alla sensordata och letar efter registreringar av typen SpeedInKmh med värden högre än 99.9.
Om en sådan registrering hittas, skrivs ett meddelande om att maxhastigheten är uppnådd.
Annars meddelas att ingen maxhastighet uppnåtts.
Konsolutskrift:
Om maxhastigheten uppnåtts:
bash
Copy code
Maxhastighet uppnådd
Om inte:
bash
Copy code
Ingen maxhastighet uppnådd
Del 3: Uppdatera bränsleförbrukning (FuelConsumption)
I den tredje delen korrigeras alla registreringar av sensortypen FuelConsumption genom att öka deras värde med 75%.

Funktionalitet:
Itererar genom alla sensordata och identifierar poster av typen FuelConsumption.
Uppdaterar värdet för varje sådan registrering genom att multiplicera det med 1.75.
Bekräftar uppdateringen genom att skriva ut ett meddelande i konsolen.
Konsolutskrift:
Copy code
Alla FuelConsumption-poster har uppdaterats med 75%.