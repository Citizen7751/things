//MIT License
//Copyright (c) 2025 Citizen7751

#include <stdio.h>
#include <math.h>

typedef struct {
    int n;
    char word[11];
} Condition;

//---------------------------------------
//---------- Configurable part ----------
const int BEGIN = 100;
const int END = 1;
const int PACE = -2;

const Condition conditions[] = {
    {3, "Fizz"},
    {5, "Buzz"},
    {7, "Bazz"},
};
//---------------------------------------
//---------------------------------------

int check_conditions_on(const int i) {
    int is_divisible = 0;
    for (unsigned long long ci = 0; ci < sizeof(conditions)/sizeof(conditions[0]); ci++)
        if (i % conditions[ci].n == 0) {
            is_divisible = 1;
            printf("%s", conditions[ci].word);
        }
    return is_divisible;
}

void FizzBuzz() {
    for (int i = BEGIN; i != END+(PACE/abs(PACE)); i+= PACE) {
        if (!check_conditions_on(i)) printf("%d", i);
        putchar('\n');
    }
}

int main() {
    FizzBuzz();
    while(getchar()!='\n');
    return 0;
}
