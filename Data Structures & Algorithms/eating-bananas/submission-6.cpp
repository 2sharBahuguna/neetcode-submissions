class Solution {
private:
    long long solve(vector<int>& arr,int mid){
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=ceil((double)arr[i]/mid);
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end= *max_element(piles.begin(),piles.end());
        int ans=-1;
        while(start<=end){
            int mid= start+((end-start)/2);

            long long total_hrs=solve(piles,mid);

            if(total_hrs<=h){
                end=mid-1;
                ans=mid;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};
