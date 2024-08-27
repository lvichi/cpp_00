/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by lvichi            #+#    #+#             */
/*   Updated: 2024/08/21 17:40:27 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream> 		// std::cout
#include <ctime> 			// std::time
#include <iomanip> 			// std::setw, std::setfill


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


// Constructor
Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount 		= initial_deposit;
	this->_nbDeposits 	= 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts++;
	this->_totalAmount 	+= initial_deposit;

	this->_displayTimestamp();
	std::cout << "index:" 	<< this->_accountIndex 	<< ";"
			  << "amount:" 	<< this->_amount 		<< ";"
			  << "created" 							<< std::endl;
}


// Destructor
Account::~Account(){
	Account::_totalAmount -= this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" 	<< this->_accountIndex 	<< ";"
			  << "amount:" 	<< this->_amount 		<< ";"
			  << "closed" 							<< std::endl;
}


int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}


int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}


int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}


int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}


void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "Accounts:" 	<< getNbAccounts() 		<< ";";
	std::cout << "total:" 		<< getTotalAmount() 	<< ";";
	std::cout << "deposits:" 	<< getNbDeposits() 		<< ";";
	std::cout << "withdrawals:" << getNbWithdrawals() 	<< std::endl;
}


void	Account::makeDeposit(int deposit) {
	this->_totalAmount 		+= deposit;
	this->_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:"		<< Account::_accountIndex 		<< ";"
	          << "p_amount:" 	<< Account::_amount 			<< ";"
			  << "deposit:" 	<< deposit 						<< ";";

	Account::_amount += deposit;
	Account::_nbDeposits++;

	std::cout << "amount:" 		<< Account::_amount 			<< ";"
			  << "nb_deposits:" << Account::_nbDeposits 		<< std::endl;
}


bool	Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > this->_amount) {
		this->_displayTimestamp();
		std::cout << "index:"		<< this->_accountIndex 		<< ";"
				  << "p_amount:" 	<< this->_amount 			<< ";"
				  << "withdrawal:" << "refused" 				<< std::endl;
		return false;
	}
	this->_displayTimestamp();
	std::cout << "index:"		<< this->_accountIndex 		<< ";"
			  << "p_amount:" 	<< this->_amount 			<< ";"
			  << "withdrawal:" 	<< withdrawal 				<< ";";

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;

	std::cout << "amount:" 			<< this->_amount 			<< ";"
			  << "nb_withdrawals:" 	<< this->_nbWithdrawals 	<< std::endl;
	return true;
}


int		Account::checkAmount(void) const {
	return this->_amount;
}


void	Account::displayStatus(void) const {
	this->_displayTimestamp();
	std::cout	<< "index:"			<< this->_accountIndex 		<< ";"
				<< "amount:"		<< this->_amount 			<< ";"
				<< "deposits:"		<< this->_nbDeposits 		<< ";"
				<< "withdrawals:"	<< this->_nbWithdrawals 	<< std::endl;
}


void	Account::_displayTimestamp( void ) {
	std::time_t 	now = std::time(0);
	std::tm 		*ltm = std::localtime(&now);

	std::cout 	<< "["
				<< ltm->tm_year + 1900
				<< std::setw(2) << std::setfill('0') << ltm->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << ltm->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << ltm->tm_hour
				<< std::setw(2) << std::setfill('0') << ltm->tm_min
				<< std::setw(2) << std::setfill('0') << ltm->tm_sec
				<< "] ";
}
