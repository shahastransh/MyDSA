#include <bits/stdc++.h>
using namespace std;




int main(){
    int n;
    int reverseNum = 0;
    cin>>n;
    int dup =n;
    int sum = 0;
    int count(int n);
        int cnt =0;
        while(n>0){
            int ld = n % 10;
            // cnt = cnt +1;
            n = n/10;
            // cout<<lastdigit<<endl;
            reverseNum = (reverseNum * 10) + ld;
            sum=sum + (ld*ld*ld);
            
            
        };
        // cout<<reverseNum;
        // cout<<cnt;
        // if(dup == reverseNum)
        //     cout << "True";
        // else cout <<"false";
        if(dup == sum) cout << "yes";
        else cout << "no";
        return 0;
    };

