#include <stdio.h>
#include "cs50.h"
#include "cash_helper.h"

int get_change(void)
{
    int change;
    while((change = get_int("Change owed: ")) < 0);
    return change;
}

int min_coins(int change)
{
    const int num_of_coin_types = 4;
    int coin_values[num_of_coin_types] = {25, 10, 5, 1};
    int num_coins = 0;
    for (int i = 0; i < num_of_coin_types; i++)
    {
        // Subtract the coin value from the change
        while (change > 0)
        {
            num_coins++;
            change -= coin_values[i];
        }

        if (change == 0)
            return num_coins;
        else
        {
            change += coin_values[i];
            num_coins--;
        }
    }
    return num_coins;
}
