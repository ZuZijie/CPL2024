#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char output[2000000];
typedef struct  node
{
    struct node *next;
    struct node *prev;
    struct node *last_same;
    char c;
    enum {l,u} type;
}node;
int IsUorL(char input)
{
    if(input>='A' && input<='Z')return 1;
    else if (input>='a' && input<='z')return 0;
    else return -1;
}
int main()
{
    node *lastU=NULL;
    node *lastL=NULL;
    node *tail=(node *)malloc(sizeof(node));
    node *head=(node *)malloc(sizeof(node));
    int Q;
    head->prev=NULL;
    scanf("%d",&Q);
    for(int q=0;q<Q;q++)
    {
        char str[10000];
        scanf("%s",str);
        {
            int len=strlen(str);
            
                if(str[0]!='?')
                {
                    for(int i=0;i<len;i++)
                    {
                    if(str[i]!='M' && str[i]!='m')
                    {
                        
                        
                        {
                            node *tempnode=(node *)malloc(sizeof(node));
                            tempnode->c=str[i];
                            tempnode->prev=tail;
                            tail->next=tempnode;
                            if(IsUorL(str[i])==1){
                                tempnode->type=u;
                                tempnode->last_same=lastU;
                                lastU=tempnode;                            
                            }
                            else{   
                                tempnode->type=l;
                                tempnode->last_same=lastL;
                                lastL=tempnode;
                            }
                            tail=tempnode;    
                        }
                    }
                    else if(str[i]=='M')
                    {
                        if(lastU==NULL);
                        else 
                        {
                            if(lastU==tail)
                            {
                                tail=tail->prev;
                                tail->next=NULL;
                                lastU=lastU->last_same;
                            }
                            else
                            {
                                if(lastU->prev!=NULL)
                                lastU->prev->next=lastU->next;
                                if(lastU->next!=NULL)
                                lastU->next->prev=lastU->prev;
                                lastU=lastU->last_same;

                            }
                        }
                    }
                    else if(str[i]=='m')
                    {
                        if(lastL==NULL);
                        else 
                        {
                            if(lastL==tail)
                            {
                                tail=tail->prev;
                                tail->next=NULL;
                                lastL=lastL->last_same;
                            }
                            else
                            {
                                if(lastL->prev!=NULL)
                                lastL->prev->next=lastL->next;
                                if(lastU->next!=NULL)
                                lastL->next->prev=lastL->prev;
                                lastL=lastL->last_same;
                                
                            }
                        }
                    }
                    
                }
                
            }
            else{
                    
                    //memset(output,'\0',sizeof(output));
                    int outputlength;
                    scanf("%d",&outputlength);
                    int length=0;
                    node *currentNode=tail;
                    while(outputlength>0)
                    {
                        output[length]=currentNode->c;
                        length++;
                        outputlength--;
                        currentNode=currentNode->prev;
                    }
                    output[length]='\0';
                    for(int j=length-1;j>=0;j--)
                    {
                        printf("%c",output[j]);
                    }
                    printf("\n");
                }
        }
        //node *t=head;
        //while(t!=NULL)
        //{
        //    printf("%s",t->c);
        //    t=t->next;
        //}               
    }
    return 0;
}