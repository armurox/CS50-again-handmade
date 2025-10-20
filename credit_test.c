#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "credit_helper.h"
#include "credit_test.h"

void test_number_of_digits(void)
{
    assert(number_of_digits(12345l) == 5);
    assert(number_of_digits(12345678l) == 8);
    assert(number_of_digits(000000) == 0);
    assert(number_of_digits(4000000) == 7);
    assert(number_of_digits(5555555555554444) == 16);
}

void test_is_valid_card(void)
{
    assert(is_valid_card(4003600000000014) == 1);
    assert(is_valid_card(4003600000000013) == 0);
}

void test_credit_card_type(void)
{
    assert(strcmp(credit_card_type(4003600000000014), "VISA") == 0);
    assert(strcmp(credit_card_type(378282246310005), "AMEX") == 0);
    assert(strcmp(credit_card_type(5555555555554444), "MASTERCARD") == 0);
    assert(strcmp(credit_card_type(555555555554444), "INVALID") == 0);

}


int main(void)
{
    test_number_of_digits();
    test_is_valid_card();
    test_credit_card_type();
}
