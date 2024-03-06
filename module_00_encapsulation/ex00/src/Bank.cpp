#include "Bank.hpp"

#include <sys/types.h>

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <random>
#include <stdexcept>

// Bank implementation

Bank::Bank(const double liquidity) : accounts_{}, liquidity_{liquidity} {}

const double& Bank::getLiquidity() const {
  return this->liquidity_;
}

const Bank::accounts_t& Bank::getAccounts() const {
  return this->accounts_;
}

void Bank::addLiquidity(const double value) {
  this->liquidity_ += value;
}

uint32_t Bank::getUniqueAccountID() const {
  auto num_gen = std::mt19937(time(nullptr));
  auto num_id = num_gen();

  for (; this->accounts_.find(num_id) != this->accounts_.end(); num_id = num_gen()) {}
  return num_id;
}

double Bank::takeBankCut(const double value) {
  auto bank_cut = value * 0.05;
  this->addLiquidity(bank_cut);
  return (value - bank_cut);
}

const Bank::account_ptr_t& Bank::createAccount(const double initial_value) {
  if (initial_value < 0) {
    throw std::invalid_argument("Value can't be negative");
  }
  auto num_id = this->getUniqueAccountID();
  auto value_after_tax = this->takeBankCut(initial_value);
  account_ptr_t new_account(new Account(value_after_tax));
  new_account->id_ = num_id;
  std::pair<id_t, account_ptr_t> value_to_acc(num_id, std::move(new_account));
  this->accounts_.emplace(std::move(value_to_acc));
  return accounts_[num_id];
}

void Bank::depositMoney(const id_t id, const double money) {
  if (money < 0) {
    throw std::invalid_argument("Value can't be negative");
  }
  auto it = this->accounts_.find(id);
  if (it == this->accounts_.end()) {
    throw std::invalid_argument("Index doesn't exist");
  }
  auto value_after_tax = this->takeBankCut(money);
  it->second->value_ += value_after_tax;
}

void Bank::getLoan(const id_t id, const double money) {
  if (money < 0) {
    throw std::invalid_argument("Value can't be negative");
  }
  auto it = this->accounts_.find(id);
  if (it == this->accounts_.end()) {
    throw std::invalid_argument("Index doesn't exist");
  }
  if (money > this->getLiquidity()) {
    throw std::invalid_argument("Value is bigger than liquidity.");
  }
  this->liquidity_ -= money;
  accounts_[id]->value_ += money;
}

double Bank::deleteAccount(const id_t id) {
  auto it = this->accounts_.find(id);
  if (it == this->accounts_.end()) {
    throw std::invalid_argument("Index doesn't exist");
  }
  auto money_left = it->second->getValue();
  this->accounts_.erase(it);
  return money_left;
}

const Bank::account_ptr_t& Bank::operator[](const id_t idx) const {
  auto it = this->accounts_.find(idx);
  if (it == this->accounts_.end()) {
    throw std::invalid_argument("Index doesn't exist.");
  }
  return it->second;
}

std::ostream& operator<<(std::ostream& os, const Bank& obj) {
  os << "Bank informations: " << std::endl;
  os << "Bank liquidity: " << obj.getLiquidity() << std::endl;
  const auto& accounts = obj.getAccounts();
  for (const auto& account : accounts) {
    os << *account.second << std::endl;
  }
  return os;
}
