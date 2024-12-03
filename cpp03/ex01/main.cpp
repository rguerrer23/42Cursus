#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap1("CL4P-TP");
	clap1.attack("enemy");
	clap1.takeDamage(5);
	clap1.beRepaired(3);

	ScavTrap scav1("SC4V-TP");
	scav1.attack("intruder");
	scav1.takeDamage(20);
	scav1.beRepaired(15);
	scav1.guardGate();

	ScavTrap scav2 = scav1;
	scav2.attack("another intruder");

	return 0;
}