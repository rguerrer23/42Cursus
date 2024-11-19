#include "Zombie.hpp"

int main()
{
	Zombie *heap = Zombie::newZombie("Zombie heap");
	heap->announce();
	Zombie::randomChump("Zombie random");
	delete heap;
}
