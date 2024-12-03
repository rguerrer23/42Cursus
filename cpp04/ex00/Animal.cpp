#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal created!" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copied!" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		type = other.type;
	std::cout << "Animal assigned!" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed! (" << type << ")" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound!" << std::endl;
}