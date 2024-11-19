#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << _name << ": is born" << std::endl;
}
Zombie::~Zombie()
{
	std::cout << _name << ": is dead" << std::endl;
}
void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
