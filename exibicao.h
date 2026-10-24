#ifndef EXIBICAO_H_INCLUDED
#define EXIBICAO_H_INCLUDED
#undef PlaySound
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <raylib.h>
#include <raymath.h>


void gatodesenho ();
void gatoaltavida ();
void gatobaixavida ();
void gatodormir();
void raposa ();
void rato ();
void pato ();
void barradevida (int vida_atual, int vida_max, char nomebarra[]);
void desenharjogo (int felicidade, int felicidademax,int fome, int fomemax);
void gatomorrer();
void encerramento (int segtot);

#endif // EXIBICAO_H_INCLUDED
