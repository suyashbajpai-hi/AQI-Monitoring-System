# Smart Air Quality Monitoring System

A prototype IoT-based system that monitors air pollution in real time and automatically activates water sprinkling when air quality crosses a safe threshold.

## Overview

Air pollution is one of the major environmental and public health challenges today. Traditional pollution-control methods such as manual sprinkling and fog cannons are often inefficient because they rely on fixed schedules, delayed response, and uneven coverage.

The **Smart Air Quality Monitoring System** is designed to solve this problem by using sensors to continuously monitor surrounding air conditions. When the detected pollution level exceeds a predefined limit, the system automatically turns on a water pump to help reduce airborne dust and pollutants.

This project is especially useful for areas such as:

- Construction sites
- Mining fields
- Industrial zones
- Dust-prone outdoor environments

## Problem Statement

Current water-based AQI control systems have several limitations:

- Manual operation causes delay
- Fixed scheduling leads to water wastage
- Uneven spraying reduces effectiveness
- No real-time adaptability to pollution spikes
- Poor adjustment to weather conditions like humidity and wind

## Proposed Solution

Our system provides a smart and automated way to control air pollution by:

- Monitoring air quality in real time
- Detecting harmful gases and environmental conditions
- Displaying live data locally
- Sending data to an IoT dashboard
- Automatically activating water sprinkling when pollution rises above safe levels

## Features

- Real-time air quality monitoring
- Automatic water pump activation
- AQI-based smart response
- Temperature and humidity sensing
- LCD display for live status
- IoT connectivity using Wi-Fi
- Remote data logging and visualization
- Reduced water wastage compared to manual systems

## Hardware Requirements

- Arduino UNO
- MQ135 Gas Sensor
- MQ7 Gas Sensor
- MQ2 Gas Sensor
- DHT11 / DHT22 Temperature and Humidity Sensor
- L293D Motor Driver
- Water Pump
- 16x2 LCD Display with I2C Module
- ESP-01 Wi-Fi Module
- Jumper wires
- Breadboard / PCB
- Power supply

## Software Requirements

- Arduino IDE
- ThingSpeak (IoT dashboard / cloud analytics platform)

## Working Principle

1. The gas sensors and temperature/humidity sensor continuously collect environmental data.
2. Arduino processes this sensor data and compares it with predefined safe thresholds.
3. If pollution exceeds the acceptable limit:
   - the motor driver is triggered
   - the water pump turns on
4. The current status is shown on the LCD display.
5. Data is sent to the IoT dashboard through the Wi-Fi module for monitoring and analysis.

## System Architecture

The system follows this flow:

**Sensors → Arduino UNO → Decision Logic → LCD / Water Pump / Wi-Fi Module → ThingSpeak Dashboard**

## Applications

- Construction dust control
- Mining area pollution reduction
- Industrial safety monitoring
- Outdoor environmental monitoring
- Smart city pollution management systems

## Benefits

- Real-time response to pollution increase
- Automated operation
- Better water management
- Lower labor dependency
- Improved environmental safety
- Useful for high-risk pollution zones
- Scalable for larger smart monitoring systems

## Future Scope

This project can be improved further by adding:

- AI-based predictive pollution control
- More accurate AQI calculation models
- Mobile app integration
- Solar-powered deployment
- Drone-based or mobile sprinkler systems
- GPS-based location tracking for large sites
- Advanced weather-adaptive control

## Result and Conclusion

The Smart Air Quality Monitoring System offers an efficient and practical method for monitoring pollution and responding automatically when air quality becomes unsafe. By combining IoT, automation, and environmental sensing, the system helps create a cleaner and healthier atmosphere in pollution-prone areas.

This project demonstrates how low-cost smart technologies can be used for sustainable environmental management.

## Team

**Team CodersBase**

- Mohit Mehta (Team Lead)
- Suyash Bajpai

## References

- Articles on AQI, anti-smog systems, and pollution control
- ThingSpeak IoT platform
- Arduino documentation
- Sensor datasheets for MQ135, MQ7, MQ2, and DHT series

## License

This project is for academic and prototype purposes. You can add a license such as MIT if you plan to make it open source.
