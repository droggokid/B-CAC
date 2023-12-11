#pragma once

#include <iostream>
#include <string>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio.hpp>
#include "json/single_include/nlohmann/json.hpp"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;
using json = nlohmann::json;
using namespace std;

char* platformOnePath = "/dev/spi_drv0";
char* GR1 = "/dev/spi_drv1";
char* minutes1 = "/dev/spi_drv2";
char* sekunder1 = "/dev/spi_drv3";
char* milisekunder1 = "/dev/spi_drv4";
char* dnf1 = "/dev/spi_drv5";

char* platformTwoPath = "/dev/spi_drv6";
char* GR2 = "/dev/spi_drv7";
char* minutes2 = "/dev/spi_drv8";
char* sekunder2 = "/dev/spi_drv9";
char* milisekunder2 = "/dev/spi_drv10";
char* dnf2 = "/dev/spi_drv11";

//string readData;
bool sentBB = false;
bool sentCC = false;

//opret player struct/class med time og initials (evt drink type)
struct Player
{
    string initials;
    string time;
};


int fileDescriptor;
bool okRecieved = false;
                                                        /*
                                                        DET SOM ER GALT:

                                                        DER KAN IKKE SAMMENLIGNES READ DATA MED 

                                                        NORMALE INTEGERS / STRINGS

                                                        fixet med mortens naive string search ;))
                                                        */
class Server
{
public:

