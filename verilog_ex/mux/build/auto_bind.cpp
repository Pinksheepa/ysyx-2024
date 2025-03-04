#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top) {
	nvboard_bind_pin( &top->y, 2, SW0, SW1);
	nvboard_bind_pin( &top->x[0], 2, SW2, SW3);
	nvboard_bind_pin( &top->x[1], 2, SW4, SW5);
	nvboard_bind_pin( &top->x[2], 2, SW6, SW7);
	nvboard_bind_pin( &top->x[3], 2, SW8, SW9);
	nvboard_bind_pin( &top->f, 2, LD0, LD1);
}
