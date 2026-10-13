//A program of matrix multiplication
#include<stdio.h>

int main()
{
    int i,j,n,x_size,y_size,h_size,sum=0,temp,x_o,y_o,h_o;
    printf("Enter number of output samples: ");
    scanf("%d",&y_size);
    printf("Enter number of impulses: ");
    scanf("%d",&h_size);
    x_size=y_size-h_size+1;
    if(h_size>x_size)
    {
        n=h_size;
    }
    else
    {
        n=x_size;
    }
    int y[y_size],h[n],x[x_size];

    for(i=0;i<n;i++)
    {
        h[i]=0;
    }
    printf("Enter output sequences: ");
    for(i=0;i<y_size;i++)
    {
        scanf("%d",&y[i]);
    }
    printf("\nEnter impulse sequences: ");
    for(i=0;i<h_size;i++)
    {
        scanf("%d",&h[i]);
    }
    printf("Enter origin point of y(n) \n");
    scanf("%d",&y_o);
    printf("Enter origin point of h(n) \n");
    scanf("%d",&h_o);
    x_o=y_o-h_o;

    for(i=0;i<x_size;i++)
    {
        temp=i;
        sum=0;
        for(j=0;j<i;j++)
        {
            sum=sum+x[j]*h[temp];
            temp--;
        }
        x[i]=(int)((y[i]-sum)/h[0]);
    }
    printf("\n Sample values of input: ");
    for(i=0;i<x_size;i++)
    {
        printf("%d  ",x[i]);
    }

    printf("\n\nOrigin point of input: %d\n",x_o);
    return 0;
}