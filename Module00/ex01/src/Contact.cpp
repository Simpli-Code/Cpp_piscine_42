/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:55:37 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/13 21:19:35 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

std::string Contact::get_first_name(void) const
{
	return (_first_name);
}

void	Contact::set_first_name(std::string first_name)
{
	_first_name = first_name;
}

std::string Contact::get_last_name(void) const
{
	return (_last_name);
}

void	Contact::set_last_name(std::string last_name)
{
	_last_name = last_name;
}

std::string Contact::get_nickname(void) const
{
	return (_nickname);
}

void	Contact::set_nickname(std::string nickname)
{
	_nickname = nickname;
}

std::string Contact::get_start_year(void) const
{
	return (_start_year);
}

void	Contact::set_start_year(std::string start_year)
{
	_start_year = start_year;
}

std::string Contact::get_phone_number(void) const
{
	return (_phone_number);
}

void	Contact::set_phone_number(std::string phone_number)
{
	_phone_number = phone_number;
}

std::string Contact::get_darkest_secret(void) const
{
	return (_darkest_secret);
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	_darkest_secret = darkest_secret;
}
