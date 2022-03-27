//Algoritmo simples, que busca a quantidade de um digito (0-9) em um número fornecido pelo úsuario.
//Simple algorithm, who seeks the amount of one digit (0-9) in a number provided by the user.

#include <stdio.h>

int contains(int, int);

int main(){
    
    int number;
    int n;

    do
    {
        printf("Entre com um numero positivo ");
        scanf("%d", &number);

    } while (number < 0);

    printf("Digite um numero que deseja verificar [0-9]: ");
    scanf("%d", &n);

    printf("\nO numero %d aparece %d vez(es) em %d\n", n, contains(n, number), number);
    
    return 0;
}

int contains(int n, int m){

    int rest;
    int count = 0;

    while (m > 0)
    {
        rest = m % 10;
        m /= 10;

        if(rest == n){
            count++;
        }
    }
    
    return count;
}
