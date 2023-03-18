#pragma once

#include <iostream>
#include <vector>
#include <string>

class Token
{
private:
	std::string m_sourceIp;
	std::string m_destinationIp;
	bool m_clockwise;
	std::string m_message;
	bool m_arrivedAtDestination;
	bool m_free;
	std::vector<std::string> m_history;

public:
	Token(std::string sourceIp, std::string destinationIp, bool clockwise, std::string message);

	void SetSourceIp(const std::string& sourceIp);

	void SetDestinationIp(const std::string& destinationIp);
	
	void SetDirection(const bool& clockwise);

	void SetMessage(const std::string& message);

	std::string GetMessage() const;

	void SetFree(const bool& free);

	bool GetFree() const;

	void AddToHistory(const std::string& computer);

	void PrintToken() const;

	void ResetToken();

	void SendMessage(const std::vector<std::string>& computers, const bool& clockwise);
};
