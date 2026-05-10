#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

static int idx = -1;

Node* buildTree(vector<int>nodes){
    idx++;
    if( nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode -> left = buildTree(nodes);
    currNode -> right = buildTree(nodes);

    return currNode;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }


    cout << root -> data<<" " ;
    preorder(root -> left);
    preorder(root -> right);

}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

}

void postOrder(Node* root){
    if(root == NULL){
        return ;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root->data << " ";
}

void levelOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout << endl;
            if(q.empty()){
                break;
            }
            q.push(NULL); //to track next line

        }else{
        
            cout << curr -> data << " ";
            

            if(curr -> left != NULL ){
                q.push(curr -> left);
                
            }
            if(curr -> right != NULL ){
                
                q.push(curr -> right);
            }

        }
        
    }
}

int count(Node* root){
    if( root == NULL){
        return 0;
    }
    int leftC = count(root -> left);
    int rightC = count(root -> right);
    return (leftC + rightC + 1);
}

int height(Node* root){
    if(root == NULL){
        return 0;

    }

    int leftHt = height(root -> left);
    int rightHt = height(root -> right);

    int currHt = max(leftHt,rightHt) + 1;

    return currHt;
}

int sumOfNodes(Node* root){
    if( root == NULL){
        return 0;
    }

    int leftS = sumOfNodes(root -> left);
    int rightS = sumOfNodes(root -> right);
    int currSum = (leftS + rightS + root -> data);
    cout << "sum = " << currSum << endl; 
    return currSum;
}

int diam1(Node* root){ //O(n^2)
    if(root == NULL){
        return 0;

    }

    int currDiam = height(root -> left) + height(root -> right)+1;
    int leftDiam = diam1(root -> left);
    int rightDiam = diam1(root -> right);

    return (max(currDiam, max(leftDiam,rightDiam)));
}

pair<int,int> diam2(Node* root ){
    if(root == NULL){
        return make_pair(0,0);
    }

    //(diameter, height)
    pair<int,int> leftInfo = diam2(root -> left); //LD, LH
    pair<int,int> rightInfo = diam2(root -> right); // RD, RH
    int currDiam = leftInfo.second + rightInfo.second + 1;

    int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
    int finalHt = (max(leftInfo.second, rightInfo.second) + 1);

    return make_pair(finalDiam,finalHt);
}
bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1 -> data != root2 -> data){
        return false;
    }
    return (isIdentical(root1->left, root2->left ) && isIdentical(root1 -> right, root2-> right));
}

bool isSubtree(Node* root, Node* subroot){
    if(root == NULL && subroot == NULL){
        return true;
    }
    if(root == NULL || subroot == NULL){
        return false;
    }
    if(root -> data == subroot -> data){
        //identical for subtrees
        if(isIdentical(root, subroot)){
            return true;
        }
    }
    bool leftSubtree = isSubtree(root -> left, subroot);
    if(!leftSubtree){
        return  isSubtree(root -> right, subroot);
    }

    return true;
}

void topView(Node* root){
    queue<pair<Node*,int>> q; //Node, HD
    map<int,int> m; // key = HD ; value = node -> data
    q.push(make_pair(root, 0));
    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0){//HD is unique then add in map
            m[currHD] = currNode -> data;
        }

        if(currNode -> left != NULL){
            pair<Node* , int> left = make_pair(currNode -> left, currHD-1);
            q.push(left);
        }
        if(currNode -> right != NULL){
            pair<Node* , int> right = make_pair(currNode -> right, currHD+1);
            q.push(right);
        }
    }

    cout<<  "top view = " <<endl;
    for(auto it : m){
        cout << it.second << endl;
    }
}

void kth_Helper(Node* root, int k, int currLevel){
    if(root == NULL){
        return;
    }
    if(currLevel == k ){
        cout << root -> data << " "  ;
        return;
    }  
    kth_Helper(root -> left, k , currLevel+1);
    kth_Helper(root -> right, k , currLevel+1);
}

void kth_level(Node* root, int k){
    kth_Helper(root, k , 1);
    cout << endl;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);

    kth_level(root,3);

    
 
    

    return 0;
}