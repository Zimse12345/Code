#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        if((n>=2&&m>=3)||(n>=3&&m>=2))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


