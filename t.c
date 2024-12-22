#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *next;
    struct node *prev;
    struct node *last_same;
    char c;
    enum { l, u } type;
} node;

node *createNode(char c, node **lastU, node **lastL) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->c = c;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (c >= 'A' && c <= 'Z') {
        newNode->type = u;
        newNode->last_same = *lastU;
        *lastU = newNode;
    } else if (c >= 'a' && c <= 'z') {
        newNode->type = l;
        newNode->last_same = *lastL;
        *lastL = newNode;
    } else {
        newNode->type = -1;
        newNode->last_same = NULL;
    }
    return newNode;
}

void deleteNode(node **target, node **lastSame) {
    if (*target == NULL) return;
    if ((*target)->prev) (*target)->prev->next = (*target)->next;
    if ((*target)->next) (*target)->next->prev = (*target)->prev;
    *lastSame = (*target)->last_same;
    free(*target);
    *target = NULL;
}

void queryLastCharacters(node *tail, int length) {
    char output[10000];
    int outputLength = 0;
    while (tail && length > 0) {
        if (tail->c != 'M' && tail->c != 'm') {
            output[outputLength++] = tail->c;
            length--;
        }
        tail = tail->prev;
    }
    for (int i = outputLength - 1; i >= 0; i--) {
        printf("%c", output[i]);
    }
    printf("\n");
}

int main() {
    int q;
    scanf("%d", &q);

    node *head = NULL, *tail = NULL;
    node *lastU = NULL, *lastL = NULL;

    for (int Q = 0; Q < q; Q++) {
        char str[1000];
        scanf("%s", str);

        if (str[0] != '?') {
            for (int i = 0; i < strlen(str); i++) {
                node *newNode = createNode(str[i], &lastU, &lastL);
                if (tail) {
                    tail->next = newNode;
                    newNode->prev = tail;
                } else {
                    head = newNode;
                }
                tail = newNode;
            }
            for (node *current = tail; current; current = current->prev) {
                if (current->c == 'M') deleteNode(&lastU, &lastU);
                else if (current->c == 'm') deleteNode(&lastL, &lastL);
            }
        } else {
            int length;
            scanf("%d", &length);
            queryLastCharacters(tail, length);
        }
    }
    return 0;
}
