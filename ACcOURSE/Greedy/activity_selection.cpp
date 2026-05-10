#include<bits/stdc++.h>

using namespace std;

int maxActivities(vector<int> start, vector<int> end ){
    // sort acording to end vector
    // select A0 as first activity
    cout<<"selecting activity A0" << endl;
    int count = 1;
    int curEndTime = end[0];

    for(int i = 1; i <= start.size(); i++){
        if(start[i] >= curEndTime ){
            cout << "selecting activity A"<< i<<endl;
            count++;
            curEndTime = end[i];
        }
    }

    return count;

}

bool compare(pair<int, int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}


int main(){
    // vector<int> start = {1,3,0,5,8,5};
    // vector<int> end = {2,4,6,7,9,9};

    // cout << maxActivities(start, end);

    vector<int> start = {0,1,3};
    vector<int> end = {9,2,4};

    vector<pair<int, int>> act(3, make_pair(0,0));
    act[0] = make_pair(0,9);
    act[1] = make_pair(1,2);
    act[2] = make_pair(3,4);

    for(int i = 0; i< act.size(); i++){
        cout<< "A" << i  << "  "<< act[i].first << " , " << act[i].second << endl;
    }

    sort(act.begin(), act.end(), compare);
    cout << "after sort" << endl;
    for(int i = 0; i< act.size(); i++){
        cout<< "A" << i  << "  "<< act[i].first << " , " << act[i].second << endl;
    }

    return 0;
}