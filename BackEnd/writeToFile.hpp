#include <iostream>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

//const char *deviceNode = "/dev/my_device"; // Replace with the actual device node

int openFile(char *deviceNode)
{
    // Step 4: Open the Device Node
    int fileDescriptor = open(deviceNode, O_WRONLY);
    if (fileDescriptor < 0)
    {
        perror("Error opening device node");
    }

    return fileDescriptor;
}

int writeFile(int fileDescriptor, const char* data)
{
    // Step 5: Write Data to the Device Node
    const char *dataWrite = data;
    ssize_t bytesWritten = write(fileDescriptor, dataWrite, strlen(dataWrite));
    if (bytesWritten < 0)
    {
        perror("Error writing to device node");
        close(fileDescriptor); // Close the device node before exiting
        return 1;
    }

    std::cout << "Data written to device: " << dataWrite << std::endl;

    // Step 6: Close the Device Node
    close(fileDescriptor);

    return bytesWritten;
}

int readFile(int fileDescriptor, string& recievedDataBuffer)
{
    // Step 8: Read Data from the Device Node
    char buffer[100]; // Adjust the buffer size based on your needs
    ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer));
    if (bytesRead < 0)
    {
        perror("Error reading from device node");
        close(fileDescriptor);
        return 1;
    }

    // Null-terminate the buffer to treat it as a string
    buffer[bytesRead] = '\0';

    std::cout << "Data read from device: " << buffer << std::endl;

    recievedDataBuffer = buffer;

    // Step 6: Close the Device Node
    close(fileDescriptor);

    return bytesRead;
};
