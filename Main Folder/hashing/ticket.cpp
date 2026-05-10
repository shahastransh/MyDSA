#include<iostream>
#include<vector>
#include<unordered_set>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;

void printItinerary(unordered_map<string,string> tickets){
    //starting piont
    unordered_set<string> to;
    for(pair<string,string> ticket : tickets){
        to.insert(ticket.second);
    }
    string start = "";
    for(pair<string,string> ticket : tickets){
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
        }
    }

    //print plan
    cout << start << " -> ";
    while(tickets.count(start)){
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << " final destination " << endl;
}

int main(){
    unordered_map<string,string> tickets;
    tickets["chennai"] = "bengaluru";
    tickets["mumbai"] = "delhi";
    tickets["goa"] = "chennai";
    tickets["delhi"] = "goa";

    printItinerary(tickets);

    return 0;
}