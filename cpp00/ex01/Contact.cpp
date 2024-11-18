/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:30:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/09/25 18:30:41 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("")
{
}
Contact::~Contact()
{
}

// Getters
std::string	Contact::getfirstName() const
{
	return this->firstName;
}
std::string	Contact::getlastName() const
{
	return this->lastName;
}
std::string	Contact::getnickName() const
{
	return this->nickName;
}
std::string	Contact::getphoneNumber() const
{
	return this->phoneNumber;
}
std::string	Contact::getdarkestSecret() const
{
	return this->darkestSecret;
}

// Setters
void	Contact::setfirstName(std::string str)
{
	this->firstName = str;
}
void	Contact::setlastName(std::string str)
{
	this->lastName = str;
}
void	Contact::setnickName(std::string str)
{
	this->nickName = str;
}
void	Contact::setphoneNumber(std::string str)
{
	this->phoneNumber = str;
}
void	Contact::setdarkestSecret(std::string str)
{
	this->darkestSecret = str;
}

// Methods
void	Contact::fieldPrint(std::string str)
{
	std::string::size_type i = 0;
	while(i < 9 && i < str.length())
	{
		std::cout << str[i];
		i++;
		if (i == 8 && str.length() > 10)
		{
			std::cout << '.';
			i++;
		}
		else if (i == 8 && str.length() == 10)
		{
			std::cout << str[9];
			i++;
		}
	}
	while (i < 10)
	{
		std::cout << ' ';
		i++;
	}
	std::cout << '|';
}
void	Contact::printContact()
{
	fieldPrint(getfirstName());
	fieldPrint(getlastName());
	fieldPrint(getnickName());
	std::cout << std::endl;
}
