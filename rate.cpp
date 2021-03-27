#include "rate.h"
#include <string>

int rate(std::string currency, bool buy)
{
    std::string curr_names[7] = {"USD", "EUR", "CHF", "GBP", "AUD", "CAD", "CZK"};
    int sell_rates[7] = {39740, 46892, 42400, 54520, 30137, 31496, 1788};
    int buying_rates[7] = {38954, 45964, 41560, 53440, 29541, 30872, 1752};

    int rate = -1;
    for(int i = 0; i < 7; ++i)
    {
        if(currency == curr_names[i])
        {
            if(buy) rate = buying_rates[i];
            else rate = sell_rates[i];
            break;
        }
    }
    return rate;
}