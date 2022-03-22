#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeTags(char *);

int main(){

    //char string[] = "<a href=\"https://terminalroot.com.br/\">Esse e um link</a>";
    //char string[] = "<a href=\"https://www.w3schools.com/\">Visit W3Schools.com!</a>";
    char string[] = "<h2>Absolute URLs\n</h2>"
                    "<p><a href=\"https://www.w3.org/\">W3C\n</a></p>"
                    "<p><a href=\"https://www.google.com/\">Google\n</a></p>"
                    "<h2>Relative URLs\n</h2>"
                    "<p><a href=\"html_images.asp\">HTML Images\n</a></p>"
                    "<p><a href=\"/css/default.asp\">CSS Tutorial\n</a></p>";

    printf("%s\n", removeTags(string));

    return 0;
}

char * removeTags(char * str){

    int j = 0;
    size_t length = strlen(str);

    char *buffer = (char *) malloc ((length + 1) * sizeof(char));

    if(buffer == NULL){
        printf("Error allocating memory!");
        return NULL;
    }

    strcpy(buffer, str);
    memset(str, 0, length);

    for (size_t i = 0; i < length; i++)
    {
        if(buffer[i] == '<'){
            while (buffer[i] != '>')
            {
                i++;
            }
            continue;

        } else {
            str[j] = buffer[i];
            j++;
        }
    }

    str[j] = '\0';

    return str;
}