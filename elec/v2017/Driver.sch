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
Sheet 12 21
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 5400 4850 0    60   Input ~ 0
+7.4V
Text HLabel 5050 3700 0    60   Input ~ 0
+5V
Text HLabel 5400 4750 0    60   Input ~ 0
GND
Text HLabel 5050 3600 0    60   Input ~ 0
EN_A
Text HLabel 6750 3600 2    60   Input ~ 0
DIR_A_1
Text HLabel 6750 3700 2    60   Input ~ 0
DIR_A_2
Text HLabel 5050 3900 0    60   Input ~ 0
EN_B
Text HLabel 6750 3800 2    60   Input ~ 0
DIR_B_1
Text HLabel 6750 3900 2    60   Input ~ 0
DIR_B_2
$Comp
L CONN_01X02 P12
U 1 1 58FD29DE
P 5700 4800
F 0 "P12" H 5700 4950 50  0000 C CNN
F 1 "Power" V 5800 4800 50  0000 C CNN
F 2 "" H 5700 4800 50  0001 C CNN
F 3 "XT-60" H 5700 4650 50  0000 C CNN
	1    5700 4800
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X04 P11
U 1 1 58FD3156
P 5700 3750
F 0 "P11" H 5700 3500 50  0000 C CNN
F 1 "Driver" H 5700 4000 50  0000 C CNN
F 2 "" H 5700 2550 50  0001 C CNN
F 3 "Sécable 2 rangées" H 5700 4100 50  0000 C CNN
	1    5700 3750
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5400 4850 5500 4850
Wire Wire Line
	5500 4750 5400 4750
$Comp
L R R22
U 1 1 58FD453F
P 5350 4200
F 0 "R22" V 5450 4150 50  0000 L CNN
F 1 "10kΩ" V 5350 4100 50  0000 L CNN
F 2 "" V 5280 4200 50  0001 C CNN
F 3 "" H 5350 4200 50  0001 C CNN
	1    5350 4200
	1    0    0    -1  
$EndComp
$Comp
L R R21
U 1 1 58FD46F1
P 5150 4200
F 0 "R21" V 5250 4150 50  0000 L CNN
F 1 "10kΩ" V 5150 4100 50  0000 L CNN
F 2 "" V 5080 4200 50  0001 C CNN
F 3 "" H 5150 4200 50  0001 C CNN
	1    5150 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3900 5450 3900
Wire Wire Line
	5050 3700 5450 3700
Wire Wire Line
	5050 3600 5450 3600
Wire Wire Line
	5150 3600 5150 4050
Connection ~ 5150 3600
Wire Wire Line
	5350 3900 5350 4050
Connection ~ 5350 3900
$Comp
L R R24
U 1 1 58FD4784
P 6250 4200
F 0 "R24" V 6350 4150 50  0000 L CNN
F 1 "10kΩ" V 6250 4100 50  0000 L CNN
F 2 "" V 6180 4200 50  0001 C CNN
F 3 "" H 6250 4200 50  0001 C CNN
	1    6250 4200
	1    0    0    -1  
$EndComp
$Comp
L R R23
U 1 1 58FD478A
P 6050 4200
F 0 "R23" V 6150 4150 50  0000 L CNN
F 1 "10kΩ" V 6050 4100 50  0000 L CNN
F 2 "" V 5980 4200 50  0001 C CNN
F 3 "" H 6050 4200 50  0001 C CNN
	1    6050 4200
	1    0    0    -1  
$EndComp
$Comp
L R R26
U 1 1 58FD47C6
P 6650 4200
F 0 "R26" V 6750 4150 50  0000 L CNN
F 1 "10kΩ" V 6650 4100 50  0000 L CNN
F 2 "" V 6580 4200 50  0001 C CNN
F 3 "" H 6650 4200 50  0001 C CNN
	1    6650 4200
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 58FD47CC
P 6450 4200
F 0 "R25" V 6550 4150 50  0000 L CNN
F 1 "10kΩ" V 6450 4100 50  0000 L CNN
F 2 "" V 6380 4200 50  0001 C CNN
F 3 "" H 6450 4200 50  0001 C CNN
	1    6450 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3600 6750 3600
Wire Wire Line
	5950 3700 6750 3700
Wire Wire Line
	5950 3800 6750 3800
Wire Wire Line
	5950 3900 6750 3900
Wire Wire Line
	6050 3600 6050 4050
Connection ~ 6050 3600
Wire Wire Line
	6250 3700 6250 4050
Connection ~ 6250 3700
Wire Wire Line
	6450 3800 6450 4050
Connection ~ 6450 3800
Wire Wire Line
	6650 3900 6650 4050
Connection ~ 6650 3900
Wire Wire Line
	5150 4350 5150 4450
Wire Wire Line
	5150 4450 6650 4450
Wire Wire Line
	5350 4350 5350 4450
Connection ~ 5350 4450
Wire Wire Line
	6050 4450 6050 4350
Wire Wire Line
	6250 4450 6250 4350
Connection ~ 6050 4450
Wire Wire Line
	6450 4450 6450 4350
Connection ~ 6250 4450
Wire Wire Line
	6650 4450 6650 4350
Connection ~ 6450 4450
Wire Wire Line
	5450 4750 5450 4450
Connection ~ 5450 4450
Connection ~ 5450 4750
$EndSCHEMATC
