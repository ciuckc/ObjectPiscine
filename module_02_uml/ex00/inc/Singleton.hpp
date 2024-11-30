#pragma once

template <typename T>
class Singleton {
 public:
  Singleton(const Singleton&) noexcept = delete;
  Singleton(const Singleton&&) noexcept = delete;
  Singleton& operator=(const Singleton&) noexcept = delete;
  Singleton& operator=(Singleton&&) noexcept = delete;

  static T& getInstance() {
    static T instance{};
    return instance;
  }

 protected:
  Singleton() noexcept = default;
  virtual ~Singleton() noexcept = default;
};
