/*
   This is the code for the project,
   Automation without Sensor


   Code is written and tested by founder and owner of techiesms(http://www.techiesms.com)
   Mr. Sachin Soni

   Owner has all the copyrights for this code, and it's provided
   open source for fair use only. No one can do business using
   this code.

*/
// Necessary Library for this project
#include <ESP8266WiFi.h>

//Name of the wifi network whom we are supposed to track
const char* SSID = "SmS";

// Relay pin number
#define relay1 0


//   Return RSSI(Received Signal Strength Indicator) or 0 if target SSID not found
int32_t getRSSI(const char* target_ssid) {
  byte available_networks = WiFi.scanNetworks();

  for (int network = 0; network < available_networks; network++) {
    if (WiFi.SSID(network).compareTo(target_ssid) == 0) {     //stringOne.compareTo(stringTwo) < 0
      return WiFi.RSSI(network);
    }
  }
  return 0;
}

void setup() {
  Serial.begin(115200);
  pinMode(relay1, OUTPUT); //  Initialize the relay pin as an output.
}

void loop() {
  int32_t rssi = getRSSI(SSID);


  // For debugging purpose only
  Serial.print("Signal strength: ");
  Serial.print(rssi);
  Serial.println("dBm");

  if (rssi > (-70) && rssi != 0) // if rssi is greater then -70 dbm or it's 0 dbm, then the light will turn ON
  {
    digitalWrite(relay1, LOW);
    Serial.println("ON");
  }
  else // else, the light will be turned OFF.
  {
    digitalWrite(relay1, HIGH);
    Serial.println("OFF");
  }
}
