#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harl.complain(av[1]);
	return 0;
}