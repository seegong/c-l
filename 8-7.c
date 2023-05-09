#include <stdio.h>

int main(void)

{
    int data [3][5] = {{2,4,6,8,10},{12,14,16,18,20},{22,24,26,28,30}};
    int row,col;
    
    printf("2차원 배열로 짝수를 출력하는 프로그램\n");
    printf("=========================================\n");
    
    for(row=0;row < 3;row++)
    {
        printf("%d 행 출력:",row+1);
        for(col=0;col<5;col++)
        {
            printf("%3d",data[row][col]);
            
        }
        printf("\n");
    }
    printf("=========================================\n");
}

