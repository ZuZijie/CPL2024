    #include "stdio.h"
    #include "stdlib.h"
    #include "string.h"

    int IsValidOption(char a, char rule[], int lengthOfRule) 
    {
        for (int i = 0; i < lengthOfRule; i++) 
        {
            if (a == rule[i]) 
            {
                return 1;
            }
        }
        return 0;
    }

    int IsOptionRequireValue(char a, char rule[], int lengthOfRule) 
    {
        for (int i = 0; i < lengthOfRule; i++) 
        {
            if (a == rule[i]) 
            {
                return (i + 1 < lengthOfRule && rule[i + 1] == ':');
            }
        }
        return 0;
    }

    int main() 
    {
        char rule[102400], name[1025];
        char token[102500][1025];
        int tokenLength = 0;
        scanf("%s", rule);
        scanf("%s", name);

        while (scanf("%s", token[tokenLength]) != EOF) 
        {
            tokenLength++;
        }
        if (tokenLength == 0) 
        {
            printf("%s\n", name);
            return 0;
        }
        int ruleLength = strlen(rule);
        if (token[tokenLength - 1][0] == '-') 
        {
            char lastOption = token[tokenLength - 1][1];
            if (IsOptionRequireValue(lastOption, rule, ruleLength)) 
            {
                printf("%s:option requires an argument -- '%c'\n", name, lastOption);
                return 0;
            }
        }
        for (int i = 0; i < tokenLength; i++) 
        {
            if (token[i][0] == '-') 
            {
                char option = token[i][1];
                if (!IsValidOption(option, rule, ruleLength)) 
                {
                    printf("%s:invalid option -- '%c'\n", name, option);
                    return 0;
                }
            }
        }
        printf("%s\n", name);

        for (int i = 0; i < tokenLength; i++) 
        {
            if (token[i][0] == '-') 
            {
                char option = token[i][1];
                if (IsOptionRequireValue(option, rule, ruleLength)) 
                {
                    if (i + 1 < tokenLength && token[i + 1][0] != '-') 
                    {
                        printf("-%c=%s\n", option, token[i + 1]);
                        i++;
                    } 
                    else 
                    {
                        printf("%s: option requires an argument -- '%c'\n", name, option);
                        return 0;
                    }
                } 
                else 
                {
                    printf("-%c\n", option);
                }
            }
        }

        return 0;
    }
