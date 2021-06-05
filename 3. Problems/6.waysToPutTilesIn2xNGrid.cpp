#include<bits/stdc++.h>
using namespace std;

int countWays2xN(int n){
    if(n < 3) return n;
    return countWays2xN(n-1) + countWays2xN(n-2);
}

int countWays2xnDP(int n){
    if(n < 3) return n;

    int a = 1, b = 2, c ;
    for(int i = 3;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int countWays3xN(int n){
    if(n == 2) return 3;


}

int waysToScore(int n ){
    if(n<0) return 0;
    if(n == 0) return 1;
    1return waysToScore(n-10) + waysToScore(n-5) + waysToScore(n-3);
}

int waysToScoreDP(int n ){
    vector<int> dp(n+1,0);
    dp[0] = 1;

    for(int i = 1;i<=n;i++){
        if(i - 3 >= 0)
            dp[i] += dp[i-3];
        if(i-5 >= 0)
            dp[i] += dp[i-5];
        if(i-10 >= 0)
            dp[i] += dp[i-10];
    }

    return dp[n];
}


int main(){

    cout<<waysToScoreDP(16);
    /*
    for(int i = 1;i<10;i++){
            cout<< countWays2xnDP(i) << " ";
    cout<< countWays2xN(i) <<endl;
    }

    */


}
