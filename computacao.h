#ifndef COMPUTACAO_H_INCLUDED
#define COMPUTACAO_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <raylib.h>

typedef struct guardaroupaestado
{
    int price;
    bool tem;
    bool emuso;
    Texture2D textura;
    Texture2D textura_maior;

}GuardaRoupa;

int sorteio (int limit1, int limit2);
int lojafunction (Color cor_fundo, Color cor_quadro, Music musica,GuardaRoupa *acessorios, int *moedas);

#endif // COMPUTACAO_H_INCLUDED
