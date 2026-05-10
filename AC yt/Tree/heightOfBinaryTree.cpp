#include<bits/stdc++.h>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& preOrder ){
    idx++;
    if (preOrder[idx] == -1) {
        
        return NULL;
    }

    Node* root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

//height of tree
int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHt = height(root -> left);
    int rightHt = height(root -> right);
    return max(leftHt,rightHt) + 1;

}

//cont elments in a tree

int count(Node* root){
    if( root == NULL){
        return 0;
    }

    int leftCnt = count(root->left);
    int rightCnt = count(root->right);

    return leftCnt + rightCnt + 1;

}

//sum of all elements
int sum(Node* root){
    if(root == 0){
        return 0;

    }

    int leftSum = sum(root -> left);
    int rightSum = sum(root -> right);
    return leftSum + rightSum + root->data;
}

int main(){
    vector<int> preOrder = { 1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int index = 0;
    Node* root = buildTree(preOrder);
    

    cout<< "height : " << height(root) << endl;
    cout<< "no. of elements : " << count(root) << endl;
    cout<<"sum of all elements : " << sum(root) << endl;
    return 0;
}