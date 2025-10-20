#include <stdio.h>
#include "cs50.h"
#include "cash_helper.h"

int main(void)
{
    // Get change from user
    int change = get_change();

    // Get minimum number of coins for that change
    printf("%d\n", min_coins(change));

}
