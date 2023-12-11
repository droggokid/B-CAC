#pragma once

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>

using namespace std;

//const char *deviceNode = "/dev/my_device"; // Replace with the actual device node

int openFile(char *deviceNode)
{
    // Step 4: Open the Device Node
    int fileDescriptor = open(deviceNode, O_RDWR); //fuck WRONLY
    if (fileDescriptor < 0)
    {
        perror("Error opening device node");
    }

    return fileDescriptor;
};

int writeFile(int fileDescriptor, const char* data)
{
    // Step 5: Write Data to the Device Node
    const char *dataWrite = data;
    // ssize_t bytesWritten = write(fileDescriptor, dataWrite, 22);
    ssize_t bytesWritten = write(fileDescriptor, dataWrite, 8);
    if (bytesWritten < 0)
    {
        perror("Error writing to device node");
        close(fileDescriptor); // Close the device node before exiting
        return 1;
    }

    std::cout << "Data written to device: " << dataWrite << std::endl;

    return bytesWritten;
};

int readFile(int fileDescriptor, string& receivedDataBuffer, int messageLength = 8)
{
    // Step 8: Read Data from the Device Node
    
    char* buffer = new char[messageLength]; // Dynamic buffer
    
    ssize_t bytesRead = read(fileDescriptor, buffer, messageLength);
    if (bytesRead < 0)
    {
        perror("Error reading from device node");
        close(fileDescriptor);
        delete[] buffer; // Delete the buffer before returning
        return 1;
    }

    // Null-terminate the buffer to treat it as a string
    buffer[bytesRead] = '\0';

    cout << "Data read from device: " << buffer << endl;

    receivedDataBuffer = buffer;

    delete[] buffer; // Delete the buffer after using it

    return bytesRead;
};

int closeFile(int fileDescriptor)
{
    close(fileDescriptor);

    return 1;
};