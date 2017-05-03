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
Sheet 20 21
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
L CONN_01X06 P22
U 1 1 59092AEE
P 5100 3600
F 0 "P22" H 5050 3950 50  0000 L CNN
F 1 "LevelShifter-3.3V_side" V 5250 3200 50  0000 L CNN
F 2 "" H 5100 3600 50  0001 C CNN
F 3 "Vertical male connector 2.54mm" H 5100 3150 50  0000 C CNN
	1    5100 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X06 P23
U 1 1 59092B31
P 6300 3600
F 0 "P23" H 6250 3950 50  0000 L CNN
F 1 "LevelShifter-5V_side" V 6450 3200 50  0000 L CNN
F 2 "" H 6300 3600 50  0001 C CNN
F 3 "Vertical male connector 2.54mm" H 6300 3050 50  0000 C CNN
	1    6300 3600
	-1   0    0    -1  
$EndComp
Text HLabel 4900 2900 1    60   Input ~ 0
+3.3V
Text HLabel 6500 2900 1    60   Input ~ 0
+5V
Text HLabel 5700 2900 1    60   Input ~ 0
GND
Wire Wire Line
	6500 2900 6500 3350
Wire Wire Line
	4900 2900 4900 3350
Wire Wire Line
	5700 2900 5700 3050
Wire Wire Line
	4800 3050 6600 3050
Wire Wire Line
	4800 3050 4800 3450
Wire Wire Line
	4800 3450 4900 3450
Wire Wire Line
	6600 3050 6600 3450
Wire Wire Line
	6600 3450 6500 3450
Connection ~ 5700 3050
Text HLabel 4700 3550 0    60   BiDi ~ 0
Ch1_3.3V
Text HLabel 4700 3650 0    60   BiDi ~ 0
Ch2_3.3V
Text HLabel 4700 3750 0    60   BiDi ~ 0
Ch3_3.3V
Text HLabel 4700 3850 0    60   BiDi ~ 0
Ch4_3.3V
Text HLabel 6700 3550 2    60   BiDi ~ 0
Ch1_5V
Text HLabel 6700 3650 2    60   BiDi ~ 0
Ch2_5V
Text HLabel 6700 3750 2    60   BiDi ~ 0
Ch3_5V
Text HLabel 6700 3850 2    60   BiDi ~ 0
Ch4_5V
Wire Wire Line
	4700 3550 4900 3550
Wire Wire Line
	4700 3650 4900 3650
Wire Wire Line
	4700 3750 4900 3750
Wire Wire Line
	4700 3850 4900 3850
Wire Wire Line
	6500 3550 6700 3550
Wire Wire Line
	6500 3650 6700 3650
Wire Wire Line
	6500 3750 6700 3750
Wire Wire Line
	6500 3850 6700 3850
$EndSCHEMATC
