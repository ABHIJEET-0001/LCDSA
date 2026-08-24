
class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i,int buy,vector<int>& prices,int fee)
    {
        if(i==prices.size())
            return 0;

        if(dp[i][buy]!=-1)
            return dp[i][buy];

        if(buy)
        {
            dp[i][buy]=max(
                -prices[i]+solve(i+1,0,prices,fee),
                solve(i+1,1,prices,fee));
        }
        else
        {
            dp[i][buy]=max(
                prices[i]-fee+solve(i+1,1,prices,fee),
                solve(i+1,0,prices,fee));
        }

        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices,int fee)
    {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return solve(0,1,prices,fee);
    }
};