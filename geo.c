#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
 
static const int RX_Pin = 4, TX_Pin = 3;
#define LED_PIN 13
static const uint32_t GPSBaud = 9600;
 
// The TinyGPSPlus object
TinyGPSPlus gps;
 
// The serial connection to the GPS device
SoftwareSerial ss(RX_Pin, TX_Pin);
 
// Geofence coordinates
#define GEOFENCE_LAT 28.523376 //replace with your latitude
#define GEOFENCE_LON 77.573295 //replace with your longitude
#define GEOFENCE_RADIUS 400 // in meters
 
 
 
void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);
  pinMode(LED_PIN, OUTPUT);
}
 
void loop() {
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {
      // double lat = gps.location.lat();
      // double lon = gps.location.lng();
      double lat = 28.525618;

      double lon = 77.574974;
       
      if (distance(lat, lon, GEOFENCE_LAT, GEOFENCE_LON) > GEOFENCE_RADIUS) {
        // digitalWrite(LED_PIN, HIGH);
        Serial.println("Outside");
      } else {
        // digitalWrite(LED_PIN, LOW);
        Serial.println("Inside");
      }
       
      Serial.print("Latitude: ");
      Serial.print(lat, 6);
      Serial.print(" Longitude: ");
      Serial.print(lon, 6);
      Serial.print(" Distance: ");
      Serial.println(distance(lat, lon, GEOFENCE_LAT, GEOFENCE_LON));
    }
  }
}
 
double distance(double lat1, double lon1, double lat2, double lon2) {
  double R = 6371000; // Earth's radius in meters
  double phi1 = radians(lat1);
  double phi2 = radians(lat2);
  double deltaPhi = radians(lat2-lat1);
  double deltaLambda = radians(lon2-lon1);
 
  double a = sin(deltaPhi/2) * sin(deltaPhi/2) +
          cos(phi1) * cos(phi2) *
          sin(deltaLambda/2) * sin(deltaLambda/2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
 
  double d = R * c;
  return d;
}
