// Problem statement: https://leetcode.com/problems/lexicographical-numbers

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> lexicalVector;

public:
    int returnNextValid(int base, int limit)
    {
        if (base <= limit)
        {
            lexicalVector.push_back(base);
            int val = returnNextValid(base * 10, limit);
            if (val == -1)
            {
                if ((base + 1) / 10 == base / 10)
                    return returnNextValid(base + 1, limit);
                return -1;
            }
            return val;
        }
        return -1;
    }
    vector<int> lexicalOrder(int n)
    {
        int base = 1;
        returnNextValid(base, n);
        return lexicalVector;
    }
};

int main()
{
    Solution solution;
    solution.lexicalOrder(13);
    return 0;
};