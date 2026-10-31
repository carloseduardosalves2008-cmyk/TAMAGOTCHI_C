#ifndef EXIBICAO_H_INCLUDED
#define EXIBICAO_H_INCLUDED
#include <string.h>
#include <raylib.h>
#include "computacao.h"

void DrawPet(Texture2D Pet, Color cor_detalhes);
void DrawPetLose(Texture2D Pet, Color cor_detalhes);
void DrawPetLifeBar(Texture2D hearts, Texture2D black_hearts, int barra_x, int barra_y, int heart_status, int heart_max);
void DrawButton (Texture2D Button_press, Texture2D Button, int x, int y, bool* button_press,float *tempo_botao);
void DrawCoin (Texture2D Coin, int moedas);
void DrawAccessories (GuardaRoupa *acessorios, int indice);

#endif // EXIBICAO_H_INCLUDED
