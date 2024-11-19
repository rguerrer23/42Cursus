#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	int size;

	size = 5;
	Zombie *zombies = zombieHorde(size, "Zombie horde");
	for (int i = 0; i < size; i++)
		zombies[i].announce();
	delete [] zombies;
}
