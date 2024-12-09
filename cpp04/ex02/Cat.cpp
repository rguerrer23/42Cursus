#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat created!" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destroyed!" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copied!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Miau Miau!" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
	brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}