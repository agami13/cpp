/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:26:59 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 02:06:38 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);

	tm *ltm = localtime(&now);
	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits() << ";withdrawals:"
		<< getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:"
		<< Account::_amount << ";deposit:" << deposit << ";amount:"
		<< Account::_amount + deposit << ";nb_deposits:" << Account::_nbDeposits + 1 << std::endl;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:"
		<< Account::_amount << ";withdrawal:";
	if (Account::_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";amount:" << Account::_amount - withdrawal
		<< ";nb_withdrawals:" << Account::_nbWithdrawals + 1 << std::endl;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:"
		<< Account::_amount << ";deposits:" << Account::_nbDeposits
		<< ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	Account::_displayTimestamp();
	Account::_amount = initial_deposit;
	Account::_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << Account::_accountIndex << ";amount:"
		<< Account::_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:"
		<< Account::_amount << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::_amount;
}
