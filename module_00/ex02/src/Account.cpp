#include <iostream>
#include <Account.hpp>
int Account::getNbAccounts(void)
{}
int Account::getTotalAmount(void)
{}
int Account::getNbDeposits(void)
{}
int Account::getNbWithdrawals(void)
{}
void Account::displayAccountsInfos(void)
{}
void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
}
bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > 0 && _amount >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		withdrawal = 0;
	}
	return (!withdrawal);
}
Account::Account(void)
{}
Account::Account(int initial_deposit)
{
	t::_nbAccounts = _totalAmount = _totalNbDeposits = _totalNbWithdrawals = 0;
	_accountIndex = _amount = _nbDeposits = _nbWithdrawals = 0;
	t::_nbAccounts++;
	_accountIndex = t::_nbAccounts - 1;
	makeDeposit(initial_deposit);

}
Account::~Account(void)
{
	std::cout << "closed" << std::endl;
}
void Account::displayStatus(void) const
{
	std::cout << "created" << std::endl;
}
int Account::checkAmount(void) const
{}
void Account::_displayTimestamp(void)
{}
