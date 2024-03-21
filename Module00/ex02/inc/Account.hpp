// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
/*
It is considered good practice to declare your class attributes as private (as often as you can)
Encapsulation ensures better control of your data, because you (or others) can change
one part of the code without affecting other parts

*/
// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account
{


public:

	typedef Account		t;

// to return the total number of accounts created
	static int	getNbAccounts( void );
// to return the total amount of money in all accounts
	static int	getTotalAmount( void );
// to return the total number of deposits made across all accounts
	static int	getNbDeposits( void );
// to return the total number of withdrawals made across all accounts
	static int	getNbWithdrawals( void );
// Displays information about all accounts
	static void	displayAccountsInfos( void );


	Account( int initial_deposit );
	~Account( void );


	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	static int	_nbAccounts; // to keep track of total num of accounts
	static int	_totalAmount;// to keep track of total amount of money in all accounts
	static int	_totalNbDeposits; // to keep track of total num of deposits in all accounts
	static int	_totalNbWithdrawals; // to keep track of total num of withdrawals

//A private static function that displays a timestamp.
// This function is used internally and is not accessible outside the class
	static void	_displayTimestamp( void );

	int				_accountIndex; //Unique index for the account
	int				_amount; //Current balance of the account
	int				_nbDeposits; //Number of deposits made to the account
	int				_nbWithdrawals; //Number of withdrawals made from the account

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
