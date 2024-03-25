#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Variaveis
    int segundos = time(0);
    srand(segundos);
    int aleatorizador = rand();
    int numeroAleatorio = aleatorizador % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    //Cabeçalho

    printf("*****************************************\n");
    printf(" * Bem vindo ao jogo do Numero Secreto * \n");
    printf("*****************************************\n");
    
    while (1){
    
        printf("Tentativa %d\n\n", tentativas);
        printf("Qual e o seu chute? \n");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0){
            printf("Voce nao pode usar numeros negativos!\n");
            tentativas--;

            continue;
        }

        int acertou = chute == numeroAleatorio;
        int maior = chute < numeroAleatorio;

        //Ifs e Elses

        if (acertou){
            printf("Parabens, voce acertou o numero secreto com %d tentativas!\n\n", tentativas);
            printf("A sua pontuacao foi de %.1f pontos", pontos);
            break;

        }else if (maior){
            printf("O numero secreto eh maior que %d\n", chute);
            pontos = pontos-((numeroAleatorio - chute) / 2.0);

        }else {
            printf("O numero secreto eh menor que %d\n", chute);  
            pontos = pontos - ((chute - numeroAleatorio) / 2.0);
        }
        tentativas++;

        }
        
}
