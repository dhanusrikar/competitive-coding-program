/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/

bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        
        if(len1 == 0)
        {
            if(s2 == s3)
                return true;
            return false;
        }
        
        if(len2 == 0)
        {
            if(s1 == s3)
                return true;
            return false;
        }
        
        // int rt[len1+1] = {0};
        // vector<int> rt(len1+1,0);
        // int dp[len2+1][len1+1] = {rt};
        vector<vector<int>> dp(len2+1, vector<int>(len1+1,0));
        
        // for(int i = 0; i <= len2; i++)
        //     for(int j = 0; j <= len1; j++)
        //         dp[i][j] = 0;
        
        for(int i = 1; i <= len2; i++)
            dp[i][0] =  dp[i-1][0] + int(s2[i-1] - 96);
        
        for(int i = 1; i <= len1; i++)
            dp[0][i] =  dp[0][i-1] + int(s1[i-1] - 96);
        
        for(int i = 1; i <= len2; i++)
        {
            int x = dp[i][0];
            for(int j = 1; j <= len1; j++)
            {
                dp[i][j] = x + dp[0][j];
            }
        }
        
        // for(int i = 0; i <= len2; i++)
        // {
        //     for(int j = 0; j <= len1; j++)
        //         cout << dp[i][j] << " ";            
        //     cout << endl;
        // }
    
        int sum = 0;
        pair<int,int> p = {0,0};
        set<pair<int, int>> v;
        v.insert(p);
        
        for(auto c : s3)
        {
            sum += int(c-96);
            // cout << "sum: " << sum << endl;
            set<pair<int,int>> v2;
            for(auto f : v)
            {
                int x = f.first;
                int y = f.second;
                // cout << x << " " << y << endl;
                if(x+1 <= len2)
                    if(dp[x+1][y] == sum)
                        v2.insert({x+1, y});
                if(y+1 <= len1)
                    if(dp[x][y+1] == sum)
                        v2.insert({x,y+1});
            }
            
            if(v2.size() == 0)
                return false;
            v.clear();
            v = v2;
        }
        if(sum == dp[len2][len1])
            return true;
        return false;
    }
