/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:24:24 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/30 13:36:10 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	// Test Harl's complaints
	harl.complain(DEBUG);
	harl.complain(INFO);
	harl.complain(WARNING);
	harl.complain(ERROR);

	// Test invalid complaint level
	harl.complain(INVALID);
	return (0);
}
