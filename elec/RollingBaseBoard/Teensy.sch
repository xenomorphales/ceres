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
Sheet 12 17
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
L Teensy3.1 U3
U 1 1 55E90B1E
P 4900 3250
F 0 "U3" H 4900 2150 60  0000 C CNN
F 1 "Teensy3.1" H 4900 4300 60  0000 C CNN
F 2 "Footprints:Teensy3.1" H 4900 4450 60  0001 C CNN
F 3 "" H 6300 5200 60  0000 C CNN
	1    4900 3250
	1    0    0    -1  
$EndComp
Text HLabel 4400 2300 0    60   Input ~ 0
GND
Text HLabel 5400 2450 2    60   Input ~ 0
GND
Text HLabel 5400 2300 2    60   Input ~ 0
+5V
Text HLabel 4400 2750 0    60   Input ~ 0
Pull
Text HLabel 4400 2900 0    60   Input ~ 0
Encoder1A
Text HLabel 4400 3050 0    60   Input ~ 0
Encoder1B
Text HLabel 4400 3200 0    60   Input ~ 0
LimitSwitch1
Text HLabel 4400 3350 0    60   Input ~ 0
LimitSwitch2
Text HLabel 4400 3500 0    60   Input ~ 0
LimitSwitch3
Text HLabel 4400 3650 0    60   Input ~ 0
LimitSwitch4
Text HLabel 4400 2450 0    60   Input ~ 0
RX1
Text HLabel 4400 2600 0    60   Output ~ 0
TX1
Text HLabel 4400 3800 0    60   Input ~ 0
RX2
Text HLabel 4400 3950 0    60   Output ~ 0
TX2
Text HLabel 5400 4100 2    60   Input ~ 0
GP2_1
Text HLabel 5400 3950 2    60   Input ~ 0
GP2_2
Text HLabel 5400 3800 2    60   Input ~ 0
GP2_3
Text HLabel 5400 3650 2    60   Input ~ 0
GP2_4
Text HLabel 5400 3350 2    60   Output ~ 0
SCL
Text HLabel 5400 3500 2    60   BiDi ~ 0
SDA
Text HLabel 5400 2750 2    60   Output ~ 0
PWM1
Text HLabel 5400 2900 2    60   Output ~ 0
PWM2
Text HLabel 5350 4850 2    60   Output ~ 0
Direction1
Text HLabel 5350 5050 2    60   Output ~ 0
Direction2
$Comp
L CONN_01X02 P14
U 1 1 55E91F10
P 4650 4800
F 0 "P14" H 4650 4950 50  0000 C CNN
F 1 "Encoder2" V 4750 4800 50  0000 C CNN
F 2 "Footprints:Conn_01x02" H 4650 4800 60  0001 C CNN
F 3 "" H 4650 4800 60  0000 C CNN
	1    4650 4800
	1    0    0    -1  
$EndComp
Text HLabel 4450 4750 0    60   Input ~ 0
Encoder2A
Text HLabel 4450 4850 0    60   Input ~ 0
Encoder2B
$Comp
L R R28
U 1 1 55E8D619
P 7150 4650
F 0 "R28" V 7230 4650 50  0000 C CNN
F 1 "82Ω" V 7150 4650 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 7080 4650 30  0001 C CNN
F 3 "" H 7150 4650 30  0000 C CNN
	1    7150 4650
	1    0    0    -1  
$EndComp
$Comp
L LED D1
U 1 1 55E8D8ED
P 7150 5000
F 0 "D1" H 7150 5100 50  0000 C CNN
F 1 "LED_Green" H 7150 4900 50  0000 C CNN
F 2 "Footprints:LED_Green_CMS" H 7150 5000 60  0001 C CNN
F 3 "" H 7150 5000 60  0000 C CNN
	1    7150 5000
	0    -1   -1   0   
$EndComp
$Comp
L R R29
U 1 1 55E8D9E6
P 7450 4650
F 0 "R29" V 7530 4650 50  0000 C CNN
F 1 "82Ω" V 7450 4650 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 7380 4650 30  0001 C CNN
F 3 "" H 7450 4650 30  0000 C CNN
	1    7450 4650
	1    0    0    -1  
