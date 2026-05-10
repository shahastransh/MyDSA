#include<bits/stdc++.h>
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

void printTreePre(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data << " ";
    printTreePre(root->left);
    printTreePre(root->right);

    
}

int sumTree(Node* root){
    if(root == NULL ){
        return 0;
    }

    
    int lSum = sumTree(root -> left);
    int rSum = sumTree( root -> right);
    root -> data += lSum + rSum ;
    return root -> data;
    
}


int main(){
    vector<int> preOrder = { 1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);

    cout<<"before conversion : "<<endl;
    printTreePre(root);
    cout<<endl;
    sumTree(root);

    cout<<"after conversion : "<<endl; 
    printTreePre(root);
    cout<< endl;

    

    return 0;
}