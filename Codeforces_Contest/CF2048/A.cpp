#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n%33==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


