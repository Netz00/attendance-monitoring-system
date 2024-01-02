#include "client.h"

const char *ssid = STASSID;
const char *pass = STAPSK;

int initWifiConnection()
{

    WiFi.begin(STASSID, STAPSK);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected! IP address: ");
    Serial.println(WiFi.localIP());

    return 0;
}

String convertBytesToHexString(byte *bytes, int len)
{
    String result = "";
    for (int i = 0; i < len; i++)
    {
        char temp[3];
        snprintf(temp, sizeof(temp), "%02X", bytes[i]);
        result += temp;
    }
    return result;
}

bool sendMessage(byte *ID, int messageLen)
{

    if (WiFi.status() != WL_CONNECTED)
    {
        return false;
    }

    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://" SERVER_IP "/api/v1/records"); // HTTP
    http.addHeader("Content-Type", "application/json");

    Serial.print("[HTTP] POST...\n");
    // start connection and send HTTP header and body

    // prepare message
    char message[70];
    snprintf(message, sizeof(message), "{\"roomName\":\"A100\",\"studentJmbag\":\"%s\"}", convertBytesToHexString(ID, messageLen).c_str());

    int httpCode = http.POST(message); // "{\"roomName\":\"A100\", \"studentJmbag\":\"60198321002313870650000023138706\"}"

    // httpCode will be negative on error
    if (httpCode > 0)
    {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);

        if (httpCode == HTTP_CODE_CREATED)
        {
            const String &payload = http.getString();
            Serial.println("received payload:\n<<");
            Serial.println(payload);
            Serial.println(">>");
            return true;
        }
    }
    else
    {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();

    return false;
}
