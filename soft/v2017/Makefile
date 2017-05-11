APPLICATION = ceres

RIOTBASE ?= ../../../RIOT

RIOTBOARD ?= boards
BOARD ?= samr21-xpro-ceres

FEATURES_REQUIRED += periph_gpio
FEATURES_REQUIRED += periph_pwm
FEATURES_REQUIRED += periph_i2c

USEMODULE += l3g4200d
USEMODULE += feetech
USEMODULE += dynamixel

include $(RIOTBASE)/Makefile.include
