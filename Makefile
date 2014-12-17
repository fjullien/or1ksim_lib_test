CROSS_COMPILE=/opt/or1k-toolchain/bin/or1k-elf-gcc

all:
	${CROSS_COMPILE} -o or1k_main or1k_main.c
	g++ -o testlib main.c libsim.a

clean:
	rm -f or1k_main testlib *.o *.~
