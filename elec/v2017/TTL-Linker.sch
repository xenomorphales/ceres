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
Sheet 19 21
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
L CONN_01X03 P20
U 1 1 59087C23
P 5200 4200
F 0 "P20" H 5200 4000 50  0000 C CNN
F 1 "TTL-Linker_TTL" V 5300 4200 50  0000 C CNN
F 2 "" H 5200 4200 50  0001 C CNN
F 3 "" H 5200 4200 50  0001 C CNN
	1    5200 4200
	-1   0    0    1   
$EndComp
Text HLabel 5400 3800 1    60   Input ~ 0
+7.4V
Text HLabel 5700 3800 1    60   Input ~ 0
GND
Text HLabel 6000 3800 1    60   BiDi ~ 0
S
Wire Wire Line
	5400 4300 6000 4300
Wire Wire Line
	6000 4300 6000 3800
$Comp
L CONN_01X02 P21
U 1 1 5908D48B
P 6800 4250
F 0 "P21" H 6750 4400 50  0000 L CNN
F 1 "TTL-Linker_UART" V 6900 3950 50  0000 L CNN
F 2 "" H 6800 4250 50  0001 C CNN
F 3 "" H 6800 4250 50  0001 C CNN
	1    6800 4250
	1    0    0    -1  
$EndComp
Text HLabel 6300 3800 1    60   Input ~ 0
RX
Text HLabel 6600 3800 1    60   Output ~ 0
TX
Wire Wire Line
	6600 3800 6600 4200
Wire Wire Line
	6600 4300 6300 4300
Wire Wire Line
	6300 4300 6300 3800
Wire Wire Line
	5400 4200 5700 4200
Wire Wire Line
	5700 4200 5700 3800
Wire Wire Line
	5400 4100 5400 3800
$EndSCHEMATC
