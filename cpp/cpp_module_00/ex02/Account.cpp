#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";created\n";

}

Account::~Account()
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit;
	std::cout<<";amount:"<<(_amount + deposit)<<";nb_deposits:"<<++_nbDeposits<<std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
		_displayTimestamp();
		if (_amount < withdrawal)
		{
			std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused\n";
			return (false);
		}
		else
		{
			std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount;
			std::cout<<";withdrawal:"<<withdrawal<<";amount:"<<(_amount - withdrawal);
			std::cout<<";nb_withdrawals:"<<++_nbWithdrawals<<std::endl;
			_totalNbWithdrawals++;
			_amount -= withdrawal;
			_totalAmount -= withdrawal;
			return (true);
		}
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";total:"<<getTotalAmount();
	std::cout<<";deposits:"<<getNbDeposits()<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount;
	std::cout<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void	Account::_displayTimestamp()
{
	std::cout<<"["<<"placeholder"<<"] ";
}