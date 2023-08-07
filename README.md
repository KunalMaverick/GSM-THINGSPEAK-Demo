# GSM-THINGSPEAK-Demo
This is a project which demonstrates how you can get GSM module to interact with thingspeak
This rep contains the the arduino code required to connect your GSM - Sim 800L or any GSM shield to thingspeak and demonstrates how you can make your GSM shield interact with thingspeak. The aim of this rep is not to dive deep into the schematics but to provide a look into how  GSM shield can be integrated with Thingspeak. (altho ill be dropping a lil info on the wiring too :)) )

## What I have used (Schematic wise)
I had used an Arduino Leonardo and a GSM sim 900 shield (thanks to the shield, the wiring wasnt a huge brainer :)) , saved a lot of time :) )
ill be dropping a basic pic on the wiring part

![image](https://github.com/KunalMaverick/GSM-THINGSPEAK-Demo/assets/40132560/edc564b6-5176-40c2-982b-fb6cac76952b)
(source:- https://forum.arduino.cc/t/arduino-uno-gsm-shield-sim-900-problem/388675)
(feel free to edit the RX and TX pins in the arduino file according to your wiring)

## Explanation:-

<img width="379" alt="image" src="https://github.com/KunalMaverick/GSM-THINGSPEAK-Demo/assets/40132560/6b36f511-9ea1-4c10-be89-7c23f75cf1b1">

This here is basically initialising all the basic required things to fire up the arduino
- Libraries and Global Variables:

The code includes the "SoftwareSerial" library, which allows software-based serial communication with external devices.
A SoftwareSerial object "gsmSerial" is defined with pins 8 (RX) and 7 (TX) for communication with the GSM/GPRS module.
A global variable "MyValue1" is declared to store the random value generated.
setup() Function:

- The setup() function is the initialization function that runs only once when the Arduino is powered on or reset.
The GSM serial port is initialized with a baud rate of 9600 using gsmSerial.begin(9600).
The hardware serial port (connected to the computer) is also initialized with a baud rate of 9600 using Serial.begin(9600).
loop() Function:

- The loop() function runs repeatedly after the setup() function finishes executing.
A random value between 50 and 500 is generated using random(50, 500) and stored in the variable "MyValue1".
The functions for connecting to the server, sending data, and closing the connection are called in sequence.

<img width="773" alt="image" src="https://github.com/KunalMaverick/GSM-THINGSPEAK-Demo/assets/40132560/e0906558-24e2-412a-bda4-c26fff42a5f1">

- Connect2Server() Function:

This function is responsible for establishing a connection with the server (Thingspeak).
It sends a series of AT commands to the GSM module to perform various tasks, such as checking the SIM card status, registering with the network, bringing up the wireless connection, getting the local IP address, etc.
The function also sets up the GSM module for single-connection mode with AT+CIPMUX=0.
The function then initiates a TCP connection to the Thingspeak server with AT+CIPSTART by providing the server address ("api.thingspeak.com") and port number (80 for HTTP).

- Field1(int data) Function:

This function is responsible for sending data to Field1 of the Thingspeak channel.
It takes an integer value (data) as input, which is the value to be sent to the server.
A URL string is constructed with the API key of the Thingspeak channel and the data value.
The function sends this URL string as an HTTP GET request to the server using AT+CIPSEND and waits for a response.

<img width="516" alt="image" src="https://github.com/KunalMaverick/GSM-THINGSPEAK-Demo/assets/40132560/9f1e772e-75a1-4e8e-9986-724f06acb8fd">




**Note: To make this code work, you need to replace <api_keyof_thingspeak> in the Field1() function with the actual API key of your Thingspeak channel. Additionally, ensure that you have a compatible GSM/GPRS module and the necessary SIM card with a valid data plan and network coverage.**

- EndConnection() Function:

This function is responsible for closing the connection with the server.
It sends the "AT+CIPSHUT" command to terminate the GPRS connection.

- ShowSerialData() Function:

This function is used to display the response received from the GSM module on the serial monitor (connected to the computer).
It continuously reads data from the GSM module's serial buffer and prints it to the hardware serial port, which is then displayed on the serial monitor.





Thats all you need to do know before cloning this rep :))

