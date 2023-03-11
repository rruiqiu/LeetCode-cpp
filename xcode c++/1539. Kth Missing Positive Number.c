//
//  1539. Kth Missing Positive Number.c
//  xcode c++
//
//  Created by Richard Qiu on 2023-03-06.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int findKthPositive(int* arr, int arrSize, int k){
    int count = 0;
    for(int i=0;i<=1000;i++){
        if(arr[i]!=i+1){
            count++;
        }
        if(count == k){
            return i;
        }
    }
    return 0;
}

//int lengthOfLongestSubstring(char * s){
//    //s consists of English letters, digits, symbols and spaces
//
//    //check repeating characters
//    //will it other english letters stuffs count?
//    // how do i check if the same letter appeared before ?
//    //does it have to be a hashtable, or i make a new string to store it and then check repetive?
//
//    //it should start with the repeated next char when detected repeat,
//    int maxLength = 0;
//    char subs[5000] = {'/0'};
//    int subsindex = 0;
//
//    int temp=0;
//    for(int i=0;i<strlen(s);i++){
//        bool condition = 1;
//        for(int j=0;j<strlen(subs);j++){
//            if(subs[j]== s[i]){ //used to check if there are any repeated characters in the substring
//                temp = strlen(subs)-j-1;
//                condition = 0;
//                break;
//            }
//        }
//        if(condition){
//            subs[subsindex] = s[i];
//            subsindex++;
//        }else{
//            if(subsindex > maxLength){
//                maxLength = subsindex;
//            }
//            //clear the current subset string
//            memset(subs,'/0',strlen(subs));
//            subsindex = 0;
//            //i want to set the new i was the one after the repeated char
//            i = i - temp-1;
//        }
//    }
//    if(subsindex > maxLength){
//        maxLength = subsindex;
//    }
//
//    return maxLength;
//}
bool isValid(char * s){
    //( ) -> 28, 29
    //{ } -> 123,125
    //[ ] -> 91,93
    if(strlen(s)==0){
        return 0;
    }
    char a[50000];
    int index = 0;
    for(int i=0;i<strlen(s);i++){
        /*
        Open brackets must be closed by the same type of brackets.
        Open brackets must be closed in the correct order.
        Every close bracket has a corresponding open bracket of the same type.
        */
        if(s[i] == 40 || s[i] == 123 || s[i] == 91){
            a[index] = s[i];
            index++;
        }else{
            if(index == 0){
                return 0;
            }
            index--;
            if((s[i]- a[index] == 1) || (s[i] - a[index] == 2)  ){
                index--;
            }else{
                return 0;
            }
        }
        //how to determine if the bracket is contained within another bracket
    }
    return 1;
}
char * longestCommonPrefix(char ** strs, int strsSize){
    char *s = (char*)calloc(5000, sizeof(char));
    
    //used one to store,
    //and another to check the reptive,
    //set repetitive to zero
    //return the final length
    for(int j=0;j<strlen(strs[0]);j++){
        s[j] = strs[0][j];
    }

    for(int i=1;i<strsSize;i++){
        if(strlen(strs[i])<strlen(s)){
            memset(s+strlen(strs[i]),0,strlen(s)-strlen(strs[i]));
        }
        for(int j=0;j<strlen(strs[i]);j++){
            if(s[j]!= strs[i][j]){
                memset(s+j,0,strlen(s)-j);
                break;
            }
        }
    }
    return s;
    
}

int lengthOfLongestSubstring(char *s)
{
    int offset[128];
    int max_len = 0;
    int len = 0;
    int index = 0;

    memset(offset, 0xff, sizeof(offset));//set the every num in offset = -1;
    while (*s != '\0') {
        if (offset[*s] == -1) {
            len++;
        } else {
            if (index - offset[*s] > len) {
                /* not included in sliding window, go on increasing */
                len++;
            } else {
                /* repetition in sliding window, count from scratch */
                len = index - offset[*s];
            }
        }
        if (len > max_len) {
            max_len = len;
        }
        offset[*s++] = index++;
    }

    return max_len;
}

int main(){
    char *str[] ={"flower","flow","flight"};
    
    char *s = longestCommonPrefix(str,3);

    printf("%s",s);
    free(s);
    //char *array = "One good thing about music";
    //isValid("()");
    //printf("%d",findKthPositive(arr, sizeof(arr)/sizeof(arr[0]), 5));
//    printf("%d",lengthOfLongestSubstring(s));
    return 0;
    
}
