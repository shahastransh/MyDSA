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

int main(){
    List LL;
    LL.push_front(4);
    LL.push_front(3);
    LL.push_front(2);
    LL.push_front(1);
    LL.tail -> next = LL.head;

    removeCycle(LL.head);
    printList(LL.head);

    return 0;
}