$EndComp
$Comp
L R R30
U 1 1 55E8DA60
P 7750 4650
F 0 "R30" V 7830 4650 50  0000 C CNN
F 1 "82Ω" V 7750 4650 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 7680 4650 30  0001 C CNN
F 3 "" H 7750 4650 30  0000 C CNN
	1    7750 4650
	1    0    0    -1  
$EndComp
$Comp
L R R31
U 1 1 55E8DA6C
P 8050 4650
F 0 "R31" V 8130 4650 50  0000 C CNN
F 1 "82Ω" V 8050 4650 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 7980 4650 30  0001 C CNN
F 3 "" H 8050 4650 30  0000 C CNN
	1    8050 4650
	1    0    0    -1  
$EndComp
$Comp
L R R32
U 1 1 55E8DAB8
P 8350 4650
F 0 "R32" V 8430 4650 50  0000 C CNN
F 1 "82Ω" V 8350 4650 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 8280 4650 30  0001 C CNN
F 3 "" H 8350 4650 30  0000 C CNN
	1    8350 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 5200 8350 5200
Connection ~ 7450 5200
Connection ~ 7750 5200
Connection ~ 8050 5200
Wire Wire Line
	7750 5200 7750 5350
Text HLabel 7750 5350 3    60   Input ~ 0
GND
Wire Wire Line
	4400 4250 4400 4450
Wire Wire Line
	4400 4450 7450 4450
Wire Wire Line
	7450 4450 7450 4500
Wire Wire Line
	4400 4100 4350 4100
Wire Wire Line
	4350 4100 4350 4500
Wire Wire Line
	4350 4500 7150 4500
Wire Wire Line
	5400 4250 7750 4250
Wire Wire Line
	7750 4250 7750 4500
Wire Wire Line
	5400 3200 8050 3200
Wire Wire Line
	8050 3200 8050 4500
Wire Wire Line
	5400 3050 8350 3050
Wire Wire Line
	8350 3050 8350 4500
$Comp
L LED D2
U 1 1 55EA48F0
P 7450 5000
F 0 "D2" H 7450 5100 50  0000 C CNN
F 1 "LED_Green" H 7450 4900 50  0000 C CNN
F 2 "Footprints:LED_Green_CMS" H 7450 5000 60  0001 C CNN
F 3 "" H 7450 5000 60  0000 C CNN
	1    7450 5000
	0    -1   -1   0   
$EndComp
$Comp
L LED D3
U 1 1 55EA4934
P 7750 5000
F 0 "D3" H 7750 5100 50  0000 C CNN
F 1 "LED_Green" H 7750 4900 50  0000 C CNN
F 2 "Footprints:LED_Green_CMS" H 7750 5000 60  0001 C CNN
F 3 "" H 7750 5000 60  0000 C CNN
	1    7750 5000
	0    -1   -1   0   
$EndComp
$Comp
L LED D4
U 1 1 55EA493A
P 8050 5000
F 0 "D4" H 8050 5100 50  0000 C CNN
F 1 "LED_Green" H 8050 4900 50  0000 C CNN
F 2 "Footprints:LED_Green_CMS" H 8050 5000 60  0001 C CNN
F 3 "" H 8050 5000 60  0000 C CNN
	1    8050 5000
	0    -1   -1   0   
$EndComp
$Comp
L LED D5
U 1 1 55EA4994
P 8350 5000
F 0 "D5" H 8350 5100 50  0000 C CNN
F 1 "LED_Green" H 8350 4900 50  0000 C CNN
F 2 "Footprints:LED_Green_CMS" H 8350 5000 60  0001 C CNN
F 3 "" H 8350 5000 60  0000 C CNN
	1    8350 5000
	0    -1   -1   0   
$EndComp
$Comp
L CONN_01X03 P15
U 1 1 55F31020
P 5150 4950
F 0 "P15" H 5150 5150 50  0000 C CNN
F 1 "Motor" V 5250 4950 50  0000 C CNN
F 2 "Footprints:Conn_01x03" H 5150 4950 60  0001 C CNN
F 3 "" H 5150 4950 60  0000 C CNN
	1    5150 4950
	-1   0    0    1   
$EndComp
Text HLabel 5350 4950 2    60   Input ~ 0
ThermalFlag
$EndSCHEMATC
