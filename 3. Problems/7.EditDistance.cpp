#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2){
    ///If s1 is empty
    /// then all characters of s2 needs to be inserted
    if(s1.size() == 0) return s2.size();

    ///If s2 is empty
    /// then all characters of s1 needs to be inserted
    if(s2.size() == 0) return s1.size();

    ///if first characters of both are same, then ignore it and find edit distance of rest of the strings
    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1), s2.substr(1));
    }
    /// find edit distance of all three operations
    int d, u, i;

    d = editDistance(s1.substr(1), s2);
    u = editDistance(s1.substr(1), s2.substr(1));
    i = editDistance(s1, s2.substr(1));

    return min(d,min(u,i)) + 1;


}
int main(){
    string s1 = "PRINT";
    string s2 = "PRIME";
    cout<<editDistance(s1,s2);

}
