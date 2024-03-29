#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

class Solution{
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for(int i = 1; i < pow(10, n); i++){
            res.push_back(i);
        }
        return res;
    }

};

// 后面的不懂不想看
class Solution2{
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n <= 0) return res;
        //创建一个能容纳最大值的字符数组,初始全部设置为0
        string number(n, '0');
        while (!Increment(number)){
            saveNumber(number);
        }
        return res;
    }
    bool Increment(string& number) {
        bool isOverflow = false;        //检测是否越界
        int nTakeOver = 0;              //存储进位
        int nLength = number.size();
        for (int i = nLength - 1; i >= 0; i--){
            int nSum = number[i] - '0' + nTakeOver;
            if (i == nLength - 1){      //如果是第一位，进位
                nSum++;
            }
            if (nSum >= 10){            //有进位
                if (i == 0){            //如果是最高位有进位，说明超过了给定得到最大值，越界
                    isOverflow = true;
                }
                else{
                    nTakeOver = 1;
                    number[i] = nSum - 10 + '0';//对第i位进行设置
                }
            }
            else{           //没有进位,设置第i位数字,并直接跳出循环
                number[i] = nSum + '0';
                break;
            }
        }
        return isOverflow;
    }
    void saveNumber(string number){		//由于此处输出，不需要修改number，因此不需要加引用
        string s = "";
        bool isBegin0 = true;
        string::iterator it = number.begin();
        while (it != number.end())		{
            if (isBegin0 && *it != '0') isBegin0 = false;
            if (!isBegin0){
                s += *it;
            }
            it++;
        }
        int num = stoi(s);
        res.push_back(num);
    }
};

class Solution_digui{
public:
    vector<int> res;
    vector<int> printNumbers(int n) {
        if (n <= 0) return res;
        string number(n, '0');
        for (int i = 0; i <= 9; i++){   //从高位到低位进行全排列
            number[0] = i + '0';        //首字符赋初值
            permutationNumbers(number, n, 1);//设置下一位
        }
        return res;
    }
    //对数字全排列
    void permutationNumbers(string& number, int length, int index) {
        if (index == length) {      //递归边界
            saveNumber(number);     //存储结果
            return;
        }
        else{
            for (int i = 0; i <= 9; i++){
                number[index] = '0' + i;//设置第index位的字符
                permutationNumbers(number, length, index + 1);
            }
        }
    }
    //存储结果
    //只能存储前导非0的排列
    void saveNumber(string number) {
        bool isBegin0 = true;
        string tempStr = "";
        string::iterator it = number.begin();
        while (it != number.end()){
            if (isBegin0 && *it != '0') 
                isBegin0 = false;
            if (!isBegin0) {
                tempStr += *it;
            }
            it++;
        }
        //从高位到低位全排列，要注意首字符为0时，tempStr为空，不能执行stoi
        if (tempStr != "") {
            int tempNum = stoi(tempStr);
            res.push_back(tempNum);
        }
        // string tempStr(number.size(),'0');
        // std::cout<< stoi(number) <<" ";
        // if(number!=tempStr)
        // res.push_back(stoi(number));
    }
};

int main(){
    
    return 0;
}