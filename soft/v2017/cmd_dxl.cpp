#include <servo.hpp>

#include "dynamixel.h"
#include "shell.h"
#include "shell_commands.h"
#include "uart_stdio.h"
#include "board.h"
#include "periph/gpio.h"

#include <stdio.h>
#include <string.h>

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))

typedef struct {
    const char *name;
    int addr;
} reg_name_addr_t;

static const reg_name_addr_t regs8[] = {
   { "VERSION", XL320_VERSION },
   { "ID", XL320_ID },
   { "BAUD_RATE", XL320_BAUD_RATE },
   { "RETURN_DELAY_TIME", XL320_RETURN_DELAY_TIME },
   { "CONTROL_MODE", XL320_CONTROL_MODE },
   { "LIMIT_TEMPERATURE", XL320_LIMIT_TEMPERATURE },
   { "LOWER_LIMIT_VOLTAGE", XL320_LOWER_LIMIT_VOLTAGE },
   { "UPPER_LIMIT_VOLTAGE", XL320_UPPER_LIMIT_VOLTAGE },
   { "RETURN_LEVEL", XL320_RETURN_LEVEL },
   { "ALARM_SHUTDOWN", XL320_ALARM_SHUTDOWN },
   { "TORQUE_ENABLE", XL320_TORQUE_ENABLE },
   { "LED", XL320_LED },
   { "D_GAIN", XL320_D_GAIN },
   { "I_GAIN", XL320_I_GAIN },
   { "P_GAIN", XL320_P_GAIN },
   { "PRESENT_VOLTAGE", XL320_PRESENT_VOLTAGE },
   { "PRESENT_TEMPERATURE", XL320_PRESENT_TEMPERATURE },
   { "REGISTERED_INST", XL320_REGISTERED_INST },
   { "MOVING", XL320_MOVING },
   { "ERROR", XL320_ERROR },
};

static const reg_name_addr_t regs16[] = {
   { "MODEL_NUMBER", XL320_MODEL_NUMBER },
   { "CW_ANGLE_LIMIT", XL320_CW_ANGLE_LIMIT },
   { "CCW_ANGLE_LIMIT", XL320_CCW_ANGLE_LIMIT },
   { "MAX_TORQUE", XL320_MAX_TORQUE },
   { "GOAL_POSITION", XL320_GOAL_POSITION },
   { "GOAL_VELOCITY", XL320_GOAL_VELOCITY },
   { "GOAL_TORQUE", XL320_GOAL_TORQUE },
   { "PRESENT_POSITION", XL320_PRESENT_POSITION },
   { "PRESENT_SPEED", XL320_PRESENT_SPEED },
   { "PRESENT_LOAD", XL320_PRESENT_LOAD },
   { "PUNCH", XL320_PUNCH },
};

#ifdef DXL_DIR_PIN
static void dir_init(uart_t uart) {
    gpio_init(DXL_DIR_PIN, GPIO_OUT);
}

static void dir_enable_tx(uart_t uart) {
    gpio_set(DXL_DIR_PIN);
}

static void dir_disable_tx(uart_t uart) {
    gpio_clear(DXL_DIR_PIN);
}
#else
#define dir_init       NULL
#define dir_enable_tx  NULL
#define dir_disable_tx NULL
#endif

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

static void print_registers(void) {
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
    if (dynamixel_ping(&ServoBus::instance().stream(), id) == DYNAMIXEL_OK) {
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
        if (dynamixel_ping(&ServoBus::instance().stream(), id) == DYNAMIXEL_OK) {
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
    dynamixel_t dev;
    dynamixel_init(&dev, &ServoBus::instance().stream(), id);
    if (reg8 >= 0) {
        uint8_t val = 0;
        int ret = dynamixel_read8(&dev, reg8, &val);
        if (ret != DYNAMIXEL_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("%i\n", (int)val);
    }
    else {
        uint16_t val = 0;
        int ret = dynamixel_read16(&dev, reg16, &val);
        if (ret != DYNAMIXEL_OK) {
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
    dynamixel_t dev;
    dynamixel_init(&dev, &ServoBus::instance().stream(), id);
    if (reg8 >= 0) {
        int ret = dynamixel_write8(&dev, reg8, val);
        if (ret != DYNAMIXEL_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("Written %i at address %i\n", (int)val, reg8);
    }
    else {
        int ret = dynamixel_write16(&dev, reg16, val);
        if (ret != DYNAMIXEL_OK) {
            printf("Error[%i] : No response from %i\n", ret, id);
            return -1;
        }
        printf("Written %i at address %i\n", (int)val, reg16);
    }
    return 0;
}

int cmd_dxl(int argc, char **argv) {
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
