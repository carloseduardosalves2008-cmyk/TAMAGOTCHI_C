#include "exibicao.h"

void DrawPet (Texture2D Pet, Color cor_detalhes)
{
    DrawRectangle(150,40,400,400,cor_detalhes);
    DrawRectangleLines(20,20,680,680,cor_detalhes);
    DrawTexture(Pet,190,80,WHITE);
}

void DrawPetLose (Texture2D Pet, Color cor_detalhes)
{
    DrawRectangle(150,80,400,400,cor_detalhes);
    DrawTexture(Pet,190,120,WHITE);
}

void DrawPetLifeBar (Texture2D hearts, Texture2D black_hearts, int barra_x, int barra_y, int heart_status, int heart_max)
{
    int qnthearts=heart_status/10;
    for (int c=0;c<qnthearts;c++)
    {
        DrawTexture(hearts,barra_x+(c*36),barra_y,WHITE);
    }

    int qntheartsmax=heart_max/10;
    for (int c=heart_status/10;c<qntheartsmax;c++)
    {
        DrawTexture(black_hearts,barra_x+(c*36),barra_y,WHITE);
    }
}

void DrawButton (Texture2D Button_press, Texture2D Button, int x, int y, bool* button_press,float *tempo_botao)
{
    if (*button_press)
    {
        if (*tempo_botao==0.0f)
        {
           *tempo_botao=GetTime();
        }

        if (GetTime()-*tempo_botao>=0.2f)
        {
            DrawTexture(Button,x,y,WHITE);
            *button_press=false;
            *tempo_botao= 0.0f;
        }

        else {DrawTexture(Button_press,x,y,WHITE);}
    }
    else {DrawTexture(Button,x,y,WHITE);}
}

void DrawCoin (Texture2D coin, int moedas)
{
    const char *textoMoedas;

    if (moedas < 1000)
    {
        textoMoedas = TextFormat("%d", moedas);
    }
    else
    {
        textoMoedas = "999+";
    }

    int xtexto = 35;
    int ytexto = 50;
    int espaco = 4;
    int largura = MeasureText(textoMoedas,30);

    DrawText(textoMoedas,xtexto,ytexto,30,WHITE);
    DrawTexture(coin,xtexto+(largura+espaco),ytexto-5,WHITE);
}
void DrawAccessories (GuardaRoupa *acessorios, int indice)
{
    switch (indice)
    {
        case 0:
        DrawTexture(acessorios[indice].textura_maior,240,125,WHITE);
        break;
        case 1:
        DrawTexture(acessorios[indice].textura_maior,283,87,WHITE);
        break;
        case 2:
        DrawTexture(acessorios[indice].textura_maior,270,200,WHITE);
        break;
        default:
        break;
    }
}
