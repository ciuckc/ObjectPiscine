#include <iostream>

#include "Hammer.hpp"
#include "Shovel.hpp"
#include "Worker.hpp"
#include "Workshop.hpp"

// Dependecy
// One object is dependent of another if the parameter variable or local variable
// of a method is the independent object

int main() {
  // Composition
  // One object is composed of another; the lifetime of the contained object is
  // tied to the parent object
  std::cout << "Composition starts here:\n";
  {
    Worker good_worker{};

    std::cout << good_worker;
    {
      std::cout << "The composition relationship ties the"
                << " contained members lifetime to the parents object lifetime.\n";
    }
  }
  // Aggregation
  //
  std::cout << "\nAggregation starts here:\n";
  {
    Shovel shovel{};
    Shovel* shovel_ptr{&shovel};
    Worker good_worker{"Goodie"};
    Worker bad_worker{"Baddie"};

    std::cout << '\n';
    good_worker.giveTool(shovel_ptr);
    good_worker.useTool(shovel_ptr);
    good_worker.takeTool(shovel_ptr);
    good_worker.useTool(shovel_ptr);

    good_worker.useTool(shovel_ptr);
    bad_worker.useTool(shovel_ptr);
    good_worker.giveTool(shovel_ptr);
    good_worker.useTool(shovel_ptr);
  }
  // Inherence
  std::cout << "\nInherence starts here:\n";
  {
    Worker good_worker{};
    Hammer hammer{};
    Hammer* hammer_ptr{&hammer};
    Shovel shovel{};
    Shovel* shovel_ptr{&shovel};

    good_worker.giveTool(hammer_ptr);
    good_worker.giveTool(shovel_ptr);
    good_worker.useTool(hammer_ptr);
    good_worker.useTool(shovel_ptr);
    if (auto* template_tool = good_worker.getTool<Hammer>(); hammer_ptr == template_tool) {
      std::cout << "They are the same\n";
    }
  }
  // Association
  // One object is aware of another; it contains a pointer or ref to the other
  std::cout << "\nAssociation starts here:\n";
  {
    Worker new_worker{"Pootzi"};
    Workshop<Shovel> shovel_workshop;
    Shovel shovel;

    new_worker.giveTool(&shovel);
    new_worker.subscribeToWorkshop(&shovel_workshop);
    shovel_workshop.executeWorkDay();
  }
}
