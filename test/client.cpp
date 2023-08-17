#include "client.h"
int main() {

	std::unique_ptr<Client> ptr_client = std::make_unique<Client>();

	ptr_client->ConnectToServer("64.233.165.91",80);
    
	return 0;
}