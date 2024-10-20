#include "stdio.h"

int main() 
{
    int n;
    scanf("%d", &n);   
    int arr[100][100] = {0};
    
    int x = 0, y = (n - 1) / 2;
    arr[x][y] = 1; 
    
    for (int i = 2; i <= n * n; i++) {

        int new_x = (x - 1 + n) % n;
        int new_y = (y + 1) % n; 
        
        if (arr[new_x][new_y] != 0) { 
            new_x = (x + 1) % n; 
            new_y = y; 
        }
        
        arr[new_x][new_y] = i; 
        x = new_x;
        y = new_y;
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