    bool search(string& pat, string txt)
    {
        int M = pat.size();
        int N = txt.size();
 
        /* A loop to slide pat[] one by one */
        for (int i = 0; i <= N - M; i++) 
        {
            int j;
 
        /* For current index i, check for pattern match */
            for (j = 0; j < M; j++)
                if (txt[i + j] != pat[j])
                    break;
 
            if (j== M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
                return true;
                //cout << "Pattern found at index " << i << endl;
        }
        return false;
    }
    Server() {}

    int start()
    {
        Player players_[2] = {{"", ""}, {"", ""}};
        cout << "Started server" << endl;

        try
        {
            net::io_context ioc;
            tcp::acceptor acceptor(ioc, {tcp::v4(), 8080});

            while (true)
            {
                tcp::socket socket(ioc);
                acceptor.accept(socket);

                beast::flat_buffer buffer;
                http::request<http::string_body> request;

                http::read(socket, buffer, request);
                // Handle the received request here
                http::response<http::string_body> response{http::status::ok, request.version()};
                response.set(http::field::server, "C++ Server");
                response.set(http::field::content_type, "application/json");
                response.set(http::field::access_control_allow_origin, "*");
                response.set(http::field::access_control_allow_methods, "GET, POST, OPTIONS");
                response.set(http::field::access_control_allow_headers, "Content-Type, Authorization");
                response.set(http::field::access_control_expose_headers, "Authorization");
                response.set(http::field::access_control_max_age, "3600");

                if (request.method() == http::verb::options)
                {
                    response.set(http::field::allow, "GET, POST, OPTIONS");
                    http::write(socket, response);
                    continue;
                }
                else if (request.method() == http::verb::post)
                {
                    std::string body = request.body();
                    cout << "Received POST body: " << body << endl;

                    json bodyJson = json::parse(body);
                    string cmd = bodyJson["cmd"];
                    json data = bodyJson["data"];

                    if (cmd == "tare")
                    {
                        cout << "Received POST tare:" << endl << data << endl;
                        fileDescriptor = openFile(platformOnePath);
                        string readData;
                        okRecieved = false;
                        writeFile(fileDescriptor, "0xAA");
                        string searchedString = "10";
                        while (!okRecieved)
                        {
                            readFile(fileDescriptor, readData);
                            //if (readData != "10"/*readData == "10" || readData == "0xA" || stoi(readData) == 10*/) // HVAD ER DER GALT MED DEN STRING
                            if (search(searchedString, readData))
                            {
                                okRecieved = true;
                                cout << "TARE REQUEST DONE" << readData << endl;
                            }
                        }
                        closeFile(fileDescriptor);
                    }
                    else if (cmd == "startGame")
                    {
                        cout << "Received POST startGame:" << endl << data << endl;
                        // gem player initials type
                        //parse the recieved JSON object and extract initials into players_
                        //nlohmann::json p1Initials = data["p1"];
                        //nlohmann::json p2Initials = data["p2"];
                        //players_[0].initials = json.dump(p1Initials); //det er ikk så vigtigt,
                        //players_[1].initials = json.dump(p2Initials); //de bliver vist oss gemt på client
                        string readData;
                        fileDescriptor = openFile(platformOnePath);
                        if (!sentCC)
                        {
                            writeFile(fileDescriptor, "0xCC");
                            sentCC = true;
                        }
                        // readFile(fileDescriptor, readData);
                        // string searchedString = "12";
                        // if (search(searchedString, readData))
                        // {
                        //     okRecieved = true;
                        //     cout << "GAME READY TO START " << readData << endl;
                        //     response.body() = "true";
                        // }
                        // else
                        //     response.body() = "false";

                        //start game kører kun 1 gang, bagefter getter den gameRunning

                        closeFile(fileDescriptor);
                    }
                    else 
                    {
                        cout << "Target not specified" << endl;
                    }
                }
                else if (request.method() == http::verb::get)
                {
                    boost::beast::string_view target = request.target();

                    cout << "Received GET target: " << target << endl;

                    if (target == "/tareReady")
                    {
                        cout << "Received GET tareReady" << endl;


                        //while (!okRecieved)
                        //{
                        string readData;
                        fileDescriptor = openFile(platformOnePath);
                        if (!sentBB)
                        {
                            writeFile(fileDescriptor, "0xBB");
                            sentBB = true;
                        }
                        //writeFile(fileDescriptor, "0xBB");
                        readFile(fileDescriptor, readData);
                        //if (readData == "11" || readData == "0xB") // HVAD ER DER GALT MED DEN STRING
                        string searchedString = "11";
                        if (search(searchedString, readData))
                        {
                            okRecieved = true; //gammel kode til while looped, lige meget
                            cout << "TARE FINISHED " << readData << endl;
                            response.body() = "true";
                        }
                        
                        //}
                        /*
                        fileDescriptor = openFile(platformOnePath);
                        string readData;
                        readFile(fileDescriptor, "0xAA")
                        while (!okRecieved)
                        {
                            readFile(fileDescriptor, readData);
                            if (readData == "10" || readData == "0xA" || stoi(readData) == 10) // HVAD ER DER GALT MED DEN STRING
                            {
                                okRecieved = true;
                                cout << "TARE REQUEST " << readData << endl;
                            }
                        }
                        closeFile(fileDescriptor);
                        */
                    else
                        response.body() = "false";
                        
                    closeFile(fileDescriptor);
                        
                    }
                    else if (target == "/gameReady")
                    {
                        cout << "Received GET gameReady" << endl;
                        response.body() = "true";

                    }
                    else if (target == "/time")
                    {
                        //hejs flag
                        fileDescriptor = openFile(platformOnePath);
                        writeFile(fileDescriptor, "0xDD");
                        closeFile(fileDescriptor);  
                        // for (uint32_t i = 0; i < 40000000; i++)
                        // {
                        //     int tal;
                        //     ++tal;
                        //     --tal;
                        //     //do nothing
                        // }

                        //flush buffer (evt add forloop)
                        {
                            string flush;
                            fileDescriptor = openFile(platformOnePath);
                            readFile(fileDescriptor, flush);
                            closeFile(fileDescriptor);
                        }
                        //-----------------//
                        string minutter_, sekunder_, milisekunder_;
                        for (int i = 0; i < 3; i++){
                        fileDescriptor = openFile(minutes1);
                        readFile(fileDescriptor, minutter_);
                        minutter_ = minutter_.substr(0, 1);
                        closeFile(fileDescriptor);
                        }

                        for (int i = 0; i < 3; i++){
                        fileDescriptor = openFile(sekunder1);
                        readFile(fileDescriptor, sekunder_);
                        sekunder_ = sekunder_.substr(0, 2);
                        closeFile(fileDescriptor);
                        }

                        for (int i = 0; i < 3; i++){
                        fileDescriptor = openFile(milisekunder1);
                        readFile(fileDescriptor, milisekunder_);
                        milisekunder_ = milisekunder_.substr(0, 1);
                        closeFile(fileDescriptor);
                        }

                        cout << "Received GET time" << endl;
                        //players_[0].time = minutter_ + ":" + sekunder_ + ":" + milisekunder_;
                        //players_[1].time = minutter_ + ":" + sekunder_ + ":" + milisekunder_;

                        //nohmann::json jsonStrPlayers;
                        //string jsonStrPlayers = json(players_).dump();
                        
                        //response.body() = jsonStrPlayers;
                        //response.body() = R"({'p1': '01:12.45', 'p2': '01:11.10'})"; //lav det om så den læser tiden i stedet
                        response.body() = "{'p1': '" + minutter_ + ":" + sekunder_ + "." + milisekunder_ + "', 'p2': '01:23.45'}"; //det her kan vi ikke bruge
                        /*
                                FIKS PARSING ERROR NÅR VI SENDER TIDEN FOR SPILLERNE
                        */
                        //response.body() = R"({'p1': )" + R"(')" + string(minutter_) + R"(:)" + sekunder_ + "R(.)" + milisekunder_ + "R(')" + R"(, 'p2': '01:23.45'})"; //det her kan vi ikke bruge
                        //response.body() = R"({'p1': )" + string(R"(')") + minutter_ + ":" + sekunder_ + R"(:)" + milisekunder_ + string(R"('), 'p2': '01:23.45'})";
                                                
                    }
                    else if (target == "/gameRunning")
                    {
                        cout << "Received GET gameRunning" << endl;

                        string readData;
                        fileDescriptor = openFile(platformOnePath);
                        readFile(fileDescriptor, readData);
                        closeFile(fileDescriptor);
                        string searchedString = "12";
                        if (search(searchedString, readData))
                        {
                            cout << "GAME FINISHED " << readData << endl;
                            response.body() = "false"; //game running bliver false
                        }
                        else
                            response.body() = "true";
                    }
                    else if (target == "/leaderboard")
                    {
                        cout << "Received GET leaderboard" << endl;

                        nlohmann::json jsonArr;
                        nlohmann::json jsonObj1;
                        jsonObj1["initials"] = "ABC"; //XX
                        jsonObj1["time"] = "01:00.30";

                        jsonArr.push_back(jsonObj1);

                        nlohmann::json jsonObj2;
                        jsonObj2["initials"] = "ABD";
                        jsonObj2["time"] = "01:00.40";

                        jsonArr.push_back(jsonObj2);

                        string jsonStr = jsonArr.dump();

                        response.body() = jsonStr;
                        // response.body() = R"({
                        //     \"1\": {\"initials\": \"XXX\", \"time\": \"01:04.30\"},
                        //     \"2\": {\"initials\": \"XXX\", \"time\": \"01:04.30\"}
                        // })";
                    }
                    else
                    {
                        cout << "Target not specified" << endl;
                    }

                    response.keep_alive(request.keep_alive());
                    response.prepare_payload();
                    http::write(socket, response);
                }
            }
        }
        catch (const std::exception &e)
        {
            cout << "not good" << endl;
            std::cerr << "Error: " << e.what() << std::endl;
            return start();
            return EXIT_FAILURE;
        }

        cout << "Server exited successfully" << endl;
        return EXIT_SUCCESS;
    }

    int close()
    {
        return 0;
    }
};
