#include "money.h"

long fromGold(double goldPieces)
{
    double bronzePieces = goldPieces * 10000;

    if (fmod(bronzePieces, 1) > 0.01) {
        std::cout << "the number of goldpieces specified cannot be represented as an integer of bronzepieces" << std::endl;
        throw;
    }

    return bronzePieces;
}

long fromSilver(double silverPieces)
{
    double bronzePieces = silverPieces * 100;

    if (fmod(bronzePieces, 1) > 0.01) {
        std::cout << "the number of silverpieces specified cannot be represented as an integer of bronzepieces" << std::endl;
        throw;
    }

    return bronzePieces;
}

Money::Money(long bronzePieces, double silverPieces, double goldPieces)
{
    m_bronzePieces = bronzePieces + fromSilver(silverPieces) + fromGold(goldPieces);
}

///
/// \brief This creates a money class from a string, typically from the print function
/// \param moneyString just the string eg. 10gp 46sp 3cp
///
Money::Money(std::string moneyString)
{
    // Split string by type
    std::string goldString = moneyString.substr(0, moneyString.find("gp"));
    std::string silverString = moneyString.substr(moneyString.find("gp ") + 3, moneyString.find("sp"));
    std::string bronzeString = moneyString.substr(moneyString.find("sp ") + 3, moneyString.find("cp") - 2);

    *this = Money(stoi(bronzeString), stof(silverString), stof(goldString));

    std::cout << moneyString << " = ";
    print();
}

long Money::getBronzePieces() const
{
    return m_bronzePieces;
}

double Money::getSilverPieces() const
{
    return m_bronzePieces / 100.;
}

double Money::getGoldPieces() const
{
    return m_bronzePieces / 10000.;
}

void Money::addBronzePieces(long bronzePieces)
{
    m_bronzePieces += bronzePieces;
}

void Money::addSilverPieces(double silverPieces)
{
    m_bronzePieces += fromSilver(silverPieces);
}

void Money::addGoldPieces(double goldPieces)
{

    m_bronzePieces += fromGold(goldPieces);
}

void Money::subtractBronzePieces(long bronzePieces)
{
    m_bronzePieces -= bronzePieces;
}

void Money::subtractSilverPieces(double silverPieces)
{
    m_bronzePieces -= fromSilver(silverPieces);
}

void Money::subtractGoldPieces(double goldPieces)
{
    m_bronzePieces -= fromGold(goldPieces);
}

Money operator+(const Money& lhs, const Money& rhs)
{
    return Money(lhs.getBronzePieces() + rhs.getBronzePieces());
}

Money operator-(const Money& lhs, const Money& rhs)
{
    return Money(lhs.getBronzePieces() - rhs.getBronzePieces());
}

Money operator+=(const Money& lhs, const Money& rhs)
{
    return Money(lhs.getBronzePieces() + rhs.getBronzePieces());
}

Money operator-=(const Money& lhs, const Money& rhs)
{
    return Money(lhs.getBronzePieces() + rhs.getBronzePieces());
}

std::string Money::toString() const
{
    std::ostringstream oss;

    long gold = floor(m_bronzePieces / 10000.);
    long silver = floor((m_bronzePieces % 10000) / 100.);
    long bronze = m_bronzePieces - gold * 10000 - silver * 100;

    oss << gold << "gp " << silver << "sp " << bronze << "cp";

    return oss.str();
}

void Money::print()
{
    std::cout << toString() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Money& obj)
{
    os << obj.toString();
    return os;
}

bool operator==(const Money& lhs, const Money& rhs)
{
    return (lhs.getBronzePieces() == rhs.getBronzePieces());
}
