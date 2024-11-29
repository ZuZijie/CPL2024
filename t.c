#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void mystrcat(char *str1, const char *str2) {
    int length1 = strlen(str1);
    int i = 0;
    while (str2[i] != '\0') {
        str1[length1 + i] = str2[i];
        i++;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    getchar(); 
    for (int t = 0; t < T; t++) {
        char s1[1000]="", s2[1000]="", s3[10000] = ""; 
        int ds1, ds2, size;
        int i = 0;
        char ch;
        while ((ch = getchar()) != ';') 
        {
            s1[i] = ch;
            i++;
        }
        i = 0;
        while ((ch = getchar()) != ';') 
        {
            s2[i] = ch;
            i++;
        }
        scanf("%d;%d;%d",&ds1,&ds2,&size);
        int start1 = 0, start2 = 0, remainedLength = size;
        while (remainedLength > 0) {
            if (remainedLength > ds1) {
                if (ds1 <= strlen(s1) - start1) {
                    char tempstr[1000];
                    for (int i = 0; i < ds1; i++) {
                        tempstr[i] = s1[start1 + i];
                    }
                    tempstr[ds1] = '\0'; 
                    mystrcat(s3, tempstr);
                    start1 += ds1;
                    remainedLength -= ds1;
                }
            } 
            else if(remainedLength>(strlen(s1)-start1)&&start1!=strlen(s1))
            {
                char tempstr[1000];
                for(int i=start1;i<strlen(s1);i++)
                {
                    tempstr[i-start1]=s1[i];
                }
                mystrcat(s3,tempstr);
                remainedLength-=(strlen(s1)-start1);
                start1=strlen(s1);
            }
            else if(start1==strlen(s1));
            else 
            {
                char tempstr[1000];
                for (int i = 0; i < remainedLength; i++) {
                    tempstr[i] = s1[start1 + i];
                }
                tempstr[remainedLength] = '\0'; 
                mystrcat(s3, tempstr);
                break;
            }

            if (remainedLength > ds2) {
                if (ds2 <= strlen(s2) - start2) {
                    char tempstr[1000];
                    for (int i = 0; i < ds2; i++) {
                        tempstr[i] = s2[start2 + i];
                    }
                    tempstr[ds2] = '\0';  
                    mystrcat(s3, tempstr);
                    start2 += ds2;
                    remainedLength -= ds2;
                }
            } 
            else if(remainedLength>(strlen(s2)-start2)&&start2!=strlen(s2))
            {
                char tempstr[1000];
                for(int i=start2;i<strlen(s2);i++)
                {
                    tempstr[i-start2]=s1[i];
                }
                mystrcat(s3,tempstr);
                remainedLength-=(strlen(s2)-start2);
                start2=strlen(s2);
            }
            else if(start2==strlen(s2));
            else 
            {
                char tempstr[1000];
                for (int i = 0; i < remainedLength; i++) {
                    tempstr[i] = s2[start2 + i];
                }
                mystrcat(s3,tempstr);  
                break;
            }
        }
        s3[size]='\0';
        printf("%s\n", s3);
    }
    return 0;
}
