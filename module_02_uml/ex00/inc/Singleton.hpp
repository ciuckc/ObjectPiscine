#pragma once

template <typename T>
class Singleton {
 public:
  Singleton(const Singleton&) noexcept = delete;
  Singleton(const Singleton&&) noexcept = delete;
  Singleton& operator=(const Singleton&) noexcept = delete;
  Singleton& operator=(Singleton&&) noexcept = delete;

  static Singleton& getInstance() { static T* instance = new T{}; }

 protected:
  Singleton() noexcept = default;
  ~Singleton() noexcept = default;
};
