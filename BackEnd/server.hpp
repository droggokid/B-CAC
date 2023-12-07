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
char* platformTwoPath = "/dev/spi_drv1";

class Server
{
public:
    Server() {}

    int start()
    {
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
                    }
                    else if (cmd == "startGame")
                    {
                        cout << "Received POST startGame:" << endl << data << endl;

                        int fd1 = openFile(platformOnePath);
                        // writeFile(fd1, /*start game char array*/);
                        closeFile(fd1);

                        int fd2 = openFile(platformTwoPath);
                        // writeFile( samme smøre );
                        closeFile(fd2);
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

                        response.body() = "true";
                    }
                    else if (target == "/gameReady")
                    {
                        cout << "Received GET gameReady" << endl;

                        response.body() = "true";
                    }
                    else if (target == "/time")
                    {
                        cout << "Received GET time" << endl;

                        response.body() = R"({'p1': '01:12.45', 'p2': '01:11.10'})";
                    }
                    else if (target == "/gameRunning")
                    {
                        cout << "Received GET gameRunning" << endl;

                        response.body() = "true";
                    }
                    else if (target == "/leaderboard")
                    {
                        cout << "Received GET leaderboard" << endl;

                        nlohmann::json jsonArr;
                        nlohmann::json jsonObj1;
                        jsonObj1["initials"] = "ABC";
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
