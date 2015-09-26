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
Sheet 11 17
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
L LMD18201 U1
U 1 1 55E9663E
P 7100 3700
AR Path="/55E965C3/55E9663E" Ref="U1"  Part="1" 
AR Path="/55E98B0C/55E9663E" Ref="U2"  Part="1" 
F 0 "U2" H 7100 3050 60  0000 C CNN
F 1 "LMD18201" H 7100 4350 60  0000 C CNN
F 2 "Footprints:LMD18201" H 6950 4500 60  0001 C CNN
F 3 "" H 6950 4500 60  0000 C CNN
	1    7100 3700
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P12
U 1 1 55E9668D
P 5600 2600
AR Path="/55E965C3/55E9668D" Ref="P12"  Part="1" 
AR Path="/55E98B0C/55E9668D" Ref="P13"  Part="1" 
F 0 "P13" H 5600 2750 50  0000 C CNN
F 1 "Motor" V 5700 2600 50  0000 C CNN
F 2 "Footprints:Power_Conn_01x02" H 5600 2600 60  0001 C CNN
F 3 "" H 5600 2600 60  0000 C CNN
	1    5600 2600
	0    -1   -1   0   
$EndComp
$Comp
L C C14
U 1 1 55E966DF
P 6300 3150
AR Path="/55E965C3/55E966DF" Ref="C14"  Part="1" 
AR Path="/55E98B0C/55E966DF" Ref="C19"  Part="1" 
F 0 "C19" H 6325 3250 50  0000 L CNN
F 1 "10nF" H 6325 3050 50  0000 L CNN
F 2 "Footprints:C_CMS0603" H 6338 3000 30  0001 C CNN
F 3 "" H 6300 3150 60  0000 C CNN
	1    6300 3150
	1    0    0    -1  
$EndComp
$Comp
L C C15
U 1 1 55E96729
P 6300 4250
AR Path="/55E965C3/55E96729" Ref="C15"  Part="1" 
AR Path="/55E98B0C/55E96729" Ref="C20"  Part="1" 
F 0 "C20" H 6325 4350 50  0000 L CNN
F 1 "10nF" H 6325 4150 50  0000 L CNN
F 2 "Footprints:C_CMS0603" H 6338 4100 30  0001 C CNN
F 3 "" H 6300 4250 60  0000 C CNN
	1    6300 4250
	1    0    0    -1  
$EndComp
Text HLabel 4700 4250 0    60   Input ~ 0
Direction
Text HLabel 4700 4350 0    60   Input ~ 0
PWM
Text HLabel 3850 3600 0    60   Input ~ 0
+15V
Text HLabel 3850 3900 0    60   Input ~ 0
GND
Text HLabel 6600 4000 0    60   Output ~ 0
ThermalFlag
$Comp
L C C11
U 1 1 55E9687D
P 4000 3750
AR Path="/55E965C3/55E9687D" Ref="C11"  Part="1" 
AR Path="/55E98B0C/55E9687D" Ref="C16"  Part="1" 
F 0 "C16" H 4025 3850 50  0000 L CNN
F 1 "100nF" H 4025 3650 50  0000 L CNN
F 2 "Footprints:C_CMS0603" H 4038 3600 30  0001 C CNN
F 3 "" H 4000 3750 60  0000 C CNN
	1    4000 3750
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 55E968B0
P 4300 3750
AR Path="/55E965C3/55E968B0" Ref="C12"  Part="1" 
AR Path="/55E98B0C/55E968B0" Ref="C17"  Part="1" 
F 0 "C17" H 4325 3850 50  0000 L CNN
F 1 "10µF" H 4325 3650 50  0000 L CNN
F 2 "Footprints:C_CMS1210" H 4338 3600 30  0001 C CNN
F 3 "" H 4300 3750 60  0000 C CNN
	1    4300 3750
	1    0    0    -1  
