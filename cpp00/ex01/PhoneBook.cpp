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

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

void	PhoneBook::addContact()
{
	if (contactCount == 8)
	{
		std::cout << "The phone book is full. You can't add more contacts." << std::endl;
		return ;
	}
	contacts[contactCount].setContact();
	contactCount++;
}

void	PhoneBook::searchContact()
{
	if (contactCount == 0)
	{
		std::cout << "The phone book is empty. You can't search for contacts." << std::endl;
		return ;
	}
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (int i = 0; i < contactCount; i++)
		contacts[i].printContact(i);
	std::cout << "Enter the index of the contact you want to see: ";
	std::string index;
	std::getline(std::cin, index);
	if (index.length() != 1 || index[0] < '0' || index[0] > '7' || index[0] - '0' >= contactCount)
	{
		std::cout << "Invalid index. Please enter a number between 0 and " << contactCount - 1 << "." << std::endl;
		return ;
	}
	contacts[index[0] - '0'].printFullContact();
}
