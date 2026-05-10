#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;


    Node(int data){
        this->data = data;
        left = right = NULL;

    }
};

Node* insert(Node* root, int val){
    if( root == NULL){
        root = new Node(val);
        return root;

    }
    if(val < root -> data){ //left subtree
        root -> left = insert(root -> left, val);

    }

    else{ //right subtree
        root -> right = insert(root -> right, val);

    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

    
}

Node* buildBST(int arr[],int size){
    Node* root = NULL;

    for(int  i = 0; i < size; i++){
        root = insert(root,arr[i]);
    }

    return root;

}

bool search(Node* root, int key){//O(height) ::: avg case == O(logn)
    if(root == NULL){
        return false;
    }
    if(root -> data == key){
        return true;

    }

    if( root ->data > key){
        return search(root -> left, key);

    }
    if( root ->data < key){
        return search(root -> right, key);
        
    }
}

Node* getInorderSuccesor(Node* root){
    while(root -> left != NULL){
        root = root -> left;
    }
    return root;
}

Node* delNode(Node* root, int val){
    if( root == NULL){
        return NULL;
    }

    if(val < root -> data){
        root -> left = delNode(root -> left, val);
    }
    else if( val > root -> data){
        root -> right = delNode(root -> right, val);
    }
    else{ // root == val
        //case 1 root has 0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }
        //case 2 - root has one child
        if(root -> left == NULL || root -> right == NULL){
            return root -> left == NULL ? root -> right : root -> left;
        }

        //case 3 - root has 2 nodes
        Node* IS = getInorderSuccesor(root -> right);
        root -> data = IS -> data;
        root -> right = delNode(root -> right, IS -> data); //can be case1 or case2
        return root;
    }
    return root;

    
}


int main(){
    // int arr[6] = {5,1,3,4,2,7};
    // Node* root = buildBST(arr,6);

    int arr2[9] = {8,5,3,1,4,6,10,11,14};
    Node* root = buildBST(arr2,9);

    inorder(root);

    cout << endl << search(root , 2) << endl; 

    delNode(root, 4);

    inorder(root);
    cout << endl;


    return 0;
}
