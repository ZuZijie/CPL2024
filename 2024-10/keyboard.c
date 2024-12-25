#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct  node
{
    struct node *next;
    struct node *prev;
    struct node *last_same;
    char c;
    enum {l,u} type;
}node;
node *list;
int IsUorL(char input)
{
    if(input>='A' && input<='Z')return 1;
    else if (input>='a' && input<='z')return 0;
    else return -1;
}
int main()
{
    int q;
    int totalLength=0;
    node *lastU=NULL;
    node *lastL=NULL;
    node *tail=NULL;
    scanf("%d",&q);
    char str[100000];
    // for(int i=0;i<2000000;i++)
    // {
    //     list[i].next=NULL;
    //     list[i].prev=NULL;
    // }
    for(int Q=0;Q<q;Q++)
    {
        
        scanf("%s",str);
        if(str[0]!='?')
        {
            for(int i=0;i<strlen(str);i++)
            {
                    if(totalLength>0)
                    {
                        if(str[i]=='M')
                        {
                            if(lastU!=NULL)
                            {
                                if(tail==lastU)tail=lastU->prev;
                                if(lastU->prev!=NULL)
                                lastU->prev->next=lastU->next;
                                if(lastU->next!=NULL)
                                lastU->next->prev=lastU->prev;
                                lastU=lastU->last_same;
                                totalLength--;
                            }
                        }
                        else if(str[i]=='m')
                        {
                            if(lastL!=NULL)
                            {
                                if(lastL->prev!=NULL)lastL->prev->next=lastL->next;
                                if(lastL->next!=NULL)lastL->next->prev=lastL->prev;
                                lastL=lastL->last_same;
                                if(tail==lastL)tail=lastL->prev;
                                totalLength--;
                            }
                        }
                        else{
                            list=malloc(sizeof(node));
                            totalLength++;
                  //          list[totalLength].prev=tail;
                            tail->next=&list[totalLength];
                            list[totalLength].c=str[i];
                            if(IsUorL(str[i])==1)
                            {
                                list[totalLength].type=u;
                                lastU=&list[totalLength];
                            }
                            else
                            {
                                list[totalLength].type=l;
                                lastL=&list[totalLength];
                            }
                            tail=&list[totalLength];
                            for(int j=totalLength-1;j>=0;j--)
                            {
                                if(list[totalLength].type==u && list[j].type==u)
                                {
                                    list[totalLength].last_same=&list[j];
                                    break;
                                }
                                else if(list[totalLength].type==l && list[j].type==l)
                                {
                                    list[totalLength].last_same=&list[j];
                                    break;
                                }
                            }
                       
                        }
                    }
                    else{
                        if(str[i]=='M'||str[i]=='m');
                        else
                        {
                        totalLength++;
                        node tempnode;
                        
                        //list[totalLength].prev=NULL;
                        //list[totalLength].c=str[i];
                        //if(IsUorL(str[i])==1)list[totalLength].type=u;
                        //else list[totalLength].type=l;
                        //list[totalLength].last_same=NULL;
                        //tail=&list[totalLength];
                        }
                    }
            }
          
        }
        else{
            int length;
            node * currentPosi=tail;
            char output[200000];
            int outputlength=0;
            scanf("%d",&length);

            while (length>0)
            {
                
                output[outputlength]=currentPosi->c;
                outputlength++;
                currentPosi=currentPosi->prev;
                length--;
            }
            for(int i=outputlength-1;i>=0;i--)printf("%c",output[i]);
            printf("\n");
        }
    }
    return 0;
}
