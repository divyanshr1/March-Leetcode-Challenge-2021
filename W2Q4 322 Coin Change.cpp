/*Coin Change

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104*/

//C++ Solution

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        int dp[size+1][amount+1];
        for(int i=0,j=0;j<amount+1;j++)
            dp[i][j] = INT_MAX - 1;
        for(int j=0,i=1;i<size+1;i++)
            dp[i][j] = 0;
        for(int i=1,j=1;j<amount+1;j++)
            if(j%coins[0]==0)
                dp[i][j] = j/coins[0];
            else
                dp[i][j] = INT_MAX - 1;
        for(int i = 2; i<size+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1] <=j)
                {
                    dp[i][j] = min(dp[i][j - coins[i-1]] + 1, dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[size][amount] == INT_MAX - 1)
            return -1;
        return dp[size][amount];
    }
};

/*Time Complexity :- O(numberOfCoins * amount);
	Space Complexity :- O(NumberOfCoins * amount);*/