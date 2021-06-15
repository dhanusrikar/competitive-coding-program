int evalRPN(vector<string>& tokens) {
        stack<int> s;
        unordered_set<string> uset({"*", "+", "/", "-"});
        int ans = 0;
        for(auto i : tokens)
        {
            if(uset.find(i) == uset.end())
                s.push(stoi(i));
            else
            {
                ans = s.top();
                s.pop();
                if(i == "*")
                    ans = ans * s.top();
                else if(i == "/")
                    ans = s.top() / ans;
                else if(i == "+")
                    ans = s.top() + ans;
                else if(i == "-")
                    ans = s.top() - ans;
                s.pop();
                s.push(ans);                
            }
        }    
        return s.top();
    }
