class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size()+nums2.size();
        int i=0;
        int j=0;
        int index2=n/2;
        int index1=index2-1;
        int cnt=0;
        int element1=0;
        int element2=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(cnt==index1) element1=nums1[i];
                if(cnt==index2) element2=nums1[i];
                i++;
                cnt++; 
            }
            else{
                if(cnt==index1) element1=nums2[j];
                if(cnt==index2) element2=nums2[j];
                j++;
                cnt++; 
            }
        }

        while(i<nums1.size()){
            if(cnt==index1) element1=nums1[i];
            if(cnt==index2) element2=nums1[i];
            i++;
            cnt++; 
        }

        while(j<nums2.size()){
            if(cnt==index1) element1=nums2[j];
            if(cnt==index2) element2=nums2[j];
            j++;
            cnt++; 
        }

        if(n&1) return element2;

        return (double)((double)(element1+element2))/2.0;
    }
};
