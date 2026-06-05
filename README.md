# 🌡️ ESP32 Cloud Weather Station (DHT22 & ThingSpeak IoT Platform)

Dự án xây dựng một hệ thống trạm đo thời tiết nhỏ gọn sử dụng vi điều khiển **ESP32** để thu thập dữ liệu nhiệt độ, độ ẩm từ cảm biến **DHT22**, sau đó đồng bộ hóa dữ liệu lên đám mây thông qua nền tảng **ThingSpeak IoT**. Hệ thống cũng tích hợp cảnh báo cục bộ bằng **Đèn LED**.

## 🚀 Tính năng chính
* [cite_start]**Thu thập dữ liệu thời gian thực:** Đọc chính xác nhiệt độ (°C) và độ ẩm (%) từ cảm biến DHT22[cite: 10].
* [cite_start]**Kết nối Cloud:** Tự động kết nối WiFi và đẩy dữ liệu lên ThingSpeak Dashboard sau mỗi 10 giây[cite: 8, 14, 17].
* [cite_start]**Cảnh báo thông minh (Local Alert):** Tự động bật đèn LED cảnh báo nếu môi trường vượt ngưỡng an toàn (Nhiệt độ > 35°C hoặc < 12°C, Độ ẩm > 70% hoặc < 40%)[cite: 12, 13].

## 🛠️ Thành phần linh kiện & Sơ đồ mạch
### Phần cứng sử dụng:
* **Vi điều khiển:** ESP32 DevKit V1
* **Cảm biến:** DHT22 (Nhiệt độ & Độ ẩm)
* **Cảnh báo:** Đèn LED Đỏ & Điện trở

### Sơ đồ kết nối chân (Pin Mapping):
* **DHT22 Data PIN** ➡️ ESP32 `GPIO15`
* **LED Anode (+)** ➡️ ESP32 `GPIO13`

---

## 💻 Cài đặt & Sử dụng

### 1. Thư viện yêu cầu (Dependencies)
[cite_start]Để chạy được code này trên Arduino IDE hoặc Wokwi, bạn cần cài đặt các thư viện[cite: 2]:
* [cite_start]`DHT sensor library for ESPx` [cite: 2]
* [cite_start]`WiFi` [cite: 2]
* [cite_start]`ThingSpeak` [cite: 2]

### 2. Cấu hình Firmware
Mở file `sketch.ino` và cập nhật thông tin mạng WiFi cũng như API Key của bạn:
```cpp
const char* WIFI_NAME = "TÊN_WIFI_CỦA_BẠN";
const char* WIFI_PASSWORD = "MẬT_KHẨU_WIFI";
const int myChannelNumber = 2226105; 
const char* myApiKey = "MÃ_API_KEY_CỦA_BẠN";