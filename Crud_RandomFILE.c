#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int account;
    char lastName[15];
    char firstName[10];
    double balance;

}ClientData;

int showMenu(void);
void textFile(FILE *readPtr);
void insertRecord(FILE *fPtr);
void updateRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(){
    
    int request;

    FILE *fp;

    if((fp = fopen("credit.dat", "rb+")) == NULL){
        printf("Error opening file for writing and reading");
        EXIT_FAILURE;
    }
    
    while ((request = showMenu()) != 0)
    {
        switch (request)
        {
            case 1:
                system("cls");
                textFile(fp);
            break;

            case 2:
                system("cls");
                insertRecord(fp);
            break;

            case 3:
                system("cls");
                updateRecord(fp);
            break;

            case 4:
                system("cls");
                deleteRecord(fp);
            break;
            
            default:
            break;
        }
    }
    

    fclose(fp);
    return 0;
}

int showMenu(void){
    int choiceMenu;

    printf("1 - Criar aquivo de texto formatado, chamado credit.txt\n");
    printf("2 - Inserir uma nova conta\n");
    printf("3 - Atualizar uma conta\n");
    printf("4 - Excluir uma conta\n");
    printf("0 - Sair: ");

    scanf("%d", &choiceMenu);

    return choiceMenu;
}

void textFile(FILE *readPtr){
    FILE *writePtr;

    if((writePtr = fopen("credit.txt", "w")) == NULL){
        printf("Error opening file for writing");
        return;
    }

    fseek(readPtr, 0, SEEK_SET);

    fprintf(writePtr, "%-6s%-16s%-11s%10s\n", "Conta", "Sobrenome", "Nome", "Saldo");

    while (!feof(readPtr))
    {   
        ClientData client = {0, "", "", 0.0};

        fread(&client, sizeof(ClientData), 1, readPtr);

        if(client.account != 0){
            fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n", client.account, client.lastName, client.firstName, client.balance);
        }
    }
    
    fclose(writePtr);
}

void insertRecord(FILE *fPtr){
    int account;
    ClientData client = {0, "", "", 0.0};

    printf("Digite o numero da conta (1 - 100): ");
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(ClientData), SEEK_SET);
    
    if((fread(&client, sizeof(ClientData), 1, fPtr)) != 1){
        printf("Error reading!");
        return;
    }

    if(client.account != 0){
        printf("A conta %d ja existe!\n", account);
        return;

    } else {
        client.account = account;

        printf("Digite o sobrenome: ");
        fflush(stdin);
        scanf("%14s", &client.lastName);

        printf("Digite o primeiro nome: ");
        fflush(stdin);            
        scanf("%9s", &client.firstName);

        printf("Digite o saldo: ");
        scanf("%lf", &client.balance);

        fseek(fPtr, (account - 1) * sizeof(ClientData), SEEK_SET);

        if((fwrite(&client, sizeof(ClientData), 1, fPtr)) != 1){
            printf("Error writing\n");
        }
    }
}

void updateRecord(FILE *fPtr){
    int account;
    ClientData client = {0};

    printf("Digite o numero da conta a atualizar: ");
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(ClientData), SEEK_SET);

    if((fread(&client, sizeof(ClientData), 1, fPtr)) != 1){
        printf("Error reading!\n");
    }

    if(client.account  == 0){
        printf("A conta %d nao existe\n", account);

    } else {

        ClientData clientTemp;

        printf("Digite o sobrenome: ");
        fflush(stdin);
        scanf("%14s", &clientTemp.lastName);

        printf("Digite o primeiro nome: ");
        fflush(stdin);            
        scanf("%9s", &clientTemp.firstName);

        printf("Digite o saldo: ");
        scanf("%lf", &clientTemp.balance);

        client = clientTemp;
        client.account = account;

        fseek(fPtr, (account - 1) * sizeof(ClientData), SEEK_SET);

        if((fwrite(&client, sizeof(ClientData), 1, fPtr)) != 1){
            printf("Error writing\n");
        } else {
            printf("A conta foi alterada com sucesso!\n");
        }
    }
}

void deleteRecord(FILE *fPtr){
    int account;
    ClientData client = {0};

    printf("Digite o numero da conta a excluir: ");
    scanf("%d", &account);

    fseek(fPtr, (account - 1) * sizeof(ClientData), SEEK_SET);

    if((fread(&client, sizeof(ClientData), 1, fPtr)) != 1){
        printf("Error reading!\n");
    }

    if(client.account  == 0){
        printf("A conta %d nao existe\n", account);

    } else {

        ClientData blankClient = {0};

        fseek(fPtr, (account - 1) * sizeof(ClientData), SEEK_SET);

        if((fwrite(&blankClient, sizeof(ClientData), 1, fPtr)) != 1){
            printf("Error writing\n");

        } else {
            printf("A conta foi deletada com sucesso!\n");
        }
    }
}