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
Sheet 14 21
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4750 3900 0    60   Input ~ 0
GND
Text HLabel 4750 4000 0    60   BiDi ~ 0
SDA
Text HLabel 4750 4100 0    60   Input ~ 0
SCL
Text HLabel 4750 4200 0    60   Input ~ 0
+3.3V
Text HLabel 6750 4000 2    60   Output ~ 0
DR
Text HLabel 6750 3900 2    60   Input ~ 0
INT
$Comp
L CONN_02X04 P15
U 1 1 58FFA800
P 5800 4050
F 0 "P15" H 5800 4400 50  0000 C CNN
F 1 "Gyro" H 5800 4300 50  0000 C CNN
F 2 "" H 5800 2850 50  0001 C CNN
F 3 "Sécable 2 rangées" H 5800 3800 50  0000 C CNN
	1    5800 4050
	1    0    0    -1  
$EndComp
$Comp
L R R28
U 1 1 58FFDB89
P 5250 4650
F 0 "R28" V 5350 4600 50  0000 L CNN
F 1 "10kΩ" V 5250 4550 50  0000 L CNN
F 2 "" V 5180 4650 50  0001 C CNN
F 3 "" H 5250 4650 50  0001 C CNN
	1    5250 4650
	0    1    1    0   
$EndComp
$Comp
L R R27
U 1 1 58FFDB3E
P 5150 4450
F 0 "R27" V 5250 4400 50  0000 L CNN
F 1 "10kΩ" V 5150 4350 50  0000 L CNN
F 2 "" V 5080 4450 50  0001 C CNN
F 3 "" H 5150 4450 50  0001 C CNN
	1    5150 4450
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 4650 5100 4650
Wire Wire Line
	4750 4200 5550 4200
Wire Wire Line
	5550 4100 4750 4100
Wire Wire Line
	4750 4000 5550 4000
Wire Wire Line
	5550 3900 4750 3900
Wire Wire Line
	5000 4450 5000 4100
Connection ~ 5000 4100
Wire Wire Line
	4900 4000 4900 4650
Connection ~ 4900 4000
$Comp
L R R29
U 1 1 58FFDE68
P 6350 3550
F 0 "R29" V 6450 3500 50  0000 L CNN
F 1 "10kΩ" V 6350 3450 50  0000 L CNN
F 2 "" V 6280 3550 50  0001 C CNN
F 3 "" H 6350 3550 50  0001 C CNN
	1    6350 3550
	0    1    1    0   
$EndComp
$Comp
L R R30
U 1 1 58FFDF3E
P 6450 3350
F 0 "R30" V 6550 3300 50  0000 L CNN
F 1 "10kΩ" V 6450 3250 50  0000 L CNN
F 2 "" V 6380 3350 50  0001 C CNN
F 3 "" H 6450 3350 50  0001 C CNN
	1    6450 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	6050 4000 6750 4000
Wire Wire Line
	6050 3900 6750 3900
Wire Wire Line
	5300 4450 5300 4200
Connection ~ 5300 4200
Wire Wire Line
	5400 4650 5400 4200
Connection ~ 5400 4200
Wire Wire Line
	6500 3550 6500 3900
Connection ~ 6500 3900
Wire Wire Line
	6600 3350 6600 4000
Connection ~ 6600 4000
Wire Wire Line
	6200 3550 5400 3550
Wire Wire Line
	5400 3550 5400 3900
Connection ~ 5400 3900
Wire Wire Line
	6300 3350 5300 3350
Wire Wire Line
	5300 3350 5300 3900
Connection ~ 5300 3900
Text Notes 9600 3250 2    60   ~ 0
Remove those two resistors if INT and DR are "open collector" IOs.\nThough, from what I understood from the datasheet, those IOs are "push-pull" so the two resistors are optional and allow to reduce noise if soldered.
$EndSCHEMATC
