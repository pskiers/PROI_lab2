#include "calculate.h"
#include <iostream>
#include <string>

void calculate_and_print(int amount, int rate, std::string currency)
{
    int result = amount * rate;
    int zloty = result / 1000000;
    int grosz = (result % 1000000) / 10000;
    if((result - zloty*1000000 - grosz*10000) >= 5000) grosz++;
    int small_ones = amount%100;
    std::string filler = "";
    if(small_ones < 10) filler = "0";
    std::cout<<amount/100<<","<<filler<<small_ones<<" "<<currency<<" za "<<zloty<<" złotych "<<grosz<<" groszy po kursie "<<rate<<"\n"; // message written in Polish because it is supposed to be a Polish currency exchange
}