#include<bits/stdc++.h>

using namespace std;
/// addChildSum(root)
///     addChildSum for left sub-tree
///     addChildSum for right sub-tree
///     add value of left and right child nodes to root
struct Node{
    Node *left;
    int data;
    Node *right;
};

void addChildSum(Node *root){

    ///Terminating Condition
    if(root == NULL) return ;

    ///Compute for Left Sub Tree
    addChildSum(root->left);

    ///Compute for right Sub Tree
    addChildSum(root->right);

    int finalSum = root->data;

    if(root->left != NULL)
        finalSum += root->left->data;

    if(root->right != NULL)
        finalSum += root->right->data;

    root->data = finalSum;
}

int addChildSum1(Node *root)[
    if(root == NULL) return 0;
    root->data += addChildSum1(root->left) + addChildSum1(root->right);
    return root->data;
]


int main(){


}
