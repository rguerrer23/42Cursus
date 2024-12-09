#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat created!" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copied!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Miau?" << std::endl;
}