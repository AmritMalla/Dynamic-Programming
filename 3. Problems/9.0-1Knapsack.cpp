#include<bits/stdc++.h>

using namespace std;

int knapsack(int weight[], int value[], int W, int n){
    if(W ==0 || n == 0)
        return 0;
    if(weight[n-1] <= W ){
        return max(knapsack(weight, value, W - weight[n-1], n-1) + value[n-1], knapsack(weight, value, W, n-1));
    }else{
        return knapsack(weight, value, W, n-1);
    }

}

int dp[30][10];

int knapsackM(int weight[], int value[], int W, int n){


    if(W == 0 || n ==  0){
        return 0;
    }
    if(dp[W][n] != -1){
        return dp[W][n];
    }
    if(weight[n-1] <= W){
        return dp[W][n] = max(knapsackM(weight, value, W - weight[n-1], n-1) + value[n-1], knapsackM(weight, value,W, n-1));
    }else
        return dp[W][n] = knapsackM(weight, value, W, n-1);


}

int main(){

    int weight[] = {2,3,5,4,2,5,7,1,8};
    int val[] = {2,5,2,6,6,1,2,4,5};
    for(int i = 5;i<30;i++){
        memset(dp,-1, sizeof(dp));

        cout<< knapsack(weight, val, i, 9)<< " ";
        cout<< knapsackM(weight, val, i,9) << endl;

    }


}
