#include "servo.hpp"

#include "feetech.h"
#include "shell.h"
#include "shell_commands.h"
#include "uart_stdio.h"

#include <stdio.h>
#include <string.h>

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))

typedef struct {
    const char *name;
    int addr;
} reg_name_addr_t;

static const reg_name_addr_t regs8[] = {
    { "ID", SCS15_ID },
    { "BAUD_RATE", SCS15_BAUD_RATE },
    { "RETURN_DELAY_TIME", SCS15_RETURN_DELAY_TIME },
    { "RETURN_LEVEL", SCS15_RETURN_LEVEL },
    { "LIMIT_TEMPERATURE", SCS15_LIMIT_TEMPERATURE },
    { "MAX_LIMIT_VOLTAGE", SCS15_MAX_LIMIT_VOLTAGE },
    { "MIN_LIMIT_VOLTAGE", SCS15_MIN_LIMIT_VOLTAGE },
    { "ALARM_LED", SCS15_ALARM_LED },
    { "ALARM_SHUTDOWN", SCS15_ALARM_SHUTDOWN },
    { "COMPLIANCE_P", SCS15_COMPLIANCE_P },
    { "COMPLIANCE_D", SCS15_COMPLIANCE_D },
    { "COMPLIANCE_I", SCS15_COMPLIANCE_I },
    { "CW_DEAD", SCS15_CW_DEAD },
    { "CCW_DEAD", SCS15_CCW_DEAD },
    { "TORQUE_ENABLE", SCS15_TORQUE_ENABLE },
    { "LED", SCS15_LED },
    { "LOCK", SCS15_LOCK },
    { "PRESENT_VOLTAGE", SCS15_PRESENT_VOLTAGE },
    { "PRESENT_TEMPERATURE", SCS15_PRESENT_TEMPERATURE },
    { "REGISTERED_INSTRUCTION", SCS15_REGISTERED_INSTRUCTION },
    { "ERROR", SCS15_ERROR },
    { "MOVING", SCS15_MOVING },
};

static const reg_name_addr_t regs16[] = {
    { "MODEL_NUMBER", SCS15_MODEL_NUMBER },
    { "VERSION", SCS15_VERSION },
    { "MIN_ANGLE_LIMIT", SCS15_MIN_ANGLE_LIMIT },
    { "MAX_ANGLE_LIMIT", SCS15_MAX_ANGLE_LIMIT },
    { "MAX_TORQUE", SCS15_MAX_TORQUE },
    { "PUNCH", SCS15_PUNCH },
    { "IMAX", SCS15_IMAX },
    { "OFFSET", SCS15_OFFSET },
    { "GOAL_POSITION", SCS15_GOAL_POSITION },
    { "GOAL_TIME", SCS15_GOAL_TIME },
    { "GOAL_SPEED", SCS15_GOAL_SPEED },
    { "PRESENT_POSITION", SCS15_PRESENT_POSITION },
    { "PRESENT_SPEED", SCS15_PRESENT_SPEED },
    { "PRESENT_LOAD", SCS15_PRESENT_LOAD },
    { "VIR_POSITION", SCS15_VIR_POSITION },
    { "CURRENT", SCS15_CURRENT },
};

static const int32_t baudrates[] = {
    1000000L,
    500000L,
    250000L,
    128000L,
    115200L,
    76800L,
    57600L,
    38400L,
};

static int parse_dev(char *arg)
{
    int dev = atoi(arg);
    if (dev < 0 || 254 < dev) {
        printf("Error: Invalid device id (%s)\n", arg);
        return -1;
    }
    return dev;
}

static void parse_reg(char *arg, int *reg8, int *reg16)
{
    *reg8 = -1;
    *reg16 = -1;

    for (size_t i = 0 ; i < ARRAY_LEN(regs8) ; i++) {
        if (strcmp(arg, regs8[i].name) == 0) {
            *reg8 = regs8[i].addr;
            return;
        }
    }

    for (size_t i = 0 ; i < ARRAY_LEN(regs16) ; i++) {
        if (strcmp(arg, regs16[i].name) == 0) {
            *reg16 = regs16[i].addr;
            return;
        }
    }

    printf("Error: Invalid register (%s)\n", arg);
}

