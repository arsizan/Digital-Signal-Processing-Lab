#include<stdio.h>

int main()
{
    int i,j,x_size,y_size,h_size,x_o,h_o,y_o;

    printf("\nEnter number of samples of x(n):");
    scanf("%d",&x_size);
    printf("\nEnter number of samples of h(n)");
    scanf("%d",&h_size);

    y_size=x_size+h_size-1;

    int x[y_size],y[y_size],h[y_size];
// padding of zeors
    for(i=0;i<y_size;i++)
    {
        x[i]=0;
        h[i]=0;
        y[i]=0;
    }

    printf("\n\nEnter sample values of x(n):\n");

    for(i=0;i<x_size; i++)
        scanf("%d",&x[i]);

    printf("Enter sample values of h(n) \n");

    for(i=0;i<h_size; i++)
        scanf("%d",&h[i]);

   printf("Enter starting index of x(n) [n value of 1st sample]: ");
scanf("%d",&x_o);
printf("Enter starting index of h(n) [n value of 1st sample]: ");
scanf("%d",&h_o);
y_o = x_o + h_o;


/* convolution operation */

    for(i=0;i<y_size;i++)
    {
        y[i]=0;

        for(j=0;j<=i;j++)
        {
            y[i]=y[i]+(x[j]*h[i-j]);
        }
    }
//displaying the o/p

    printf("\n Sample values of output: ");
    for(i=0;i<y_size;i++)
    {
        printf("%d ",y[i]);
    }

    printf("\n\nOrigin point of output: %d\n",y_o);

    return 0;
}