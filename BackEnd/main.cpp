#include "rwFile.hpp"
#include "server.hpp"

int fileDescriptor;
Server server;

int main()
{
    string readData;

    fileDescriptor = openFile("test.txt");
    writeFile(fileDescriptor, "12345678");
    readFile(fileDescriptor, readData);

    cout << "read: " << readData << endl;
    closeFile(fileDescriptor);

    server.start();
}
