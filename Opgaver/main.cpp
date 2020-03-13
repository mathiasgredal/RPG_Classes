#include "party.h"
#include <iostream>
#include <string>

int main()
{
    Party party;

    std::string inputCommand;

    do {
        std::cout << "\n> ";
        std::cin >> inputCommand;
        std::cin.get();

        if (inputCommand == "print")
            party.print();
        else if (inputCommand == "read_names")
            party.read_names();
        else if (inputCommand == "read_xp_level")
            party.read_xp_level();
        else if (inputCommand == "sort")
            party.sort();
        else
            std::cout << "Command not found try again";

    } while (inputCommand != "quit");

    return 0;
}
