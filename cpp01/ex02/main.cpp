#include <iostream>

int main ()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* brainPtr = &brain;
	std::string& brainRef = brain;

	std::cout << "Memory address of brain: " << &brain << std::endl;
	std::cout << "Memory address of brainPtr: " << brainPtr << std::endl;
	std::cout << "Memory address of brainRef: " << &brainRef << std::endl;

	std::cout << "Value of brain: " << brain << std::endl;
	std::cout << "Value of brainPtr: " << *brainPtr << std::endl;
	std::cout << "Value of brainRef: " << brainRef << std::endl;

	return 0;
}