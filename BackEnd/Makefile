# Makefile for compiling and transferring the code to Raspberry Pi Zero

CXX = arm-rpizw-g++
CXXFLAGS = -I/home/stud/bin/arm-rpizw-g++

# Adjust the following variables based on your Raspberry Pi's IP address and login credentials
RPI_USER = root
RPI_HOST = 10.9.8.2# Replace with your Raspberry Pi's IP address
RPI_PATH =

# The name of the executable file
EXECUTABLE = backend

# Source files
SRCS = server.cpp

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(EXECUTABLE)

.PHONY: transfer
transfer: $(EXECUTABLE)
	scp $(EXECUTABLE) $(RPI_USER)@$(RPI_HOST):$(RPI_PATH)

.PHONY: run_on_pi
run_on_pi: transfer
	ssh $(RPI_USER)@$(RPI_HOST) 'cd $(RPI_PATH) && ./$(EXECUTABLE)'
