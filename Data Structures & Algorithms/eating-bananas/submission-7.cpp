class Solution {
private:
    long count(vector<int>& arr,int b){
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/b);
        }
        return sum;

    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=1;
        int end=*max_element(piles.begin(),piles.end());
        int maxi=0;
        while(start<=end){
            int mid= (start+end)/2;
            long long bananasPerHour= count(piles,mid);

            if(bananasPerHour<=h){
                end=mid-1;
                maxi=mid;
            }
            else{
                start=mid+1;
            }
        }

        return maxi;
    }
};
