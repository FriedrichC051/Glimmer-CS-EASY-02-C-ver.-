#include<stdio.h>
char st[1000],s[1000];
int top=0,pos=0;
int main()
{
    freopen("part3.in","r",stdin);
    freopen("part3.out","w",stdout);
    scanf("%s",s);
    int op;
    for(int i=1;i<=34;++i)
    {
        scanf("%d",&op);
        if(i&1)
            while(op--)
            {
                st[++top]=s[pos];
                pos++;

            }
        else
            while(op--)
            {
                printf("%c",st[top]);
                top--;
            }
    }
    return 0;
}
