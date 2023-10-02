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
#include <boost/smart_ptr/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/is_placeholder.hpp>
#include <vector>;
#include <bitset>



template<typename T>
static void printlog(const T& message) {
	std::cout << "[Client: " << message << "]" << std::endl;
}


void set_size_to_bit_array(std::uint16_t* write_size, const size_t& size) {
	std::memcpy(write_size, &size, sizeof(size_t));
}


size_t get_size_from_bit_array(std::uint16_t* write_size) {
	size_t return_size;
	std::memcpy(&return_size, write_size, sizeof(size_t));
	return return_size;
}

size_t get_type_message(std::string& str) {
	size_t type = *str.begin() - '0';
	str.erase(str.begin());
	return type;
}

enum class type_message : std::size_t {
	Send = 0, Find = 1, Ping = 2
};


class Client : public boost::enable_shared_from_this<Client>
{
public:
	Client() : socket(context) { read_message = std::string(6,'1'); }

	~Client() {}

	bool ConnectToServer(const std::string& ipaddress, const uint32_t& port);
	void send_to_server(type_message type_m, const std::string& message);
	void read();
	void start_thread() { thread_client = std::thread([this]() { context.run(); }); };

private:
	boost::asio::io_context context;
	boost::system::error_code error;
	boost::asio::ip::tcp::socket socket;
	boost::asio::ip::tcp::endpoint serverip;
	std::thread thread_client;
	std::string write_message;
	std::uint16_t write_size[sizeof(size_t)];
	std::uint16_t read_size[sizeof(size_t)];
	std::string read_message;
};
