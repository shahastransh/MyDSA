#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Node{
public: 
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;

        for(int i = 0; i<key.size(); i++){
            if(temp -> children.count(key[i]) == 0){
                temp -> children[key[i]] = new Node();

            }
            temp = temp -> children[key[i]];

        }
        temp -> endOfWord = true;

    }

    bool search(string key){
        Node* temp = root;
        for(int i = 0; i< key.size(); i++){
            if(temp -> children.count(key[i])){
                temp = temp -> children[key[i]];
            }else{
                return false;
            }
            
        }
        return temp -> endOfWord ;
    }

    bool startsWith(string prefix){
        Node* temp = root;

        for(int i = 0; i<prefix.size(); i++){
            if(temp -> children.count(prefix[i])){
                temp = temp -> children[prefix[i]];
            }else{
                return false;
            }
        }
        return true;
    }
};

// bool helper(Trie &trie, string key){
//     if(key.size() == 0){
//         return true;
//     }
//     for(int i = 0; i<key.size(); i++){
//         string first = key.substr(0,i+1);
//         string second = key.substr(i+1);

//         if(trie.search(first) && helper(trie,second)){
//             return true;
//         }
//     }
//     return false;
// }

// bool wordBreak(vector<string> dict, string key){
//     Trie trie;
//     for(int i = 0; i<dict.size(); i++){
//         trie.insert(dict[i]);
//     }

//     return helper(trie,key);


// }



int main(){
    vector<string> dict ={"app", "apple", "mango", "man", "woman"};
    Trie trie;

    for(int i = 0; i< dict.size(); i++){
        trie.insert(dict[i]);
    }

    cout << trie.startsWith("wm") << endl;
    

    return 0;
}
