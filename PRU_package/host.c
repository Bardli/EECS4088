#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "prussdrv.h"
#include "pruss_intc_mapping.h"

#define PRU_NUM 1			// define which pru is used
#define SHM_OFFSET 2048		// http://www.embedded-things.com/bbb/understanding-bbb-pru-shared-memory-access/

int pru_init(void)
{
	tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
	prussdrv_init();
	if (prussdrv_open(PRU_EVTOUT_0))
	{
		return -1;
	}
	else
	{
		prussdrv_pruintc_init(&pruss_intc_initdata);
		return 0;
	}
}

void pru_load(int pru_num, char* datafile, char* codefile)
{
	// load datafile in PRU memory
	prussdrv_load_datafile(pru_num, datafile);
	// load and execute codefile in PRU
	prussdrv_exec_program(pru_num, codefile);
}

void pru_stop(int pru_num)
{
	prussdrv_pru_disable(pru_num);
	prussdrv_exit();
}

volatile int32_t* init_prumem()
{
	volatile int32_t* p;
	prussdrv_map_prumem(PRUSS0_SHARED_DATARAM, (void**)&p);
	return p+SHM_OFFSET;
}

int main(void)
{
	// initialize the PRU
	printf("pruss driver init (%i)\n", pru_init());

	// load the PRU code (consisting of both code and data bin file).
	pru_load(PRU_NUM, "pru_data.bin", "pru_code.bin");

	// get the memory pointer to the shared data segment
	volatile unsigned int* pruDataMem = init_prumem();

	printf("sending CAFEBABE to PRU\n");

	// write to shared data memory 
	pruDataMem[0]=0xCAFEBABE;

	sleep(1);

	// read from shared data memory
	printf("PRU replies: %X\n", pruDataMem[1]);

	pru_stop(PRU_NUM);

	return 0;
}