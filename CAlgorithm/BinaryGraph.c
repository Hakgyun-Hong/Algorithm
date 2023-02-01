#include <stdio.h>
#include <stdlib.h> // using malloc.h

int K, V, E;

typedef struct st
{
    int node;
    struct st *next;
}Node;

Node head[20200];
Node pool[20200*2];

int pcnt=0;

int check[20200];

void init(void)
{
    pcnt=0;
    
    for(int i=1;i<=V;i++) (void)(head[i].next= 0), check[i]=0;
}

/*
 * Make:
 * p번째 헤드에 c를 입력한다.
 */
void Make(int p, int c)
{
    Node *nd = &pool[pcnt++];
    
    nd->node = c;
    
    nd->next = head[p].next;
    head[p].next = nd;
}

int DFS(int node, int color)
{
    check[node] = color;
    
    for(Node *p = head[node].next ; p ; p=p->next)
    {
        if(check[p->node] == color )return 0;
        if(!check[p->node])
        {
            if(!DFS(p->node,3-color)) return 0;
        }
    }
    
    return 1;
}

int main (void)
{
    scanf("%d", &K);
    
    for(int tc=1;tc<=K;tc++)
    {
        int flag;
        scanf("%d %d",&V,&E);
        
        init();
        
        for(int i=0;i<E;i++)
        {
            int p,c;
            
            scanf("%d %d",&p,&c);
            Make(p,c);
            Make(c,p);
        }
        
        flag=0;
        for(int i=1;i<=V;i++)
        {
            if(!check[i])
            {
                flag=DFS(i,1);
                if(!flag) break;
            }
        }
        
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
