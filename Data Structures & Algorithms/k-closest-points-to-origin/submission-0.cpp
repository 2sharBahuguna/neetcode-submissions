class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k>points.size()) return {};
         priority_queue<pair<double, pair<int, int>>,vector<pair<double, pair<int, int>>>,greater<pair<double, pair<int, int>>>> pq;
        double x2=0;
        double y2=0;
        for(auto it:points){
            double x1=it[0];
            double y1=it[1];
            double distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
            pq.push({distance,{x1,y1}});
        }
        vector<vector<int>> ans;
        while(k--){
            int point_x=pq.top().second.first;
            int point_y=pq.top().second.second;
            ans.push_back({point_x,point_y});
            pq.pop();
        }

        return ans;

        
        
    }
};
