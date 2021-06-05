#include<bits/stdc++.h>

using namespace std;


int numberOfWaysToReachNthGrid(int N){
    vector<vector<int>> grid(N, vector<int>(N, 0));
    for(int i = 0;i<N;i++){
        grid[i][0] = grid[0][i] = 1;
    }
    for(int i = 1;i<N;i++){
        for(int j = 1;j<N;j++){
            grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
    }

    return grid[N-1][N-1];
}

int recursiveWaysToReachNthGrid(int i, int j){
    if(i == 0 || j == 0) return 1;
    return recursiveWaysToReachNthGrid(i-1, j) + recursiveWaysToReachNthGrid(i,j-1);
}



int main(){
    for(int i = 1;i<10;i++)
    cout<< numberOfWaysToReachNthGrid(i) << " ";
    cout<<endl;
    for(int i = 0;i<10;i++)
    cout<< recursiveWaysToReachNthGrid(i,i) << " ";

}
