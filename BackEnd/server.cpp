// Compile and run:
// g++ -o server server.cpp -lwebsockets
// ./ server

#include <iostream>
#include <string>
// #include <boost/beast/core.hpp>
// #include <boost/beast/http.hpp>
//#include <boost/asio.hpp>

//#include "beast/include/boost/beast.hpp"
#include "writeToFile.hpp"
//make comment
// namespace beast = boost::beast;
// namespace http = beast::http;
// namespace net = boost::asio;
// using tcp = boost::asio::ip::tcp;
using namespace std;

int fileDescriptor;

int main() 
{
    string readData;

    fileDescriptor = openFile("/home/root/testRead.txt");
    writeFile(fileDescriptor, "din tekst fil er grim");
    fileDescriptor = openFile("/home/root/testRead.txt");
    readFile(fileDescriptor, readData);

    cout << readData << endl;
    
    cout << "Started server" << endl;

    // try
    // {
    //     net::io_context ioc;
    //     tcp::acceptor acceptor(ioc, {tcp::v4(), 8080});
    //     tcp::socket socket(ioc);

    //     acceptor.accept(socket);

    //     beast::flat_buffer buffer;
    //     http::request<http::string_body> request;
    //     http::read(socket, buffer, request);

    //     // Handle the received request here
    //     http::response<http::string_body> response{http::status::ok, request.version()};
    //     response.set(http::field::server, "C++ Server");
    //     response.set(http::field::content_type, "application/json");

    //     // Set CORS headers for all requests
    //     response.set(http::field::access_control_allow_origin, "*");
    //     response.set(http::field::access_control_allow_methods, "GET, POST, OPTIONS");
    //     response.set(http::field::access_control_allow_headers, "Content-Type, Authorization");
    //     response.set(http::field::access_control_expose_headers, "Authorization");
    //     response.set(http::field::access_control_max_age, "3600"); // 1 hour

    //     if (request.method() == http::verb::options)
    //     {
    //         // Respond to OPTIONS requests immediately
    //         response.set(http::field::allow, "GET, POST, OPTIONS");
    //         http::write(socket, response);
    //         return EXIT_SUCCESS;
    //     }
    //     else if (request.method() == http::verb::post)
    //     {
    //         // Handle POST request
    //         // Assuming the body is in the form of JSON
    //         std::string body = request.body();
    //         cout << "Received POST body: " << body << endl;

    //         // Process the body as needed

    //         // Continue with the response
    //     }
    //     else if (request.method() == http::verb::get)
    //     {
    //         boost::beast::string_view target = request.target();

    //         cout << "Received GET target: " << target << endl;

    //         if (target == "/time")
    //         {
    //             cout << "yeah time" << endl;
    //             response.body() = "11:30";
    //         }
    //     }

    //     // For other HTTP methods (GET, POST, etc.), continue processing the request
    //     response.keep_alive(request.keep_alive());
    //     response.prepare_payload();
    //     http::write(socket, response);
    // }
    // catch (const std::exception &e)
    // {
    //     cout << "not good" << endl;
    //     std::cerr << "Error: " << e.what() << std::endl;
    //     return EXIT_FAILURE;
    // }

    // cout << "Server exited succesfully" << endl;
    // return EXIT_SUCCESS;
}