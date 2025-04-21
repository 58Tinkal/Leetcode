class Solution {
    vector<int> findAllSums(vector<int>& nums,int start,int end,int offset){        
        vector<int> res;
        int n=end-start+1;
        for(int i=0;i<(1<<n);++i){
            int sum=0;
            for(int j=0;j<n;++j){
                if(i&(1<<j))
                    sum+=nums[j+offset];
            }
            res.push_back(sum);
        }
        return res;
    }
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        if(n==1)    return min(abs(goal),abs(nums[0]-goal));
        
        vector<int> firstHalf = findAllSums(nums,0,n/2-1,0);
        vector<int> secondHalf = findAllSums(nums,n/2,n-1,n/2);
        sort(secondHalf.begin(),secondHalf.end());
        
        int res=INT_MAX;
        for(int i=0;i<firstHalf.size();++i){
            int lb = lower_bound(secondHalf.begin(),secondHalf.end(),goal-firstHalf[i])-secondHalf.begin();
            
            if(lb>0)
                res=min(res,abs(goal-secondHalf[lb-1]-firstHalf[i]));
            if(lb<secondHalf.size())
                res=min(res,abs(goal-secondHalf[lb]-firstHalf[i]));
        }
        return res;
    }
};