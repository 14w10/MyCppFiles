#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void sp(int &x,int &y)
{
    int tp=x;x=y;y=tp;
}
int it(int a[],int b[],int n)
{
    int i,j,fg=1;
    for(i=1;i<n;i++)
    {
        int tp=i;
        for(j=i;j>=0;j--)
        if(a[tp]<a[j])
        {
            sp(a[tp],a[j]);tp=j;
        }
        if(fg==0)
        {
            printf("Insertion Sort\n");
            for(j=0;j<n-1;j++) printf("%d ",a[j]);
            printf("%d\n",a[j]);
            return 1;
        }
        fg=0;
        for(j=0;j<n;j++)
        if(a[j]!=b[j])
        {
            fg=1;break;
        }
    }
    return 0;
}
void max_heap(int a[],int st,int ed)
{
    int dad=st;
    int son=dad*2+1;
    while(son<=ed)
    {
        if(son+1<=ed&&a[son]<a[son+1]) son++;
        if(a[dad]>a[son]) return ;
        else
        {
            sp(a[dad],a[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}
void heap(int a[],int b[],int n)
{
    printf("Heap Sort\n");
    int i,j,fg=1;
    for(i=n/2-1;i>=0;i--)
    {
        max_heap(a,i,n-1);
        if(fg==0)
        {
            for(j=0;j<n-1;j++) printf("%d ",a[j]);
            printf("%d\n",a[j]);
            return ;
        }
        fg=0;
        for(j=0;j<n;j++)
        if(a[j]!=b[j])
        {
            fg=1;break;
        }
    }
    for(i=n-1;i>0;i--)
    {
        sp(a[0],a[i]);
        max_heap(a,0,i-1);
        if(fg==0)
        {
            for(j=0;j<n-1;j++) printf("%d ",a[j]);
            printf("%d\n",a[j]);
        }
        fg=0;
        for(j=0;j<n;j++)
        if(a[j]!=b[j])
        {
            fg=1;break;
        }
    }
}
int main(void)
{
    int i,n,a[120],b[120],c[120];
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i],c[i]=a[i];
    for(i=0;i<n;i++) cin>>b[i];
    if(it(a,b,n)==1) return 0;
    else heap(c,b,n);
    return 0;
}
