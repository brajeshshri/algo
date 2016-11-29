#include<stdio.h>

int get_msb(int num)
{
    int bitpos = 0;

    while(num) {
        bitpos++;
        num = num >> 1;
    }
    return (bitpos == 0) ? 0 : bitpos -1;
}

int bitwise_and_of_range(int srange, int erange)
{
    int s_msb = 0;
    int e_msb = 0;
    int result = 0;
    while(srange && erange) {
        s_msb = get_msb(srange);
        e_msb = get_msb(erange);

        if(s_msb == e_msb) {
            srange -= 1<< s_msb;
            erange -= 1<<s_msb;
            result += 1 << s_msb;
        } else {
            break;
        }
    }

    return result;
}

int main()
{
    int srange = 0, erange = 0;
    printf("Enter starting range: ");
    scanf("%d", &srange);

    printf("Enter ending range: ");
    scanf("%d", &erange);

    int result = bitwise_and_of_range(srange, erange);

    printf(" Result is: %d\n", result); 
}

