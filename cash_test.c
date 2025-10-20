#include <assert.h>
#include "cash_helper.h"
#include "cash_test.h"

void test_min_coins(void)
{
    assert(min_coins(25) == 1);
    assert(min_coins(70) == 4);
    assert(min_coins(75) == 3);
    assert(min_coins(10) == 1);
    assert(min_coins(5) == 1);
    assert(min_coins(1) == 1);
}


int main(void)
{
    test_min_coins();
}
