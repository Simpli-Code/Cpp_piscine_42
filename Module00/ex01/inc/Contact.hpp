/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:55:49 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/14 17:48:40 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

/*
The Purpose of Encapsulation is whatever is happening behind the scenes
we don't want to expose that to the public
*/

class Contact
{

public:

	Contact(void);
	~Contact(void);

	std::string	get_first_name(void) const;
	void		set_first_name(std::string first_name);

	std::string	get_last_name(void) const;
	void		set_last_name(std::string last_name);

	std::string	get_nickname(void) const;
	void		set_nickname(std::string nickname);

	std::string	get_start_year(void) const;
	void		set_start_year(std::string start_year);

	std::string	get_phone_number(void) const;
	void		set_phone_number(std::string phone_number);

	std::string	get_darkest_secret(void) const;
	void		set_darkest_secret(std::string darkest_secret);

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_start_year;
	std::string	_phone_number;
	std::string	_darkest_secret;

};

#endif
