//
// Created by ckp on 18-7-13.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef int PRECISION;
class Solution {
public:
    string high_precision_mul(const string &a, const string &b) {
        vector<string> sum_list;
        // a*b
        for(PRECISION i=b.size()-1;i>=0;i--) {
            string each_sum;
            //Initialize
            each_sum.insert(each_sum.begin(), b.size()-i-1,'0');
            PRECISION b_i = b[i] - '0';
            PRECISION carry = 0;
            for(PRECISION j=a.size()-1;j>=0;j--){
                // to PRECISION
                PRECISION a_j = a[j] - '0';
                PRECISION res = b_i * a_j + carry;
                // calculate next carry
                char chr = (char)(res % 10) + '0';
                each_sum.insert(each_sum.begin(),1,chr);
                // next carry
                carry =  res / 10;
            }
            sum_list.push_back(each_sum);
        }
        // cal result
        for(PRECISION i=0;i<sum_list.size();i++) {
            string &each_sum = sum_list[i];
            each_sum.insert(each_sum.begin(),sum_list.size()-i-1, '0');
        }
        // complement
        //for(auto &item:sum_list) {
        //    std::cout<<item.size()<<" ";
        //}
        string result;
        PRECISION length = (PRECISION)sum_list[0].size();
        PRECISION carry = 0;
        for(PRECISION i=length-1;i>=0;i--) {
            PRECISION single_res = 0;
            for(PRECISION j=sum_list.size()-1;j>=0;j--) {
                string &each_sum = sum_list[j];
                single_res += (each_sum[i] - '0');
            }
            //
            single_res += carry;
            char chr = (char)(single_res % 10) + '0';
            result.insert(result.begin(),1,chr);
            carry = single_res / 10;
        }

        return result;


    }

};

int main()
{
    std::cin.set
    string a = "1";
    string b = "13";
    Solution solu;
    std::cout<< solu.high_precision_mul(a, b);
}