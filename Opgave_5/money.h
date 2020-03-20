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

    long getBronzePieces() const;
    double getSilverPieces() const;
    double getGoldPieces() const;

    void addSilverPieces(double silverPieces);
    void addBronzePieces(long bronzePieces);
    void addGoldPieces(double goldPieces);
    void print();
};

#endif // MONEY_H
