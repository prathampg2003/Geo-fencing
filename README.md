# GPS Geofencing System with Arduino and TinyGPSPlus

This project implements a GPS geofencing system using an Arduino board and the TinyGPSPlus library. The system detects whether a GPS receiver's location is within a specified geofence area and alerts accordingly.
#### When radius is 400m:-
![image](https://github.com/prathampg2003/Geo-fencing/assets/89197939/c057821e-eb5e-4bbf-b313-938991479831)

#### When radius is 10m:-

![WhatsApp Image 2024-05-07 at 18 36 57_4f2552f3](https://github.com/prathampg2003/Geo-fencing/assets/89197939/e49c6e1c-b049-4785-b6e6-47b0b5d55e8d)


### Components Used:
- Arduino board
- GPS module
- LEDs
- Jumper wires

### Libraries Used:
- TinyGPSPlus: A library for parsing NMEA data streams provided by GPS modules.

### Circuit Diagram:
- Connect the RX pin of the GPS module to pin 4 of the Arduino (RX pin).
- Connect the TX pin of the GPS module to pin 3 of the Arduino (TX pin).
- Connect an LED to pin 13 of the Arduino.

### Functionality:
1. **Setup**: 
   - Serial communication is initialized with the GPS module and the Arduino.
   - Pin 13 is set as an output pin to control the LED.

2. **Loop**:
   - While data is available from the GPS module, the system reads and parses the data using the TinyGPSPlus library.
   - The current latitude and longitude are obtained from the GPS data.
   - The distance between the current location and a predefined geofence location is calculated using the Haversine formula.
   - If the distance exceeds the specified geofence radius, it indicates that the current location is outside the geofence area, and an "Outside" message is printed. Otherwise, an "Inside" message is printed.
   - The current latitude, longitude, and distance from the geofence location are displayed.

3. **Distance Calculation**:
   - The `distance()` function calculates the distance between two coordinates using the Haversine formula, which considers the curvature of the Earth's surface.

### Usage:
1. Connect the GPS module and LED to the Arduino board as per the circuit diagram.
2. Upload the provided Arduino code to the Arduino board.
3. Open the serial monitor to view the system's output.
4. Ensure that the specified geofence coordinates and radius are appropriate for your application.
5. Test the system by moving the GPS module within and outside the geofence area.

### Notes:
- Ensure that the GPS module has a clear view of the sky to obtain accurate location data.
- Adjust the geofence coordinates and radius according to your specific requirements.

