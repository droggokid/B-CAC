#include "rwFile.hpp"
#include "server.hpp"

Server server;

int main()
{
    //char *readData;
    string readData;
    //uint8_t readData;
    bool okRecieved = false;

    // char* platformOnePath = "/dev/spi_drv0";    
    // char* GR = "/dev/spi_drv1";
    // char* minutes = "/dev/spi_drv2";
    // char* sekunder = "/dev/spi_drv3";
    

    //UC 1-4 er syncronous -- vent på OK
    //UC1 = 0xA
    //UC2 = 0xB 
    //læs værdien af "gameReady"
    //UC3 = 
    // fileDescriptor = openFile(platformOnePath);

    // readData='0';
    // //readData = 0;
    // okRecieved = false;

    // writeFile(fileDescriptor, "0xBB");
    // while(!okRecieved)
    // {
    //     readFile(fileDescriptor, readData);
    //         if(readData == "11" || readData == "0xB")
    //         //if (readData == 41)
    //         {
    //             okRecieved = true;
    //             cout << "GAME READY \n" << readData << endl;
    //         }
    //         // else
    //         // {
    //         //     cout << readData << " is not = 41\n\n";
    //         // }
    // }

    // readData="0";
    // //readData=0;
    // okRecieved = false;

    // writeFile(fileDescriptor, "0x5");
    // writeFile(fileDescriptor, "0x5");
    // while(!okRecieved){
    // readFile(fileDescriptor, readData);
    //     if(readData != "0")
    //     //if (readData != 0)
    //     {
    //         okRecieved = true;
    //         cout << "Recieved data: " << readData << endl;
    //     }
    // }
    
    // //readFile(fileDescriptor, readData);

    // //cout << "read: " << readData << endl;
    // closeFile(fileDescriptor);


    //flush buffer:
    
    server.start();
}
