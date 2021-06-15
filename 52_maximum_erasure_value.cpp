/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. 
The score you get by erasing the subarray is equal to the sum of its elements.
Return the maximum score you can get by erasing exactly one subarray.
An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
*/

int maximumUniqueSubarray(vector<int>& nums) {
        deque<int> q;
        // set<int> s;
        // s.insert(nums[0]);
        q.push_front(nums[0]);
        int end = 1, start = 0;
        int sum = nums[0], ans = nums[0];
        while(end < nums.size()){
            sum += nums[end];
            if(find(q.begin(), q.end(), nums[end]) == q.end()){
                q.push_back(nums[end]);
                // cout << "not found: " << nums[end] << endl;


            }
            else{
                // cout << "found: " << nums[end] << endl;
                q.push_back(nums[end]);
                for(auto x : q){
                    sum = sum - x;
                    if(q.front() == nums[end]){
                        q.pop_front();
                        // end++;
                        break;
                    }
                    q.pop_front();    
                }
                // cout << "queue: " << endl;
                // for(auto f : q)
                //     cout << f << " ";
                // cout << endl;
            }
            end++;
            // cout << "sum: " << sum << " ans: " << ans << endl;
            ans = max(ans, sum);
        }
        return ans;
    }
