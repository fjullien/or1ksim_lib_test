#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "or1ksim.h"

int generic_read(void *class_ptr, unsigned long int addr, unsigned char mask[], unsigned char rdata[], int data_len)
{
	int i;

	for (i = 0; i < data_len; i++)
		rdata[i] = i;

	printf("Read at 0x%08lX\n", addr);
	
	return 0;
}

int generic_write(void *class_ptr, unsigned long int addr, unsigned char mask[], unsigned char wdata[], int data_len)
{
	int i;

	for (i = 0; i < data_len; i++)
		printf("-- %02X\n", wdata[i]);

	printf("Write at 0x%08lX\n", addr);

	return 0;
}

int main(int argc, char **argv)
{
	int ret;
	
	ret = or1ksim_init(argc, argv, NULL, generic_read, generic_write);
	if (ret) {
		printf("or1ksim_init failed (%d)\n", ret);
		return -1;
	}

	ret = or1ksim_run(1);
	printf("or1ksim_run returned %d\n", ret);

	return 0;
}
