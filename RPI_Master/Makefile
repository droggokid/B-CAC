CC = arm-rpizw-gcc
CFLAGS = -Wall

TARGET = RPI_Master

$(TARGET): RPI_Master.c
	$(CC) $(CFLAGS) -o $(TARGET) RPI_Master.c

clean:
	rm -f $(TARGET)


modules_install: modules
	scp $(TARGET) root@10.9.8.2:
