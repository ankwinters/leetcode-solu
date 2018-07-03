//
// Created by ckp on 18-7-3.
//
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {

        if(s.length()==0)
            return 0;

        // Vector of string to save tokens
        vector <string> tokens;

        // stringstream class check1
        stringstream check(s);

        string intermediate;

        // Tokenizing w.r.t. space ' '
        while(getline(check, intermediate, ' '))
        {
            tokens.push_back(intermediate);
        }

        // Printing the token vector
        auto last = int(tokens.size());
        for(auto &item:tokens)
        {
            cout<<"item:"<<item<<endl;
            cout<<"item length:"<<item.length()<<endl;
        }

        int length = 0;

        for(int i=last-1;i>=0;i--)
        {
            if(tokens[i].length()>0)
            {
                length = int(tokens[i].length());
                break;
            }
        }
        return length;

    }
};


int main()
{
    string str = "     ";

    // do something
    Solution solu;
    auto length = solu.lengthOfLastWord(str);
    cout<<"Length of last word:"<<length<<endl;

    return 0;
}