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

void Dog::makeSound() const
{
	std::cout << "Guau Guau!" << std::endl;
}