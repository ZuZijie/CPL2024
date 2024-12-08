#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h> 


void addout(char *output, size_t *pos, const char *format, ...) {
    va_list args;
    va_start(args, format); 

    *pos += vsprintf(output + *pos, format, args);
    va_end(args);  
}

int main() {
    char *output = (char *)malloc(4096 * sizeof(char)),
         *rules = (char *)malloc(128 * sizeof(char)),
         *name = (char *)malloc(1024 * sizeof(char)),
         *arg = (char *)malloc(1024 * sizeof(char)),
         *value = (char *)malloc(1024 * sizeof(char));
    size_t pos = 0;
    scanf("%s%s", rules, name);
    addout(output, &pos, "%s\n", name);
    while ((scanf("%s", arg) != EOF)) {
        if (*arg != '-') continue;
        char *rule = strchr(rules, *(arg + 1));
        if (rule != NULL) {
            if (*(rule + 1) == ':') {
                if (scanf("%s", value) == EOF) {
                    return 0 & printf("%s: option requires an argument -- '%c'\n", name, *rule);
                }
                else addout(output, &pos, "%c=%s\n", *rule, value);  
            }
            else addout(output, &pos, "%c\n", *rule);  
        }
        else return 0 & printf("%s: invalid option -- '%c'\n", name, *(arg + 1));
    }
    printf("%s", output);
    return 0;
}
