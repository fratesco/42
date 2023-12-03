#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	std::cout<<"[Insert the date here_Insert the time here] ";
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
	std::cout<<"[Insert the date here_Insert the time here] ";
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed\n";
}

void	Account::makeDeposit(int deposit)
{
	std::cout<<"[Insert the date here_Insert the time here] ";
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit<<";amount:"<<(_amount + deposit)<<";nb_deposits:"<<++_nbDeposits<<std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
		std::cout<<"[Insert the date here_Insert the time here] ";
}