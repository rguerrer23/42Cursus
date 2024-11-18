/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:56:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/09/24 12:56:36 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0)
{
}
PhoneBook::~PhoneBook()
{
}
void	PhoneBook::searchContact()
{
	std::string index;
	std::cout << "Introduce the index of the contact you want to see: " << std::endl;
	std::getline(std::cin, index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
	{
		int idx = index[0] - '0';
		if (contacts[idx].getfirstName() != "")
		{
			std::cout << "   index  |first name|last name | nickname |" << std::endl;
			std::cout << "    " << index << "     |";
			contacts[idx].printContact();
			std::cout << std::endl;
		}
		else
			std::cout << "No contact in that index." << std::endl;
	}
	else
		std::cout << "Invalid index. Please enter a number between 0 and 7." << std::endl;
}

void	PhoneBook::addContact()
{
	std::string str;
	int	idx = 0;
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].getfirstName() == "")
		{
			idx = i;
			break;
		}
		idx = i;
	}
	if (idx == 7 && contacts[idx].getfirstName() != "")
	{
		std::cout << "The phonebook is full, overwriting oldest one." << std::endl;
		idx = contactCount;
		contactCount++;
	}
	std::cout << "Enter the first name: ";
	std::getline(std::cin, str);
	contacts[idx].setfirstName(str);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, str);
	contacts[idx].setlastName(str);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, str);
	contacts[idx].setnickName(str);
	std::cout << "Enter the number: ";
	std::getline(std::cin, str);
	contacts[idx].setphoneNumber(str);
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, str);
	contacts[idx].setdarkestSecret(str);
}
