/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.
*/
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,0);
        dp[1] = cost[0];
        for(int i = 1; i < n; i++)
            dp[i+1] = min(dp[i-1] + cost[i], dp[i] + cost[i]);
        
        return min(dp[n], dp[n-1]);
    }
