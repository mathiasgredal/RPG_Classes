#include <iostream>
#include <string>

#include "character.h"
#include "equipment.h"
#include "shop.h"

int main()
{
    // Create shop with test equipment
    Shop shop;
    for (const auto& equipment : testEquipment())
        shop.AddEquipment(equipment);

    // Create test character with 100$ of money on the balance
    //Character character("Bob", 100);

    // Create test character with 0$ of money on the balance
    //Character character("PoorBob", 0);

    // Create test character with 0 kg max load
    Character character("PoorBob", 100, 0);

    std::string inputCommand;

    do {
        std::cout << "\n> ";
        std::cin >> inputCommand;
        std::cin.get();

        if (inputCommand == "print_shop")
            shop.print();
        else if (inputCommand == "print_character")
            character.print();
        else if (inputCommand == "add_allowed")
            shop.AddCustomer(character, true);
        else if (inputCommand == "add_notallowed")
            shop.AddCustomer(character, false);
        else if (inputCommand == "buy_equipment") {
            std::string equipmentIndex;
            std::cin >> equipmentIndex;
            shop.BuyEquipment(character, std::stoi(equipmentIndex));
        } else
            std::cout << "Command not found try again";

    } while (inputCommand != "quit");

    return 0;
}
