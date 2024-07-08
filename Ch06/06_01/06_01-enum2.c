#include <stdio.h>

int main()
{
    enum {ALPHA=1,BETA,GAMMA};
    int test;

    printf("Which test is this? (1-3): ");
    scanf("%d",&test);

    switch(test)
    {
        case ALPHA:
            puts("Alpha test");
            break;
        case BETA:
            puts("Beta test");
            break;
        case GAMMA:
            puts("Gamma test/release");
            break;
        default:
            puts("Unknown test number");
    }

    return(0);
}
