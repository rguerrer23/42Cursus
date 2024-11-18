#include "Zombie.hpp"

Zombie::Zombie() : _name("")
{
}
Zombie::Zombie(std::string name)
{
	_name = name;
}
Zombie::~Zombie()
{
	std::cout << _name << ": is dead" << std::endl;
}
void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
