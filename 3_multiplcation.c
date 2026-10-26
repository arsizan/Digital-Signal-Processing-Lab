//multiplication of two discrete signals
#include<stdio.h>
//ok
int main()
{
    int x_size, y_size, z_size;
    int x[100],y[100],z[100];
    printf("Enter number of sample of first signal: ");
    scanf("%d",&x_size);
    printf("Enter number of sample of second signal: ");
    scanf("%d",&y_size);
    if(x_size>y_size)
    {
        z_size=x_size;
    }
    else
    {
        z_size=y_size;
    }
    for(int i=0;i<z_size;i++)
    {
        x[i]=0;
        y[i]=0;
        z[i]=0;
    }
    printf("Enter the samples of first signal: \n");
    for(int i=0;i<x_size;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("Enter the samples of second signal: \n");
    for(int i=0;i<y_size;i++)
    {
        scanf("%d",&y[i]);
    }
    printf("\n\nResultant signal samples after multiplication: ");
    for(int i=0;i<z_size;i++)
    {
        z[i]=x[i]*y[i];
        printf("%d  ",z[i]);
    }
    printf("\n");
    return 0;
}