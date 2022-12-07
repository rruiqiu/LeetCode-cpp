//
//  bit manipulation.cpp
//  xcode c++
//
//  Created by Richard Qiu on 2022-12-01.
//

#include <stdio.h>
#include <cstdio>
#include <cinttypes>
#include <iostream>
#include <stdint.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= n & 1;
            n >>= 1;
        }
        
        return result;
    }
};

int main(){
    Solution res;
    uint32_t a = 0b10011100000000000000000000000000;
    uint32_t b;
    b = res.reverseBits(a);
    return 0;
}
