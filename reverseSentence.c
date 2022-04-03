#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXT_SIZE 100

char* reverseStr(char *);
void readLine(char *, int);

int main(){

    char string[100];

    printf("Enter any sentence: ");
    readLine(string, TEXT_SIZE);
    
    printf( "Input was: %s\n", string);

    printf("Now the inverse: %s\n", reverseStr(string));

    return 0;
}

void readLine(char * buffer, int size){
    int i, ch;

    for (i = 0; (i < (size - 1)) && ((ch = getchar()) != EOF)
                         && (ch != '\n'); i++)
    {
        buffer[i] = (char) ch;
    }

    buffer[i] = '\0';
}

char* reverseStr(char *sPtr){
    
    size_t length = strlen(sPtr);
    int wordCount = 0;

    char *p = sPtr;
    char *strTemp = (char*) malloc(length + 1);

    if(strTemp != NULL){
        
        memset(strTemp, 0, length + 1);

        for(size_t i = 0; i < length; i++)
        {
            if(sPtr[i] == ' '){
                sPtr[i] = '\0';
                wordCount++;
            }
        }
        wordCount;

        char *array[wordCount + 1];

        for (int i = wordCount; i >= 0; p++)
        {
            if(*p == '\0'){
                array[i] = sPtr;
                i--;
                sPtr = p + 1;
            }
        }

        for (size_t i = 0; i <= wordCount; i++)
        {
            strcat(strTemp, array[i]);
            strcat(strTemp, " ");
        }

        strcpy(sPtr, strTemp);
        free(strTemp);

    } else {
        printf("Memory Allocation Error!\n");
        return NULL;
    }

    return sPtr;
}