#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define tam 10


int numero_de_geracoes()
{
    int geracoes = 1;

    do
    {
        printf("\t\tBem vindo ao jogo da vida de Conway!!!\n");
        printf("Para jogar é necessário definir certa quantidade de gerações que o jogo fará\n\n");
        printf("Digite quantas gerações deseja fazer\n");
        printf("\t==> ");
        scanf("%d", &geracoes);
        if(geracoes <= 0)
        {
            printf("\tNÚMERO INVÁLIDO!!!\n");
            printf("\tDigite um número maior que 0\n");
            system("pause");
            system("cls");
            continue;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while(geracoes < 1);
    return geracoes;
}

void geracao_do_tabuleiro(int m[tam][tam])
{
    srand(time(NULL));

    int i = 0;
    int j = 0;
    int contap = 0;


    for(i = 0; i < tam; i++)
    {
        for(j = 0; j < tam; j++)
        {
            contap = rand() % 2;
            if(contap == 0)
            {
                m[i][j] = 0;
            }
            else
            {
                m[i][j] = 1;
            }
        }
    }
    
}

void verificacao_criacao_tabuleiros(int geracoes)
{
    int m1[tam][tam];
    int m2[tam][tam];

    int i = 0;
    int j = 0;
    int l = 0;
    int c = 0;
    int vivas = 0;
    int iter = 1;

    geracao_do_tabuleiro(m1);

    while(geracoes > 0)
    {
        printf("%d Geração\n", iter);
        for(i = 0; i < tam; i++)
        {
            printf("\n");
            for(j = 0; j < tam; j++)
            {
                printf("%d\t", m1[i][j]);
            }
        }

        for(i = 0; i < tam; i++)
        {
            for(j = 0; j < tam; j++)
            {
                vivas = 0;
                for(l = i - 1; l <= i + 1; l++)
                {
                    for(c = j - 1; c <= j + 1; c++)
                    {
                        if(l >= 0 && l < tam && c >= 0 && c < tam && (l != i || c != j))
                        {
                            if(m1[l][c] == 1)
                            {
                            vivas++;
                            }
                        }
                        
                    }
                }

                if(m1[i][j] == 1 && (vivas < 2 || vivas > 3))
                {
                m2[i][j] = 0;
                }
                else
                {
                    if(m1[i][j] == 0 && vivas == 3)
                    {
                    m2[i][j] = 1;
                    }
                    else
                    {
                        m2[i][j] = m1[i][j];
                    }
                }
            }
        }
            
        for(i = 0; i < tam; i++)
        {
            for(j = 0; j < tam; j++)
            {
            m1[i][j] = m2[i][j];
            }
        }

        printf("\n\n");
        system("pause");
        system("cls");
        iter++;
        geracoes--;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int jogar = 1;
    int geracoes = 0;

    do
    {
        geracoes = numero_de_geracoes();
        verificacao_criacao_tabuleiros(geracoes);

        printf("\tDeseja jogar novamente??\n");
        printf("\tSIM(1) NÃO(0)\n");
        printf("\t==> ");
        scanf("%d", &jogar);
        if(jogar != 1 && jogar != 0)
        {
            printf("\tNÚMERO INVÁLIDO!!!\n");
            printf("\tSaindo do jogo\n");
            system("pause");
            system("cls");
            exit(0);
        }
        system("cls");
    }
    while(jogar == 1);
    return 0;
}