#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,s[N],t;

signed main(){
    cin>>n;
    while(n--){
        int ty=0;
        cin>>ty;
        if(ty==1)++t,cin>>s[t];
        else printf("%d\n",s[t]),t=max(t-1,0);
    }
    return 0;
}


