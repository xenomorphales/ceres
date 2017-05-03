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
Sheet 13 21
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
L CONN_01X02 P13
U 1 1 55E7E313
P 5700 3800
F 0 "P13" H 5700 3950 50  0000 C CNN
F 1 "Bat7.4V" V 5800 3800 50  0000 C CNN
F 2 "" H 5700 3800 60  0001 C CNN
F 3 "male XT-60" H 5700 4050 60  0000 C CNN
	1    5700 3800
	1    0    0    -1  
$EndComp
Text HLabel 5000 3750 0    60   Output ~ 0
GND
Text HLabel 5000 4350 0    60   Output ~ 0
+7.4V
$Comp
L CONN_01X02 P14
U 1 1 58FD949B
P 5700 4300
F 0 "P14" H 5650 4450 50  0000 L CNN
F 1 "EmergStop" V 5800 4100 50  0000 L CNN
F 2 "" H 5700 4300 50  0001 C CNN
F 3 "female XT-60" H 5700 4050 50  0000 C CNN
	1    5700 4300
	1    0    0    -1  
$EndComp
$Comp
L CP1 C14
U 1 1 59088A59
P 5150 4050
F 0 "C14" H 5035 4004 50  0000 R CNN
F 1 "470µF" H 5035 4095 50  0000 R CNN
F 2 "" H 5150 4050 50  0001 C CNN
F 3 "" H 5150 4050 50  0001 C CNN
	1    5150 4050
	-1   0    0    1   
$EndComp
Wire Wire Line
	5000 4350 5500 4350
Wire Wire Line
	5500 3750 5000 3750
Wire Wire Line
	5500 3850 5500 4250
Wire Wire Line
	5150 3900 5150 3750
Connection ~ 5150 3750
Wire Wire Line
	5150 4200 5150 4350
Connection ~ 5150 4350
$EndSCHEMATC
