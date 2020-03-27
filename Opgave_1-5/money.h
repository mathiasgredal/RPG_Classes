#ifndef MONEY_H
#define MONEY_H

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>

class Money {
    long m_bronzePieces = 0;

public:
    Money(long bronzePieces, double silverPieces = 0, double goldPieces = 0);
    Money(std::string moneyString);

    void print();

    // Det virker som meget kodedublikering at have alle disse funktioner som næsten gør det samme,
    long getBronzePieces() const;
    double getSilverPieces() const;
    double getGoldPieces() const;

    void addSilverPieces(double silverPieces);
    void addBronzePieces(long bronzePieces);
    void addGoldPieces(double goldPieces);

    void subtractBronzePieces(long bronzePieces);
    void subtractSilverPieces(double silverPieces);
    void subtractGoldPieces(double goldPieces);

    friend Money operator+(const Money& lhs, const Money& rhs);
    friend Money operator-(const Money& lhs, const Money& rhs);

    friend Money operator+=(const Money& lhs, const Money& rhs);
    friend Money operator-=(const Money& lhs, const Money& rhs);
};

#endif // MONEY_H
