#include<bits/stdc++.h>
using namespace std;
int isInterleaving(char* A, char *B, char* C){
    ///If all strings are empty
    if(!(*A) && !(*B) && !(*C)){
        return true;
    }

    ///If C is empty, A or B (or Both) is not empty
    if(*C == '\0')
        return false;

    ///If both A and B are empty, but C is not
    if(*A == '\0' && *B == '\0')
        return false;

    int first = false;
    int second = false;

    ///If first char of A = first char of C
    if(*A == *C)
        first = isInterleaving(A+1, B, C+1);

    ///If first char of B = first char of C
    if(*B == *C)
        second = isInterleaving(A,B+1, C+1);

    return first||second;

}


int main(){
    char* a  = "amrit";
    char* b = "malla";
    char* c = "amallarit";
    cout<<isInterleaving(a,b,c);


}
