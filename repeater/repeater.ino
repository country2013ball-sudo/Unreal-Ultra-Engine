#include <WiFi.h>

const char* STA_SSID = "YOUR_2_4_GHZ_WIFI_SSID";
const char* STA_PASS = "YOUR_WIFI_PASSWORD";
const char* AP_SSID  = "ESP32_Repeater";
const char* AP_PASS  = "CHANGE_THIS_PASSWORD";

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);

  if (!WiFi.softAP(AP_SSID, AP_PASS)) {
    Serial.println("Failed to start the repeater access point.");
  }
  WiFi.AP.enableNAPT(true);

  WiFi.begin(STA_SSID, STA_PASS);
}

void loop() {
  static unsigned long lastReconnectAttempt = 0;
  if (WiFi.status() != WL_CONNECTED &&
      millis() - lastReconnectAttempt >= 10000) {
    lastReconnectAttempt = millis();
    WiFi.reconnect();
  }

  delay(10000);
}
