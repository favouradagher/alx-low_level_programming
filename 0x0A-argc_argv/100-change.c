#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int coins[] = {25, 10, 5, 2, 1};
    int num_coins = 5;
    int total_cents, remaining_cents, num_each_coin = 0, i;

    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    total_cents = atoi(argv[1]);

    if (total_cents < 0) {
        printf("0\n");
        return 0;
    }

    remaining_cents = total_cents;

    for (i = 0; i < num_coins; i++) {
        num_each_coin += remaining_cents / coins[i];
        remaining_cents %= coins[i];
    }

    printf("%d\n", num_each_coin);

    return 0;
}