void print_registers(void) {
    puts("available 8bits registers :");
    for (size_t i = 0 ; i < ARRAY_LEN(regs8) ; i++) {
        printf("\t%s\n", regs8[i].name);
    }

    puts("available 16bits registers :");
    for (size_t i = 0 ; i < ARRAY_LEN(regs16) ; i++) {
        printf("\t%s\n", regs16[i].name);
    }
}

static int cmd_ping(int argc, char **argv) {
    int id = -1;

    if (argc != 2) {
        printf("usage; %s <dev_id>\n", argv[0]);
        return 1;
    }
    /* parse parameters */
    id = parse_dev(argv[1]);
    if (id < 0) {
        return -1;
    }

    /* ping */
    if (feetech_ping(&ServoBus::instance().stream(), id) == FEETECH_OK) {
        printf("Device %i responded\n", id);
    }
    else {
        printf("No response from %i\n", id);
    }
    return 0;
}

static int cmd_scan(int argc, char **argv) {
    int min = -1;
    int max = -1;

    if (argc == 3) {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
        if (min < 0) {
            return -1;
        }
        if (max > 254) {
            return -1;
        }
        if (max < min) {
            return -1;
        }
    }
    else if (argc == 1) {
        min = 0;
        max = 254;
    }
    else {
        printf("usage; %s [<min_id> <max_id>]\n", argv[0]);
        return 1;
    }

    /* ping */
    puts("Scanning...");
    for (int id = min ; id < max ; id++) {
        if (feetech_ping(&ServoBus::instance().stream(), id) == FEETECH_OK) {
            printf("Device %i available\n", id);
        }
    }
    puts("End");
    return 0;
}

static int cmd_read(int argc, char **argv) {
    int id = -1;
    int reg8 = -1;
    int reg16 = -1;

    if (argc != 3) {
        printf("usage; %s <dev_id> <reg>\n", argv[0]);
        print_registers();
        return 1;
    }
    /* parse parameters */
    id = parse_dev(argv[1]);
    if (id < 0) {
        return -1;
    }

    parse_reg(argv[2], &reg8, &reg16);
    if (reg8 < 0 && reg16 < 0) {
        return -1;
    }

    /* read */
    feetech_t dev;
    feetech_init(&dev, &ServoBus::instance().stream(), id);
    if (reg8 >= 0) {
        uint8_t val = 0;
        int ret = feetech_read8(&dev, reg8, &val);
        if (ret != FEETECH_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("%i\n", (int)val);
    }
    else {
        uint16_t val = 0;
        int ret = feetech_read16(&dev, reg16, &val);
        if (ret != FEETECH_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("%i\n", (int)val);
    }
    return 0;
}

static int cmd_write(int argc, char **argv) {
    int id = -1;
    int reg8 = -1;
    int reg16 = -1;

    if (argc != 4) {
        printf("usage; %s <dev_id> <reg> <value>\n", argv[0]);
        print_registers();
        return 1;
    }
    /* parse parameters */
    id = parse_dev(argv[1]);
    if (id < 0) {
        return -1;
    }

    parse_reg(argv[2], &reg8, &reg16);
    if (reg8 < 0 && reg16 < 0) {
        return -1;
    }

    int val = atoi(argv[3]);
    if (val < 0) {
        return -1;
    }

    /* read */
    feetech_t dev;
    feetech_init(&dev, &ServoBus::instance().stream(), id);
    if (reg8 >= 0) {
        int ret = feetech_write8(&dev, reg8, val);
        if (ret != FEETECH_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("Written %i at address %i\n", (int)val, reg8);
    }
    else {
        int ret = feetech_write16(&dev, reg16, val);
        if (ret != FEETECH_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("Written %i at address %i\n", (int)val, reg16);
    }
    return 0;
}

int cmd_servo(int argc, char **argv) {
  if(argc < 2) {
    return -1;
  }

  if(strcmp("ping", argv[1]) == 0) {
    return cmd_ping(argc-1, &argv[1]);
  }

  if(strcmp("scan", argv[1]) == 0) {
    return cmd_scan(argc-1, &argv[1]);
  }

  if(strcmp("write", argv[1]) == 0) {
    return cmd_write(argc-1, &argv[1]);
  }

  if(strcmp("read", argv[1]) == 0) {
    return cmd_read(argc-1, &argv[1]);
  }

  return -1;
}
