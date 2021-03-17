/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:20:03 by abaur             #+#    #+#             */
/*   Updated: 2021/03/17 14:46:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"

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
}
#pragma endregion


#pragma region PublicMember
Account::Account( int initial_deposit ) {
}

Account::~Account( void ) {
}


void	Account::makeDeposit( int deposit ) {
}

bool	Account::makeWithdrawal( int withdrawal ) {
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
}
#pragma endregion


#pragma region PrivateMembers
Account::Account( void ) {
}
#pragma endregion