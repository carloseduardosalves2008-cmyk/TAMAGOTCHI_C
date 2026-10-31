#include "computacao.h"

int sorteio (int limit1, int limit2)
{
    srand(time(NULL));

    int num = rand()%limit1+limit2;

    return num;
}
int lojafunction (Color cor_fundo, Color cor_quadro, Music musica,GuardaRoupa *acessorios, int *moedas)
{
    Texture2D coin = LoadTexture("coin.png");
    Texture2D x = LoadTexture("X.png");
    Rectangle xbutton = {55,50,64,64};

    int espaco = 24;
    int colunas = 3;
    int linhas = 2;
    int tamanhodatela = 720;
    int blocotamanho = 128;

    int x0 = ((tamanhodatela-(colunas*blocotamanho))-((colunas-1)*espaco))/2;
    int x1 = x0+blocotamanho+espaco;
    int x2 = x0+2*(blocotamanho+espaco);

    int y0 = ((tamanhodatela-(linhas*blocotamanho))-((linhas-1)*espaco))/2;
    int y1 = y0+blocotamanho+espaco;

    int x0roupa = x0+(blocotamanho-96)/2;
    int x1roupa = x1+(blocotamanho-96)/2;
    int x2roupa = x2+(blocotamanho-85)/2;
    int y01roupa = y0+(blocotamanho-96-16)/2;
    int y2roupa = y0+(blocotamanho-35)/2;

    int ytexto = y01roupa+96;
    int x0texto = x0roupa+32-10;
    int x1texto = x1roupa+32-10;
    int x2texto = x2roupa+32-10;

    int IndiceRoupaEmUso=-1;
    int c=0;

    Rectangle button1 = {x0,y0,96,96};
    Rectangle button2 = {x1,y0,96,96};
    Rectangle button3 = {x2,y0,96,96};
    Rectangle button4 = {x0,y1,96,96};
    Rectangle button5 = {x1,y1,96,96};
    Rectangle button6 = {x2,y1,96,96};

    Rectangle equipar0 = {x0roupa-12,ytexto-4,6*20,25};
    Rectangle equipar1 = {x1roupa-12,ytexto-4,6*20,25};
    Rectangle equipar2 = {x2roupa-10,ytexto-4,6*20,25};

    while (1)
    {
        UpdateMusicStream(musica);
        Vector2 mouseposi = GetMousePosition();//EXTRAI A POSIÇÃO DO MOUSE EM VECTOR 2 (X,Y)
        bool mousesobrebotaoX = CheckCollisionPointRec(mouseposi,xbutton);
        bool mousesobreroupa1 = CheckCollisionPointRec(mouseposi,button1);
        bool mousesobreroupa2 = CheckCollisionPointRec(mouseposi,button2);
        bool mousesobreroupa3 = CheckCollisionPointRec(mouseposi,button3);
        bool mousesobreroupa4 = CheckCollisionPointRec(mouseposi,button4);
        bool mousesobreroupa5 = CheckCollisionPointRec(mouseposi,button5);
        bool mousesobreroupa6 = CheckCollisionPointRec(mouseposi,button6);
        bool mousesobreequipar0;
        bool mousesobreequipar1;
        bool mousesobreequipar2;

        BeginDrawing();
        ClearBackground(cor_fundo);
        DrawTexture(x,55,50,WHITE);
        DrawText("LOJA",(tamanhodatela/2)-(MeasureText("LOJA",50)/2),50,50,WHITE);

        if (mousesobrebotaoX && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){break;}
        if (WindowShouldClose()){break;}

        DrawRectangle(x0,y0,blocotamanho,blocotamanho,cor_quadro);
        DrawRectangle(x1,y0,blocotamanho,blocotamanho,cor_quadro);
        DrawRectangle(x2,y0,blocotamanho,blocotamanho,cor_quadro);

        DrawRectangle(x0,y1,blocotamanho,blocotamanho,cor_quadro);
        DrawRectangle(x1,y1,blocotamanho,blocotamanho,cor_quadro);
        DrawRectangle(x2,y1,blocotamanho,blocotamanho,cor_quadro);

        DrawTexture(acessorios[0].textura,x0roupa,y01roupa,WHITE);
        DrawTexture(acessorios[1].textura,x1roupa,y01roupa,WHITE);
        DrawTexture(acessorios[2].textura,x2roupa,y2roupa,WHITE);

        if (!acessorios[0].tem)
        {
            DrawText(TextFormat("%d",acessorios[0].price),x0texto,ytexto,20,WHITE);
            DrawTexture(coin,x0roupa+48+10,ytexto,WHITE);
        }
        else if (!acessorios[0].emuso)
        {
            DrawRectangle(x0roupa-12,ytexto-4,6*20,25,cor_fundo);
            DrawText("EQUIPAR?",x0roupa,ytexto,20,WHITE);
            mousesobreequipar0 = CheckCollisionPointRec(mouseposi,equipar0);
            if (mousesobreequipar0 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                for (c=0;c<=6;c++)
                {
                    if (acessorios[c].emuso){acessorios[c].emuso=false;}
                }
                acessorios[0].emuso=true;
            }
        }
        else
        {
            DrawRectangle(x0roupa-12,ytexto-4,6*20,25,cor_fundo);
            DrawText("EQUIPADO",x0roupa,ytexto,20,WHITE);
        }



        if (!acessorios[1].tem)
        {
            DrawText(TextFormat("%d",acessorios[1].price),x1roupa+32-10,ytexto,20,WHITE);
            DrawTexture(coin,x1roupa+48+10,ytexto,WHITE);
        }
        else if (!acessorios[1].emuso)
        {
            DrawRectangle(x1roupa-12,ytexto-4,6*20,25,cor_fundo);
            DrawText("EQUIPAR?",x1roupa,ytexto,20,WHITE);
            mousesobreequipar1 = CheckCollisionPointRec(mouseposi,equipar1);
            if (mousesobreequipar1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                for (c=0;c<=6;c++)
                {
                    if (acessorios[c].emuso){acessorios[c].emuso=false;}
                }
                acessorios[1].emuso=true;
            }
        }
        else
        {
            DrawRectangle(x1roupa-12,ytexto-4,6*20,25,cor_fundo);
            DrawText("EQUIPADO",x1roupa,ytexto,20,WHITE);
        }



        if (!acessorios[2].tem)
        {
            DrawText(TextFormat("%d",acessorios[2].price),x2roupa+32-10,ytexto,20,WHITE);
            DrawTexture(coin,x2roupa+48+10,ytexto,WHITE);
        }
        else if (!acessorios[2].emuso)
        {
            DrawRectangle(x2roupa-17,ytexto-4,6*20,25,cor_fundo);
            DrawText("EQUIPAR?",x2roupa-7,ytexto,20,WHITE);
            mousesobreequipar2 = CheckCollisionPointRec(mouseposi,equipar2);
            if (mousesobreequipar2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                for (c=0;c<=6;c++)
                {
                    if (acessorios[c].emuso){acessorios[c].emuso=false;}
                }
                acessorios[2].emuso=true;
            }
        }
        else
        {
            DrawRectangle(x2roupa-17,ytexto-4,6*20,25,cor_fundo);
            DrawText("EQUIPADO",x2roupa-7,ytexto,20,WHITE);
        }


        if (!acessorios[0].tem && mousesobreroupa1 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (*moedas>=acessorios[0].price)
            {
                *moedas-=acessorios[0].price;
                acessorios[0].tem=true;
            }
        }
        else if (!acessorios[1].tem &&mousesobreroupa2 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (*moedas>=acessorios[1].price)
            {
                *moedas-=acessorios[1].price;
                acessorios[1].tem=true;
            }
        }
        else if (!acessorios[2].tem &&mousesobreroupa3 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            if (*moedas>=acessorios[2].price)
            {
                *moedas-=acessorios[2].price;
                acessorios[2].tem=true;
            }
        }

        EndDrawing();
    }
    UnloadTexture(coin);
    UnloadTexture(x);
    for (c=0;c<=6;c++)
    {
        if (acessorios[c].emuso){IndiceRoupaEmUso=c; break;}
    }
    return IndiceRoupaEmUso;
}
