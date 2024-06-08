#include <iostream>
#include <optional>
#include <vector>
using namespace std;


// application of counting sort 
// question was to find the min diff in each entity such that their prefferd position is given in the list and you have to find the 
// method to min the practical position and preffered position.



int badness(vector<pair<string, int> > teams)
{
 //Complete this function to return the min badness
        int n=teams.size();  
        int M = 0;
     
        for (int i = 0; i < n; i++){
            M = max(M, teams[i].second);
    }
    
    vector<int> countArray(M + 1, 0);
    
    // storing the occurence
    for (int i = 0; i < n; i++)
        countArray[teams[i].second]++;
        
    for (int i = 1; i <= M; i++)
               countArray[i] += countArray[i - 1];
    
    vector<pair<string, int> > outputArray(n);    
    int cnt=0;
    
    for (int i = n - 1; i >= 0; i--)
    
       {
           int index=teams[i].second;
           outputArray[countArray[index] - 1] = { teams[i].first,teams[i].second } ;
           int diff=abs((countArray[index] - 1)-(teams[i].second-1));  //-1 in teams[i].second as the position are relative to starting of 1 as starting index
           // cout<<diff<<endl;
           cnt+=diff;
           countArray[index]--;
       }
       
return cnt;

}


int main(){
    vector<pair<string, int> > input = {{"A", 1}, {"B", 2}, {"C", 2}, {"D", 1}, {"E", 5}, {"F", 7},{"G",7}};
    cout<<badness(input)<<endl;

}