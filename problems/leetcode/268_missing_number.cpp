class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size()+1;
        int arr[n], missing = -1;
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
        for(int i=0;i<n-1;i++){
            arr[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                missing= i;
                break;
            }
        }
        return missing;
    }
};