#include <stdio.h>

int check(int x, int y, int h, int k, int a, int b)
{
    float equation = ((float)(x-h)*(x-h))/(a*a) + (float)((y-k)*(y-k))/(b*b);
    if(equation<=1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int a =8; //a
    int b = 6; //b
    int h = 10; //h
    int k = 8; //k

    //equation is ((x-h)^2)/a^2 + ((y-k)^2)/b^2 == 1
    for(int x=h-a;x<=h+a;x++)
    {
        for(int y=k-b;y<=k+b;y++)
        {
            int original_point = check(x,y,h,k,a,b);
            int horizontal_point = check(x+1,y,h,k,a,b);
            int vertical_point = check(x,y+1,h,k,a,b);
            int outside_point = check(x+1,y+1,h,k,a,b);
            if(original_point + horizontal_point + vertical_point + outside_point<4 && original_point + horizontal_point + vertical_point + outside_point>1)
            {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

}