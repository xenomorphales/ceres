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
Sheet 10 21
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
L R R17
U 1 1 5603CA31
P 5700 3350
F 0 "R17" V 5780 3350 50  0000 C CNN
F 1 "100kΩ" V 5700 3350 50  0000 C CNN
F 2 "" V 5630 3350 30  0001 C CNN
F 3 "" H 5700 3350 30  0000 C CNN
	1    5700 3350
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 5603CA38
P 5950 3500
F 0 "R18" V 6030 3500 50  0000 C CNN
F 1 "18kΩ" V 5950 3500 50  0000 C CNN
F 2 "" V 5880 3500 30  0001 C CNN
F 3 "" H 5950 3500 30  0000 C CNN
	1    5950 3500
	0    1    1    0   
$EndComp
$Comp
L C C13
U 1 1 5603CA3F
P 6150 3750
F 0 "C13" H 6175 3850 50  0000 L CNN
F 1 "1µF" H 6175 3650 50  0000 L CNN
F 2 "" H 6188 3600 30  0001 C CNN
F 3 "" H 6150 3750 60  0000 C CNN
	1    6150 3750
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P9
U 1 1 5603CA46
P 5500 3850
F 0 "P9" H 5500 4000 50  0000 C CNN
F 1 "Switch" V 5600 3850 50  0000 C CNN
F 2 "" H 5500 3850 60  0001 C CNN
F 3 "Vertical male connector 2.54mm" H 5500 4100 60  0000 C CNN
	1    5500 3850
	-1   0    0    1   
$EndComp
Text HLabel 5700 3200 1    60   Input ~ 0
+3.3V
Text HLabel 5950 3900 3    60   Input ~ 0
GND
Wire Wire Line
	5700 3500 5800 3500
Wire Wire Line
	6100 3500 6450 3500
Wire Wire Line
	6150 3600 6150 3500
Connection ~ 6150 3500
Wire Wire Line
	5700 3500 5700 3800
Wire Wire Line
	5700 3900 6150 3900
Text HLabel 6450 3500 2    60   Output ~ 0
Signal
$EndSCHEMATC