$EndComp
$Comp
L CP1 CP1
U 1 1 55E968DA
P 4650 3750
AR Path="/55E965C3/55E968DA" Ref="CP1"  Part="1" 
AR Path="/55E98B0C/55E968DA" Ref="CP2"  Part="1" 
F 0 "CP2" H 4675 3850 50  0000 L CNN
F 1 "330µF" H 4675 3650 50  0000 L CNN
F 2 "Footprints:C_Radial" H 4650 3750 60  0001 C CNN
F 3 "" H 4650 3750 60  0000 C CNN
	1    4650 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 3200 6600 2900
Wire Wire Line
	6600 2900 6300 2900
Wire Wire Line
	6300 2900 6300 3000
Wire Wire Line
	6600 4200 6600 4500
Wire Wire Line
	6600 4500 6300 4500
Wire Wire Line
	6300 4500 6300 4400
Wire Wire Line
	3850 3900 5350 3900
Connection ~ 4000 3900
Connection ~ 4300 3900
Wire Wire Line
	3850 3600 5350 3600
Connection ~ 4000 3600
Connection ~ 4300 3600
Wire Wire Line
	5350 3900 5350 3800
Wire Wire Line
	5350 3800 6600 3800
Connection ~ 4650 3900
Wire Wire Line
	5350 3600 5350 3700
Wire Wire Line
	5350 3700 6600 3700
Connection ~ 4650 3600
Connection ~ 6300 3300
Wire Wire Line
	5450 4100 6600 4100
Connection ~ 6300 4100
$Comp
L R R24
U 1 1 56038FFA
P 4950 4050
AR Path="/55E965C3/56038FFA" Ref="R24"  Part="1" 
AR Path="/55E98B0C/56038FFA" Ref="R26"  Part="1" 
F 0 "R26" V 5030 4050 50  0000 C CNN
F 1 "10kΩ" V 4950 4050 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 4880 4050 30  0001 C CNN
F 3 "" H 4950 4050 30  0000 C CNN
	1    4950 4050
	1    0    0    -1  
$EndComp
$Comp
L R R25
U 1 1 56039073
P 5150 4050
AR Path="/55E965C3/56039073" Ref="R25"  Part="1" 
AR Path="/55E98B0C/56039073" Ref="R27"  Part="1" 
F 0 "R27" V 5230 4050 50  0000 C CNN
F 1 "10kΩ" V 5150 4050 50  0000 C CNN
F 2 "Footprints:R_CMS1206" V 5080 4050 30  0001 C CNN
F 3 "" H 5150 4050 30  0000 C CNN
	1    5150 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4350 5900 4350
Wire Wire Line
	5900 4350 5900 3600
Wire Wire Line
	5900 3600 6600 3600
Connection ~ 5150 4350
Wire Wire Line
	4700 4250 5800 4250
Wire Wire Line
	5800 4250 5800 3400
Wire Wire Line
	5800 3400 6600 3400
Connection ~ 4950 4250
Connection ~ 4950 3900
Connection ~ 5150 3900
$Comp
L C C13
U 1 1 560392C1
P 5600 3100
AR Path="/55E965C3/560392C1" Ref="C13"  Part="1" 
AR Path="/55E98B0C/560392C1" Ref="C18"  Part="1" 
F 0 "C18" H 5625 3200 50  0000 L CNN
F 1 "1nF" H 5625 3000 50  0000 L CNN
F 2 "Footprints:C_CMS0603" H 5638 2950 30  0001 C CNN
F 3 "" H 5600 3100 60  0000 C CNN
	1    5600 3100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5750 3300 6600 3300
Wire Wire Line
	5750 2800 5750 3300
Wire Wire Line
	5750 2800 5650 2800
Connection ~ 5750 3100
Wire Wire Line
	5450 2800 5450 4100
Wire Wire Line
	5450 2800 5550 2800
Connection ~ 5450 3100
Wire Wire Line
	6500 3900 6600 3900
Wire Wire Line
	6500 3500 6500 3900
Connection ~ 6500 3800
Wire Wire Line
	6600 3500 6500 3500
Wire Wire Line
	4950 4200 4950 4250
Wire Wire Line
	5150 4350 5150 4200
$EndSCHEMATC
