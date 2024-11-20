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

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0)
{
}
PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook destroyed." << std::endl;
}
void	PhoneBook::searchContact()
{
	std::string str;

	if (contacts[0].getfirstName() != "")
	{
		std::cout << "____________________________________________" << std::endl;
		std::cout << "   Index  |First name|Last name | Nickname |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < contactCount; i++)
		{
			std::cout << "    " << i + 1 << "     |";
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
		if (std::getline(std::cin, str) && str != "")
		{
			int idx = std::atoi(str.c_str()) - 1;
			if (idx >= 0 && idx < contactCount)
			{
				std::cout << "First name: " << contacts[idx].getfirstName() << std::endl;
				std::cout << "Last name: " << contacts[idx].getlastName() << std::endl;
				std::cout << "Nickname: " << contacts[idx].getnickName() << std::endl;
				std::cout << "Phone number: " << contacts[idx].getphoneNumber() << std::endl;
				std::cout << "Darkest secret: " << contacts[idx].getdarkestSecret() << std::endl;
				break;
			}
			else
				std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << "." << std::endl;
		}
	}
}

void	PhoneBook::addContact()
{
	std::string str;
	int	idx;

	str = "";
	if (contactCount < 8)
		idx = contactCount;
	else
	{
		idx = oldestContactIndex;
		std::cout << "The phonebook is full. The oldest contact will be replaced." << std::endl;
		oldestContactIndex = (oldestContactIndex + 1) % 8;
	}

	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the first name: ";
		if (std::getline(std::cin, str) && str != "")
			contacts[idx].setfirstName(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the last name: ";
		if (std::getline(std::cin, str) && str != "")
			contacts[idx].setlastName(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the nickname: ";
		if (std::getline(std::cin, str) && str != "")
			contacts[idx].setnickName(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the phone number: ";
		if (std::getline(std::cin, str) && str != "")
			contacts[idx].setphoneNumber(str);
	}
	str = "";
	while (str == "" && !std::cin.eof())
	{
		std::cout << "Enter the darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			contacts[idx].setdarkestSecret(str);
	}

	if (contactCount < 8)
		contactCount++;
}
