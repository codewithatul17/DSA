class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        long long largest = LLONG_MIN;
        long long secondlargest = LLONG_MIN;
        long long thirdlargest = LLONG_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>largest){
                thirdlargest=secondlargest;
                secondlargest=largest;
                largest=nums[i];
            }else if(nums[i]<largest && nums[i]>secondlargest){
                thirdlargest=secondlargest;
                secondlargest=nums[i];
            }else if(nums[i]>thirdlargest && nums[i]<secondlargest){
                thirdlargest=nums[i];
            }
            
        }
        if(thirdlargest==LLONG_MIN){
                return largest;
        }
        return thirdlargest;
    }
};