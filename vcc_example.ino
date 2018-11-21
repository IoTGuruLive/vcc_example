#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

ADC_MODE(ADC_VCC);

void setup() {
    Serial.begin(115200);
    Serial.setTimeout(2000);

    WiFi.mode(WIFI_STA);
    WiFi.begin("your.wifi.ssid", "your.wifi.password");

    while (WiFi.status() != WL_CONNECTED) {
        delay(50);
        Serial.print(".");
    }

    Serial.println("Connected...");
}

void loop()
{
    String vcc = String(ESP.getVcc());

    HTTPClient http;
    http.begin("http://api.iotguru.live/measurement/create/sTs5N5dlTmhbPT-ISHZApQ/battery/" + vcc);
    Serial.println("Result code: " + String(http.GET()));
    http.end();
    
    delay(10000);
}

