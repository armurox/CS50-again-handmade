#include <stdio.h>
#include <stdlib.h>
#include "cs50.h"

// Internal usage only
void flush_stdin(void)
{
    char c;
    while ((c = getchar()) != EOF && c != '\n');
}

int get_int(string prompt)
{
    int input;
    int start = 1;
    do
    {
        printf("%s", prompt);
        if (!start)
            flush_stdin();
        start = 0;
    } while (scanf("%d", &input) == 0);

    return input;
}

long get_long(string prompt)
{
    long input;
    int start = 1;
    do
    {
        printf("%s", prompt);
        if (!start)
            flush_stdin();
        start = 0;
    } while (scanf("%ld", &input) == 0);

    return input;
}

float get_float(string prompt)
{
    float input;
    int start = 1;
    do
    {
        printf("%s", prompt);
        if (!start)
            flush_stdin();
        start = 0;
    } while (scanf("%f", &input) == 0);

    return input;
}

double get_double(string prompt)
{
    double input;
    int start = 1;
    do
    {
        printf("%s", prompt);
        if (!start)
            flush_stdin();
        start = 0;
    } while (scanf("%lf", &input) == 0);

    return input;
}


string get_string(string prompt)
{
    char *input = malloc(1024);
    do
    {
        printf("%s", prompt);
        
    } while (scanf("%[^\n]", input) == 0);
    return input;     
}
