#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	Animal* animals[4];

	for (int i = 0; i < 4; ++i) 
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	Dog* dog = dynamic_cast<Dog*>(animals[0]);
	if (dog) 
	{
		dog->setIdea(0, "Chase the mailman.");
		std::cout << "Dog's idea: " << dog->getIdea(0) << std::endl;
	}

	Cat* cat = dynamic_cast<Cat*>(animals[2]);
	if (cat) 
	{
		cat->setIdea(0, "Sleep all day.");
		std::cout << "Cat's idea: " << cat->getIdea(0) << std::endl;
	}

	for (int i = 0; i < 4; ++i) 
		delete animals[i];

	return 0;
}