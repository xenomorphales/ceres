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
Sheet 8 17
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
L CONN_01X04 P7
U 1 1 55E71CE3
P 5850 4300
AR Path="/55E78073/55E71CE3" Ref="P7"  Part="1" 
AR Path="/55E78AE8/55E71CE3" Ref="P8"  Part="1" 
F 0 "P8" H 5850 4550 50  0000 C CNN
F 1 "Encoder" V 5950 4300 50  0000 C CNN
F 2 "" H 5850 4300 60  0000 C CNN
F 3 "" H 5850 4300 60  0000 C CNN
	1    5850 4300
	0    1    1    0   
$EndComp
$Comp
L C C9
U 1 1 55E71CEC
P 6800 3950
AR Path="/55E78073/55E71CEC" Ref="C9"  Part="1" 
AR Path="/55E78AE8/55E71CEC" Ref="C10"  Part="1" 
F 0 "C10" H 6825 4050 50  0000 L CNN
F 1 "100nF" H 6825 3850 50  0000 L CNN
F 2 "" H 6838 3800 30  0000 C CNN
F 3 "" H 6800 3950 60  0000 C CNN
	1    6800 3950
	1    0    0    -1  
$EndComp
Text HLabel 6800 4300 3    60   Input ~ 0
+5V
Text HLabel 6800 3000 1    60   Input ~ 0
GND
Text HLabel 5900 3000 1    60   Output ~ 0
A
Text HLabel 5600 3000 1    60   Output ~ 0
B
$Comp
L R R10
U 1 1 5602AF11
P 5600 3200
AR Path="/55E78073/5602AF11" Ref="R10"  Part="1" 
AR Path="/55E78AE8/5602AF11" Ref="R14"  Part="1" 
F 0 "R14" V 5680 3200 50  0000 C CNN
F 1 "22Ω" V 5600 3200 50  0000 C CNN
F 2 "" V 5530 3200 30  0000 C CNN
F 3 "" H 5600 3200 30  0000 C CNN
	1    5600 3200
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5602AF44
P 5900 3200
AR Path="/55E78073/5602AF44" Ref="R11"  Part="1" 
AR Path="/55E78AE8/5602AF44" Ref="R15"  Part="1" 
F 0 "R15" V 5980 3200 50  0000 C CNN
F 1 "22Ω" V 5900 3200 50  0000 C CNN
F 2 "" V 5830 3200 30  0000 C CNN
F 3 "" H 5900 3200 30  0000 C CNN
	1    5900 3200
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 5602B19C
P 6350 3650
AR Path="/55E78073/5602B19C" Ref="R13"  Part="1" 
AR Path="/55E78AE8/5602B19C" Ref="R17"  Part="1" 
F 0 "R17" V 6430 3650 50  0000 C CNN
F 1 "10kΩ" V 6350 3650 50  0000 C CNN
F 2 "" V 6280 3650 30  0000 C CNN
F 3 "" H 6350 3650 30  0000 C CNN
	1    6350 3650
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 5602B1C5
P 6350 3450
AR Path="/55E78073/5602B1C5" Ref="R12"  Part="1" 
AR Path="/55E78AE8/5602B1C5" Ref="R16"  Part="1" 
F 0 "R16" V 6430 3450 50  0000 C CNN
F 1 "10kΩ" V 6350 3450 50  0000 C CNN
F 2 "" V 6280 3450 30  0000 C CNN
F 3 "" H 6350 3450 30  0000 C CNN
	1    6350 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 4100 6800 4100
Wire Wire Line
	5900 4100 5900 3800
Wire Wire Line
	5900 3800 6800 3800
Wire Wire Line
	5800 3350 5800 4100
Wire Wire Line
	5700 3350 5700 4100
Wire Wire Line
	6800 3800 6800 3000
Wire Wire Line
	6500 3650 6800 3650
Connection ~ 6800 3650
Wire Wire Line
	6500 3450 6800 3450
Connection ~ 6800 3450
Wire Wire Line
	5800 3650 6200 3650
Wire Wire Line
	5700 3450 6200 3450
Wire Wire Line
	5800 3350 5900 3350
Connection ~ 5800 3650
Wire Wire Line
	5700 3350 5600 3350
Connection ~ 5700 3450
Wire Wire Line
	5900 3050 5900 3000
Wire Wire Line
	5600 3050 5600 3000
Wire Wire Line
	6800 4100 6800 4300
$EndSCHEMATC
