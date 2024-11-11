#include "stdio.h"

void bubbleSort(int arr[],int arr2[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                temp=arr2[j];
                arr2[j]=arr2[j+1];
                arr2[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int L;
    int value=0;
    scanf("%d",&L);
    int arr1[10000];
    int arr2[10000];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
      for(int i=0;i<n;i++)
    {
        scanf("%d",&arr2[i]);
    }
    bubbleSort(arr1,arr2,n);
    for(int i=0;i<n;i++)
    {
        if(L>=arr2[i])
        {
            value+=arr2[i]*arr1[i];
            L-=arr2[i];
        }
        else
        {
            value+=L*arr1[i];
            break;
        }
    }
    printf("%d",value);
    return 0;
}