#include <iostream>
#include <string>

#include "money.h"

int main()
{

    //Money money(10000, 32.03, 23);
    Money money("10gp 46sp 3cp");
    money.print();

    return 0;
}
