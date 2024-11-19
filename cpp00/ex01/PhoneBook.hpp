/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:44:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/08/12 18:44:00 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact contacts[8];
		int		contactCount;
		int		oldestContactIndex;
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
};

#endif