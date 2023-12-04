# Kernel Module
KMODULE := spi_drv
DTB_FILE := $(KMODULE)-overlay.dtb
DTBO_FILE := $(KMODULE).dtbo

# Set the appropriate cross-compiler prefix for Raspberry Pi OS
CCPREFIX = arm-linux-gnueabihf-

# Set the path to the Raspberry Pi kernel source directory
KERNELDIR = /lib/modules/$(shell uname -r)/build

# To build modules outside of the kernel tree, we run "make"
# in the kernel source tree; the Makefile then includes this
# Makefile once again.
# This conditional selects whether we are being included from the
# kernel Makefile or not.
ifeq ($(KERNELRELEASE),)

# The current directory is passed to sub-makes as an argument
PWD := $(shell pwd)

modules:
    $(MAKE) ARCH=arm CROSS_COMPILE=$(CCPREFIX) -C $(KERNELDIR) M=$(PWD)

    # Rename .dtb to .dtbo, required by dtoverlay
    mv $(DTB_FILE) $(DTBO_FILE)

modules_install: modules
    scp *.ko *.dtbo pi@raspberrypi.local:/lib/modules/$(shell uname -r)/kernel/drivers/

clean:
    rm -rf *.o *.dtb *.dtbo *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions modules.order Module.symvers .*.tmp

.PHONY: default clean

else
# called from the kernel build system: just declare what our modules are
ccflags-y := -DDEBUG -g -std=gnu99 -Wno-declaration-after-statement
# Device Tree Blobs to build
always := $(DTB_FILE)
# Kernel Object target file(s)
obj-m += $(KMODULE).o
# If the object must be linked from multiple parts
#xxxxmod-objs := part1.o part2.o

endif