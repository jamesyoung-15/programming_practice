#include <stdio.h>
#include <stdint.h>

int main()
{
    //grid to emulate 24x24 pixel display
    uint8_t grid[24][24]={0};
    //data generated from dotmatrixtool.org
    uint8_t data[] =
    {
    0x00, 0x01, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x7f, 0x01, 0x00, 0x80, 0x01, 0x00, 0x80, 0x81, 0xff, 0x83, 0x01, 0x10, 0x80, 0x00, 0x10, 0x00, 0xf0, 0xff, 0x0f, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x11, 0x00, 0x00, 0x1e, 0x00
    };

    //counter to keep track of row
    uint8_t row =0;
    //each row has 24 bits, so 3 hex values, so split each row into 3 and keep track with column_split
    uint8_t column_split =0;
    for(uint8_t i = 0; i<72; i++)
    {
        uint8_t temp = data[i];
        if(i%3==0 && i!=0)
        {
            row++;
        }
        for(int k = 0; k<8;k++)
        {
            if(temp & 0x01)
            {
                // printf("k= %d, row = %d\n",k, row);
                grid[row][k+column_split*8] = 1;
            }
            temp = temp>>1;
        }
        column_split++;
        if(column_split>=3)
        {
            // printf("i=%d\n",i);
            column_split =0;
        }
    }

    for(int i = 0; i<24; i++)
    {
        for(int j = 0; j<24;j++)
        {
            if(grid[i][j]==1)
            {
                printf("1");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }    

    return 0;
}