#include <chrono>
#include <iostream>

#include "PackageReductionDiscountCommand.hpp"
#include "TuesdayDiscountCommand.hpp"

int main() {
  {
    PackageReductionDiscountCommand package_reduction_discount = {
        std::chrono::day(29) / std::chrono::April / 2024, (unsigned int)(0), "Robert"};

    package_reduction_discount.add_articles(10, 25);

    std::cout << "Command price: " << package_reduction_discount.GetTotalPrice()
              << ", command with 10 euros discount: " << package_reduction_discount.GetDiscountedPrice()
              << "\n";

    TuesdayDiscountCommand tuesday_discount_command = {std::chrono::day(30) / std::chrono::April / 2024,
                                                       (unsigned int)(1), "Jake"};

    tuesday_discount_command.add_articles(15, 10);

    std::cout << "Command price: " << tuesday_discount_command.GetTotalPrice()
              << ", command with tuesday discount: " << tuesday_discount_command.GetDiscountedPrice()
              << "\n\n";
  }
  {
    PackageReductionDiscountCommand package_reduction_discount = {
        std::chrono::day(29) / std::chrono::April / 2024, (unsigned int)(0), "Robert"};

    package_reduction_discount.add_articles(10, 14);

    std::cout << "Command price: " << package_reduction_discount.GetTotalPrice()
              << ", command with 10 euros discount: " << package_reduction_discount.GetDiscountedPrice()
              << "\n"
              << "Command is less than 150 euros.\n";

    TuesdayDiscountCommand tuesday_discount_command = {std::chrono::day(14) / std::chrono::April / 2024,
                                                       (unsigned int)(1), "Jake"};

    tuesday_discount_command.add_articles(25, 5);

    std::cout << "Command price: " << tuesday_discount_command.GetTotalPrice()
              << ", command with tuesday discount: " << tuesday_discount_command.GetDiscountedPrice() << "\n"
              << "Command is not placed on a Tuesday.\n";
  }
}
