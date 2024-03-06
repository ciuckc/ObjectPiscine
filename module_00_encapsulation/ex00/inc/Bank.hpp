#pragma once

#include <stdint.h>
#include <sys/types.h>

#include <cstdint>
#include <memory>
#include <ostream>
#include <unordered_map>
#include <vector>

class Bank {
 public:
  class Account;
  using account_ptr_t = std::unique_ptr<Account>;
  using accounts_t = std::unordered_map<id_t, account_ptr_t>;

 public:
  Bank(const double liquidity);
  Bank() = default;
  Bank(const Bank&) = default;
  Bank& operator=(const Bank&) = default;
  ~Bank() = default;

  void depositMoney(const id_t id, const double money);
  void getLoan(const id_t id, const double money);

  const accounts_t& getAccounts() const;
  const double& getLiquidity() const;

  const account_ptr_t& createAccount(const double initial_value);
  double deleteAccount(const id_t id);

  const account_ptr_t& operator[](const id_t idx) const;

 private:
  void addLiquidity(const double value);
  double takeBankCut(const double value);
  uint32_t getUniqueAccountID() const;

  accounts_t accounts_{};
  double liquidity_{0};
};

class Bank::Account {
 public:
  friend Bank;

 public:
  Account(const double initial_value);
  Account(const Account&) = delete;
  Account(Account&&) = default;
  Account& operator=(const Account&) = delete;
  Account& operator=(Account&&) = default;
  ~Account() = default;

  const uint32_t& getId() const;
  const uint32_t& getValue() const;

 private:
  uint32_t id_{0};
  uint32_t value_{0};
};

std::ostream& operator<<(std::ostream& os, const Bank::Account& obj);

std::ostream& operator<<(std::ostream& os, const Bank& obj);
