//even and odd components of a discrete signal
#include<stdio.h>
#define MAX 100

/* n-তম মান ফেরত দেয়, সীমার বাইরে হলে 0 */
int xval(int x[], int ns, int ne, int n)
{
    if(n < ns || n > ne) return 0;
    return x[n-ns];
}

int main()
{
    int x[MAX];
    float xe[2*MAX+1], xo[2*MAX+1];
    int x_size, i, n, org, ns, ne, L, a, b;

    printf("Enter number of sample of signal: ");
    scanf("%d",&x_size);
    printf("Enter the samples of signal: \n");
    for(i=0;i<x_size;i++)
    {
        printf("Enter sample: ");
        scanf("%d",&x[i]);
    }
    printf("Enter the sample no. which is the origin (1 to %d): ", x_size);
    scanf("%d",&org);

    ns = -(org-1);              /* starting index */
    ne = ns + x_size - 1;       /* ending index */

    /* ফলাফল সবসময় origin-র দুই পাশে সমান দূর পর্যন্ত ছড়ায় */
    a = (ns<0) ? -ns : ns;
    b = (ne<0) ? -ne : ne;
    L = (a>b) ? a : b;

    for(n=-L; n<=L; n++)
    {
        xe[n+L] = (xval(x,ns,ne,n) + xval(x,ns,ne,-n)) / 2.0;
        xo[n+L] = (xval(x,ns,ne,n) - xval(x,ns,ne,-n)) / 2.0;
    }

    printf("\nOriginal Signal:\n");
    for(i=0;i<x_size;i++)
    {
        printf("x[%d] = %d\n", ns+i, x[i]);
    }

    printf("\nEven component:\n");
    for(n=-L; n<=L; n++)
    {
        printf("xe[%d] = %.1f\n", n, xe[n+L]);
    }

    printf("\nOdd component:\n");
    for(n=-L; n<=L; n++)
    {
        printf("xo[%d] = %.1f\n", n, xo[n+L]);
    }

    printf("\nVerification (xe + xo = x):\n");
    for(n=-L; n<=L; n++)
    {
        printf("n=%d : %.1f + %.1f = %.1f\n", n, xe[n+L], xo[n+L], xe[n+L]+xo[n+L]);
    }

    return 0;
}