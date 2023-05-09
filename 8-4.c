#include <stdio.h>

int main(void)

{
    int det[5],cnt;
    
    double sum=0,avg=0;
    
    printf("배열을 사용하여 5과목의 평균을 산출 하는프로그램\n");
    printf("====================================\n");
    
    
    
    
    for(cnt=0;cnt<=4;cnt++)
    {
        printf("%d 번째 과목:",cnt+1);
        scanf("%d",&det[cnt]);
        sum += det[cnt];
        
    }
    avg = sum/5;
    printf("-------------------------------------\n");
    printf("5과목 평균 [ %.2f]\n",avg);
    printf("-------------------------------------\n");
    

}
