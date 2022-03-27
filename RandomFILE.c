#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;

}ClientData;

int main(){

    ClientData client = {0, "", "", 0.0};

    FILE *fp;

    if((fp = fopen("credit.dat", "wb")) == NULL){
        printf("Error opening file for writing");
        EXIT_FAILURE;
    }

    for (size_t i = 1; i <= 100; i++)
    {
        if((fwrite(&client, sizeof(ClientData), 1, fp)) != 1){
            printf("Error writing!\n");
            EXIT_FAILURE;
        }
    }
    
    fclose(fp);
    return 0;
}