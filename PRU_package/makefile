pru_options 		= --silicon_version=2 --hardware_mac=on -i/usr/include/arm-linux-gnueabihf/include -i/usr/include/arm-linux-gnueabihf/lib
pru_compiler 		= /usr/bin/clpru
pru_hex_converter 	= /usr/bin/hexpru

all: exports host

host: pru_data.bin pru_code.bin host.c
	gcc -std=gnu11 host.c -o host -lprussdrv -lrt

#
# Here's the PRU code generation part
#

exports:
	@export PRU_SDK_DIR=/usr
	@export PRU_CGT_DIR=/usr/include/arm-linux-gnueabihf

pru.obj: pru.c
	$(pru_compiler) $(pru_options) --opt_level=off -c pru.c
	
pru.elf: pru.obj 
	$(pru_compiler) $(pru_options) -z pru.obj -llibc.a -m pru.map -o pru.elf AM335x_PRU.cmd --quiet 

pru_code.bin pru_data.bin: bin.cmd pru.elf
	$(pru_hex_converter) bin.cmd ./pru.elf --quiet

clean:
	rm pru.obj
	rm pru.elf
	rm pru.map