#include <stdlib.h>
#include <string.h>
#include "credit_helper.h"


int number_of_digits(long number)
{
    int num_digits = 0;
    while (number)
    {
        number /= 10;
        num_digits++;
    }
    return num_digits;
}

char *credit_card_type(long number)
{
    // First, check if valid credit card
    char *card_type = calloc(11, sizeof(char));
    if (!is_valid_card(number))
    {
        strcpy(card_type, "INVALID");
        return card_type;
    }

    // Compute card type
    int num_digits = number_of_digits(number);
    if (num_digits == 16 && ((number / (long) 1e14 >= 51) && (number / (long) 1e14) <= 55))
        strcpy(card_type, "MASTERCARD");
    else if (num_digits == 15 && (number / (long) 1e13 == 34 || number / (long) 1e13 == 37))
        strcpy(card_type, "AMEX");
    else if (num_digits == 13 && number / (long) 1e12 == 4)
        strcpy(card_type, "VISA");
    else if (num_digits == 16 && number / (long) 1e15 == 4)
        strcpy(card_type, "VISA");
    // If card type is not one of the above, then it is invalid
    else
        strcpy(card_type, "INVALID");

    return card_type;
}

int is_valid_card(long number)
{
    // Run Luhn's algorithm
    int secondary_digit_sum = 0;
    long temp_number = number / 10;
    while (temp_number)
    {
        if (2 * (temp_number % 10) > 9)       
            secondary_digit_sum += (2 * (temp_number % 10)) % 10 + (2 * (temp_number % 10)) / 10; // Add only digits
        else
            secondary_digit_sum += 2 * (temp_number % 10);
        temp_number /= 100;
    }

    // Step 2 - Non secondary digit sum
    int non_secondary_digit_sum = 0;
    long temp_number_1 = number;
    while (temp_number_1)
    {
        non_secondary_digit_sum += temp_number_1 % 10;
        temp_number_1 /= 100;
    }

    // Step 3, compute total and determine if last digit is 0
    return (non_secondary_digit_sum + secondary_digit_sum) % 10 == 0;
}
