#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "DEBUG: I love having extra bacon for my burger!" << std::endl;
}

void Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning()
{
	std::cout << "WARNING: I think I deserve free bacon for my loyalty." << std::endl;
}

void Harl::error()
{
	std::cout << "ERROR: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*actions[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	for (; i < 4; i++)
	{
		if (levels[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			(this->*actions[0])();
			break;
		case 1:
			(this->*actions[1])();
			break;
		case 2:
			(this->*actions[2])();
			break;
		case 3:
			(this->*actions[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}