#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<vector <int>> & input,int x,int y,int no){

    //checking the rows and column
    for(int i=0;i<9;i++){
        if(input[x][i]==no or input[i][y]==no){
            return false;
        }
    }

    //checking in the subsection
    int sx=(x/3)*3;
    int sy=(y/3)*3;
    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(input[i][j]==no){
                return false;
            }
        }
    }
    
    return true;

}

bool solution(vector<vector<int>> & input, int x, int y, vector<vector<int>> & output)
{

    //base case
    if(x==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                output[i][j]=input[i][j];
            }
        }
        return true;
    }

    if(y==9){
        return solution(input,x+1,0,output);
    }
    if(input[x][y]!=0){
        return solution(input,x,y+1,output);
    }
    for(int no=1;no<=9;no++){
        if(canPlace(input,x,y,no)){
            input[x][y]=no;

            bool success=solution(input,x,y+1,output);
            if(success){
                return true;
            }
        }
    }
    input[x][y]=0;
    return false;
}

vector<vector<int>> solveSudoku(vector<vector<int>> input)
{
    int i=0;
    int j=0;
    vector<vector<int>> output(9, vector<int>(9, 0));
    solution(input,i,j,output);
    return output;

}



int main(){

    vector<vector<int>> input = 
    { 
        {0,3,0,0,0,0,9,0,0},

        {0,0,6,0,0,0,0,0,0},

        {0,0,0,2,4,1,0,3,0},

        {0,0,0,9,0,0,7,0,0},

        {0,0,0,0,0,2,0,0,4},

        {0,8,0,0,7,0,0,2,0},

        {8,5,0,0,0,0,0,0,0},

        {0,9,0,7,0,4,0,0,0},

        {0,0,0,0,0,6,0,0,1}
        
    };


  

    auto ans = solveSudoku(input);
    for (const auto &row : ans)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

}