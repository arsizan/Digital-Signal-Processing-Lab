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
        scanf("%d",&x[i]);
    }
    printf("Enter the samples of second signal: \n");
    for(i=0;i<y_size;i++)
    {
        scanf("%d",&y[i]);
    }
     printf("Resultant signal samples: ");
    for(i=0;i<z_size;i++)
    {
        z[i]=x[i]+y[i];
        printf("%d  ",z[i]);
    }
    
    printf("\n");
    return 0;
}

// #include<stdio.h>

// int main()
// {
//     int x_size, y_size, z_size, i;
//     int ox, oy, oz;                 /* origin = sample no. of n=0 */
//     int xs, ys, zs, xe, ye, ze;     /* start & end index */
//     int x[100], y[100], z[100];

//     printf("Enter number of sample of first signal: ");
//     scanf("%d",&x_size);
//     printf("Enter the sample no. which is the origin: ");
//     scanf("%d",&ox);
//     printf("Enter number of sample of second signal: ");
//     scanf("%d",&y_size);
//     printf("Enter the sample no. which is the origin: ");
//     scanf("%d",&oy);

//     xs = -(ox-1);           /* first index of x */
//     ys = -(oy-1);           /* first index of y */
//     xe = xs + x_size - 1;   /* last index of x  */
//     ye = ys + y_size - 1;   /* last index of y  */

//     if(xs<ys)  zs = xs;  else  zs = ys;      /* earliest start */
//     if(xe>ye)  ze = xe;  else  ze = ye;      /* latest end */

//     z_size = ze - zs + 1;
//     oz = -zs + 1;           /* origin of result */

//     for(i=0;i<z_size;i++)
//     {
//         z[i]=0;
//     }

//     printf("Enter the samples of first signal: \n");
//     for(i=0;i<x_size;i++)
//     {
//         scanf("%d",&x[i]);
//     }
//     printf("Enter the samples of second signal: \n");
//     for(i=0;i<y_size;i++)
//     {
//         scanf("%d",&y[i]);
//     }

//     for(i=0;i<x_size;i++)
//     {
//         z[xs+i-zs] = z[xs+i-zs] + x[i];      /* put x in its place */
//     }
//     for(i=0;i<y_size;i++)
//     {
//         z[ys+i-zs] = z[ys+i-zs] + y[i];      /* add y in its place */
//     }

//     printf("\nResultant signal samples: ");
//     for(i=0;i<z_size;i++)
//     {
//         printf("%d  ",z[i]);
//     }
//     printf("\n\nOrigin of resultant signal: sample no. %d\n", oz);

//     return 0;
// }