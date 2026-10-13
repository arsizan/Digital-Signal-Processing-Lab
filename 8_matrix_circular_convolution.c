// circular convolution - the matrix method
#include <stdio.h>

int main()
{
    int i, j, x1_size, x2_size, y_size;

    printf("Enter number of first signal samples: ");
    scanf("%d", &x1_size);
    printf("Enter number of second signal samples: ");
    scanf("%d", &x2_size);

    // Determine the size for circular convolution (N = max length)
    if(x1_size > x2_size)
    {
        y_size = x1_size;
    }
    else
    {
        y_size = x2_size;
    }

    int x1[y_size], x2[y_size], y[y_size];
    int matrix[y_size][y_size];

    // Initialize arrays with zeros (handles zero-padding automatically)
    for(i = 0; i < y_size; i++)
    {
        x1[i] = 0;
        x2[i] = 0;
        y[i] = 0;
    }

    printf("Enter first signal sequences: ");
    for(i = 0; i < x1_size; i++)
    {
        scanf("%d", &x1[i]);
    }

    printf("Enter second signal sequences: ");
    for(i = 0; i < x2_size; i++)
    {
        scanf("%d", &x2[i]);
    }

    // 1. Construct the Circulant Matrix from the second signal
    for(i = 0; i < y_size; i++)
    {
        for(j = 0; j < y_size; j++)
        {
            // Shifts elements to the right for each subsequent row
            matrix[i][j] = x2[(i - j + y_size) % y_size];
        }
    }

    // (Optional) Print the circulant matrix to visualize the matrix structure
    printf("\nCirculant Matrix (from second signal):\n");
    for(i = 0; i < y_size; i++)
    {
        for(j = 0; j < y_size; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // 2. Perform Matrix-Vector Multiplication: y = Matrix * x1
    for(i = 0; i < y_size; i++)
    {
        for(j = 0; j < y_size; j++)
        {
            y[i] += matrix[i][j] * x1[j];
        }
    }

    // 3. Print the resulting sequence
    printf("\nResult of Circular Convolution:\n");
    for(i = 0; i < y_size; i++)
    {
        printf("%d  ", y[i]);
    }
    printf("\n");

    return 0;
}