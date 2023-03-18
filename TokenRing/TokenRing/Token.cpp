#include "Token.h"

Token::Token(std::string sourceIp, std::string destinationIp, bool clockwise, std::string message) :
	m_sourceIp(sourceIp), m_destinationIp(destinationIp), m_clockwise(clockwise), m_message(message), m_arrivedAtDestination(false), m_free(true) {}

void Token::SetSourceIp(const std::string& sourceIp)
{
	m_sourceIp = sourceIp;
}

void Token::SetDestinationIp(const std::string& destinationIp)
{
	m_destinationIp = destinationIp;
}

void Token::SetDirection(const bool& clockwise)
{
	m_clockwise = clockwise;
}

void Token::SetMessage(const std::string& message)
{
	m_message = message;
}

std::string Token::GetMessage() const
{
	return m_message;
}

void Token::SetFree(const bool& free)
{
	m_free = free;
}

bool Token::GetFree() const
{
	return m_free;
}

void Token::AddToHistory(const std::string& computer)
{
	m_history.push_back(computer);
}

void Token::PrintToken() const
{
	std::cout << std::endl << "Source IP: " << m_sourceIp;
	std::cout << std::endl << "Destination IP: " << m_destinationIp;
	std::cout << std::endl << "Message: " << m_message;
	std::cout << std::endl << "Arrived at destination: " << m_arrivedAtDestination;
	std::cout << std::endl << "Free: " << m_free;
	std::cout << std::endl << "History: ";

	for (std::string computer : m_history)
	{
		std::cout << computer << " ";
	}

	std::cout << std::endl;
}

void Token::ResetToken()
{
	m_sourceIp.clear();
	m_destinationIp.clear();
	m_clockwise = true;
	m_message.clear();
	m_arrivedAtDestination = false;
	m_free = true;
	m_history.clear();
}

void Token::SendMessage(const std::vector<std::string>& computers, const bool& clockwise)
{
	bool reachedDestination = false;
	int indexOfComputer, numberOfLoops = 0;

	for (int i = 0; i < computers.size(); i++) 
	{
		if (computers[i].compare(m_sourceIp) == 0) 
		{
			indexOfComputer = i;
			break;
		}
	}

	while (reachedDestination == false)
	{
		if (computers[indexOfComputer].compare(m_sourceIp) == 0)
		{
			m_free = false;
			m_history.emplace_back('C' + std::to_string(indexOfComputer + 1));
			std::cout << std::endl << "At computer " << indexOfComputer + 1 << " of IP: " << computers[indexOfComputer];
			PrintToken();
		}
		else
		{
			std::cout << std::endl << "At computer " << indexOfComputer + 1 << " of IP: " << computers[indexOfComputer];
			PrintToken();
			if (clockwise == true) 
			{
				indexOfComputer++;
			}
			else 
			{
				indexOfComputer--;
			}
		}

		while (!m_free)
		{
			if (clockwise == true) 
			{
				indexOfComputer++;
			}
			else 
			{
				indexOfComputer--;
			}

			if (indexOfComputer < 0) 
			{
				indexOfComputer = computers.size() - 1;
				numberOfLoops++;
			}
			else if (indexOfComputer == computers.size())
			{
				indexOfComputer = 0;
				numberOfLoops++;
			}

			std::cout << std::endl << "At computer " << indexOfComputer + 1 << " of IP: " << computers[indexOfComputer];

			if (computers[indexOfComputer].compare(m_destinationIp) == 0)
			{
				m_arrivedAtDestination = true;
			}

			m_history.emplace_back('C' + std::to_string(indexOfComputer + 1));

			if (computers[indexOfComputer].compare(m_sourceIp) == 0 && numberOfLoops > 0 && m_arrivedAtDestination == true)
			{
				ResetToken();
				reachedDestination = true;
			}

			PrintToken();
		}
	}
}

