/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
int climbStairs(int n) {
        if(n == 1 or n == 2)
            return n;
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n-1];
    }
