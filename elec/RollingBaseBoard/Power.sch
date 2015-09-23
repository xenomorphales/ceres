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
LIBS:RollingBaseBoard-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 17
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
L CONN_01X02 P5
U 1 1 55E7E300
P 5150 3200
F 0 "P5" H 5150 3350 50  0000 C CNN
F 1 "Bat5V" V 5250 3200 50  0000 C CNN
F 2 "" H 5150 3200 60  0000 C CNN
F 3 "" H 5150 3200 60  0000 C CNN
	1    5150 3200
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X02 P6
U 1 1 55E7E313
P 6800 3200
F 0 "P6" H 6800 3350 50  0000 C CNN
F 1 "Bat15V" V 6900 3200 50  0000 C CNN
F 2 "" H 6800 3200 60  0000 C CNN
F 3 "" H 6800 3200 60  0000 C CNN
	1    6800 3200
	1    0    0    -1  
$EndComp
Text HLabel 5350 3150 2    60   Output ~ 0
+5V
Wire Wire Line
	5350 3250 6000 3250
Wire Wire Line
	6000 3250 6000 2950
Wire Wire Line
	6600 3150 6000 3150
Connection ~ 6000 3150
Text HLabel 6000 2950 1    60   Output ~ 0
GND
Wire Wire Line
	6600 3250 6300 3250
Wire Wire Line
	6300 3250 6300 3700
Wire Wire Line
	6300 3700 5950 3700
Text HLabel 5450 3700 0    60   Output ~ 0
+15V
$Comp
L FUSE F1
U 1 1 560397C6
P 5700 3700
F 0 "F1" H 5800 3750 50  0000 C CNN
F 1 "FUSE" H 5600 3650 50  0000 C CNN
F 2 "" H 5700 3700 60  0000 C CNN
F 3 "" H 5700 3700 60  0000 C CNN
	1    5700 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
