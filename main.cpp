#include <iostream>
#include "rate.h"
#include "calculate.h"
#include <string>
#include <limits>

int main() // all comunicates shown to the user are written in Polish since this is supposed to be a currency exchange in Poland
{
    bool run = true;
    std::string av_curr = "Obecnie prowadzimy handel następującymi walutami: USD, EUR, CHF, GBP, AUD, CAD, CZK\n",
    help_info = "Jeśli chcesz kupić walutę wpisz 'kup'\nJeśli chcesz sprzedać walutę wpisz 'sprzedaj'\nAby wyjść z kantoru wpisz 'exit'\n";
    std::cout<<"Witaj w kantorze!\nMożesz tu kupić lub sprzedać obcą walutę\n"<<av_curr;
    while (run)
    {
        std::cout<<help_info;
        std::string inp_msg;
        std::cin>>inp_msg;
        if(inp_msg == "sprzedaj" || inp_msg == "kup")
        {
            std::string currency;
            int am_big_ones, am_small_ones;
            if(inp_msg == "sprzedaj")std::cout<<av_curr<<"Jaką walutę chcesz sprzedać?\n";
            else std::cout<<av_curr<<"Jaką walutę chcesz kupić?\n";
            std::cin>>currency;
            if(inp_msg == "sprzedaj")std::cout<<"Ile odpowiedników złotówki chcesz sprzedać?\n";
            else std::cout<<"Ile odpowiedników złotówki chcesz kupić?\n";
            std::cin>>am_big_ones;
            if(std::cin.fail() || am_big_ones<0)
            {
                std::cout<<"Podano niewłaściwą ilość odpwiedników złotówek\n";
                std::cin.clear();
                std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
                continue;
            }
            if(inp_msg == "sprzedaj")std::cout<<"Ile odpowiedników groszy chcesz sprzedać?\n";
            else std::cout<<"Ile odpowiedników groszy chcesz kupić?\n";
            std::cin>>am_small_ones;
            if(std::cin.fail() || am_small_ones<0)
            {
                std::cout<<"Podano niewłaściwą ilość odpwiedników groszy\n";
                std::cin.clear();
                std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
                continue;
            }
            int amount = am_big_ones * 100 + am_small_ones;
            int the_rate = rate(currency, false);
            if(the_rate == -1) // -1 was chosen as a error code to comunicate that the entered currency name is not in the array of availabe currencies
            {
                std::cout<<"Podana waluta nie jest sprzedawana w tym kantorze\n"<<av_curr;
                continue;
            }
            if(inp_msg == "sprzedaj")std::cout<<"Sprzedano ";
            else std::cout<<"Kupiono ";
            calculate_and_print(amount, the_rate, currency);
        }
        else if(inp_msg == "exit")
        {
            run = false;
        }
        else
        {
            std::cout<<"Niestety nie wpisano odpowiedniej komendy\n";
        }
    }
    return 0;
}