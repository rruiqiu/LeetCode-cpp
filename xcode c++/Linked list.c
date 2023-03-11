#include <stdio.h>

int calculateCycleLength(int a, int b){
    int max = 0;
    for(int i=a;i<=b;i++){
        int count = 0;
        int n = i;
        while(n!=1){
            if(n%2==0){
                n = n/2;
            }else{
                n = n*3 + 1;
            }
            count ++;
        }
        if(count > max){
            max = count;
        }
    }
    return max;
}

int main()
{
    int i=1;
    int j=10;
   // calculateCycleLength(i,j);
    printf("%d",calculateCycleLength(i,j));

    return 0;
}
