/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:20:03 by abaur             #+#    #+#             */
/*   Updated: 2021/03/17 14:54:16 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"

#include <iostream>


#pragma clang diagnostic ignored "-Wunknown-pragmas"

#pragma region PublicStatic
int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "[Displaying accounts infos]";
}
#pragma endregion


#pragma region PublicMember
Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 1;
	this->_nbWithdrawals = 0;
}

Account::~Account( void ) {
}


void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits++;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals++;
		this->_amount += withdrawal;
		return true;
	}
	else
		return false;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
}
#pragma endregion


#pragma region PrivateStatics
int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void	Account::_displayTimestamp( void ) {
	std::cout << "[19920104_091532] ";
}
#pragma endregion


#pragma region PrivateMembers
Account::Account( void ) {
	this->_accountIndex = _nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
#pragma endregion