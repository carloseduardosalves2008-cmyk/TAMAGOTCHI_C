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

void DrawButton (Texture2D Button_press, Texture2D Button, int x, int y, bool* button_press)
{
    if (*button_press){DrawTexture(Button_press,x,y,WHITE); *button_press=false;}
    else {DrawTexture(Button,x,y,WHITE);}
}
