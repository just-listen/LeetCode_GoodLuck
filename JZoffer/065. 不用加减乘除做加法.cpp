#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    int add(int a, int b) {
        //求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止 
        while(b != 0){
            //保存进位值，下次循环用
            int c = (unsigned int)(a & b)<<1;
            //保存不进位值，下次循环用
            a ^= b;
            //如果还有进位，再循环，如果没有，则直接输出没有进位部分即可。
            b = c;
        }
    return a;
    }
};

int main(){
    Solution s;
    
    return 0;
}