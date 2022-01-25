#include <stdio.h>

int reverseNumber(int);

int main(){
    
    int number;

    printf("Entre com um numero: ");
    scanf("%d", &number);

    printf("Numero original: %d\nNumero invertido: %d\n", number, reverseNumber(number));
    
    return 0;
}

int reverseNumber(int number){

    int rest;
    int n = 0;

    while(number > 0){
        
        n *= 10;
        rest = number % 10;
        number /= 10;

        n += rest;
    }

    return n;
}