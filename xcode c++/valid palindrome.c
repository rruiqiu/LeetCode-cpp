//
//  valid palindrome.c
//  xcode c++
//
//  Created by Richard Qiu on 2023-03-04.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //return format [nums[i],nums[j],nums[k]]
    //could have more than one solution
    //and notice the solutino set must not contain duplicate triplets, which means it could have different orders
    //fix one point, then do the two sum problem for the rest two
    qsort(nums,  numsSize, sizeof(int), comparator);
    int size = 0;
    int **arr = 0;
    //-4-1-1012
//    for(int i=0;i< numsSize;i++){
//        printf("%d",nums[i]);
//    }
    //now the problem is to fix repetive elements
    for(int i=0;i<numsSize;i++){
        int first_index = i+1;
        int last_index = numsSize-1;
        int target = 0 - nums[i];
        while(first_index < last_index){
            int temp = nums[first_index]+nums[last_index];
            if(temp == target){
                // if(size == 0){
                    size++;
                // }
                //first need to check if it was duplicate tripletes
                //runtime error cuz before is not assigned int*
                //cuz it will store the 2d array pointer, wow amazing
                arr = realloc(arr,(size)*sizeof(int*));
                arr[size-1] = (int*)malloc(3*sizeof(int));
                arr[size-1][0]=nums[i];
                arr[size-1][1]=nums[first_index];
                arr[size-1][2]=nums[last_index];
                first_index++;
                last_index--;
                while(first_index < last_index && nums[first_index] == nums[first_index-1]){
                    first_index++;
                }
                while(first_index < last_index && nums[last_index] == nums[last_index+1]){
                    last_index--;
                }
            }else if(temp < target){
                first_index++;
            }else{
                last_index--;
            }
        }
        while(i<numsSize-1 && nums[i] == nums[i+1]){
            i++;
        }
    }
    *returnSize = size;
    *returnColumnSizes = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*returnColumnSizes)[i] = 3;
    }
    //now how do we determine if the same array appeared before?
    return arr;
}


bool isPalindrome(char * s){
//reads the same forward and backward
//one pointer at the front
//one pointer at the back
//loop thourgh, only capture the valid pointer

//an algorithm first check if the current is a valid alphbateic char, if yes,
//then store as the temp
//then check inversly if it is, then store as another temp,
//finally compare these two temps if they are the same

    int last_index = strlen(s)-1;
    int first_index = 0;
    char temp1 = 0;
    char temp2 = 0;
    while(first_index <= last_index){
        if(temp1 == 0){
            if(s[first_index] >= 97 && s[first_index] <= 122){
                temp1 = s[first_index];
                first_index ++;
            }else if(s[first_index] >= 65 && s[first_index] <= 90){
                temp1 = s[first_index]+32;
                first_index ++;
            }else{
                first_index ++;
                // temp1 = 0;
            }
        }

        if(temp2 == 0){
            if(s[last_index] >= 97 && s[last_index] <= 122){
                temp2 = s[last_index];
                last_index--;
            }else if(s[last_index] >= 65 && s[last_index] <= 90){
                temp2 = s[last_index] + 32;
                last_index--;
            }else{
                last_index--;
                // temp2 = 0;
            }
        }

        if(temp1!= 0 && temp2!=0){
            if(temp1 == temp2){
                temp1 = 0;
                temp2 = 0;
            }else{
                return 0;
            }
        }
    }
    return 1;
}

int main(){
//    char s[] = "A man, a plan, a canal: Panama";
//    isPalindrome(s);
    int count;
    int *returnColumnSize;
    int nums[] = {-1,0,1,2,-1,-4};
    int length = sizeof(nums)/sizeof(nums[0]);
    int **triplets = threeSum(nums,length,&count,&returnColumnSize);
    for (int i = 0; i < count; i++) {
        printf("%d %d %d\n", triplets[i][0], triplets[i][1], triplets[i][2]);
    }
    
    
    return 0;
}
