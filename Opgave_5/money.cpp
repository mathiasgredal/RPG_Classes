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

void Money::print()
{
    long gold = floor(m_bronzePieces / 10000.);
    long silver = floor((m_bronzePieces % 10000) / 100.);
    long bronze = m_bronzePieces - gold * 10000 - silver * 100;

    std::cout << gold << "gp " << silver << "sp " << bronze << "cp" << std::endl;
}
