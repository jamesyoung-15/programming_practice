#include <stdio.h>

void swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr_size, int data[], char *str)
{
    int i;
    printf("%s", str);
    for(i=0;i<arr_size;i++)
    {
        printf("%d\t", data[i]);
    }
}
void bubble(int data[], int arr_size)
{
    int i, j, go_on;

    for(i=0;i<arr_size;i++)
    {
        print_array(arr_size, data, "\ninside bubble\n");
        printf("i = %d, input any int to continue:", i);
        scanf("%d", &go_on);
        for(j=arr_size -1; j>i; j--)
        {
            if(data[j-1]>data[j])
            {
                swap(&data[j-1],&data[j]);
            }
        }
    }
}

int main(void)
{
    const int SIZE = 7;
    int dataArr[]= {12, 51, 81, 61, 20, 101, 8};
    print_array(SIZE, dataArr, "Data: ");
    bubble(dataArr, SIZE);
    print_array(SIZE, dataArr, "Sorted Data: ");
    printf("\n");
    return 0;
}