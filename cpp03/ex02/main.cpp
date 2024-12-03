#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap frag("FR4G-TP");

	frag.attack("target");
	frag.takeDamage(25);
	frag.beRepaired(15);
	frag.highFivesGuys();

	FragTrap fragCopy(frag);

	FragTrap anotherFrag("AnotherFrag");
	anotherFrag = frag;

	return 0;
}