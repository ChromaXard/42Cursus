/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:34:08 by akastler          #+#    #+#             */
/*   Updated: 2023/08/28 11:06:53 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;
int _accountIndex = 0;
int	_amount = 0;
int	_nbDeposits = 0;
int	_nbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t timestamp = std::time(0);
    std::tm *now = std::localtime(&timestamp);
    std::cout << "[" << now->tm_year + 1900;
    if (now->tm_mon < 10)
        std::cout << "0";
    std::cout << now->tm_mon + 1;
    if (now->tm_mday < 10)
        std::cout << "0";
    std::cout << now->tm_mday << "_";
    if (now->tm_hour < 10)
        std::cout << "0";
    std::cout << now->tm_hour;
    if (now->tm_min < 10)
        std::cout << "0";
    std::cout << now->tm_min;
    if (now->tm_sec < 10)
        std::cout << "0";
    std::cout << now->tm_sec;
    std::cout << "] ";
}

int Account::getNbAccounts(void) {
    return(Account::_nbAccounts);
}

int Account::getTotalAmount(void){
    return(Account::_totalAmount);
}

int Account::getNbDeposits(void){
    return(Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void){
    return(Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void){
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
}

Account::Account(int initial_deposit)
{
    Account::_amount = initial_deposit;
    this->_totalAmount += Account::_amount;
    Account::_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;

    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void){
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    this->_totalAmount += deposit;
    Account::_amount += deposit;
    this->_totalNbDeposits++;
    Account::_nbDeposits++;
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "p_amount:" << Account::_amount - deposit << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > Account::_amount)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << Account::_accountIndex << ";";
        std::cout << "p_amount:" << Account::_amount << ";";
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    this->_totalAmount -= withdrawal;
    Account::_amount -= withdrawal;
    this->_totalNbWithdrawals++;
    Account::_nbWithdrawals++;
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "p_amount:" << Account::_amount + withdrawal << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
    return (true);
}

int Account::checkAmount(void) const{
    return(Account::_amount);
}

void Account::displayStatus(void) const{
    Account::_displayTimestamp();
    std::cout << "index:" << Account::_accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "deposits:" << Account::_nbDeposits << ";";
    std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}
