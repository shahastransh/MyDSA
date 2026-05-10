#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;


    Node(int val){
        data = val;
        next = NULL;
    }

    
};

class List{
public:    
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }
    

    void push_front(int val){
        Node* newNode = new Node(val);//dynamic
        
        if(head == NULL){
            head = tail = newNode;
            
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;

        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    

    

    

    void pop_front(){
        if(head == NULL){
            cout <<"LL is empty "<< endl;
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }

        
};

void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp ->data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
}

bool cycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast =  fast -> next -> next;

        if( fast == slow){
            cout << "cycle exist "<< endl;
            return true;

        }
    }
    cout<<"cycle doesn't exist "<< endl;
    return false;
}

void removeCycle(Node* head){
    //detect cycle
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if( fast ==  slow){
            cout<< " cycle detected "<<endl;
            isCycle = true;
            break;
        }

    }

    if(!isCycle){
        cout<< " cycle doesnot exist "<<endl;
        return;
    }

    slow = head;
    if(slow == fast){//special case
        while( fast -> next !=  slow){
            fast = fast ->  next;
        }
        fast ->  next = NULL; //remove cyle

    }else{
        Node* prev = fast;
        while(slow !=  fast){
            slow =  slow -> next;
            prev = fast;
            fast = fast -> next;

        }
        prev -> next = NULL; //remove cyle

    }
}
Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    while(fast != NULL && fast -> next != NULL ){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;

    }
    if(prev != NULL){
        prev -> next = NULL;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i -> next;
        }else{
            ans.push_back(j->data);
            j = j -> next;
        }
    }
    while(i != NULL){
        ans.push_back(i->data);
        i = i -> next;
    }
    while(j != NULL){
        ans.push_back(j->data);
        j = j -> next;
    }

    return ans.head;
}

Node* merge_sort(Node* head){
    if(head == NULL || head -> next ==NULL){
        return head;
    }
    Node* rightHead = splitAtMid(head);
    Node* left = merge_sort(head);
    Node* right = merge_sort(rightHead);

    return merge(left,right);
}

int main(){
    List LL;
    LL.push_front(2);
    LL.push_front(3);
    LL.push_front(4);
    LL.push_front(5);
    LL.push_back(7);
    

    
    printList(LL.head);
    LL.head = merge_sort(LL.head);
    printList(LL.head);

    return 0;
}