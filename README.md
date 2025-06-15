# 🤖 Never Falling Bot

A simple Arduino-powered robot that moves freely on a table and **never falls off the edge**, using two downward-facing **IR sensors** to detect surface boundaries.

---

## 📌 Features

- ✅ Detects table edges using 2 IR sensors  
- 🔁 Automatically turns or reverses to avoid falling  
- 🔋 Battery-powered and wireless  
- 📟 Real-time serial messages for debugging  
- 🧠 Smart behavior with simple digital logic

---

## 🎯 Objective

To build a robot that explores table-like surfaces safely without falling off, by sensing the absence of a surface beneath it and changing direction accordingly.

---

## 🧰 Components Used

| Component               | Quantity |
|-------------------------|----------|
| Arduino Uno/Nano        | 1        |
| L293D Module            | 1        |
| IR Sensors              | 2        |
| DC Gear Motors          | 4        |
| Wheels + Chassis        | 1 set    |
| 3.7V Li-ion Batteries   | 2 (series connected for ~7.4V) |
| Battery Holder/Switch   | 1        |
| Jumper Wires            | Several  |

---

## 🔌 Pin Connections

### IR Sensors
- **Left IR Sensor OUT** → Pin **6** (Input)  
- **Right IR Sensor OUT** → Pin **7** (Input)  

### Motor Driver (L293D)
- **Left Motors (2 motors connected in parallel)**  
  - IN1 → Pin **2**  
  - IN2 → Pin **3**  

- **Right Motors (2 motors connected in parallel)**  
  - IN3 → Pin **4**  
  - IN4 → Pin **5**  

**Power:**
- Motors powered using external 7.4V battery pack  
- Arduino powered via VIN (from same battery)  
- Make sure the battery can supply sufficient current for 4 motors

---

👉 View the full code here:  
🔗 [`Never_Falling_Robot.ino`](https://github.com/LakshyaXRobo/Never-Falling-Bot/blob/main/Never_Falling_Robot.ino)

## 🎥 Demo Video

Watch the robot in action as it avoids falling off the table!  
▶️ [Click to Watch Demo Video](https://github.com/LakshyaXRobo/Never-Falling-Bot/blob/main/Never%20Falling%20Bot.mp4)

---

## 🛠️ How to Use

1. Wire up the components according to the pin table above.
2. Upload the code using Arduino IDE.
3. Place the bot on a flat table surface.
4. Power it on using the battery pack.
5. Observe the bot move and safely avoid falling.

---

## 💡 Future Enhancements

- Add more IR sensors for 360° edge detection  
- Integrate obstacle detection using ultrasonic sensors  
- Add buzzer or LED indicators  
- Use PID control for smoother movement  
- Add Bluetooth module for manual override

---

## 👨‍💻 Made By

**Lakshya Sharma**  
Inventor & Developer  
B.Tech ECE | Robotics Enthusiast