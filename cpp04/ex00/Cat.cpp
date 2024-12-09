#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat created!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
	std::cout << "Cat copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau!" << std::endl;
}