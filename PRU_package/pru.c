#include "pru_cfg.h"

#define PRU_SHARED_MEM_ADDR 0x00012000

int main(void)
{
	// direct pointer to memory address
	volatile int* shared_mem = (volatile int *) PRU_SHARED_MEM_ADDR;

	// enable OCP
	CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

	while(shared_mem[0]!=0xCAFEBABE) {}

	shared_mem[1]=0xDEADBEEF;

	while(1) {}

	__halt();

	return 0;
}