    obj-m := mydrive.o
    PWD := $(shell pwd)
    KERNELDIR := /home/songchujun/linux-3.18.96
all:
	make -C $(KERNELDIR) M=$(PWD) modules
 
 
.PHONY: clean
clean:
	rm -rf *.o *~ core *.ko *.mod.c modules.order Module.symvers