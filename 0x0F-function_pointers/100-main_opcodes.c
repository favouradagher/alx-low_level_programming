#include <stdio.h>
#include <stdlib.h>

void print_opcodes(char *addr, int len)
{
    int i;
    for (i = 0; i < len - 1; i++)
        printf("%02hhx ", addr[i]);
    printf("%02hhx\n", addr[i]);
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int len = atoi(argv[1]);
    if (len < 0) {
        printf("Error\n");
        return 2;
    }

    char *ptr = (char *)main;
    print_opcodes(ptr, len);

    return 0;
}

