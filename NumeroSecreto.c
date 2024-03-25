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
    int acertou = 0;
    //Cabeçalho

    printf("*****************************************\n");
    printf(" * Bem vindo ao jogo do Numero Secreto * \n");
    printf("*****************************************\n");

    int nivel;

    printf("Qual o nivel de dificuldade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numeroDeTentativas;

    if(nivel == 1){
        numeroDeTentativas = 20;
    } else if (nivel == 2){
        numeroDeTentativas = 10;
    } else if (nivel == 3){
        numeroDeTentativas = 5;
    }
    
    for (int i = 1; i <= numeroDeTentativas; i++){
    
        printf("Tentativa %d\n\n", tentativas);
        printf("Qual e o seu chute? \n");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0){
            printf("Voce nao pode usar numeros negativos!\n");
            tentativas--;

            continue;
        }

        acertou = chute == numeroAleatorio;
        int maior = chute < numeroAleatorio;

        //Ifs e Elses

        if (acertou){
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
    if (acertou){
    printf("Parabens, voce acertou o numero secreto com %d tentativas!\n\n", tentativas);
    printf("A sua pontuacao foi de %.1f pontos", pontos);
    }else{
        printf("Voce perdeu! Tente novamente!");
    }
}
