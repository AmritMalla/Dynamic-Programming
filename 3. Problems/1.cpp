#include<bits/stdc++.h>

using namespace std;

void moveTowerOfHanoi(char S, char D, char E, int n){
    static int callCount = 0;
    if(n == 1){
    cout<< callCount++ <<  " Move "<< n<< "th Disc from "<< S << " to " << D<< endl;
        return;
    }
    moveTowerOfHanoi(S, E, D, n-1);
    cout<< callCount++ <<  " Move "<< n<< "th Disc from "<< S << " to " << D<< endl;
    moveTowerOfHanoi(E, D, S, n-1);
}

struct Node{
    Node *left;
    int data;
    Node *right;
};

void inOrder(Node *r){
    if(r == NULL){
        return;
    }

    inOrder(r->left);
    cout<<r->data << endl;
    inOrder(r->right);
}

void inOrder1(Node *r){
    if(r == NULL)
        return;
    if(r->left != NULL)
        inOrder1(r->left);
    cout<< r->data <<endl;

    if(r->right != NULL)
        inOrder1(r->right);
}


void swapp(int *a, int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void bubbleSortR(vector<int> arr, int n){
    if(n <= 1) return;

    for(int a: arr){
        cout<< a<< " ";
    }
    cout<<endl;

    for(int i = 0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            swapp(&arr[i], &arr[i+1]);
        }
    }
    bubbleSortR(arr, n-1);
}



int main(){
    bubbleSortR({4,5,-2,3,8,1}, 6);

}
