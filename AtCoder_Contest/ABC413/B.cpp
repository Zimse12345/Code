#include <bits/stdc++.h>
using namespace std;

const int N=110;
int n;
string s[N];
set<string> S;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)if(i!=j){
            string str=s[i]+s[j];
            S.insert(str);
        }
    }
    printf("%llu\n",S.size());
    return 0;
}


