struct Event{
    int y;
    bool start;
    int x1;
    int x2;

    bool operator<(const Event& other) const {
                return y < other.y;
    }
};

struct Strip{
    int y;
    int length;
    int width;
};



class Solution {
    int findUnionWidth(vector<pair<int,int>>&activeIntervals){
        int n=activeIntervals.size();
        if(n==0) return 0;

        sort(activeIntervals.begin(),activeIntervals.end());

        int width=0;
        int prev_e=-1e9;
        for(auto [x1,x2]:activeIntervals){
            if(x1>prev_e){
                width+=(x2-x1);
                prev_e=x2;
            }
            else if(x2>prev_e){
                width+=(x2-prev_e);
                prev_e=x2;
            }
        }

        return width;

    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event>events;
        for(auto square:squares){
            int x=square[0],y=square[1],l=square[2];
            events.push_back({y,1,x,x+l});
            events.push_back({y+l,0,x,x+l});
        }

        sort(events.begin(),events.end());

        vector<pair<int,int>>activeIntervals;
        vector<Strip>strips;
        int prev_y=events[0].y;
        double A0=0;

        for(auto event:events){
            if(event.y>prev_y){
                int dy=event.y-prev_y;
                int union_width=findUnionWidth(activeIntervals);
                if(union_width>0){
                    strips.push_back({event.y-dy,dy,union_width});
                    A0+=(double)union_width*dy;
                }
            }

            if(event.start){
                activeIntervals.push_back({event.x1,event.x2});
            }
            else{
                for(auto it=activeIntervals.begin();it!=activeIntervals.end();it++){
                    if(it->first==event.x1 and it->second==event.x2){
                        activeIntervals.erase(it);
                        break;
                    }
                }
            }
            prev_y=event.y;
        }

        double area=0;
        double A2=A0/2;
        for(auto strip:strips){
            double strip_h=(double)strip.length;
            double strip_w=(double) strip.width;
            double curr_area=strip_h*strip_w;
            // cout<<curr_area<<" "<<area<<endl;
            if(area+curr_area>=A2){
                return strip.y+(A2-area)/strip_w;
            }
            area+=curr_area;
        }

        return -1;

    }
};
