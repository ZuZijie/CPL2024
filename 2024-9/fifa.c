#include "stdio.h"
#include "stdlib.h"

typedef struct 
{
    char name[100];
    int score1;
    int score2;
    int score3;
} team;

team teams[1000];

int compareByScore1(const void *a, const void *b) {
    return (((team*)b)->score1 - ((team*)a)->score1);
}

int compareByScore2(const void *a, const void *b) {
    return (((team*)b)->score2 - ((team*)a)->score2);
}

int compareByScore3(const void *a, const void *b) {
    return (((team*)b)->score3 - ((team*)a)->score3);
}

int main() {
    int n;
    scanf("%d", &n); 
    
    for (int i = 0; i < n; i++) {
        scanf("%s", teams[i].name);
        int tempinput1, tempinput2, tempinput3;
        teams[i].score1 = 0;
        teams[i].score2 = 0;
        teams[i].score3 = 0;
        
        for (int j = 0; j < 11; j++) {
            char teamName[100];
            scanf("%s %d %d %d", teamName, &tempinput1, &tempinput2, &tempinput3);
            teams[i].score1 += tempinput1;
            teams[i].score2 += tempinput2;
            teams[i].score3 += tempinput3;
        }
    }
    qsort(teams, n, sizeof(team), compareByScore1);
    for (int i = 0; i < n; i++) {
        printf("%s ", teams[i].name);
    }
    printf("\n");
    
    qsort(teams, n, sizeof(team), compareByScore2);
    for (int i = 0; i < n; i++) {
        printf("%s ", teams[i].name);
    }
    printf("\n");
    qsort(teams, n, sizeof(team), compareByScore3);
    for (int i = 0; i < n; i++) {
        printf("%s ", teams[i].name);
    }
    printf("\n");
    return 0;
}
