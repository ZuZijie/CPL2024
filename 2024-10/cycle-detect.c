#include "stdio.h"

typedef struct 
{
    char str[1000];
    int nextNode;
} node;

node list[100000];

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 100000; i++) {
        list[i].nextNode = 0;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%s", list[i].str);
        scanf("%d", &list[i].nextNode);
        if(list[i].nextNode<=0 || list[i].nextNode>100000)
        {
            printf("-1");
            return 0;
        }
    }
    int slow = 1, fast = 1;
    while (1) {
        if (fast == 0 || list[fast].nextNode == 0 || list[list[fast].nextNode].nextNode==0) {
            printf("-1"); 
            return 0;
        }
        slow = list[slow].nextNode;
        fast = list[list[fast].nextNode].nextNode;
        if (slow == fast) {
            break;
        }
    }
    slow = 1;
    while (slow != fast) {
        slow = list[slow].nextNode;
        fast = list[fast].nextNode;
    }
    printf("%s\n", list[slow].str);
    free(list);
    return 0;
}
