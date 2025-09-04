#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);  // Server on port 80

#define led D5

void setup() {
  Serial.begin(9600);
  WiFi.softAP("GURUJI", "123456789");  // ESP as hotspot

  Serial.println();
  Serial.println("NODEMCU AP STARTED!");
  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());

  server.begin();
  pinMode(led, OUTPUT);
}

void loop() {
  client = server.available();  // Check for incoming client

  if (client) {
    Serial.println("New Client Connected!");
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();

    if (request.indexOf("/ledon") != -1) {
      digitalWrite(led, HIGH);
    }
    if (request.indexOf("/ledoff") != -1) {
      digitalWrite(led, LOW);
    }

    // Send HTML response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("Connection: close");
    client.println();
    client.println("<!DOCTYPE html>");
    client.println("<html>");
    client.println("<head><title>ESP8266 LED Control</title></head>");
    client.println("<body style='text-align:center;'>");
    client.println("<h1>WELCOME TO PROJECT</h1>");
    client.println("<h3>CONTROLLER</h3><br>");
    client.println("<a href=\"/ledon\"><button>LED ON</button></a>");
    client.println("<a href=\"/ledoff\"><button>LED OFF</button></a>");
    client.println("</body></html>");

    delay(1);
    client.stop();
    Serial.println("Client disconnected.");
  }
}
