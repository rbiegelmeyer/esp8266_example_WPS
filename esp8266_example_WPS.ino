// Test for ESP8266 WPS connection.

#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP); 
}

void connectWPS(){
  // WPS works in STA (Station mode) only.
  WiFi.mode(WIFI_STA);
  delay(100);
  // Called to check if SSID and password has already been stored by previous WPS call.
  // The SSID and password are stored in flash memory and will survive a full power cycle.
  // Calling ("",""), i.e. with blank string parameters, appears to use these stored values.
  WiFi.begin("","");
  // Long delay required especially soon after power on.
  delay(3000);
  // Check if WiFi is already connected and if not, begin the WPS process. 
  if (WiFi.status() != WL_CONNECTED) {
      Serial.println("\nAttempting connection ...");
      WiFi.beginWPSConfig();
      // Another long delay required.
      delay(5000);
      if (WiFi.status() == WL_CONNECTED) {
        Serial.println("Connected!");
        Serial.println(WiFi.localIP());
        Serial.println(WiFi.SSID());
        Serial.println(WiFi.macAddress());
      }
    else {
        Serial.println("Connection failed!");
      }
  }
  else {
    Serial.println("\nConnection already established.");
  }
}

void teste(){
  WiFi.begin("Qualquer coisa","CoisaQualquer");
  delay(1000);
  Serial.println("Connection lost!");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if (!digitalRead(12))
    connectWPS();
  else if (!digitalRead(14))
    teste();
    
}
