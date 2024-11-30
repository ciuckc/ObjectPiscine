#pragma once

#include "Command.hpp"
#include "IDiscountedPrice.hpp"

class PackageReductionDiscountCommand : public Command, IDiscountedPrice {
 public:
  PackageReductionDiscountCommand(const Command& command) : Command(command) {}

  PackageReductionDiscountCommand(std::chrono::year_month_day date, uint32_t id, std::string client)
      : Command(date, id, client){};

  PackageReductionDiscountCommand(const PackageReductionDiscountCommand&) = default;

  PackageReductionDiscountCommand(PackageReductionDiscountCommand&&) = default;

  PackageReductionDiscountCommand& operator=(const PackageReductionDiscountCommand&) = default;

  PackageReductionDiscountCommand& operator=(PackageReductionDiscountCommand&&) = default;

  TotalPrice GetDiscountedPrice() const {
    auto total = GetTotalPrice();
    return total < 150 ? total : total - 10;
  }

 private:
};
