#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);

		void makeSound() const;
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif