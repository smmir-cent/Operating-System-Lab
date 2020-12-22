ifneq ($(KERNELRELEASE),)
  # call from kernel build system
  obj-m   := lab2.o
else
  KERNELDIR ?= /lib/modules/$(shell uname -r)/build
  PWD       := $(shell pwd)
modules:
  echo $(MAKE) -C $(KERNELDIR) M=$(PWD) LDDINC=$(PWD)/../include modules
  $(MAKE) -C $(KERNELDIR) M=$(PWD) LDDINC=$(PWD)/../include modules
endif