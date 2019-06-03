#include<stdio.h>
#include <string.h>
#include <math.h>

unsigned int switch_bit(unsigned int num, int bit);
char* to_binary(unsigned int value, char* binary_num);

int main()
{
    char binary_num[37] = "\0";
    unsigned int num = 0;
    int bit = 0;

    printf("Podaj dodatnia, calkowita liczbe:");
    scanf("%u",&num);

    while(bit>=0)
    {

        printf("\nLiczba: %u(10) = %s(2)\n",num,to_binary(num,binary_num));
        printf("Ktory bit chcesz zmienic:");
        scanf("%d",&bit);
        num = switch_bit(num,bit);//dla bitow 0 i mniejszych nie robi nic
    }

    return 0;
}

unsigned int switch_bit(unsigned int num, int bit)
{
    if(bit<=0) return num;

    num ^= (1<<bit-1);

    return num;
}

char* to_binary(unsigned int value, char* binary_num)
{
    int i,j;
    int potega = 31;
    binary_num[0] = '\0';

    for(i=4;i>0;i--){
        for(j=8;j>0;j--){
            if( (unsigned long long)pow( 2 , potega ) & value ){
                strcat(binary_num,"1");
            }else{
                strcat(binary_num,"0");
            }
            potega--;
        }
        strcat(binary_num," ");
    }

    return binary_num;
}
