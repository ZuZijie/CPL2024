#include <stdio.h>
#include <ctype.h>

void formatSentence(char *input, char *output) {
    int i = 0, j = 0;
    int firstWord = 1; // 

    while (input[i] != '\0') {
        if (isupper(input[i])) { 
            if (!firstWord) {
                output[j++] = ' '; 
            }
            firstWord = 0; 
            output[j++] = tolower(input[i]);
        } else { 
            output[j++] = input[i];
        }
        i++;
    }
    output[j] = '\0';
}

int main() {
    char input[10240];  
    char output[10240];  

    scanf("%s", input); 

    formatSentence(input, output);
    if (output[0] != '\0') {
        output[0] = toupper(output[0]);
    }

    printf("%s\n", output);

    return 0;
}
