#include "client.h"
#include <condition_variable>
#include <mutex>

Client;

void add_chat(const std::unique_ptr<Client>& ptr_client) {
	size_t FindID;
	std::cout << "Input ID: "; std::cin >> FindID;
	ptr_client->send_to_server(std::to_string(FindID));
}

void menu(const std::unique_ptr<Client> &ptr_client) {
	int menu;
	std::cout << "\t\tMENU\n";
	std::cout << "(1) Chats\n";
	std::cout << "(2) Add Chat\n";
	std::cout << "(0) Exit\n";
	std::cout << "Input your number: "; std::cin >> menu;
	switch (menu)
	{
	case 1: {

	}
	case 2: {
		add_chat(ptr_client);
		break;
	}
	case 0: {

	}
	}
}


int main() {

	std::mutex mt;
	std::condition_variable c_variable;

	std::unique_ptr<Client> ptr_client = std::make_unique<Client>();

	ptr_client->ConnectToServer("127.0.0.1", 1000);

	while (true)
	{
		menu(ptr_client);
	}

	
	return 0;
}


bool Client::ConnectToServer(const std::string& ipaddress, const uint32_t& port) {
	serverip = boost::asio::ip::tcp::endpoint(boost::asio::ip::make_address(ipaddress, error), port);
	if (error) {
		printlog("Invalid Ip or Port!!!");
		return false;
	}
	socket.async_connect(serverip, 
		[&,this](const boost::system::error_code& err) {
			if (!error) {
				printlog("On connect");
				read();
			}
			else {
				printlog("No connect");
			}
			
		});
	start_thread();
	return true;
}

void Client::read() {
	boost::asio::async_read(socket, boost::asio::buffer(read_size),
		[this](boost::system::error_code error, std::size_t bytes_transferred) {
			if (!error) {
				size_t size = get_size_from_bit_array(read_size);
				read_message.resize(size);
				boost::asio::async_read(socket, boost::asio::buffer(read_message),
					[this](const boost::system::error_code& error, size_t bytes_transferred) {
						if (!error) {
							printlog(read_message);
						}
						else {
							printlog("Error by read message");
						}
					});
			}
			else {
				printlog("Error by read size");
			}
		});

}

void Client::send_to_server(const std::string &message) {
	write_message = message;
	set_size_to_bit_array(write_size, write_message.size());
	boost::asio::async_write(socket, boost::asio::buffer(write_size),
		[this](const boost::system::error_code& error, size_t bytes_transferred) {
			if (!error) {
				boost::asio::async_write(socket, boost::asio::buffer(write_message),
					[](const boost::system::error_code& error_, size_t bytes_transferred_) {
						if (!error_) {
							printlog("Success send");
						}
						else {
							printlog("Error by send message");
						}
					});
			}
			else {
				printlog("Error by send size");
			}
		});
}

