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
Sheet 6 21
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
L CONN_01X04 P5
U 1 1 58FCB696
P 4600 3150
AR Path="/58FCB631/58FCB696" Ref="P5"  Part="1" 
AR Path="/58FCCE91/58FCB696" Ref="P6"  Part="1" 
AR Path="/58FCD707/58FCB696" Ref="P7"  Part="1" 
AR Path="/58FCD70D/58FCB696" Ref="P8"  Part="1" 
F 0 "P8" H 4600 3400 50  0000 C CNN
F 1 "Ultrasonic" V 4700 3150 50  0000 C CNN
F 2 "" H 4600 3150 50  0001 C CNN
F 3 "Sécable" H 4600 3500 50  0000 C CNN
	1    4600 3150
	-1   0    0    1   
$EndComp
Text HLabel 4800 2650 1    60   Input ~ 0
+5V
Text HLabel 5100 2650 1    60   Input ~ 0
GND
$Comp
L C C9
U 1 1 58FCBA16
P 4950 2800
AR Path="/58FCB631/58FCBA16" Ref="C9"  Part="1" 
AR Path="/58FCCE91/58FCBA16" Ref="C10"  Part="1" 
AR Path="/58FCD707/58FCBA16" Ref="C11"  Part="1" 
AR Path="/58FCD70D/58FCBA16" Ref="C12"  Part="1" 
F 0 "C12" H 5050 2900 50  0000 C CNN
F 1 "10µF" H 5050 2700 50  0000 C CNN
F 2 "" H 4988 2650 50  0001 C CNN
F 3 "" H 4950 2800 50  0001 C CNN
	1    4950 2800
	0    1    1    0   
$EndComp
Text HLabel 5400 2650 1    60   Input ~ 0
Trigger
Wire Wire Line
	4800 2650 4800 3000
Connection ~ 4800 2800
Wire Wire Line
	5100 3300 4800 3300
Wire Wire Line
	5100 2650 5100 3300
Connection ~ 5100 2800
Wire Wire Line
	4800 3100 5400 3100
Wire Wire Line
	5400 3100 5400 2650
Text HLabel 5800 3200 2    60   Output ~ 0
Echo
$Comp
L R R9
U 1 1 58FCBD9B
P 5550 3200
AR Path="/58FCB631/58FCBD9B" Ref="R9"  Part="1" 
AR Path="/58FCCE91/58FCBD9B" Ref="R11"  Part="1" 
AR Path="/58FCD707/58FCBD9B" Ref="R13"  Part="1" 
AR Path="/58FCD70D/58FCBD9B" Ref="R15"  Part="1" 
F 0 "R15" V 5450 3200 50  0000 C CNN
F 1 "10kΩ" V 5550 3200 50  0000 C CNN
F 2 "" V 5480 3200 50  0001 C CNN
F 3 "" H 5550 3200 50  0001 C CNN
	1    5550 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4800 3200 5400 3200
$Comp
L R R10
U 1 1 58FCBEB1
P 5750 3000
AR Path="/58FCB631/58FCBEB1" Ref="R10"  Part="1" 
AR Path="/58FCCE91/58FCBEB1" Ref="R12"  Part="1" 
AR Path="/58FCD707/58FCBEB1" Ref="R14"  Part="1" 
AR Path="/58FCD70D/58FCBEB1" Ref="R16"  Part="1" 
F 0 "R16" V 5650 3000 50  0000 C CNN
F 1 "20kΩ" V 5750 3000 50  0000 C CNN
F 2 "" V 5680 3000 50  0001 C CNN
F 3 "" H 5750 3000 50  0001 C CNN
	1    5750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 3200 5800 3200
Wire Wire Line
	5100 2800 5750 2800
Wire Wire Line
	5750 2800 5750 2850
Wire Wire Line
	5750 3200 5750 3150
Connection ~ 5750 3200
$EndSCHEMATC
