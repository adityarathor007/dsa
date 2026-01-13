pair<double,double> calculateArea(double y, vector<vector<int>>& squares){
        double below_area=0,above_area=0;
        for(const auto& square:squares){
            double cl=square[2],cy=square[1];
            if(cy+cl>y){
                if(cy<=y){
                    below_area+=(y-cy)*cl;
                    above_area+=(cy+cl-y)*cl;
                }
                else above_area+=cl*cl;
            }
            else below_area+=cl*cl;

        }

        return {below_area,above_area};

    }


    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double l=INT_MAX,r=INT_MIN;

        for(int i=0;i<n;i++){
            l=min((double) squares[i][1],l);
            r=max((double) squares[i][1]+squares[i][2],r);
        }

        double ans=-1;

        while(r-l>1e-5){
            double mid=(l+r)/2;
            auto [below_area,above_area]=calculateArea(mid,squares);
            // cout<<mid<<" "<<below_area<<" "<<above_area<<endl;
            //as the solution will exist and even if the difference i very small still it considers it as the answer and then try to bring the mid more down as we need the minimum y
            if(below_area>=above_area){
                ans=mid;
                r=mid;
            }
            else l=mid;
        }


        return ans;
