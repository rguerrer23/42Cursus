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
	std::cout << "Phonebook destroyed." << std::endl;
}
void	PhoneBook::searchContact()
{
	if (contacts[0].getfirstName() != "")
	{
		std::cout << "____________________________________________" << std::endl;
		std::cout << "   Index  |First name|Last name | Nickname |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < contactCount; i++)
		{
			std::cout << "    " << i << "     |";
			contacts[i].fieldPrint(contacts[i].getfirstName());
			contacts[i].fieldPrint(contacts[i].getlastName());
			contacts[i].fieldPrint(contacts[i].getnickName());
			std::cout << std::endl;
		}
		std::cout << "--------------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "No contacts to display." << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Enter the index of the contact you want to display: ";
		return ;
	}
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
	while (!std::cin.eof() && contacts[idx].getfirstName() == "")
	{
		std::cout << "Enter the first name: ";
		std::getline(std::cin, str);
		contacts[idx].setfirstName(str);
	}
	while (!std::cin.eof() && contacts[idx].getlastName() == "")
	{
		std::cout << "Enter the last name: ";
		std::getline(std::cin, str);
		contacts[idx].setlastName(str);
	}
	while (!std::cin.eof() && contacts[idx].getnickName() == "")
	{
		std::cout << "Enter the nickname: ";
		std::getline(std::cin, str);
		contacts[idx].setnickName(str);
	}
	while (!std::cin.eof() && contacts[idx].getphoneNumber() == "")
	{
		std::cout << "Enter the phone number: ";
		std::getline(std::cin, str);
		contacts[idx].setphoneNumber(str);
	}
	while (!std::cin.eof() && contacts[idx].getdarkestSecret() == "")
	{
		std::cout << "Enter the darkest sceret: ";
		std::getline(std::cin, str);
		contacts[idx].setdarkestSecret(str);
	}
	contactCount++;
}
