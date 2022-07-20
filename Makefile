obj-m += testModule.o

testModule-objs := init.o exit.o
testModule-objs += mainFunction.o timedLogOutput.o

PWD := $(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
