# Climate and Gas Monitoring

## Overview

This project implements a system to monitor environmental conditions using a **DHT22 sensor** to measure **humidity** and **temperature**, and an analog sensor to detect **ammonia levels** in the air. The data is processed and displayed via the **Serial Monitor**.

## Components Used

- **DHT22 Sensor (AM2302)**: Measures temperature and humidity.
- **Analog Sensor**: Detects ammonia levels (PPM) through analog readings.
- **Arduino**: The microcontroller to run the program.

## Features

- **Humidity Monitoring**: Displays the current humidity percentage.
- **Temperature Monitoring**: Displays the current temperature in Celsius.
- **Ammonia Detection**: Converts the analog signal from the sensor to represent the ammonia concentration in parts per million (PPM).

## Wiring

- **DHT22 Sensor**: Connect the data pin to digital pin 7 of the Arduino.
- **Ammonia Sensor**: Connect the analog output to analog pin A3 of the Arduino.

## How It Works

1. **DHT22 Sensor**: The sensor is initialized in the `setup()` function and begins reading humidity and temperature values in the `loop()`. These values are printed to the Serial Monitor.
   
2. **Ammonia Sensor**: The analog sensor value is read and converted using the `map()` function to estimate the ammonia level in PPM. Both the raw and converted values are printed to the Serial Monitor.

3. **Data Output**: Every 60 seconds, the system prints updated readings for humidity, temperature, and ammonia concentration to the Serial Monitor.

## How to Use

1. Clone the repository:

 git clone https://github.com/yourusername/Climate-and-Gas-Monitoring.git

2. Upload the code to your Arduino.

3. Open the Serial Monitor in the Arduino IDE to see the readings every 60 seconds.

## License

This project is licensed under the MIT License.