#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog created!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed!" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
	std::cout << "Dog copied!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Guau Guau!" << std::endl;
}