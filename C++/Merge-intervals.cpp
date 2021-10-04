class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<pair<int,int> > s;
        stack<pair<int,int>> stack;
        
        for(int i=0;i<intervals.size();i++)
        {
            s.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
        
        sort(s.begin(),s.end());
        stack.push(s[0]);
        for(int i=0;i<intervals.size();i++)
        {
            auto it = stack.top();
            if(it.second >= s[i].first)
            {
                stack.pop();
                if(it.second < s[i].second)
                stack.push(make_pair(it.first, s[i].second));
                else
                    stack.push(make_pair(it.first,it.second));
            }
            else
                stack.push(make_pair(s[i].first,s[i].second));
        }
        while(stack.empty()!=true)
        {
            auto it = stack.top();
            ans.push_back({it.first,it.second});
            stack.pop();
        }
        return ans;
    }
};
