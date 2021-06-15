/*
Given an array of strings products and a string searchWord.
We want to design a system that suggests at most three product names from products after each character of searchWord is typed. 
Suggested products should have common prefix with the searchWord. 
If there are more than three products with a common prefix return the three lexicographically minimums products.
Return list of lists of the suggested products after each character of searchWord is typed. 
*/


vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        
        unordered_map<string,vector<string>> umap;
        vector<string> words;
        int n = 1;
        string find_word = to_string(searchWord[0]);

        for(auto x : products){
            if(find_word == to_string(x[0]))
                words.push_back(x);
        }
        vector<vector<string>> ans(searchWord.size());
        // for(auto x : words)
        //     cout << x << endl;
        
        if(words.size() == 0)
            return ans;
        
        
        auto rep = [&](vector<string> f){
            int c = 0; 
            vector<string> wr;
            for(auto x : f)
            {
                if(c == 3)
                    break;
                wr.push_back(x);
                c++;
            }
            return wr;
        };
        
        
        
        umap[find_word] = words;
        ans[0] = rep(words);
        int count = 0;
        while(n < searchWord.size()){
            
            string f = searchWord.substr(0, n+1);
            cout << f << endl;
            words.clear();
            for(auto x : umap[find_word])
            {
                // cout <<"inside: " <<x << endl;
                string q = x.substr(0,n+1);
                if(q == f)
                {
                    // cout << x << endl;
                    words.push_back(x);
                }
                    
            }
            if(words.size() == 0)
                return ans;
            ans[++count] = rep(words);
            find_word = searchWord.substr(0, ++n);
            umap[find_word] = words;
            // for(auto x : words)
            //     cout << x << endl;
        }
        return ans;
    }
