#include "rwFile.hpp"
#include "server.hpp"

int fileDescriptor;
Server server;

int main()
{
    string readData;
    bool okRecieved = false;

    char* platformOnePath = "/dev/spi_drv0";
    char* platformTwoPath = "/dev/spi_drv1";

    //fileDescriptor = openFile("test.txt");
    fileDescriptor = openFile(platformTwoPath);
    writeFile(fileDescriptor, "0xAA");
    writeFile(fileDescriptor, "0xAA");
    while(!okRecieved){
        readFile(fileDescriptor, readData);
        if(readData == "0x99" || readData == "0x55")
        {
            okRecieved = true;
            cout << "Recieved ok!" << endl;
        }
    }
    writeFile(fileDescriptor, "0xBB");
    writeFile(fileDescriptor, "0xCC");

    readFile(fileDescriptor, readData);

    cout << "read: " << readData << endl;
    closeFile(fileDescriptor);

    server.start();
}
