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

    ~Node(){
        // cout << "destructor code for node data = " << data << endl;
        if(next != NULL){
            delete next;
            next = NULL;

        }
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }
    ~List(){
        // cout << "destructor code for list" << endl;
        if(head != NULL){
            delete head;
            head = NULL;

        }
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
    void push_pack(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp ->data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp = head;
        for( int i = 0; i < pos-1; i++){
            if(temp == NULL){
                cout << "position is invalid "<<endl;
                return;
            }
            temp = temp-> next;
             
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
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

    void pop_back(){
        Node* temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        temp -> next =NULL;
        delete tail;
        tail = temp;
    }

    int searchItr(int key){
        Node* temp = head;
        int idx = 0;

        while(temp != NULL){
            if(temp -> data == key){
                return idx;
            }

            temp = temp->next;
            idx++;

        }

        return -1;
    }

    int helper( Node* h, int key){
        if (h == NULL){
            return -1;
        }

        if(h -> data == key){
            return 0;
        }
        int idx = helper(h -> next, key);
        if(idx == -1){
            return -1;
        }
        return idx + 1;
    }
    int searchRec(int key){
        return helper(head,key);    
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        tail = head;
        

        while(curr != NULL){
            Node* next = curr -> next;
            curr -> next = prev;
            // updation for next itr
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    int size(){
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n){
        Node* prev = head;

        for( int i = 1; i <(size() - n); i++){
            prev = prev -> next;
        }

        Node* toDel = prev -> next;
        cout << "going to delete from end = " << toDel -> data << endl;
        prev -> next = prev -> next -> next;
    }
    
};

int main(){
    List LL;
    LL.push_front(10);
    LL.push_front(20);
    LL.push_front(30);
    LL.push_pack(40);
    LL.push_pack(15);
    LL.insert(1,3);
    LL.printList();
    
    LL.pop_front();
    LL.printList();
    LL.pop_back();
    LL.printList();
    cout << LL.searchItr(1) << endl;
    cout << LL.searchRec(40) << endl;
    LL.removeNth(2);
    // LL.reverse();
    LL.printList();
    
    return 0;
}