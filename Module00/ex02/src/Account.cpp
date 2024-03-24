/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:42:14 by chruhin           #+#    #+#             */
/*   Updated: 2024/03/24 17:49:34 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::checkAmount( void ) const
{
	return (_amount);
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/*
man localtime
to display the current date and time in this format
[year/month/day_hour/min/sec] -> [19991107_153356]
time() returns the current time in sec since Unix epoch (00:00:00: UTC on Jan, 1.1970)
time(0) zero to give the current time saved into 'now'. localtime() returns a ptr to struct
that provides access to all the structure members
*/
static void	displayTimestamp(void)
{
	const time_t	now = time(0);
	tm				*ptr = localtime(&now);

	std::cout << "["
		<< 1900 + ptr->tm_year
		<< std::setfill('0') << std::setw(2) << 1 + ptr->tm_mon
		<< std::setfill('0') << std::setw(2) << ptr->tm_mday
		<< "_"
		<< std::setfill('0') << std::setw(2) << ptr->tm_hour
		<< std::setfill('0') << std::setw(2) << ptr->tm_min
		<< std::setfill('0') << std::setw(2) << ptr->tm_sec
		<< "] ";
}

/*

*/
void	Account::displayStatus(void) const
{
	displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";"
	<< "deposits:" << _nbDeposits << ";"
	<< "withdrawals:" << _nbWithdrawals << std::endl;
}

/*
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void Account::makeDeposit(int deposit)
{
	displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "deposit:" << deposit << ";";
		_amount += deposit;
		_totalAmount += deposit;
		std::cout << "amount:" << _amount << ";";
		_nbDeposits++;
		_totalNbDeposits++;
		std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "p_amount:" << _amount << ";"
	<< "withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

Account::Account( int initial_deposit ) : _amount(initial_deposit)
{
	displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std:: cout << "created" << std::endl;
	_totalAmount+=initial_deposit;
	_nbAccounts++;
}

Account::~Account( void )
{
	displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}
