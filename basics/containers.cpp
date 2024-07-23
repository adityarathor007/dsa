#include<iostream>
#include<vector>
using namespace std;

// void explainVector(){
//     vector<int> v;
//     v.push_back(1);
//     v.emplace_back(2); //similar to push_back

//     vector<pair<int,int>>vec;
//     v.push_back({1,2});
//     v.emplace_back(1,2);

//     vector<int> v(4,100);

//     vector<int> v(4);


//     vector<int>v1(5,10);
//     vector<int> v2(v1); //creating copy of v1

//     // iterator approach for accessing elements of vector
//     vector<int>::iterator it=v.begin();
//     it++;
//     cout<<*(it)<<" ";
//     i+=2;
//     cout<<*(it)<<" ";


//     vector<int>::iterator it=v.end(); //will point to memory just next to last element of the vector


//     for(auto it=v.begin();it!=v.end();it++)
//         cout<<*(it)<<" ";

//     for(auto it:v){
//         cout<<it<<" ";

//     }

//     v.erase(v.begin()+1); //remove the second element of the vector
//     v.erase(v.begin()+1,v.begin()+3); //this remove the the element at index [1,3) i.e index 1 and 2


//     vector<int> v(2,100);//{100,100}
//     v.insert(v.begin(),300);//{300,100,100}
//     v.insert(v.begin()+1,2,10)//{300,10,10,100,100}



//     vector<int> v2(2,50);
//     v.insert(v.begin(),v2.begin(),v.end()); //{50,50,300,10,10,100,100}

//     cout<<v.size()<<endl;

//     v.pop_back();

//     v1.swap(v2);

//     v.clear(); //erases the entire vector

//     cout<<v.empty<<endl; //if it has none element it will say it is empty   


// }


// void explainList(){  //similar to vector but gives front operations as well
//     list<int> ls;

//     ls.push_back(2);
//     ls.emplace_back(4);

//     ls.push_front(5);

//     ls.emplace_front(5);

//      rest functions same as vector
//     //begin,end,clear,insert,size,swap
// }

// void explainDeque(){
//     deque<int> dq;
//     dq.push_back(1);
//     dq.emplace_back(2);
//     dq.push_front(5);
//     dq.emplace_front(4);

//     dq.pop_back();
//     dq.pop_front();

//     dq.back();
//     dq.front();

// //     //rest functions same as vector
// //     //begin,end,clear,insert,size,swap
// }

// void explainStack(){ //LIFO 
//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.emplace(5);

//     cout<<s.top()<<endl; //gives 5

//     s.pop();

//     cout<<s.size()<<endl;

//     cout<<s.empty()<<endl;

//     stack<int> s1,s2;
//     s1.swap(s2);
// }


// void explainQueue(){
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.emplace(4);

//     q.back()+=5;
//     cout<<q.back()<<endl;

//     cout<<q.front();

//     q.pop();

//     cout<<q.front()<<endl;


// }

// void explainPQ(){
//     priority_queue<int> pq;
//     pq.push(5);
//     pq.push(2);
//     pq.push(3);
    
//     cout<<pq.top();

//     pq.pop();

//     priority_queue<int,vector<int>,greater<int>> pq;  //minheap
//     pq.push(5);
//     pq.push(2);//{2,5}
//     pq.push(18);//{2,5,18}
//     pq.emplace(1);//{1,2,5,18}

//     cout<<pq.top()<<endl;


// }



// void explainSet(){   //stores unique things and sorted 
//     set <int> st;
//     st.insert(1);
//     st.emplace(2);
//     st.insert(2);
//     st.insert(4);

//     auto it=st.find(1);

//     auto it=st.find(5);  //it will point to s.end()

//     st.erase(1);

//     int cnt=st.count(1); //return 1 if there in the set else 0

//     auto it1=st.find(2);
//     auto it2=st.find(4);
//     st.erase(it1,it2);  //[first,last)

//     //{1,2,4}
//     auto it=st.lower_bound(2); //will return iterator pointing to 2 
//     auto it=st.lower_bound(3); //will return itertor pointing to the next greater element which is 4
//     auto it=st.upper_bound(5); //will return iterator pointing to st.end() 
//     //the only difference between lower bound and upper bound is that in upper bound even if the element is present it will point to the next greater element

//     int ind=st.lower_bound(2)-st.begin(); //to get the index    


// }


// void explainMultiSet(){
//     multiset<int> ms;
//     ms.insert(1);
//     ms.insert(1);
//     ms.insert(1);   //{1,1,1}

//     ms.erase(1);

//     int cnt=ms.count(1);//will count the number of elements in the multiset

//     //only a single 1 is erased
//     ms.erase(ms.find(1));

//     ms.erase(ms.find(1),ms.find(1)+2) //move till 3rd but dont erase the 3rd element

//     ///rest function same as set
// }

// void explainUSet(){
//     unordered_set<int> st;  //unique but not sorted it's stores randomly(does everything in O(1) time)
//     //lower_bound and upper_bound function does not works, rest same as set
// }

// void explainMap(){  //the keys are unique and sorted but values may repeat for different keys
//     map <int,int> mpp;

//       mpp[1]=2;
//       mpp.inserT({2,4});
//     mpp.emplace({3,1});




//     map<int,pair<int,int>> mpp;
//     map<pair<int,int>,int> mpp;
//     mpp[{2,3}]=10;


//     for(auto it:mpp){
//         cout<<it.first<<" "<<it.second<<endl;

//     }

//     cout<<mpp[1];
//     cout<<mpp[5]; //it will show 0 as nothing stored for this key 


//     auto it=mpp.find(3);
//     cout<<*(it).second;

//     auto it=mpp.find(5);

//     auto it=mpp.lower_bound(2);
//     auto it=mpp.upper_bound(4);

// }


// void explainMutliMap(){
//     //everything same as map, only it can store multiple keys
//     //only mpp[key] cannot be used here
// }

// void explainUnorderedMap(){ ///does everything in O(1)
//     //same as set and unordered_Set diff
// }



// bool comp(pair<int,int> p1,pair<int,int> p2){  //we assume that pair p1 lies before p2
//     if(p1.second<p2.second){
//         return true;
//     }
//     if(p1.second>p2.second){
//         return false;
//     }
//     if(p1.first>p2.first){
//         return true;
//     }
//     return false;
// }   


// void explainSort(){
//     int a[]={1,5,3,2};
//     sort(a,a+4); //[start,end)  

//     // for vector
//     sort(v.begin(),v.end());

//     sort(a+2,a+4);// to sort the from 3 to 2


//     // to sort in descending order
//     sort(a,a+n,greater<int>); //to sort in descending order

//     pair<int,int> a[]={{1,2},{2,1},{4,1}};
//     //custom sort
//     sort(a,a+n,comp); //sort acc to 2nd element and if second elmeent same then sort acc to first element but in descending order


//     //finding the number of set bits
//     int num=7;
//     int cnt=__builtin_popcount(num);
    
//     long long num=165786578687;
//     int cnt=__builtin_popcountll(num); // for long long

//     string s="134";
//     sort(s.begin(),s.end());
//     //imp to be sorted before getting all permutation as it gives in lexigraphic inc order

//     do{
//         cout<<s<<endl;
//     }while(next_permutation(s.begin(),s.end()));

//     int maxi=*max_element(a,a+n);






// }






int main(){
    
    



}
