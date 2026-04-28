# ECG Monitoring System using AD8232 and Arduino UNO

A real-time Electrocardiogram (ECG) monitoring system designed to capture, filter, and visualize heart activity using the AD8232 heart rate monitor module and an Arduino UNO.

## 🚀 Overview

This project provides a complete solution for low-cost ECG monitoring. It features lead-off detection, baseline drift removal, and low-pass filtering to ensure a clean and stable waveform suitable for visualization on the Arduino Serial Plotter or other serial-based visualization tools.

## ✨ Key Features

- **Real-time Signal Processing**: Implements baseline removal and low-pass filtering on-chip.
- **Lead-off Detection**: Automatically detects when electrodes are disconnected (LO+ or LO-).
- **Optimized Data Rate**: Uses decimation to provide a smooth, flicker-free graph at 50Hz (downsampled from 250Hz).
- **Professional Documentation**: Includes full project report, component list, and presentation.

## 🛠️ Hardware Requirements

| Component | Quantity |
|-----------|----------|
| Arduino UNO | 1 |
| AD8232 Heart Rate Monitor | 1 |
| ECG Electrodes (3-lead) | 1 set |
| Jumper Wires | As needed |
| Breadboard | 1 |

### Circuit Connections

| AD8232 Pin | Arduino Pin |
|------------|-------------|
| GND        | GND         |
| 3.3V       | 3.3V        |
| OUTPUT     | A0          |
| LO-        | D11         |
| LO+        | D10         |

## 💻 Software Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/Saibashita/ECG-Monitoring-System-using-AD8232-and-Arduino-UNO.git
   ```
2. Open `firmware/ecg_monitor/ecg_monitor.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
3. Connect your Arduino UNO to your computer.
4. Select **Arduino UNO** under *Tools > Board*.
5. Click **Upload**.
6. Open the **Serial Plotter** (*Tools > Serial Plotter*) and set the baud rate to **115200**.

## 📊 Signal Processing

The firmware includes a digital signal processing pipeline:
- **Baseline Removal**: Uses a moving average filter to eliminate low-frequency drift caused by breathing or movement.
- **Low-pass Filter**: Reduces high-frequency noise while preserving the QRS complex.
- **Decimation**: Reduces the serial data overhead for smoother plotting.

## 📁 Project Structure

```text
├── firmware/
│   └── ecg_monitor/        # Arduino source code
├── docs/
│   ├── ecg_report.pdf      # Detailed project report
│   ├── presentation.pptx   # Project presentation slides
│   └── components_list.xlsx# Bill of Materials (BOM)
├── assets/
│   └── demonstration.mp4   # Video demonstration of the system
└── README.md
```

## 📜 License

This project is for educational and hobbyist purposes only. It is not a medical-grade device.

---
Developed by [Saibashita](https://github.com/Saibashita)
