#include "client.h"
#include <condition_variable>
#include <mutex>

int main() {
	std::mutex mt;
	std::condition_variable c_variable;

	std::unique_ptr<Client> ptr_client = std::make_unique<Client>();

	ptr_client->ConnectToServer("127.0.0.1",1000);
    
	while (true)
	{
		std::unique_lock<std::mutex> m_lock(mt);
		c_variable.wait(m_lock);
	}


	return 0;
}

bool Client::ConnectToServer(const std::string& ipaddress, const uint32_t& port) {
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