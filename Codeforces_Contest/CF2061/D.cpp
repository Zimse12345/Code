#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m;
map<int,int> a;

bool f(int x){
    if(a[x]>0){
        --a[x];
        return true;
    }
    if(x<=1)return false;
    if(!f(x/2))return false;
    if(!f(x-x/2))return false;
    return true;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        a.clear();
        for(int i=1,x;i<=n;i++){
            cin>>x;
            a[x]++;
        }
        int ans=1;
        for(int i=1,x;i<=m;i++){
            cin>>x;
            if(!f(x))ans=0;
        }
        for(map<int,int>::iterator it=a.begin();it!=a.end();it++){
            if((it->second)>0)ans=0;
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


