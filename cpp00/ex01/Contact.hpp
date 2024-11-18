/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:29:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/09/25 18:29:32 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class Contact
{
	private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	public:
		Contact();
		~Contact();
		// Getters
		std::string	getfirstName(void) const;
		std::string	getlastName(void) const;
		std::string	getnickName(void) const;
		std::string	getphoneNumber(void) const;
		std::string	getdarkestSecret(void) const;
		// Setters
		void	setfirstName(std::string str);
		void	setlastName(std::string str);
		void	setnickName(std::string str);
		void	setphoneNumber(std::string str);
		void	setdarkestSecret(std::string str);
		// Methods
		void	printContact();
		void	fieldPrint(std::string str);
};

#endif