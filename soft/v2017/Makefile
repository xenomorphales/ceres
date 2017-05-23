APPLICATION = ceres

RIOTBASE ?= ../../../RIOT

RIOTBOARD ?= boards
BOARD ?= samr21-xpro-ceres

DIRS += robot_drivers

USEMODULE += robot_drivers
USEMODULE += shell shell_commands

CXXEXFLAGS += -std=c++11

include robot_drivers/Makefile.include
include $(RIOTBASE)/Makefile.include
