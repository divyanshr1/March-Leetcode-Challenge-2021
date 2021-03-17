/*Binary Trees With Factors

Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 

Constraints:

1 <= arr.length <= 1000
2 <= arr[i] <= 109*/

//C++ Solution

class Solution {
public:
 
    #define MOD 1000000007
    #define ll long long
 
    int numFactoredBinaryTrees(vector<int>& arr)
    {
        ll ans = 0;
 
        unordered_map<ll,ll> mp;
 
        sort(arr.begin(),arr.end());
 
 
        for(int i=0;i<arr.size();i++)
        {
            // leaf node
            ll curr_ans  = 1;
 
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j])
                    continue;
 
                ll num1 = arr[j];
                ll num2 = arr[i]/arr[j];
 
                curr_ans = (curr_ans+(mp[num1]*mp[num2])%MOD)%MOD;
            }
 
            mp[arr[i]] = curr_ans;
 
            ans = (ans+curr_ans)%MOD;
        }
 
        return (int)ans;
    }
};