#include "car.hpp"

int main() {
  Car car{};
  car.start();
  car.shift_gears_up();
  car.accelerate(5);
  car.accelerate(5);
  car.shift_gears_up();
  car.accelerate(15);
  car.shift_gears_up();
  car.accelerate(20);
  std::cout << "Pigeon is on the road!\n";
  car.shift_gears_down();
  car.apply_force_on_brakes(10);
  car.turn_wheel(20);
  car.apply_emergency_brakes();
  car.stop();
  std::cout << "Pigeon is safe!\n";
}
