#include <stdio.h>
#include <string.h>

#define max 5 // 저장 가능한 최대 연산 개수

typedef struct
{
    char sik[100]; // char 로 sik에 저장할수있게 문자열을 비워둠
    int result; // 연산 결과
} hood;



int calculate(char* sik, int* result) //계산기 연산부분
{
    int su1, su2;
    char operator;
    
    if (sscanf(sik, "%d%c%d", &su1, &operator, &su2) != 3)  // sik 을 을불러와 ,"%d%c%d", &num1, &operator, &num2 는 숫자 연산부호 숫자 로 구별함 숫자 연산자 숫자 총 3개의 값을 가져와야함.
    {
        printf("잘못된 형식의 연산식입니다.\n");
        return 0;
    }

    switch (operator) // 연산부호로 들어온 operator 값으로 아래 케이스중 1개를 한개를 작동함
    {
        case '+':  //만일 + 가 연산부호로 들어온다면 아래 코드를 작동함
            *result = su1 + su2;
            break;
        case '-':
            *result = su1 - su2;
            break;
        case '*':
            *result = su1 * su2; // 연산된 값은 result에 저장
            break;
        case '/':
            if (su1 == 0) //하지만 0은 나눗셈이 불가능 함으로 초기로 돌림
            {
                printf("0으로 나눌 수 없습니다.\n");
                return 0;
            }
            *result = su1 / su2; //정상적인 값이 들어왔다면 아래 연산을 수행함
            break;
        default:
            printf("유효하지 않은 연산자입니다.\n");
            return 0;
    }

    return 1;
}

int main()
{
    char input[100];
    int result;
    hood operations [max]; //operations 저장 가능한 최대값을 위에서 설정한 max 값인 5로 저장
    int operationCount = 0;  //operationCount 는 0으로 설정
    int option;
    int i;

    while (1)
    {
        printf("1. 연산 시작하기\n");
        printf("2. 최근 연산 값 불러오기\n");
        printf("3. 종료\n");
        printf("옵션을 선택하세요: ");
        scanf("%d", &option); // 옵션 선택한 값을 저장함

        switch (option) //선택받은 옵션값으로 아래 케이스중 맞는 숫자를 실행함.
        {
            case 1:
                printf("\n연산식을 입력하세요: ");
                scanf("%s", input); //연산식을 받은것을 input으로 저장

                hood operation; // Operation 의 operation 을사용할거라는것을 선언
                strcpy(operation.sik, input); // 인풋값을 operation.expression에 복사한다고함.

                if (calculate(operation.sik, &result)) { // 계산기 값이 정상으로 돌아오고 계산 된값이 불러와지면
                    operation.result = result; //result 값을 operation.result 값에 저장을하고

                    if (operationCount < max) { // 계산결과가 max 값인 5보다 작을때
                        operations[operationCount] = operation; //위에서 저장된 operation.result 값에 연산식을 배정함
                        operationCount++; // 저장된 값에 카운트 값을 늘린다.
                    }
                    
                    else
                    { //최대값 보다 많을때
                        
                        for (i = 0; i < max - 1; i++) { // 맥스값 만큼 루프를 돌림
                            operations[i] = operations[i + 1]; // 1의 연산식은 0으로 간다 라고 하면서 한칸씩 덮어씌움
                        }
                        operations[max - 1] = operation; //최대 값보다 낮은 자리에 배치
                        
                    }
                    printf("연산 결과: %d\n", result); //출력부분
                }
                break;

            case 2:
                
                
                if (operationCount == 0) //아무 연산식도 입력하지 않은채로 연산식 출력 부분을 돌릴때 예외처리
                {
                    printf("\n\n저장된 연산식이 없습니다.\n\n");
                    break;
                }
                else
                {
                    printf("최근 %d개의 연산 값:\n\n-------------------\n\n", operationCount);
                    
                    for (i = 0; i < operationCount; i++) // operationCount 값은 실시간으로 증가하기때문에 operationCount 값 만큼 루프를 돌려 과거 데이터 출력
                    {
                        printf("%d. 연산 식: %s\n", i + 1, operations[i].sik); //0부터 출력하지 않기 위해 i+1 을 미리 하여 0부터가아닌 1부터 출력함
                        printf("   연산 결과: %d\n\n-------------------\n", operations[i].result); //아래도
                    }
                    break;
                }
                
                

            case 3:
                return 0;
                
        }

        printf("\n");
    }
}

