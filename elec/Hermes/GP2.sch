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
LIBS:Hermes-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 17
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
L CONN_01X03 P1
U 1 1 55E7C054
P 4900 3750
AR Path="/55E75835/55E7C054" Ref="P1"  Part="1" 
AR Path="/55E760A5/55E7C054" Ref="P2"  Part="1" 
AR Path="/55E7647A/55E7C054" Ref="P3"  Part="1" 
AR Path="/55E7647F/55E7C054" Ref="P4"  Part="1" 
F 0 "P4" H 4900 3950 50  0000 C CNN
F 1 "GP2" V 5000 3750 50  0000 C CNN
F 2 "Footprints:Conn_01x03" H 4900 3750 60  0001 C CNN
F 3 "" H 4900 3750 60  0000 C CNN
	1    4900 3750
	-1   0    0    1   
$EndComp
$Comp
L C C1
U 1 1 55E7C068
P 5250 3450
AR Path="/55E75835/55E7C068" Ref="C1"  Part="1" 
AR Path="/55E760A5/55E7C068" Ref="C3"  Part="1" 
AR Path="/55E7647A/55E7C068" Ref="C5"  Part="1" 
AR Path="/55E7647F/55E7C068" Ref="C7"  Part="1" 
F 0 "C7" H 5275 3550 50  0000 L CNN
F 1 "10µF" H 5275 3350 50  0000 L CNN
F 2 "Footprints:C_CMS1210" H 5288 3300 30  0001 C CNN
F 3 "" H 5250 3450 60  0000 C CNN
	1    5250 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 3300 5100 3650
Wire Wire Line
	5400 3750 5100 3750
Wire Wire Line
	5400 3300 5400 3750
Text HLabel 5100 3300 1    60   Input ~ 0
+5V
Text HLabel 5400 3300 1    60   Input ~ 0
GND
Connection ~ 5100 3450
Connection ~ 5400 3450
Wire Wire Line
	5100 3850 5550 3850
Text HLabel 5950 4050 3    60   Output ~ 0
Signal
$Comp
L R R2
U 1 1 55E88E74
P 5700 3850
AR Path="/55E75835/55E88E74" Ref="R2"  Part="1" 
AR Path="/55E760A5/55E88E74" Ref="R4"  Part="1" 
AR Path="/55E7647A/55E88E74" Ref="R6"  Part="1" 
AR Path="/55E7647F/55E88E74" Ref="R8"  Part="1" 
F 0 "R8" V 5780 3850 50  0000 C CNN
F 1 "10kΩ" V 5700 3850 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5630 3850 30  0001 C CNN
F 3 "" H 5700 3850 30  0000 C CNN
	1    5700 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	5850 3850 6050 3850
Connection ~ 5950 3850
$Comp
L R R3
U 1 1 55E88FA1
P 6200 3850
AR Path="/55E75835/55E88FA1" Ref="R3"  Part="1" 
AR Path="/55E760A5/55E88FA1" Ref="R5"  Part="1" 
AR Path="/55E7647A/55E88FA1" Ref="R7"  Part="1" 
AR Path="/55E7647F/55E88FA1" Ref="R9"  Part="1" 
F 0 "R9" V 6280 3850 50  0000 C CNN
F 1 "20kΩ" V 6200 3850 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 6130 3850 30  0001 C CNN
F 3 "" H 6200 3850 30  0000 C CNN
	1    6200 3850
	0    1    1    0   
$EndComp
Wire Wire Line
	5950 3800 5950 4050
Wire Wire Line
	6350 3850 6350 3450
Wire Wire Line
	6350 3450 5400 3450
$Comp
L C C2
U 1 1 5602AA98
P 5950 3650
AR Path="/55E75835/5602AA98" Ref="C2"  Part="1" 
AR Path="/55E760A5/5602AA98" Ref="C4"  Part="1" 
AR Path="/55E7647A/5602AA98" Ref="C6"  Part="1" 
AR Path="/55E7647F/5602AA98" Ref="C8"  Part="1" 
F 0 "C8" H 5975 3750 50  0000 L CNN
F 1 "100nF" H 5975 3550 50  0000 L CNN
F 2 "Footprints:C_CMS0603" H 5988 3500 30  0001 C CNN
F 3 "" H 5950 3650 60  0000 C CNN
	1    5950 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 3500 5950 3450
Connection ~ 5950 3450
$EndSCHEMATC
