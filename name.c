#include <stdio.h>
#include "cs50.h"

int main(void)
{
    string s = get_string("What is your name?: ");
    printf("Your name is %s\n", s);
}
