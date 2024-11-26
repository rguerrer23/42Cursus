#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap1("CL4P-TP");
	ClapTrap clap2 = clap1;
	ClapTrap clap3;

	clap3 = clap1;

	clap1.attack("target1");
	clap1.takeDamage(3);
	clap1.beRepaired(5);

	clap2.attack("target2");
	clap2.takeDamage(7);

	clap3.beRepaired(10);

	return 0;
}