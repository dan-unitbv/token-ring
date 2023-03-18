#include <iostream>
#include <vector>

#include "Token.h"

int main()
{
	int nrOfComputers;
	std::vector<std::string> computers;
	bool clockwise;
	std::string message;

	std::cout << "Number of computers: ";
	std::cin >> nrOfComputers;
	std::cout << std::endl;

	for (int i = 0; i < nrOfComputers; i++) 
	{
		std::string ip = "192.168." +
		std::to_string(rand() % 256) + "." +
		std::to_string(rand() % 256);
		computers.push_back(ip);
	}

	for (int i = 0; i < computers.size(); i++)
	{
		std::cout << "Computer " << i + 1 << ": " << computers[i] << std::endl;
	}
	std::cout << std::endl;

	int sourceComputerIndex, destinationComputerIndex;

	std::cout << "Source computer's index: ";
	std::cin >> sourceComputerIndex;

	std::cout << "Destination computer's index: ";
	std::cin >> destinationComputerIndex;

	std::cout << "Clockwise direction (Y/N): ";
	char response;
	std::cin >> response;
	if (response == 'Y' || response == 'y')
	{
		clockwise = true;
	}
	else if (response == 'N' || response == 'n')
	{
		clockwise = false;
	}

	std::cout << "Message: "; 
	std::cin >> message;

	Token token(computers[sourceComputerIndex - 1], computers[destinationComputerIndex - 1], clockwise, message);

	bool stillSending = true;
	while (stillSending == true)
	{
		token.SendMessage(computers, clockwise);

		std::cout << std::endl << "Do you want to send another message? (Y/N): ";
		char response;
		std::cin >> response;
		std::cout << std::endl;
		if (response == 'Y' || response == 'y')
		{
			for (int i = 0; i < computers.size(); i++)
			{
				std::cout << "Computer " << i + 1 << ": " << computers[i] << std::endl;
			}
			std::cout << std::endl;

			std::cout << "Source computer's index: ";
			std::cin >> sourceComputerIndex;

			std::cout << "Destination computer's index: ";
			std::cin >> destinationComputerIndex;

			std::cout << "Clockwise direction (Y/N): ";
			char response;
			std::cin >> response;
			if (response == 'Y' || response == 'y')
			{
				clockwise = true;
			}
			else if (response == 'N' || response == 'n')
			{
				clockwise = false;
			}

			std::cout << "Message: "; 
			std::cin >> message;

			token.SetSourceIp(computers[sourceComputerIndex - 1]);
			token.SetDestinationIp(computers[destinationComputerIndex - 1]);
			token.SetDirection(clockwise);
			token.SetMessage(message);
		}
		else if (response == 'N' || response == 'n')
		{
			stillSending = false;
		}
	}

	return 0;
}