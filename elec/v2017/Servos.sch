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
Sheet 18 21
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
L CONN_01X03 P16
U 1 1 5908AA39
P 5200 4200
AR Path="/59087A92/5908AA39" Ref="P16"  Part="1" 
AR Path="/5908C624/5908AA39" Ref="P17"  Part="1" 
AR Path="/5908C923/5908AA39" Ref="P18"  Part="1" 
AR Path="/5908C928/5908AA39" Ref="P19"  Part="1" 
F 0 "P19" H 5200 4000 50  0000 C CNN
F 1 "Servo" V 5300 4200 50  0000 C CNN
F 2 "" H 5200 4200 50  0001 C CNN
F 3 "male 5264 3P" H 5200 4450 50  0000 C CNN
	1    5200 4200
	-1   0    0    1   
$EndComp
Text HLabel 5400 3800 1    60   Input ~ 0
+7.4V
Text HLabel 5700 3800 1    60   Input ~ 0
GND
Text HLabel 6000 3800 1    60   BiDi ~ 0
S
$Comp
L C C15
U 1 1 5908802E
P 5550 3950
AR Path="/59087A92/5908802E" Ref="C15"  Part="1" 
AR Path="/5908C624/5908802E" Ref="C16"  Part="1" 
AR Path="/5908C923/5908802E" Ref="C17"  Part="1" 
AR Path="/5908C928/5908802E" Ref="C18"  Part="1" 
F 0 "C18" H 5650 4050 50  0000 C CNN
F 1 "10µF" H 5650 3850 50  0000 C CNN
F 2 "" H 5588 3800 50  0001 C CNN
F 3 "" H 5550 3950 50  0001 C CNN
	1    5550 3950
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 4300 6000 4300
Wire Wire Line
	5700 4200 5400 4200
Connection ~ 5400 3950
Connection ~ 5700 3950
Wire Wire Line
	5400 3800 5400 4100
Wire Wire Line
	5700 3800 5700 4200
Wire Wire Line
	6000 4300 6000 3800
$EndSCHEMATC
