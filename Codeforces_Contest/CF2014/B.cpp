#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int c=(n+1)/2-(n-k+1)/2;
        if(c&1)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}


