#include <WiFi.h> 
#include "DHTesp.h"
#include "ThingSpeak.h"

const int DHT_PIN = 15; 
const int LED_PIN = 13; 
const char* WIFI_NAME = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";
const int myChannelNumber =2226105 ; 
const char* myApiKey = "6DJVFJ7DZ3A57A0M"; // API key để gửi dữ liệu lên kênh
const char* server = "api.thingspeak.com"; // Địa chỉ server của ThingSpeak

DHTesp dhtSensor; // Tạo đối tượng cảm biến DHT22
WiFiClient client; // Tạo client để kết nối Internet

void setup() {
  Serial.begin(115200); // Khởi động giao tiếp Serial để xem log
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
  pinMode(LED_PIN, OUTPUT); // Đặt chân LED là output
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.println("Wifi not connected");
  }
  Serial.println("Wifi connected !");
  Serial.println("Local IP: " + String(WiFi.localIP()));
  WiFi.mode(WIFI_STA); // Đặt ESP32 là thiết bị khách
  ThingSpeak.begin(client);
}

void loop() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity(); // Đọc dữ liệu nhiệt độ và độ ẩm từ DHT22
  ThingSpeak.setField(1,data.temperature); // Gửi nhiệt độ lên field 1 của ThingSpeak
  ThingSpeak.setField(2,data.humidity);
  if (data.temperature > 35 || data.temperature < 12 || data.humidity > 70 || data.humidity < 40) {
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
  
  int x = ThingSpeak.writeFields(myChannelNumber,myApiKey); // Gửi dữ liệu lên ThingSpeak
  
  Serial.println("Temp: " + String(data.temperature, 2) + "°C");
  Serial.println("Humidity: " + String(data.humidity, 1) + "%");
  
  if(x == 200){
    Serial.println("Data pushed successfull");
  }else{
    Serial.println("Push error" + String(x));
  }
  Serial.println("---");

  delay(10000); // Chờ 10 giây trước lần đọc/gửi tiếp theo
}