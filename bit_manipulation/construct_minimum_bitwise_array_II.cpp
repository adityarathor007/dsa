class Solution {
    int unsetIthBit(int num,int i){
        int num2=0;
        for(int j=31;j>=0;j--){
            if(j!=i){
                num2+=((num>>j)&1)<<j;
            }
        }

        return num2;
    }
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int num:nums){
            if(!(num&1)) ans.push_back(-1);
            else{
                for(int i=31;i>=0;i--){
                    if((num>>i)&1){
                        int n1=unsetIthBit(num,i); //unseting bit from right to left and if one of the case then that is the required num
                        if((n1|(n1+1))==num){
                            ans.push_back(n1);
                            break;
                        }
                    }
                }
            }

        }

        return ans;
    }
};
