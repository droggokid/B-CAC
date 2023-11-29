#include "rwFile.hpp"
#include "server.hpp"

int fileDescriptor;
Server server;

int main()
{
    string readData;

    fileDescriptor = openFile("/home/root/testRead.txt");
    writeFile(fileDescriptor, "din tekst fil er grim");
    readFile(fileDescriptor, readData);

    cout << "read: " << readData << endl;
    closeFile(fileDescriptor);

    server.start();
}
