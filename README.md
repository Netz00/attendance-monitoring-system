# Attendance monitoring system

- [Presentation](./documentation/AttendanceMonitoringSystem.pptx)


## Main Concept

<p align="center">
  <img src="./documentation/basicIdea.png" alt="Basic idea" width="670"/>
</p>

---

<p align="center">
  <img src="./documentation/tls.png" alt="TLS security" width="670"/>
</p>

## Recording attendance flow

<p align="center">
  <img src="./documentation/sequence_diagram.png" alt="Recording attendance flow" width="750"/>
</p>

## RFID Reader
- *./esp8266* : Card reader arduino code

<p align="center">
  <img src="./documentation/reader.png" alt="Reader" width="500"/>
</p>

## Server side
- *./attendance-monitoring-system* : Backend

### Development and environments 

<p align="center">
  <img src="./documentation/server.png" alt="Development" width="750"/>
</p>

### ER diagram

<p align="center">
  <img src="./documentation/erd.svg" alt="ER diagram" width="750"/>
</p>




## Requirements
- NFC-enabled mobile devices with [MIFARE Classic Tool apk](https://play.google.com/store/apps/details?id=de.syss.MifareClassicTool&hl=en)
- Java 21, Maven
- Visual Studio Code
  - PlatformIO extension
- Router or mobile hotspot
- optional:
  - IntelliJ
  - Docker (if you want to use Postregs DB instead H2)
- Electronics
  - ESP8266
  - RC522 (working one)
  - Buzzer
  - RGB LED
  - ISO-14443A tag (usually comes with RC522)

## Get started

### 1. Tag preparement
1. MIFARE Classic Tool apk 

### 2. Starting the system
1. Connect the server to the Internet
2. Get server IP address
3. Insert server IP address and Wi-Fi credentials [here](./src/client/client.h).
4. Upload code to the ESP8266
5. Run the Spring boot application
6. Open [H2 Console](http://localhost:8080/h2-console/) and test tag reading!

# References

- [Tutorial: how an RFID 13.56 Mhz read/write ISO-14443A tag works.](https://www.puntoflotante.net/TUTORIAL-RFID-ISO-14443A-TAGS-13.56-MHZ.htm)
- [Tag Memory access](https://www.mouser.com/datasheet/2/302/MF1S503x-89574.pdf#page=11)
- [A 2018 practical guide to hacking NFC/RFID](https://smartlockpicking.com/slides/Confidence_A_2018_Practical_Guide_To_Hacking_RFID_NFC.pdf)
- [Online tool for creating UML sequence diagrams](https://sequencediagram.org/)
