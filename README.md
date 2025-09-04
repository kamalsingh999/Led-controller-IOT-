# 🌐 ESP8266 LED Control Web Server

This is a **practice IoT project** made using **ESP8266 (NodeMCU)**.
The ESP8266 runs in **Access Point (AP) mode** and hosts a small web page where you can turn an LED **ON/OFF** with just one click.

---

## ✨ Features

* 📶 ESP8266 creates its own Wi-Fi hotspot (no external Wi-Fi needed)
* 🌍 Web interface with LED ON/OFF buttons
* 💡 Real-time LED control from any browser
* 🔧 Beginner-friendly IoT practice project

---

## 🛠️ Hardware Used

* ESP8266 (NodeMCU)
* LED + Resistor (220Ω – 330Ω)
* Breadboard & jumper wires

---

## ⚡ Circuit Connection

* **D5 (GPIO14)** → LED (+)
* **GND** → LED (–)

---

## 🚀 How To Use

1. Upload the code to ESP8266 using Arduino IDE.
2. Power up the NodeMCU. It will start a Wi-Fi hotspot:

   * **SSID:** `GURUJI`
   * **Password:** `123456789`
3. Connect your phone/laptop to this Wi-Fi.
4. Open any browser → Type **192.168.4.1**.
5. Control your LED with the **ON/OFF buttons**.

---

## 💻 Code Logic (Core Part)

```cpp
if (request.indexOf("/ledon") != -1) {
  digitalWrite(led, HIGH);   // LED ON
}
if (request.indexOf("/ledoff") != -1) {
  digitalWrite(led, LOW);    // LED OFF
}
```

---

## 🔮 Future Improvements

* Add multiple LED/device control
* Show LED status on webpage (ON/OFF indicator)
* Better UI with CSS styling
* Option to connect ESP8266 in **Wi-Fi Station mode** for internet control

---

✨ This project is just a **practice build**, but it’s a great first step into the world of **IoT and Web Servers with ESP8266** 🚀
