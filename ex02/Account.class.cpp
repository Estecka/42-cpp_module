/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:20:03 by abaur             #+#    #+#             */
/*   Updated: 2021/03/18 17:48:09 by abaur            ###   ########.fr       */
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
	_displayTimestamp();
	std::cout \
		<< "accounts:"    << _nbAccounts         << ';' \
		<< "total:"       << _totalAmount        << ';' \
		<< "deposits:"    << _totalNbDeposits    << ';' \
		<< "withdrawals:" << _totalNbWithdrawals \
		<< std::endl;
}
#pragma endregion


#pragma region PublicMember
Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout \
		<< "index:"  << this->_accountIndex << ';' \
		<< "amount:" << this->_amount       << ';' \
		<< "created" << std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout \
		<< "index:"  << this->_accountIndex << ';' \
		<< "amount:" << this->_amount << ';' \
		<< "closed" << std::endl;
}


void	Account::makeDeposit( int deposit ) {
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout \
		<< "index:"       << this->_accountIndex       << ';' \
		<< "p_amount:"    << (this->_amount - deposit) << ';' \
		<< "deposit:"     << deposit                   << ';' \
		<< "amount:"      << this->_amount             << ';' \
		<< "nb_deposits:" << this->_nbDeposits \
		<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout \
		<< "index:"    << this->_accountIndex << ';' \
		<< "p_amount:" << this->_amount       << ';' \
		<< "withdrawal:";
	if (withdrawal <= this->_amount) {
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << withdrawal << ';' \
			<< "amount:"         << this->_amount        << ';' \
			<< "nb_withdrawals:" << this->_nbWithdrawals \
			<< std::endl;
		return true;
	}
	else {
		std::cout << "refused" << std::endl;
		return false;
	}
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout \
		<< "index:"       << this->_accountIndex  << ';' \
		<< "amount:"      << this->_amount        << ';' \
		<< "deposits:"    << this->_nbDeposits    << ';' \
		<< "withdrawals:" << this->_nbWithdrawals \
		<< std::endl;
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
	std::cout << "Empty account created" << std::endl;
	this->_accountIndex = _nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}
#pragma endregion