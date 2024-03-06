#include <iostream>
#include <ostream>

#include "Bank.hpp"

int main() {
  Bank ing_bank(2000);

  const auto& new_acc = ing_bank.createAccount(300);
  const auto& another_acc = ing_bank.createAccount(103);

  std::cout << *new_acc << std::endl;
  std::cout << *another_acc << std::endl;

  try {
    ing_bank.depositMoney(0, 100);
  } catch (const std::exception& e) {
    std::cerr << "Tried to deposit in inexistent account: " << e.what() << std::endl;
  }

  try {
    ing_bank.depositMoney(new_acc->getId(), -100);
  } catch (const std::exception& e) {
    std::cerr << "Tried to deposit negative amount: " << e.what() << std::endl;
  }
  try {
    ing_bank.depositMoney(new_acc->getId(), 500);
  } catch (const std::exception& e) {}
  try {
    ing_bank.getLoan(new_acc->getId(), 1999);
    ing_bank.getLoan(another_acc->getId(), 1);
    std::cout << "Bank liquidity: " << ing_bank.getLiquidity() << std::endl;
    ing_bank.getLoan(new_acc->getId(), 200);
  } catch (const std::exception& e) {
    std::cerr << "Tried to get loan: " << e.what() << std::endl;
  }
  std::cout << ing_bank << std::endl;
}
