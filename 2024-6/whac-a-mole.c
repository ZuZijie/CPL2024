#include "stdio.h"
#include "math.h"
#include "limits.h"
#include "stdlib.h"
int arr[1000][1000];
int main()
{
    int n,m,d;
    int ansN=0;
    int max_sum=INT_MIN;
    int ansPosi[100000][2];
    scanf("%d %d %d",&n,&m,&d);
    for(int i=d;i<d+n;i++)
    {
        for(int j=d;j<d+m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=d;i<d+n;i++)
    {
        int tempsum=0;
        for(int p=i-d;p<=i+d;p++)
            {
                for(int q=d-d;q<=d+d;q++)
                {
                    if((abs(p-i)+abs(q-d))<=d)
                    {
                        tempsum+=arr[p][q];
                    }
                }
            }
        if(tempsum==max_sum)
            {
                ansN+=1;
                ansPosi[ansN-1][0]=i-d+1;
                ansPosi[ansN-1][1]=d-d+1;
            }
            if(tempsum>max_sum)
            {
                max_sum=tempsum;
                
                for(int g=0;g<ansN;g++)
                {
                    ansPosi[g][0]=0;
                    ansPosi[g][1]=0;
                }
                ansN=1;
                ansPosi[0][0]=i-d+1;
                ansPosi[0][1]=d-d+1;
            }
            int leftsum=0;
            for(int p=i-d;p<=i;p++)
            {
                for(int q=0;q<=d;q++)
                {
                    if((abs(p-i)+d-q)==d)leftsum+=arr[p][q];
                }
            }
        for(int j=d;j<d+m;j++)
        {
            int tempsum=0;
            int rightsum=0;
            
            for(int p=i-d;p<=i+d;p++)
            {
                for(int q=j-d;q<=j+d;q++)
                {
                    if((abs(p-i)+q-j)==d)
                    {
                        rightsum+=arr[p][q];
                    }
                    if((abs(p-i)+j-q)==d)
                    {
                        leftsum+=arr[p][q];
                    }
                }
            }
            if(leftsum)
        }
    }
    printf("%d %d\n",max_sum,ansN);
    for(int i=0;i<ansN;i++)
    {
        printf("%d %d\n",ansPosi[i][0],ansPosi[i][1]);
    }
    return 0;
}