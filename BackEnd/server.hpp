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
    Server(){}

    int start()
    {
        cout << "Started server" << endl;

        try
        {
            net::io_context ioc;
            tcp::acceptor acceptor(ioc, {tcp::v4(), 8080});
            tcp::socket socket(ioc);

            acceptor.accept(socket);

            beast::flat_buffer buffer;
            http::request<http::string_body> request;
            http::read(socket, buffer, request);

            bool serverActive = true;
            while (serverActive)
            {
                // Handle the received request here
                http::response<http::string_body> response{http::status::ok, request.version()};
                response.set(http::field::server, "C++ Server");
                response.set(http::field::content_type, "application/json");

                // Set CORS headers for all requests
                response.set(http::field::access_control_allow_origin, "*");
                response.set(http::field::access_control_allow_methods, "GET, POST, OPTIONS");
                response.set(http::field::access_control_allow_headers, "Content-Type, Authorization");
                response.set(http::field::access_control_expose_headers, "Authorization");
                response.set(http::field::access_control_max_age, "3600"); // 1 hour

                if (request.method() == http::verb::options)
                {
                    // Respond to OPTIONS requests immediately
                    response.set(http::field::allow, "GET, POST, OPTIONS");
                    http::write(socket, response);
                    return EXIT_SUCCESS;
                }
                else if (request.method() == http::verb::post)
                {
                    // Handle POST request
                    // Assuming the body is in the form of JSON
                    std::string body = request.body();
                    cout << "Received POST body: " << body << endl;

                    json bodyJson = json::parse(body);
                    string cmd = bodyJson["cmd"];
                    json data = bodyJson["data"];

                    if (cmd == "tare")
                    {
                        cout << data << endl;
                    }
                    else if (cmd == "startGame")
                    {
                        /*For platform 1:*/
                        int fd1 = openFile(platformOnePath);
                        //writeFile(fd1, /*start game char array*/);
                        closeFile(fd1);
                        /*              */
                        /*For platform 2*/
                        int fd2 = openFile(platformTwoPath);
                        //writeFile( samme smøre );
                        closeFile(fd2);
                        /*              */
                        cout << data << endl;
                    }
                }
                else if (request.method() == http::verb::get)
                {
                    boost::beast::string_view target = request.target();

                    cout << "Received GET target: " << target << endl;

                    if (target == "/time")
                    {
                        response.body() = "{'p1': '01:10.45', 'p2': '01:11.10'}";
                    }
                    else if (target == "/gameRunning")
                    {
                        response.body() = "true";
                    }
                    else if (target == "/leaderboard")
                    {
                        response.body() = "[{'initials': 'XXX', 'time': '01:04.30'}, {'initials': 'XXX', 'time': '01:04.30'}]";
                    }
                    else 
                    {
                        cout << "target not specified" << endl;
                    }
                }

                // For other HTTP methods (GET, POST, etc.), continue processing the request
                response.keep_alive(request.keep_alive());
                response.prepare_payload();
                http::write(socket, response);
            }
        }
        catch (const std::exception &e)
        {
            cout << "not good" << endl;
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }

        cout << "Server exited succesfully" << endl;
        return EXIT_SUCCESS;
    }

    int close()
    {
        return 0;
    }
};
