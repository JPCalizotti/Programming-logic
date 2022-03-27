//Minha versão de algumas das funções nativas da linguagem C para manipulação de strings.
//My version of some of the native functions of the C language for string manipulation.

#include <stdio.h>
#include <stdlib.h>

void strToLowerCase(char *str);
void strToUpperCase(char *str);
void strConcat(char *dest, const char *src);
void strCopy(char* dest, const char* src);
size_t strLength(const char *str);
int strCompare(const char* str1, const char* str2);
char* searchChr(const char *str, int c);
char* searchStr(const char *haystack, const char *needle);

int main(){    

    return 0;
}

void strToLowerCase(char *str){
    while(*str != '\0'){
        
        if(*str >= 65 && *str <= 90){
            *str += 32;
        }
        
        str++;
    }
}

void strToUpperCase(char *str){
    while(*str != '\0'){
        
        if(*str >= 97 && *str <= 122){
            *str -= 32;
        }
        
        str++;
    }
}

size_t strLength(const char *str){
    size_t x = 0;

    while (*str != '\0')
    {
        x++;
        str++;
    }
    
    return x;
}

void strConcat(char *dest, const char *src){
    for(; *dest != '\0'; dest++);

    for(; (*dest = *src) != '\0'; dest++, src++);
}

void strCopy(char* dest, const char* src){
    for(; (*dest = *src) != '\0'; dest++, src++);
}

int strCompare(const char* str1, const char* str2){

    while((*str1 == *str2)){
        if(*str1 == '\0' && *str2 == '\0'){
            return 0;
        }
        str1++;
        str2++;
    }

    if(*str1 < *str2){
        return -1;
    } else {
        return 1;
    }
}

char* searchChr(const char *str, int c){
    while (*str != '\0')
    {
        if (*str == c)
        {   
            return (char *) str;
        }
        str++;
    }
    
    return NULL;
}

char* searchStr(const char *haystack, const char *needle){
    int i = 0;
    
    while (haystack)
    {
        if (*haystack == needle[i])
        {
            if(needle[i + 1] == '\0'){

                return (char *) haystack - i;
            }
            i++;

        } else {
            i = 0;
        }
        
        haystack++;
    }

    return NULL;
}
