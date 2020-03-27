#include "character.h"

Character::Character(std::string name, Money moneyBalance, float maxLoad, std::vector<Equipment> equipment, boost::uuids::uuid uuid)
{
    boost::trim(name);

    assert(("Name cannot be empty", name != ""));
    assert(("MaxLoad must be positive", maxLoad >= 0));

    m_name = name;
    m_moneyBalance = moneyBalance;
    m_maxLoad = maxLoad;
    m_equipment = equipment;
}

void Character::print()
{
    std::cout << "##### CHARACTER OVERVIEW #####\n";
    std::cout << "\t Name: " << name() << std::endl;
    std::cout << "\t Id: " << uuid() << " $\n";
    std::cout << "\t Max Load: " << maxLoad() << " kg\n";
    std::cout << "\t Current Load: " << currentLoad() << std::endl;
    std::cout << "\t Money Balance: " << moneyBalance() << std::endl;
    std::cout << "\t Equipment:" << std::endl;

    for (const auto& equipment : getEquipment()) {
        std::cout << "\t";
        equipment.print();
    }

    std::cout << "##############################" << std::endl;
}

std::string Character::name() const
{
    return m_name;
}

boost::uuids::uuid Character::uuid() const
{
    return m_uuid;
}

Money Character::moneyBalance() const
{
    return m_moneyBalance;
}

std::vector<Equipment> Character::getEquipment() const
{
    return m_equipment;
}

float Character::maxLoad() const
{
    return m_maxLoad;
}

float Character::currentLoad() const
{
    float load = 0;
    for (const auto& equipment : m_equipment)
        load += equipment.getWeight();

    return load;
}

void Character::addMoneyToBalance(Money money)
{
    m_moneyBalance += money;
}

bool afford(const Character& character, Money money)
{
    return (character.moneyBalance().getBronzePieces() - money.getBronzePieces() >= 0);
}

void Character::takeMoneyFromBalance(Money money)
{
    if (afford(*this, money))
        m_moneyBalance -= money;
    else
        std::cout << "Cant draw money because you dont have enough money!" << std::endl;
}

void Character::setMaxLoad(float maxLoad)
{
    m_maxLoad = maxLoad;
}

bool capacity(const Character& character, float extraweight)
{
    return character.currentLoad() + extraweight > character.maxLoad();
}

void Character::addEquipment(Equipment equipment)
{
    if (capacity(*this, equipment.getWeight()))
        std::cout << "Cant add equipment, because it is exceeding max weight." << std::endl;
    else
        m_equipment.push_back(equipment);
}
