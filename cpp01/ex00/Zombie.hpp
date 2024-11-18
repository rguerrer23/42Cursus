#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		static void	randomChump(std::string name);
		static Zombie* newZombie(std::string name);
		void	announce();
};

#endif