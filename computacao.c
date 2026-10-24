#include "computacao.h"

int sorteio (int limit1, int limit2)
{
    srand(time(NULL));

    int num = rand()%limit1+limit2;

    return num;
}
