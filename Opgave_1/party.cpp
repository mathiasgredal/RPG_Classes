#include "party.h"

Party::Party()
{
    characters.push_back({ "Bob", 5, 2 });
    characters.push_back({ "John", 2, 2 });
    characters.push_back({ "Doris", 8, 5 });
}

void Party::read_names()
{
    // Print Add names for the party members.
    // Press enter when adding a new name.
    // when finished writing names, just add the name "end"

    std::cout << "Add the names for the party members" << std::endl;

    std::string inputName = "";
    std::vector<std::string> inputNames;

    do {
        std::cout << "\t- ";
        getline(std::cin, inputName);
        if (inputName != "\0") {
            characters.push_back({ inputName, 0, 0 });
            inputNames.push_back(inputName);
        }
        std::cout << std::endl;
    } while (inputName != "\0");

    std::cout << "Added the following names to the party list: ";
    for (const auto& name : inputNames) {
        std::cout << name << ", ";
    }
    std::cout << std::endl;
}

void Party::read_xp_level()
{
    // Print Add XP and Lvl for each party member
    // Press enter to use the existing values for the member
    // Write XP first and lvl second, seperate the values by comma.

    std::cout << "Add XP and Lvl for each party member" << std::endl;

    std::string inputString = "";

    for (Character& character : characters) {
    // I know this is bad code soory
    begin:

        std::cout << "\t- ";
        getline(std::cin, inputString);
        if (inputString != "\0") {
            // Now we need to split the string by the delimiter ',' and remove whitespace
            // Then we have to parse the 2 strings into ints.
            // If it fails we should print only ints and retry input for that character

            int delimiterPos = inputString.find(',');

            std::string xpString = inputString.substr(0, delimiterPos);
            std::string levelString = inputString.substr(delimiterPos + 1);

            boost::trim(xpString);
            boost::trim(levelString);

            int xp;
            int lvl;

            try {
                xp = std::stoi(xpString);
                lvl = std::stoi(levelString);
            } catch (...) {
                std::cout << "ERROR: You are only allowed to input numbers" << std::endl;
                goto begin; // SOORRRRYYYY
            }

            character.xp = xp;
            character.level = lvl;
        }
        std::cout << std::endl;
    }
}

void Party::print()
{
    std::cout << "##### CHARACTERS #####" << std::endl;
    for (const Character& character : characters) {
        std::cout << "- " << character.name
                  << " has " << character.xp
                  << " and level " << character.level << std::endl;
    }
    std::cout << "######################" << std::endl;
}

void Party::sort()
{
    std::sort(characters.begin(), characters.end(), [](Character rhs, Character lhs) {
        boost::algorithm::to_lower(rhs.name);
        boost::algorithm::to_lower(lhs.name);
        return rhs.name < lhs.name;
    });
}
