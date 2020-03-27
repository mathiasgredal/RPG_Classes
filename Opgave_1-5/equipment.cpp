#include "equipment.h"

Equipment::Equipment(std::string name, Money price, EquipmentType type, float weight, std::string description, bool ready)
{
    boost::trim(name);

    assert(("Name cannot be empty", name != ""));
    assert(("Price must be positive", price.getBronzePieces() >= 0));
    assert(("Weight must be positive", weight >= 0));

    m_name = name;
    m_price = price;
    m_type = type;
    m_weight = weight;
    m_description = description;
    m_ready = ready;
}

std::string Equipment::getName() const
{
    return m_name;
}

Money Equipment::getPrice() const
{
    return m_price;
}

EquipmentType Equipment::getType() const
{
    return m_type;
}

std::string Equipment::getTypeString() const
{
    switch (m_type) {
    case Weapon:
        return "Weapon";
    case Ammo:
        return "Ammo";
    case Armor:
        return "Armor";
    case Trinket:
        return "Trinket";
    case Consumable:
        return "Consumable";
    }
}

float Equipment::getWeight() const
{
    return m_weight;
}

std::string Equipment::getDescription() const
{
    return m_description;
}

bool Equipment::getReady() const
{
    return m_ready;
}

void Equipment::changeEquipmentReadyState()
{
    m_ready = !m_ready;
}

void Equipment::print() const
{
    std::cout << "EQUIPMENT OVERVIEW:\n";
    std::cout << "\t  Name: " << m_name << std::endl;
    std::cout << "\t  Price: " << m_price << " $\n";
    std::cout << "\t  Weight: " << m_weight << " kg\n";
    std::cout << "\t  Type: " << getTypeString() << std::endl;
    std::cout << "\t  Description: " << m_description << std::endl;
    std::cout << "\t  Ready: " << m_ready << "\n"
              << std::endl;
}

std::vector<Equipment> testEquipment()
{
    return {
        Equipment("Axe", 100, EquipmentType::Weapon, 3, "Can i axe you a question?", false),
        Equipment("Gambeson", 250, EquipmentType::Armor, 8, "Padded jacket for protection, and some warmth around the heart.", false),
        Equipment("Flaming Arrows", 10, EquipmentType::Ammo, 0.35f, "5 flaming arrows, wear protective gloves when storing them.", false),
        Equipment("Corona", 5, EquipmentType::Consumable, 0.5f, "An interesting name for a beer.", false),
        Equipment("Skullcup", 5, EquipmentType::Trinket, 0.3f, "The perfect cup for some Corona.", false)
    };
}

bool operator==(const Equipment& lhs, const Equipment& rhs)
{
    return lhs.getName() == rhs.getName() && //
        lhs.getType() == rhs.getType() && //
        lhs.getPrice() == rhs.getPrice() && //
        lhs.getReady() == rhs.getReady() && //
        lhs.getWeight() == rhs.getWeight() && //
        lhs.getDescription() == rhs.getDescription();
}
