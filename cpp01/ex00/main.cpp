#include "Zombie.hpp"

int main()
{
	Zombie stack("Zombie stack");
	Zombie *heap = Zombie::newZombie("Zombie heap");

	stack.announce();
	heap->announce();
	Zombie::randomChump("Zombie random");
	delete heap;
}
