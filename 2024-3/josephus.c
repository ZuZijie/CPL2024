#include "stdio.h"
int main()
{
    int n, k, temp, count = 0, index = 0;
    int arr[1000000];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        arr[i] = 1;

   
    while(count < n - 1)
    {
        temp = k;

        
        while(temp > 0)
        {
            if(arr[index])  
            {
                temp--; 
            }
            
            if(temp == 0) 
            {
                arr[index] = 0; 
                count++; 
                break;
            }

            index = (index + 1) % n; 
        }
    }

    
    for(int i = 0; i < n; i++)
    {
        if(arr[i])
        {
            printf("%d", i + 1); 
            break;
        }
    }
    
    return 0;
}
