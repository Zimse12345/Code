#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,s,t[N],ans=1; 

signed main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        if(t[i]-t[i-1]>s)ans=0;
    }
    if(ans)printf("Yes\n");
    else printf("No\n");
    return 0;
}


