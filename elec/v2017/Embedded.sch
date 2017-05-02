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
Sheet 21 21
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
L CONN_02X15 P24
U 1 1 5908EEDE
P 5400 3800
F 0 "P24" H 5400 4715 50  0000 C CNN
F 1 "Embedded" H 5400 4624 50  0000 C CNN
F 2 "" H 5400 2650 50  0001 C CNN
F 3 "" H 5400 2650 50  0001 C CNN
	1    5400 3800
	1    0    0    -1  
$EndComp
Text HLabel 5050 3200 0    60   Output ~ 0
+5V
Text HLabel 5750 3100 2    60   Output ~ 0
+3.3V
Text HLabel 5050 3100 0    60   Output ~ 0
GND
Text HLabel 5750 3200 2    60   Input ~ 0
Pull
Text HLabel 5050 3300 0    60   Input ~ 0
Servos_RX
Text HLabel 5750 3300 2    60   Output ~ 0
Servos_TX
Text HLabel 5050 3400 0    60   Output ~ 0
SCL
Text HLabel 5750 3400 2    60   BiDi ~ 0
SDA
Text HLabel 5050 3500 0    60   Input ~ 0
DR
Text HLabel 5750 3500 2    60   Output ~ 0
INT
Text HLabel 5050 3600 0    60   Output ~ 0
EN_A
Text HLabel 5750 3600 2    60   Output ~ 0
EN_B
Text HLabel 5050 3700 0    60   Output ~ 0
DIR_A_1
Text HLabel 5050 3800 0    60   Output ~ 0
DIR_A_2
Text HLabel 5750 3700 2    60   Output ~ 0
DIR_B_1
Text HLabel 5750 3800 2    60   Output ~ 0
DIR_B_2
Text HLabel 5050 3900 0    60   Output ~ 0
Trigger_1
Text HLabel 5750 3900 2    60   Input ~ 0
Echo_1
Text HLabel 5050 4000 0    60   Output ~ 0
Trigger_2
Text HLabel 5750 4000 2    60   Input ~ 0
Echo_2
Text HLabel 5050 4100 0    60   Output ~ 0
Trigger_3
Text HLabel 5750 4100 2    60   Input ~ 0
Echo_3
Text HLabel 5050 4200 0    60   Output ~ 0
Trigger_4
Text HLabel 5750 4200 2    60   Input ~ 0
Echo_4
Text HLabel 5050 4300 0    60   Input ~ 0
GP2_1
Text HLabel 5750 4300 2    60   Input ~ 0
GP2_2
Text HLabel 5050 4400 0    60   Input ~ 0
GP2_3
Text HLabel 5750 4400 2    60   Input ~ 0
GP2_4
Text HLabel 5050 4500 0    60   Input ~ 0
Extra_RX
Text HLabel 5750 4500 2    60   Output ~ 0
Extra_TX
Wire Wire Line
	5050 3100 5150 3100
Wire Wire Line
	5050 3200 5150 3200
Wire Wire Line
	5050 3300 5150 3300
Wire Wire Line
	5050 3400 5150 3400
Wire Wire Line
	5050 3500 5150 3500
Wire Wire Line
	5050 3600 5150 3600
Wire Wire Line
	5050 3700 5150 3700
Wire Wire Line
	5050 3800 5150 3800
Wire Wire Line
	5050 3900 5150 3900
Wire Wire Line
	5050 4000 5150 4000
Wire Wire Line
	5050 4100 5150 4100
Wire Wire Line
	5050 4200 5150 4200
Wire Wire Line
	5050 4300 5150 4300
Wire Wire Line
	5050 4400 5150 4400
Wire Wire Line
	5050 4500 5150 4500
Wire Wire Line
	5650 3100 5750 3100
Wire Wire Line
	5650 3200 5750 3200
Wire Wire Line
	5650 3300 5750 3300
Wire Wire Line
	5650 3400 5750 3400
Wire Wire Line
	5650 3500 5750 3500
Wire Wire Line
	5650 3600 5750 3600
Wire Wire Line
	5650 3700 5750 3700
Wire Wire Line
	5650 3800 5750 3800
Wire Wire Line
	5650 3900 5750 3900
Wire Wire Line
	5650 4000 5750 4000
Wire Wire Line
	5650 4100 5750 4100
Wire Wire Line
	5650 4200 5750 4200
Wire Wire Line
	5650 4300 5750 4300
Wire Wire Line
	5650 4400 5750 4400
Wire Wire Line
	5650 4500 5750 4500
$EndSCHEMATC
