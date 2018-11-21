/**
 * VCC send example
 *
 *
 * You need to sign up for create your own node and field: https://iotguru.live/signup
 * 
 * The variables of the API call:
 *
 * {nodeKey} - the API key of your node
 * {field} - the field of the node
 * {value} - the measurement as number
 *
 * http://api.iotguru.live/measurement/create/create/{nodeKey}/{field}/{value}
 *
 * See the example HTTP call below (don't forget to replace values!).
 *
 * Let us 5-10 minutes to begin the aggreation of your measurements and displays them on fancy charts... :)
 *
 */
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
