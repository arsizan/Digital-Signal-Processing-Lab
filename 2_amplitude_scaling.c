//amplitude factor, one signal is multiplied by this factor
#include<stdio.h>
//ok
int main()
{
    int x_size,i;
    float x[100],y[100];
    float factor;
     printf("Enter the amplitude factor: ");
    scanf("%f",&factor);
    printf("Enter number of sample of signal: ");
    scanf("%d",&x_size);
    printf("Enter the samples of signal: \n");
    for(i=0;i<x_size;i++)
    {
        scanf("%f",&x[i]);
        
    }
    printf("\n\nResultant signal samples after amplitude scaling: ");
    for(i=0;i<x_size;i++)
    {
        x[i]=x[i]*factor;
        printf("%.3f ", x[i]);
    }
    printf("\n");
    return 0;
}