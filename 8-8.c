#include <stdio.h>

int main(void)

{
    int a[2][3];
    int row ,sum=0;
    double avg=0;
    
    printf("\n");
    printf("\n");
    
    for(row=0;row<2;row++)
    {
        printf("%d 번째의 학생 정수를 입력하시오\n",row+1);
        printf("-------------------------------\n");
        printf("국어 점수:\n");
        scanf("%d",&a[row][0]);
        printf("영어 점수:\n");
        scanf("%d",&a[row][1]);
        printf("수학 점수:\n");
        scanf("%d",&a[row][2]);
        
        
        sum = a[row][2]+a[row][1]+a[row][0];
        avg = sum/3.0;
        printf("-------------------------------\n");
        printf("%d\n",sum);
        printf("%.3f\n",avg);
        printf("-------------------------------\n");
        
    }
}
