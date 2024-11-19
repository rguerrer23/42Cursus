/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:34:48 by rguerrer          #+#    #+#             */
/*   Updated: 2024/08/12 18:34:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to the phonebook!" << std::endl;
	while (1)
	{
		std::cout << "Enter a command: "<< std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
	}
	return 0;
}
