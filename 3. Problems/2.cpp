#include<bits/stdc++.h>

using namespace std;

int cost[4][4] = {
{0, 10, 75, 94},
{-1, 0, 35, 50},
{-1, -1, 0, 80},
{-1, -1, -1, 0}
};

//Exponential Time complexity

int calcMinimumCost(int s, int d){
    if(d - s <= 1) return cost[s][d];
    int minCost = cost[s][d];
    for(int i = s + 1;i<d;i++){
        int temp = calcMinimumCost(s, i) + calcMinimumCost(i, d);
        minCost = min(minCost, temp);
    }
    return minCost;
}

//Top down memoized solution
//Cubic Time complexity with square time complexity

int calculateMinimumCost(int s, int d){

    static int memo[4][4];

    if(s - d <= 1){
        return cost[s][d];
    }

    if(memo[s][d] == 0){
        int minCost = cost[s][d];
        for(int i = s+ 1;i<d;i++){
            int temp = calculateMinimumCost(s, i) + calculateMinimumCost(i, d);
            minCost = min(temp, minCost);
        }
        memo[s][d] = minCost;
    }
    return memo[s][d];
}

///Bottom up dynamic solution
/// This is square time complexity algorithms with linear extra space

int calculateMinimumCostDP(int d){
    int minCost[4] = {0};
    int N = 4;
    minCost[1] = cost[0][1];

    for(int i = 2;i<N;i++){
        minCost[i] = cost[0][i];
        for(int j = 1;j<i;j++){

            ///Here minCost[j] is already calculated and we should check if we can reach the destination
            /// i by stopping at station j
            if(minCost[i] > minCost[j] + cost[j][i]){
                minCost[i] = minCost[j] + cost[j][i];
            }
        }

    }

    return minCost[d];
}


int main(){
    //cout<< calcMinimumCost(0,3);
    for(int i = 1;i<4;i++)
        cout<< calculateMinimumCostDP(i)<< " ";
}
