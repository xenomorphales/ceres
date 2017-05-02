EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:v2017-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 11 21
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_01X03 P10
U 1 1 55E8DDC2
P 5650 3500
F 0 "P10" H 5650 3700 50  0000 C CNN
F 1 "UART" V 5750 3500 50  0000 C CNN
F 2 "" H 5650 3500 60  0001 C CNN
F 3 "Sécable" H 5650 3300 60  0000 C CNN
	1    5650 3500
	1    0    0    -1  
$EndComp
Text HLabel 5100 3500 0    60   Input ~ 0
GND
Text HLabel 5100 3400 0    60   Input ~ 0
TX
Text HLabel 5100 3600 0    60   Output ~ 0
RX
Text HLabel 5100 2650 0    60   Input ~ 0
+3.3V
$Comp
L R R19
U 1 1 5602B2EE
P 5200 2800
F 0 "R19" V 5280 2800 50  0000 C CNN
F 1 "10kΩ" V 5200 2800 50  0000 C CNN
F 2 "" V 5130 2800 30  0001 C CNN
F 3 "" H 5200 2800 30  0000 C CNN
	1    5200 2800
	1    0    0    -1  
$EndComp
$Comp
L R R20
U 1 1 5602B4FB
P 5400 2800
F 0 "R20" V 5480 2800 50  0000 C CNN
F 1 "10kΩ" V 5400 2800 50  0000 C CNN
F 2 "" V 5330 2800 30  0001 C CNN
F 3 "" H 5400 2800 30  0000 C CNN
	1    5400 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3400 5450 3400
Wire Wire Line
	5100 3500 5450 3500
Wire Wire Line
	5100 3600 5450 3600
Wire Wire Line
	5200 2950 5200 3400
Connection ~ 5200 3400
Wire Wire Line
	5400 2950 5400 3600
Connection ~ 5400 3600
Wire Wire Line
	5100 2650 5400 2650
Connection ~ 5200 2650
$EndSCHEMATC
