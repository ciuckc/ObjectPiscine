#pragma once

#include <cstdint>
#include <iostream>

class Car {
 public:
  void start() {
    if (!_is_started) {
      _is_started = true;
      std::cout << "Car was started!\n";
    }
  }

  void stop() {
    if (_is_started) {
      _is_started = false;
      std::cout << "Car was stopped!\n";
    }
  }

  void accelerate(int speed) {
    if (!_is_started) {
      std::cout << "Car is not started!\n";
      return;
    }
    _current_speed += speed;
    std::cout << "Car is rolling at " << _current_speed << " km/h!\n";
  }

  void shift_gears_up() {
    switch (_current_gear) {
      case Transmission::kOff:
        _current_gear = Transmission::kFirst;
        break;
      case Transmission::kFirst:
        _current_gear = Transmission::kSecond;
        break;
      case Transmission::kSecond:
        _current_gear = Transmission::kThird;
        break;
      case Transmission::kThird:
        _current_gear = Transmission::kFourth;
        break;
      case Transmission::kFourth:
        std::cout << "Can't switch higher!\n";
        break;
      default:
        std::cout << "error switching gears";
        return;
    }
  }

  void shift_gears_down() {
    switch (_current_gear) {
      case Transmission::kReverse:
        _current_gear = Transmission::kOff;
        break;
      case Transmission::kOff:
        break;
      case Transmission::kFirst:
        _current_gear = Transmission::kOff;
        break;
      case Transmission::kSecond:
        _current_gear = Transmission::kFirst;
        break;
      case Transmission::kThird:
        _current_gear = Transmission::kSecond;
        break;
      case Transmission::kFourth:
        _current_gear = Transmission::kThird;
        break;
      default:
        std::cout << "error switching gears\n";
        return;
    }
    std::cout << "Gears were shifted up!\n";
  }

  void reverse() {
    _current_gear = Transmission::kReverse;
    std::cout << "Gearbox set to reverse!\n";
  }

  void turn_wheel(double angle) {
    if (_current_angle + angle > kMaxWheelAngleTurn || _current_angle + angle < -kMaxWheelAngleTurn) {
      std::cout << "Wheel can't be turned more or less than " << kMaxWheelAngleTurn << "\n";
    }
    _current_angle += angle;
    std::cout << "Wheel was turned " << angle << " degrees!\n";
  }

  void straighten_wheels() {
    _current_angle = 0;
    std::cout << "Wheels are straight!\n";
  }

  void apply_force_on_brakes(double force) {
    if (force < 0.0) {
      std::cout << "Can't apply negative force!\n";
      return;
    }
    _break_pressure += force;
    std::cout << "Pressing the break with this force: " << force << "!\n";
  }

  void apply_emergency_brakes() {
    _current_speed = 0;
    std::cout << "Emergency brakes! Current speed is 0!\n";
  }

 private:
  bool _is_started{false};
  int _current_speed{0};
  enum class Transmission : unsigned int {
    kReverse = 0,
    kOff,
    kFirst,
    kSecond,
    kThird,
    kFourth
  } _current_gear{Transmission::kOff};
  double _current_angle{};
  static constexpr double kMaxWheelAngleTurn{40};
  double _break_pressure{0};
};
