#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

int main()
{
	auto const address = net::ip::make_address("127.0.0.1");
    auto const port = static_cast<unsigned short>(9000);
    // The io_context is required for all I/O
    net::io_context ioc{1};

    // The acceptor receives incoming connections
    tcp::acceptor acceptor{ioc, {address, port}};
    for(;;)
    {
        // This will receive the new connection
        tcp::socket socket{ioc};

		std::cout << "Waiting for connection\n";
        // Block until we get a connection
        acceptor.accept(socket);
		std::cout << "Got connection\n";
    }
}