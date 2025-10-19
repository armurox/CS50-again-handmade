#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"
#include "credit_helper.h"

int main(void)
{
    // Get number from user
    long number = get_long("Number: ");
    char *card_type = credit_card_type(number);
    // Print credit_card_type
    printf("%s\n", card_type);
    free(card_type);
}
