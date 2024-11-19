#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << _name << ": is born" << std::endl;
}

Zombie::Zombie()
{
	this->_name = "(null)";
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

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie* Zombie::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void	Zombie::randomChump(std::string name)
{
	Zombie z = Zombie(name);
	z.announce();
}
