#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contains(int [], int);
void add(int [], int);
void bubbleSort(int [], int);

int main(){
    
    int i;
    int number;
    int list[6] = {0};

    srand(time(NULL));

    for(i = 1; i <= 6; i++){
        do{
            number = 1 + (rand() % 60);
        } while (contains(list, number)); // Enquanto gerar um número repetido
        
        add(list, number); //add(&list[0], number)
    }

    printf("\n Os numeros sorteados foram: ");
    bubbleSort(list, sizeof(list)/sizeof(list[0]));
    for(i = 0; i < 6; i++){
        printf("%d ", list[i]);
    }

    return 0;
}

int contains(int a[], int number){
   
   int i = 0;

   while(a[i] != 0){
       if(a[i] == number){
           return 1;
       }
       i++;
   }

   return 0;
}

void add(int *listPtr, int n){
    while(*listPtr != 0){
        ++listPtr;
    }
    
    *listPtr = n;
}
 
 void bubbleSort(int a[], int size){
     int pass;
     int i;
     int hold;
     int swap;

     for(pass = 1; pass < size; pass++){
         swap = 0;

         for(i = 0; i < size - pass; i++){
             if(a[i] > a[i + 1]){
                 hold = a[i];
                 a[i] = a[i + 1];
                 a[i + 1] = hold;

                 swap = 1; // Houve pelo menos uma troca
             }
         }

         if (swap == 0) // Se não houve nenhuma troca, então os dados já deveram estar na ordem certa
         {
            break;
         } 
     }
 }
