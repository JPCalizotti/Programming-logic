#include <stdio.h>

int isPrime(int n);

int main(){
    
    int i;
    int range = 0;

    printf("Lista dos 100 primeiros numeros primos: \n");
     
    for(i = 1; range != 100; i++){
        if (isPrime(i))
        {
            printf("%d ", i);
            ++range;
        }
    }

    return 0;
}

/*Um número primo é um número natural maior que um, que só é divisível por um e por ele mesmo.*/
/*Um loop for foi usado, para ir de 2 (primeiro numero primo) até n-1, se em algum momento ele for divisivel por 'i', então ele não é um numero primo*/
/*Se o numero não for primo, 0 vai ser retornado.*/
int isPrime(int n){
    int i;

    if(n < 2 ){
        return 0;

    } else {
        for(i = 2; i < n; i++){
            if(n % i == 0){
                return 0;
            }
        }
    }
    return 1;
}
 
 /*Implementação de um algoritmo mais eficiente*/
int isPrime2(int n){
    int i;

    if(n < 2){
        return 0;
    }

    for (i = 2; i * i <= n; i++){
        if (n % i == 0){
            return 0;
        }
    }

    return 1;
}
