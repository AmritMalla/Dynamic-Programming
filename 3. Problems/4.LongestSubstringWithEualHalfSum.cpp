#include<bits/stdc++.h>
using namespace std;
/*
  Problem:
    Find length of longest substring of a given string of digits, such that
    sum of digits in the first half and second half of the substring is same.
    For example
    Input: "142124"
    output: 6

    Input: 9430723
    output: 4

*/

int maxSubStringLength(string str){
    int n = str.size();

    int maxLen = 0;

    ///i = Starting index of the substring

    for(int i = 0;i<n;i++){
        ///j = End index of the substring(even length)
        for(int j = i+1; j<n;j+=2){
            ///len = Length of the current Substring
            int len = j - i + 1;

            ///if maxLen > length of the current substring
            ///do nothing

            if(maxLen >= len) continue;

            int lSum = 0, rSum = 0;
            for(int k = 0;k<len/2;k++){
                lSum += (str[i + k] - '0');
                rSum += (str[i + k + len/2] - '0');
            }
            if(lSum == rSum)
                maxLen = len;
        }

    }
    return maxLen;
}

int maximumLengthEqualSumSubstring(string s){

    int n = s.size();
    if(n < 2) return n;

    int maxLen = 0;


    for(int i = 0;i<n;i++){
        for(int j = ((n-i)/2)*2 + i-1;j >i; j-= 2){
            int len = j - i + 1;
            if(maxLen >= len) break;

            int lSum = 0, rSum = 0;
            for(int k = 0; k<len/2;k++){
                lSum += (s[i + k] - '0');
                rSum += (s[i + k + len/2] - '0');
            }
            if(lSum == rSum){
                maxLen = len;
                break;
            }
        }
    }
    return maxLen;
}

int maxSubStringLengthDP(string s){
    static int sum[100][100];

    int n = s.size();
    int maxLen = 0;

    ///Lower diagonal of the matrix is not used (i>j)
    ///Filling diagonal values;

    for(int i = 0;i<n;i++)
        sum[i][i] = s[i] - '0';

    for(int len = 2;len<= n;len++){
        ///pick i and j for current substring
        for(int i = 0;i<n - len + 1; i++){

            int j = i + len - 1;
            int k = len/2;

            sum[i][j] = sum[i][j-k] + sum[j-k+1][j];

            cout<<endl;

            for(int x = 0;x<4;x++){
                for(int z = 0;z<4;z++){
                    cout<<sum[x][z] << " ";
                }
                cout<<endl;
            }
            cout<<endl;


            /// Update if len is even, left and right
            ///Sums are same and len is more than maxLen
            if(len%2 == 0 && sum[i][j-k] == sum[j - k + 1][j] && len > maxLen){
                maxLen = len;
            }
        }
    }
    return maxLen;
}

int maxSubStringLengthSquare(string s){
    int n = s.size();
    int maxLen = 0;

    for(int i =0;i<n;i++){
        int pSum = 0, fSum = 0;
        for(int j = i, k = i;j<n;j++){
            fSum += (s[j] - '0');
            int len = j - i + 1;
            if(len%2 == 0){
                pSum += (s[k++] - '0');
                if(fSum - pSum == pSum)
                    maxLen = max(maxLen,len);
            }
        }
    }
    return maxLen;
}



int main(){
    string s = "219840";
//    cout<<maxSubStringLengthDP(s)<< " ";
    cout<<maxSubStringLengthSquare(s);
    //cout<<  maximumLengthEqualSumSubstring(s);
}
