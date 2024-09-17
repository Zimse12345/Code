#include <bits/stdc++.h>
using namespace std;

const int N=4.01e5;
int n,m,q,ans;
set<int> L[N],C[N];

signed main(){
    cin>>n>>m>>q;
    ans=n*m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            L[i].insert(j);
            C[j].insert(i);
        }
    }
    for(int i=1;i<=n;i++)L[i].insert(0),L[i].insert(m+1);
    for(int i=1;i<=m;i++)C[i].insert(0),C[i].insert(n+1);
    while(q--){
        int x,y;
        cin>>x>>y;
        set<int>::iterator it=L[x].lower_bound(y);
        if(*it==y){
            --ans;
            L[x].erase(y);
            C[y].erase(x);
            continue;
        }
        if(*it<=m)C[*it].erase(x),L[x].erase(*it),--ans;
        
        it=L[x].lower_bound(y),--it;
        if(*it>=1)C[*it].erase(x),L[x].erase(*it),--ans;
        
        it=C[y].lower_bound(x);
        if(*it<=n)L[*it].erase(y),C[y].erase(*it),--ans;
        
        it=C[y].lower_bound(x),--it;
        if(*it>=1)L[*it].erase(y),C[y].erase(*it),--ans;
    }
    printf("%d\n",ans);
    return 0;
}


