#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
#define true 1
#define false 0
 
typedef short int boolean;
 
struct _amigo {
    int numero;
    boolean espada;
};
 
typedef struct _amigo Amigo;
 
void exibir( Amigo a ) {
 
    printf("Amigo Nº %d e " , a.numero );
 
    if(a.espada == true ) {
        printf("está com a espada");
    } else {
        printf("não está com a espada");
    }
 
    printf("\n");
}
 
 
void jogar(Amigo amigos) {
    for(int i =0;i<10;i++) {
 
    }
}
 
int main()
{
    boolean continuar = true;
    int quantidade = 0, possuiEspada = 0, k = 0;
 
    printf("Qual a quantidade de Amigos? ");
    scanf("%d", &quantidade);

    Amigo amigos[quantidade];
 
    printf("Quem tem a espada? [0 a %d] ", (quantidade-1));
    scanf("%d", &possuiEspada);
 
    for(k = 0; k<quantidade; k++){
        Amigo novo;
        novo.numero = k+1;
        if(possuiEspada==k+1) {
            novo.espada = true;
        } else {
            novo.espada = false;
        }
 
        amigos[k] = novo;
    }
 
 
    // jogar( amigos );
   
    int valores[5] = {1,2,3,4,5};
 
    for(int j = 0; j <= 16; j++) {
        printf("%d ",valores[j]);
    }
 
 
 
    return false;
}