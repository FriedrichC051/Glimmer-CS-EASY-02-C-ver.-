#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
int sum=0;
void ins_head(int x)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
    nd->val=x;
    nd->next=head;
    head=nd;
    if(tail==NULL){tail=nd;}
}
void ins_tail(int x)
{
    struct node *nd=(struct node*)malloc(sizeof(struct node));
    nd->val=x;
    nd->next=NULL;
    if(tail==NULL){head=tail=nd;}
    else
    {
        tail->next=nd;
        tail=nd;
    }
}
int del(int i)
{
    if(head==NULL)return 0;
    struct node *temp=head;
    if(i==1)
    {
        head=head->next;
        if(head==NULL)tail=NULL;
        free(temp);
        return 1;
    }
    for(int cnt=1;temp!=NULL&&cnt<i-1;++cnt)
    {
        temp=temp->next;//当cnt=i-2时，temp已经指向i-1
        //cout<<temp->val<<'\n';
    }
    if(temp==NULL||temp->next==NULL)return 0;//如果删除的元素并不存在
    struct node *t=temp->next;
    temp->next=t->next;
    if(t->next==NULL)tail=temp;
    free(t);
    return 1;
}
void print()
{
    int cnt=1;
    struct node *temp=head;
    while(temp!=NULL&&cnt<=sum)
    {
        printf("rk%d: %d\n",cnt,temp->val);
        temp=temp->next;
        cnt++;
    }
}
void cir()
{
    //if(head==NULL)return;
    tail->next=head;
}
void del2(struct node *p)
{
    p->val=p->next->val;
    struct node *t=p->next;
    p->next=p->next->next;
    free(t);
    sum--;
}
void num()//报数
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->val==3)break;
        temp=temp->next;
    }
    int cnt=1,turn=1;
    while(temp!=NULL)
    {
        if(temp->next==temp){printf("%d\n",temp->val);break;}
        if(cnt==turn)
        {
            printf("%d\n",temp->val);
            struct node *t=temp;
            del2(t);
            //temp=temp->next;

            turn++;
            cnt=1;
        }
        else
        {
            temp=temp->next;
            cnt++;
        }
        //print();
    }
}
int main()
{
    freopen("Josephus.out","w",stdout);
    int n=16;
    char op;
    int a,b,c,loc;
    ins_head(1);
    sum++;
    while(n--)
    {
        scanf(" %c",&op);
        if(op=='H')
        {
            scanf("%d %d %d",&a,&b,&c);
            ins_head(c);
            ins_head(b);
            ins_head(a);
            sum+=3;
        }
        else if(op=='T')
        {
            scanf("%d %d %d",&a,&b,&c);
            ins_tail(a);
            ins_tail(b);
            ins_tail(c);
            sum+=3;
        }
        else if(op=='D')
        {
            scanf("%d",&loc);
            if(del(loc))sum--;
        }
        else cir();
        //print();printf("\n");
    }
    num();
    return 0;
}

