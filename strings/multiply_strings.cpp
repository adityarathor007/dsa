class Solution {
public:
    int maximumCons(vector<int>&vec){
        int max_cons=0;
        int curr_cons=1;
        int i=1;
        while(i<vec.size()){
            if(vec[i-1]==vec[i]-1) curr_cons+=1;
            else{
                max_cons=max(max_cons,curr_cons);
                curr_cons=1;
            }
            i+=1;
        }
        max_cons=max(max_cons,curr_cons);
        return max_cons;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        //need to look for consecutive

        int h_max_cons=maximumCons(hBars);
        int v_max_cons=maximumCons(vBars);

        int min_cons=min(h_max_cons,v_max_cons);
        return pow(min_cons+1,2);
    }
};
