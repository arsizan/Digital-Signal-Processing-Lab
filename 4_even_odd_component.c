//even and odd components of a discrete signal
#include<stdio.h>
int main()
{
    int x_size,i;
    int x[100],x_even[100],x_odd[100];
    printf("Enter number of sample of signal: ");
    scanf("%d",&x_size);
    printf("Enter the samples of signal: \n");
    for(i=0;i<x_size;i++)
    {
        printf("Enter sample: ");
        scanf("%d",&x[i]);
    }
    for(i=0;i<x_size;i++)
    {
        if(i%2==0)
        {
            x_even[i]=x[i];
        }
        else
        {
            x_odd[i]=x[i];
        }
    }
    printf("\nOriginal Signal samples: ");
    for(i=0;i<x_size;i++)
    {
        printf("%d  ",x[i]);
    }
    printf("\n\nEven components: ");
    for(i=0;i<x_size;i++)
    {
        if(i%2==0)
        {
            printf("%d  ",x_even[i]);
        }
    }
    printf("\n\nOdd components: ");
    for(i=0;i<x_size;i++)
    {
        if(i%2!=0)
        {
            printf("%d  ",x_odd[i]);
        }
    }
    printf("\n");
    return 0;
}