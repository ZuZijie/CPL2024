#include "stdio.h"
int main()
{
    int n, k, temp, count = 0, index = 0, b, l;
    int temp2=1;
    scanf("%d %d %d %d", &n, &k,&b,&l);
        int arr[10000];
    for(int i = 0; i < n; i++)
        arr[i] = l;

   
    while(count < n*l - 1)
    {
        temp = k;

        
        while(temp > 0)
        {
            if(arr[index]!=0)  
            {
                temp--; 
            }
            
            if(temp == 0) 
            {
                if(temp2<=b)
                {
                    arr[index]=arr[index]-1; 
                    count++; 
                    temp2++;
                }
                else
                {
                    temp2=1;
                }
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
