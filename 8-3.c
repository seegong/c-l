#include <stdio.h>

int main(void)

{
    int a, b, c, d, e;
    double sum=0,avg=0;
    
    printf("배열을 사용하지 않고 5과목의 평균을 구하는 프로그램\n");
    printf("======================================\n");
    printf("1번째 과목:");
    scanf("%d",&a);
    printf("2번째 과목:");
    scanf("%d",&b);
    printf("3번째 과목:");
    scanf("%d",&c);
    printf("4번째 과목:");
    scanf("%d",&d);
    printf("5번째 과목:");
    scanf("%d",&e);
    
    sum = a+b+c+d+e;
    avg = sum/5;
    
    
    printf("-------------------------------------\n");
    printf("5과목 평균 [ %.2f]\n",avg);
    printf("-------------------------------------\n");
    

}
