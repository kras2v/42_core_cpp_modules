// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Aug 11 09:47:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : kvalerii <kvalerii@student.com>                   //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	char buffer[100];

	std::tm* localTime = std::localtime(&now);

	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
	std::cout << "[" << buffer << "] ";
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

/* [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0 */
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
	<< "total:" << getTotalAmount() << ';'
	<< "deposits:" << getNbDeposits() << ';'
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

/*  [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0 */
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
	<< "amount:" << checkAmount() << ';'
	<< "deposits:" << this->_nbDeposits << ';'
	<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* [19920104_091532] index:0;amount:42;created */
Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
	<< "amount:" << checkAmount() << ';'
	<< "created" << std::endl;
}

/* [19920104_091532] index:0;amount:47;closed */
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
	<< "amount:" << checkAmount() << ';'
	<< "closed" << std::endl;
}

/* [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1 */
void	Account::makeDeposit( int deposit )
{
	this->_totalNbDeposits++;
	this->_nbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
	<< "p_amount:" << checkAmount() << ';'
	<< "deposit:" << deposit << ';'
	<< "amount:" << checkAmount() + deposit << ';'
	<< "nb_deposits:" << this->_nbDeposits << std::endl;

	this->_amount += deposit;
	this->_totalAmount += deposit;
}

/* [19920104_091532] index:0;p_amount:47;withdrawal:refused */
/* [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1 */
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << + "index:" << this->_accountIndex << ';'
	<< "p_amount:" << checkAmount() << ';';

	if (withdrawal <= checkAmount())
	{
		this->_totalNbWithdrawals++;
		this->_nbWithdrawals++;

		std::cout << "withdrawal:" << withdrawal << ';'
		<< "amount:" << checkAmount() - withdrawal << ';'
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	return (true);
}