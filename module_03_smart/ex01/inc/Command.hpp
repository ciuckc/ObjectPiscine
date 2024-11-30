#pragma once

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <string>
#include <utility>

class Command {
 public:
  using TotalPrice = std::size_t;
  using Quantity = std::size_t;
  using Price = std::size_t;
  using Articles = std::pair<Quantity, Price>;

 public:
  Command(std::chrono::year_month_day date, uint32_t id, std::string client)
      : _date{date}, _id{id}, _client{client} {}

  void add_articles(Quantity article_quantity, Price article_price) {
    _articles.push_back(std::make_pair(article_quantity, article_price));
  }

  TotalPrice GetTotalPrice() const {
    TotalPrice total = 0;
    for (auto article : _articles) {
      total += article.first * article.second;
    }
    return total;
  }

  std::chrono::year_month_day get_date() const { return _date; }

 private:
  uint32_t _id{};
  std::chrono::year_month_day _date{};
  std::string _client{};
  std::vector<Articles> _articles{};
};
