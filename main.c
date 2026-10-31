
#include <string.h>
#include "raylib.h"
#include "computacao.h"
#include "exibicao.h"

int main()
{
    //DECLARACAO E CONFIGURACAO DE VARIAVEIS
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(720,720,"TAMAGOTCHI EM C");
    InitAudioDevice();

    int felicidademax=100;
    int felicidade=felicidademax;
    int fomemax=100;
    int fome=fomemax;
    int barra_felicidade_x = 170;
    int barra_felicidade_y = 470;
    int barra_fome_x = 170;
    int barra_fome_y = 520;
    int moedas=0;
    int volume=-1;
    int cuidado=0;
    int tipo = sorteio(10,1);
    int mostrar=1;
    int Tamanho_Guarda_Roupa = 6;
    int IndiceRoupaEmUso=-1;

    bool botaoC_press=false;
    bool botaoF_press=false;

    GuardaRoupa acessorios[Tamanho_Guarda_Roupa];
    for (int c=0;c>Tamanho_Guarda_Roupa;c++)
    {
        acessorios[c].tem=false;
        acessorios[c].emuso=false;
    }

    acessorios[0].price = 100;
    acessorios[1].price = 500;
    acessorios[2].price = 300;

    double tempo_inicio_aviso;
    float tempo_botao=0.0f;
    char msg[100];
    char nome[11];

    Music musica = LoadMusicStream("musica.ogg");
    musica.looping=true;

    Sound som_pet;
    Sound moeda = LoadSound("coin.wav");
    Sound perder = LoadSound("perder.wav");
    Sound comer = LoadSound("comer.wav");

    Rectangle FbuttonP = { 200, 580, 96, 96 };
    Rectangle CbuttonP = { 400, 580, 96, 96 };
    Rectangle lojabutton = { 610, 30, 64, 64 };

    Texture2D pet;
    Texture2D pet_perder;
    Texture2D Fbutton;
    Texture2D Cbutton;
    Texture2D Fbutton_press;
    Texture2D Cbutton_press;
    Texture2D loja = LoadTexture("loja.png");
    Texture2D x = LoadTexture("X.png");
    Texture2D coin = LoadTexture("coin_big.png");
    Texture2D smile = LoadTexture("smile.png");
    Texture2D heart = LoadTexture("hungry.png");
    Texture2D darksmile = LoadTexture("darksmile.png");
    Texture2D darkheart = LoadTexture("darkhungry.png");

    acessorios[0].textura = LoadTexture ("Flor.png");
    acessorios[1].textura = LoadTexture ("coroaview.png");
    acessorios[2].textura = LoadTexture ("oculosview.png");

    acessorios[0].textura_maior = LoadTexture ("Flor.png");
    acessorios[1].textura_maior = LoadTexture ("coroa.png");
    acessorios[2].textura_maior = LoadTexture ("oculos.png");

    Color cor_fundo;
    Color cor_quadro;

    //LOAD TEXTURE DA INTERFACE DO JOGO DE ACORDO COM A PELAGEM DO GATO
    switch (tipo)
    {
        case 1:
        strcpy(nome,"OREO");
        pet = LoadTexture("oreo.png");
        pet_perder = LoadTexture("oreo_olho_fechado.png");
        som_pet = LoadSound("miado.wav");
        Fbutton = LoadTexture("GREENFBUTTON.png");
        Cbutton = LoadTexture("GREENCBUTTON.png");
        Fbutton_press = LoadTexture("GREENFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("GREENCBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){116,118,77,255};
        cor_quadro = CLITERAL(Color){140,142,95,255};
        break;
        case 2:
        strcpy(nome,"PANTHERA");
        pet = LoadTexture("panthera.png");
        pet_perder = LoadTexture("panthera_olho_fechado.png");
        som_pet = LoadSound("miado.wav");
        Fbutton = LoadTexture("YELLOWFBUTTON.png");
        Cbutton = LoadTexture("YELLOWCBUTTON.png");
        Fbutton_press = LoadTexture("YELLOWFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("YELLOWCBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){199,166,121,255};
        cor_quadro = CLITERAL(Color){232,196,126,255};
        break;
        case 3:
        strcpy(nome,"KITTY");
        pet = LoadTexture("kitty.png");
        pet_perder = LoadTexture("kitty_olho_fechado.png");
        som_pet = LoadSound("miado.wav");
        Fbutton = LoadTexture("PURPLEFBUTTON.png");
        Cbutton = LoadTexture("PURPLECBUTTON.png");
        Fbutton_press = LoadTexture("PURPLEFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("PURPLECBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){89,69,91,255};
        cor_quadro = CLITERAL(Color){146,127,152,255};
        break;
        case 4:
        strcpy(nome,"MILO");
        pet = LoadTexture("milo.png");
        pet_perder = LoadTexture("milo_olho_fechado.png");
        som_pet = LoadSound("miado.wav");
        Fbutton = LoadTexture("PINKFBUTTON.png");
        Cbutton = LoadTexture("PINKCBUTTON.png");
        Fbutton_press = LoadTexture("PINKFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("PINKCBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){208,143,143,255};
        cor_quadro = CLITERAL(Color){176,114,114,255};
        break;
        case 5:
        strcpy(nome,"PEPITO");
        pet = LoadTexture("pepito.png");
        pet_perder = LoadTexture("pepito_olho_fechado.png");
        som_pet = LoadSound("miado.wav");
        Fbutton = LoadTexture("BLUEFBUTTON.png");
        Cbutton = LoadTexture("BLUECBUTTON.png");
        Fbutton_press = LoadTexture("BLUEFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("BLUECBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){115,137,154,255};
        cor_quadro = CLITERAL(Color){77,92,104,255};
        break;
        case 6:
        strcpy(nome,"LEO");
        pet = LoadTexture("leo.png");
        pet_perder = LoadTexture("leo_olho_fechado.png");
        som_pet = LoadSound("latido.wav");
        Fbutton = LoadTexture("TURQUOISEFBUTTON.png");
        Cbutton = LoadTexture("TURQUOISECBUTTON.png");
        Fbutton_press = LoadTexture("TURQUOISEFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("TURQUOISECBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){106,132,123,255};
        cor_quadro = CLITERAL(Color){149,175,166,255};
        break;
        case 7:
        strcpy(nome,"ADELA");
        pet = LoadTexture("adela.png");
        pet_perder = LoadTexture("adela_olho_fechado.png");
        som_pet = LoadSound("bolhas.wav");
        Fbutton = LoadTexture("MAGENTAFBUTTON.png");
        Cbutton = LoadTexture("MAGENTACBUTTON.png");
        Fbutton_press = LoadTexture("MAGENTAFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("MAGENTACBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){99,31,94,255};
        cor_quadro = CLITERAL(Color){133,40,125,255};
        break;
        case 8:
        strcpy(nome,"COCO");
        pet = LoadTexture("coco.png");
        pet_perder = LoadTexture("coco_olho_fechado.png");
        som_pet = LoadSound("grunhido.wav");
        Fbutton = LoadTexture("OLIVEFBUTTON.png");
        Cbutton = LoadTexture("OLIVECBUTTON.png");
        Fbutton_press = LoadTexture("OLIVEFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("OLIVECBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){141,133,59,255};
        cor_quadro = CLITERAL(Color){172,165,99,255};
        break;
        case 9:
        strcpy(nome,"LULU");
        pet = LoadTexture("lulu.png");
        pet_perder = LoadTexture("lulu_olho_fechado.png");
        som_pet = LoadSound("latido.wav");
        Fbutton = LoadTexture("ANILFBUTTON.png");
        Cbutton = LoadTexture("ANILCBUTTON.png");
        Fbutton_press = LoadTexture("ANILFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("ANILCBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){51,49,92,255};
        cor_quadro = CLITERAL(Color){81,78,150,255};
        break;
        case 10:
        strcpy(nome,"PASCAL");
        pet = LoadTexture("sapo.png");
        pet_perder = LoadTexture("sapo_olho_fechado.png");
        som_pet = LoadSound("coaxar.wav");
        Fbutton = LoadTexture("ORANGEFBUTTON.png");
        Cbutton = LoadTexture("ORANGECBUTTON.png");
        Fbutton_press = LoadTexture("ORANGEFBUTTON_PRESSED.png");
        Cbutton_press = LoadTexture("ORANGECBUTTON_PRESSED.png");
        cor_fundo = CLITERAL(Color){189,119,34,255};
        cor_quadro = CLITERAL(Color){227,159,70,255};
        break;
    }

    double tempo_dano=5.0;
    double recarga_acao=2.0;

    SetSoundVolume(moeda,2.0);
    SetSoundVolume(som_pet,0.3);
    SetSoundVolume(comer,0.3);
    SetMusicVolume(musica,0.6);
    SetTargetFPS(60);

    //AVISO INICIAL
    tempo_inicio_aviso = GetTime();
    while (mostrar==1)
    {
        if (mostrar && (GetTime()-tempo_inicio_aviso>=1.0))
        {
            mostrar=0;
        }

        strcpy(msg,"-> BEM VINDO AO TAMAGOTCHI EM C! \n");
        BeginDrawing();
        ClearBackground(cor_fundo);

        DrawText(msg, 50,50,25,WHITE);

        strcpy(msg,"-> PARABENS PELO SEU GATINHO ");
        DrawText(msg,50,80,25,WHITE);

        DrawText(nome,50,120,25,WHITE);
        EndDrawing();
    }

    //LIMPEZA SE A JANELA FOR FECHADA
    if (WindowShouldClose())
    {
        UnloadTexture(pet);
        UnloadTexture(coin);
        UnloadTexture(acessorios[0].textura);
        UnloadTexture(acessorios[1].textura);
        UnloadTexture(acessorios[2].textura);
        UnloadTexture(acessorios[0].textura_maior);
        UnloadTexture(acessorios[1].textura_maior);
        UnloadTexture(acessorios[2].textura_maior);
        UnloadTexture(x);
        UnloadTexture(pet_perder);
        UnloadTexture(Fbutton);
        UnloadTexture(Cbutton);
        UnloadTexture(Fbutton_press);
        UnloadTexture(Cbutton_press);
        UnloadTexture(loja);
        UnloadTexture(heart);
        UnloadTexture(smile);
        UnloadTexture(darkheart);
        UnloadTexture(darksmile);
        UnloadSound(som_pet);
        UnloadSound(perder);
        UnloadSound(comer);
        CloseWindow();
        CloseAudioDevice();
        return 0;
    }

    //ESCOLHA DE VOLUME DA MUSICA
    while (!WindowShouldClose() && (volume<0 || volume>1))
    {
        strcpy(msg,"\n-> INFORME O VOLUME DA MUSICA DE FUNDO: \n");
        BeginDrawing();
        DrawText(msg,50,140,25,WHITE);
        strcpy(msg,"\n-> [ 0 ] - BAIXO    [ 1 ] - MEDIO \n");
        DrawText(msg,50,170,25,WHITE);
        EndDrawing();

        if (IsKeyPressed(KEY_KP_0) || IsKeyPressed(KEY_ZERO)){volume=0;}

        else if (IsKeyPressed(KEY_KP_1) || IsKeyPressed(KEY_ONE)){volume=1;}
    }

    //LIMPEZA SE A JANELA FOR FECHADA
    if (WindowShouldClose())
    {
        UnloadTexture(pet);
        UnloadTexture(coin);
        UnloadTexture(acessorios[0].textura);
        UnloadTexture(acessorios[1].textura);
        UnloadTexture(acessorios[2].textura);
        UnloadTexture(acessorios[0].textura_maior);
        UnloadTexture(acessorios[1].textura_maior);
        UnloadTexture(acessorios[2].textura_maior);
        UnloadTexture(x);
        UnloadTexture(pet_perder);
        UnloadTexture(Fbutton);
        UnloadTexture(Cbutton);
        UnloadTexture(Fbutton_press);
        UnloadTexture(Cbutton_press);
        UnloadTexture(loja);
        UnloadTexture(heart);
        UnloadTexture(smile);
        UnloadTexture(darkheart);
        UnloadTexture(darksmile);
        UnloadSound(som_pet);
        UnloadSound(perder);
        UnloadSound(comer);
        CloseWindow();
        CloseAudioDevice();
        return 0;
    }

    if (volume==0){SetMasterVolume(0.5);}
    else if (volume==1){SetMasterVolume(1.0);}

    //INICIALIZAÇÃO DE VARIAVEIS DO TIMER
    double ultimo_dano_fome = GetTime();
    double ultimo_dano_felicidade = GetTime();
    double ultimo_carinho = GetTime();
    double ultima_comida = GetTime();

    PlayMusicStream(musica);

    PlaySound(som_pet);

    //ESTRUTURA DE REPETICAO DO JOGO
    while (!WindowShouldClose() && felicidade>0 && fome>0)
    {
        Vector2 mouseposi = GetMousePosition();//EXTRAI A POSIÇÃO DO MOUSE EM VECTOR 2 (X,Y)
        bool mousesobrebotaoF = CheckCollisionPointRec(mouseposi,FbuttonP);
        bool mousesobrebotaoC = CheckCollisionPointRec(mouseposi,CbuttonP);
        bool mousesobrebotaoloja = CheckCollisionPointRec(mouseposi,lojabutton);

        double tempo_atual = GetTime();

        UpdateMusicStream(musica);

        if (cuidado>5)
        {
            cuidado=0;
            moedas+=1000;
            PlaySound(moeda);
        }

        BeginDrawing();
        ClearBackground(cor_fundo);

        //DESENHO BOTAO LOJA
        DrawTexture(loja,610,30,WHITE);

        //DESENHO MOEDAS
        DrawCoin(coin,moedas);

        //DESENHO BOTAO F
        DrawButton(Fbutton_press,Fbutton,200,580,&botaoF_press,&tempo_botao);

        //DESENHO BOTAO C
        DrawButton(Cbutton_press,Cbutton,400,580,&botaoC_press,&tempo_botao);

        //DESENHO PET E MOLDURA
        DrawPet(pet,cor_quadro);

        //DESENHO ROUPA
        DrawAccessories(acessorios,IndiceRoupaEmUso);

        //DESENHO BARRA DE FELICIDADE
        DrawPetLifeBar(smile,darksmile,barra_felicidade_x,barra_felicidade_y,felicidade,felicidademax);

        //DESENHO BARRA DE FOME
        DrawPetLifeBar(heart,darkheart,barra_fome_x,barra_fome_y,fome,fomemax);

        //LOGICA LOJA
        if (IsKeyPressed(KEY_L) || mousesobrebotaoloja && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            IndiceRoupaEmUso=lojafunction(cor_fundo,cor_quadro,musica,acessorios,&moedas);
        }


        //LOGICA DE DANO
        if (tempo_atual-ultimo_dano_felicidade>=tempo_dano)
        {
            felicidade-=10;
            ultimo_dano_felicidade=tempo_atual;
        }
        if (tempo_atual-ultimo_dano_fome>=tempo_dano)
        {
            fome-=10;
            ultimo_dano_fome=tempo_atual;
        }

        //LOGICA DE CARINHO
        if (tempo_atual-ultimo_carinho>=recarga_acao && (IsKeyPressed(KEY_C) || (mousesobrebotaoC && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))))
        {
            if (felicidade<=90)
            {
                felicidade+=10;
                ultimo_dano_felicidade=tempo_atual;
            }
            else
            {felicidade+=(felicidademax-felicidade);}

            //DESENHO BOTAO C
            botaoC_press=true;

            cuidado++;
            PlaySound(som_pet);
            ultimo_carinho=tempo_atual;
        }

        //LOGICA DE ALIMENTAÇÃO
        else if (tempo_atual-ultima_comida>=recarga_acao && (IsKeyPressed(KEY_F) || (mousesobrebotaoF && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))))
        {
            if (fome<=90)
            {
                fome+=10;
            }
            else
            {fome+=(fomemax-fome);}

            //DESENHO BOTAO F
            botaoF_press=true;

            cuidado++;
            PlaySound(comer);
            ultima_comida=tempo_atual;
        }
        EndDrawing();
    }

    //LIMPEZA SE A JANELA FOR FECHADA
    if (WindowShouldClose())
    {
        UnloadTexture(pet);
        UnloadTexture(coin);
        UnloadTexture(acessorios[0].textura);
        UnloadTexture(acessorios[1].textura);
        UnloadTexture(acessorios[2].textura);
        UnloadTexture(acessorios[0].textura_maior);
        UnloadTexture(acessorios[1].textura_maior);
        UnloadTexture(acessorios[2].textura_maior);
        UnloadTexture(x);
        UnloadTexture(pet_perder);
        UnloadTexture(Fbutton);
        UnloadTexture(Cbutton);
        UnloadTexture(Fbutton_press);
        UnloadTexture(Cbutton_press);
        UnloadTexture(loja);
        UnloadTexture(heart);
        UnloadTexture(smile);
        UnloadTexture(darkheart);
        UnloadTexture(darksmile);
        UnloadMusicStream(musica);
        UnloadSound(som_pet);
        UnloadSound(perder);
        UnloadSound(comer);
        CloseAudioDevice();
        CloseWindow();
        return 0;
    }

    //GAME OVER
    if (felicidade==0 || fome==0)
    {
        mostrar=1;
        tempo_inicio_aviso = GetTime();
        StopMusicStream(musica);
        while (mostrar==1)
        {
            if (mostrar && (GetTime()-tempo_inicio_aviso>=3.0))
            {
                mostrar=0;
            }

            ClearBackground(cor_fundo);
            strcpy(msg,"-> SEU TAMAGOTCHI NAO FOI BEM TRATADO...\n");
            BeginDrawing();

            DrawText(msg, 50,500,25,WHITE);

            strcpy(msg,"-> CUIDE MELHOR DO SEU PET NA PROXIMA VEZ ");
            DrawText(msg,50,550,25,WHITE);

            DrawPetLose(pet_perder,cor_quadro);

            EndDrawing();
        }
        PlaySound(perder);
    }

    if (felicidade==0 || fome==0)
    {
        mostrar=1;
        tempo_inicio_aviso = GetTime();
        while (mostrar==1)
        {
            if (mostrar && (GetTime()-tempo_inicio_aviso>=3.5))
            {
                mostrar=0;
            }

            ClearBackground(cor_fundo);
            strcpy(msg,"-> CREDITOS\n");
            BeginDrawing();
            DrawText(msg,30,50,25,WHITE);
            strcpy(msg,"-> CARLOS EDUARDO DOS SANTOS ALVES ");
            DrawText(msg,30,80,25,WHITE);
            strcpy(msg,"-> DESENVOLVEDOR INDIE \n INICIANTE, UNIVERSITÁRIO ");
            DrawText(msg,30,110,25,WHITE);
            strcpy(msg,"-> =^o^=");
            DrawText(msg,30,170,25,WHITE);

            EndDrawing();
        }
    }

    //LIMPEZA
    UnloadTexture(pet);
    UnloadTexture(coin);
    UnloadTexture(acessorios[0].textura);
    UnloadTexture(acessorios[1].textura);
    UnloadTexture(acessorios[2].textura);
    UnloadTexture(acessorios[0].textura_maior);
    UnloadTexture(acessorios[1].textura_maior);
    UnloadTexture(acessorios[2].textura_maior);
    UnloadTexture(x);
    UnloadTexture(pet_perder);
    UnloadTexture(Fbutton);
    UnloadTexture(Cbutton);
    UnloadTexture(Fbutton_press);
    UnloadTexture(Cbutton_press);
    UnloadTexture(loja);
    UnloadTexture(heart);
    UnloadTexture(smile);
    UnloadTexture(darkheart);
    UnloadTexture(darksmile);
    UnloadMusicStream(musica);
    UnloadSound(som_pet);
    UnloadSound(perder);
    UnloadSound(comer);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
