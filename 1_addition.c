#include<stdio.h>
//ok
int main()
{
    int x_size, y_size, z_size,i;
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
    for(i=0;i<z_size;i++)
    {
        x[i]=0;
        y[i]=0;
        z[i]=0;
    }
    printf("Enter the samples of first signal: \n");
    for(i=0;i<x_size;i++)
    {
        printf("Enter sample: ");
        scanf("%d",&x[i]);
    }
    printf("Enter the samples of second signal: \n");
    for(i=0;i<y_size;i++)
    {
        printf("Enter sample: ");
        scanf("%d",&y[i]);
    }
    for(i=0;i<z_size;i++)
    {
        z[i]=x[i]+y[i];
    }
    printf("\nFirst Signal samples: ");
    for(i=0;i<x_size;i++)
    {
        printf("%d  ",x[i]);
    }
    printf("\n\nSecond Signal samples: ");
    for(i=0;i<y_size;i++)
    {
        printf("%d  ",y[i]);
    }
    printf("\n\nResultant signal samples: ");
    for(i=0;i<z_size;i++)
    {
        printf("%d  ",z[i]);
    }
    printf("\n");
    return 0;
}