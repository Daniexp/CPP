#include <Account.hpp>
#include <iostream>
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}
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
		_displayTimestamp();
		std::cout <<" index:"<<_accountIndex<<";p_amount:"<< _amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
		withdrawal = 0;
	}
	else
	{
		_displayTimestamp();
		std::cout <<" index:"<<_accountIndex<<";p_amount:"<< withdrawal - _amount<<";withdrawal:refused"<<std::endl;
	}
	return (!withdrawal);
}
Account::Account(void)
{
	_displayTimestamp();
	//displayStatus();
	std::cout <<" index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
	//displayStatus();
//	std::cout << ";created" << std::endl;
}
Account::Account(int initial_deposit)
{
//	_nbAccounts = _totalAmount = _totalNbDeposits = _totalNbWithdrawals = 0;
	_accountIndex = _amount = _nbDeposits = _nbWithdrawals = 0;
	_accountIndex = getNbAccounts();
	_nbAccounts++;
//	makeDeposit(initial_deposit);
	_totalAmount += initial_deposit;
	_amount = initial_deposit;

}
Account::~Account(void)
{
	_displayTimestamp();
	//displayStatus();
	std::cout <<" index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
	//std::cout << ";closed" << std::endl;
//	std::cout << " index:" << _accountIndex << ";amount:" << _amount <<  ";closed" << std::endl;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout <<" index:"<<_accountIndex<<";amount:"<<_amount<<";created"<<std::endl;
}
int Account::checkAmount(void) const
{
	return (this->_amount);
}
void Account::_displayTimestamp(void)
{
	time_t now = time(0);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&now));
    std::cout << "[" << buffer << "]";
}
