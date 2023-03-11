//
//  practise.c
//  xcode c++
//
//  Created by Richard Qiu on 2023-03-01.
//

#include <stdio.h>


int search(int* nums, int numsSize, int target){
    int lowerindex = 0;
    int upperindex = numsSize-1;

    while(lowerindex < upperindex){
        int index = (lowerindex+upperindex)/2;
        
        if(nums[index] == target){
            return index;
        }

        if(target > nums[index]){
            lowerindex = index+1;
        }

        if(target < nums[index]){
            upperindex = index-1;
        }

    }
    return -1;
}


int main(){
    int arr[] = {5};
    printf("%d",search(arr, 1, 5));
    return 0;
}
