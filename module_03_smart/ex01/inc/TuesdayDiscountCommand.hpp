#pragma once

#include <chrono>

#include "Command.hpp"
#include "IDiscountedPrice.hpp"

class TuesdayDiscountCommand : public Command, IDiscountedPrice {
 public:
  TuesdayDiscountCommand(const Command& command) : Command(command) {}

  TuesdayDiscountCommand(std::chrono::year_month_day date, uint32_t id, std::string client)
      : Command(date, id, client){};

  TuesdayDiscountCommand(const TuesdayDiscountCommand&) = default;

  TuesdayDiscountCommand(TuesdayDiscountCommand&&) = default;

  TuesdayDiscountCommand& operator=(const TuesdayDiscountCommand&) = default;

  TuesdayDiscountCommand& operator=(TuesdayDiscountCommand&&) = default;

  TotalPrice GetDiscountedPrice() const {
    auto is_tuesday = [](std::chrono::year_month_day ymd) {
      std::chrono::sys_days date = ymd;
      std::chrono::weekday weekday = date;
      return weekday == std::chrono::Tuesday;
    };
    auto total = GetTotalPrice();
    return is_tuesday(get_date()) ? total - (total * 0.1) : total;
  };

 private:
};
