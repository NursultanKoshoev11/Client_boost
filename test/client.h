#pragma once
#ifdef _WIN32
#define _WIN32_WINNT 0x0A00
#endif
#define ASIO_STANDALONE

#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>
#include <boost/asio/error.hpp>
#include <boost/system/error_code.hpp>



template<typename T>
void print(const T& message) {
	std::cout << "[" << message << "]" << std::endl;
}



class Client
{
public:
	Client() : socket(context) {}

	~Client() {}


	bool ConnectToServer(const std::string &ipaddress,const uint32_t& port) {
		serverip = boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(ipaddress, error), port);
		if (error) {
			print("Invalid Ip or Port!!!");
			return false;
		}

		socket.connect(serverip, error);

		if (error) {
			print("Fail to Connect!!!");
			return false;
		}

		print("Connect is succesful!!!");

		return true;
	}

private:
	boost::asio::io_context context;
	boost::system::error_code error;
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::endpoint serverip;
};
