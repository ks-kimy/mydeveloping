#include <stdio.h>
#include <math.h>

int number(int num);    // 자릿 수 구하기.
int left(int x, int y); // 왼쪽방향으로 합 구하기, x = L , y= K, n : 자릿 수

int main()
{
    int l, r, k;
    int i, j;
    i = 0;
    j = 0;

    printf("L : ");
    scanf("%d", &l);
    printf("R : ");
    scanf("%d", &r);
    printf("K : ");
    scanf("%d", &k);
    printf("왼쪽 기준 : %d ,오른쪽 기준: %d\n", left(l, k), left(k, r));

    if (left(l, k) < left(k, r))
    {
        printf("총합 : %d\n", left(l, k));
    }
    else if (left(l, k) > left(k, r))
    {
        printf("총합 : %d\n", left(k, r));
    }
    else
    {
        printf("총합 : %d\n", left(r, k));
    }

    return 0;
}

int number(int num)
{
    int count = 0;

    while (num != 0)
    {
        count++;
        num /= 10;
    }
    return count;
}
int left(int x, int y) // x에 시작값 대입, y 에 도착값
{
    int sum = 0; // 총합을 나타냄 x 부터 y 까지 진행될 때 변하는 값
    int i;
    for (i = x; i < y; i++)
    {
        int count = 0;
        int temp;
        int num = number(i + 1); // i 를 999 라고 해보자
        if (i % 10 != (i + 1) % 10)
        {
            count += 1; // count =1
        }
        for (temp = 1; temp <= num; temp++) // n =4 4자리 수에서 출발
        {
            if ((i / (int)(pow(10, temp))) != ((i + 1) / (int)(pow(10, temp)))) // 999/10=99 1000/10=100
            {
                count++;
            }
        }
        sum = sum + count;
    }
    return sum;
}
