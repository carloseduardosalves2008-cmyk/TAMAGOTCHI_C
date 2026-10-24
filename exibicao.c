#include "exibicao.h"

void gatodesenho ()
{
    printf("\n\n   /\\_/\\ ");
    printf("\n  ( o.o )");
    printf("\n   > ^ < \n");
}
void gatoaltavida ()
{
    printf("\n\n   /\\_/\\ ");
    printf("\n  ( ^.^ )");
    printf("\n   > ^ < \n");
}
void gatobaixavida ()
{
    printf("\n\n   /\\_/\\ ");
    printf("\n  ( =.= )");
    printf("\n   > ^ < \n");
}
void gatomorrer ()
{
    system("cls");
    printf("\n+=================================+\n");
    printf("|     SEU PET MORREU... :(        |\n");
    printf("+=================================+\n");

    printf("\n\n   /\\_/\\ ");
    printf("\n  ( x.x )");
    printf("\n   > ^ < \n");
}
void gatodormir()
{
    printf("\n\n   /\\_/\\ ");
    printf("\n  ( o.o )");
    printf("\n   > ^ < \n");

    printf("\n\n   /\\_/\\ ");
    printf("\n  ( =.= )");
    printf("\n   > ^ < \n");

    printf("\n\n   /\\_/\\ ");
    printf("\n  ( =.= ) Z");
    printf("\n   > ^ < \n");

    printf("\n\n   /\\_/\\ z");
    printf("\n  ( =.= ) Z");
    printf("\n   > ^ < \n");

    printf("\n\n           Z");
    printf("\n   /\\_/\\ z");
    printf("\n  ( =.= ) Z");
    printf("\n   > ^ < \n");

}

void raposa ()
{
    printf("\n\n /\\_/\\ ");
    printf("\n( o.o ) ");
    printf("\n /   \\ ");
    printf("\n(_____)>");
}
void rato ()
{
    printf("\n\n _   _");
    printf("\n(q\\_/p)");
    printf("\n (o.o)");
    printf("\n > ^ <");
}
void pato ()
{
    printf("\n\n__(o)<");
    printf("\n\\___)");
    printf("\n >> ");
}

void barradevida (int vida_atual, int vida_max, char nomebarra[])
{
    printf("\n[");
    for (int c=0;c<=vida_atual;c++){printf("=");}
    for (int c=vida_atual;c<vida_max;c++){printf(" ");}
    printf("]\n");
    printf(" -> %s = [ %i / %i ]\n",nomebarra,vida_atual*5,vida_max*5);
}
void desenharjogo (int felicidade, int felicidademax,int fome, int fomemax)
{
    system("cls");
    printf("\n+======== TAMAGOTCHI EM C ========+\n");
    if (felicidade>70){gatoaltavida();}
    else if (felicidade<=70 && felicidade>25){gatodesenho();}
    else if (felicidade<=25 && felicidade>0){gatobaixavida();}
    else if (felicidade==0) {gatomorrer();}
    barradevida(felicidade/5,felicidademax/5,"FELICIDADE");
    barradevida(fome/5,fomemax/5,"FOME");
    printf("\n+=================================+\n");
    printf("|    [F]-ALIMENTAR   [C]-CARINHO  |");
    printf("\n+=================================+\n");
}
void encerramento (int segtot)//duração do timer
{
    time_t inictimer = time(NULL);//inicio do timer
    int segspassados=0;//tempo de timer passado
    int ultimseg=0;//ultimo segundo por onde o while passou
    printf("ENCERRANDO PROGRAMA ");
    while (segspassados<segtot)
    {
        segspassados=difftime(time(NULL),inictimer);
        if (segspassados>ultimseg)
        {
            printf(" o");
            ultimseg=segspassados;
        }
    }
    printf("\n");
}
