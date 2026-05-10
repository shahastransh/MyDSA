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

void topView(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> m;
    q.push({root,0});

    while(q.size() > 0){
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr -> data;
        }

        if(curr -> left != NULL ){
            q.push({curr -> left, currHD - 1});

        }
        if(curr -> right != NULL ){
            q.push({curr -> right, currHD + 1});

        }
    }

    for(auto it : m){
        cout << it.second << " ";
    }
    cout<<endl;
}


int main(){
    vector<int> preOrder = { 1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preOrder);

    topView(root);

    return 0;
}