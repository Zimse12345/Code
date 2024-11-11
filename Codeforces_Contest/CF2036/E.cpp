#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,k,q,m;
vector<int> a[N];

signed main(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        a[i].resize(k+1);
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
            if(i>1)a[i][j]|=a[i-1][j];
        }
    }
    while(q--){
        cin>>m;
        int l=1,r=n;
        while(m--){
            int id,val;
            char c;
            cin>>id>>c>>val;
            if(c=='>'){
                int L=1,R=n,p=n+1;
                while(L<=R){
                    int M=(L+R)/2;
                    if(a[M][id]>val)p=M,R=M-1;
                    else L=M+1;
                }
                l=max(l,p);
            }
            if(c=='<'){
                int L=1,R=n,p=0;
                while(L<=R){
                    int M=(L+R)/2;
                    if(a[M][id]<val)p=M,L=M+1;
                    else R=M-1;
                }
                r=min(r,p);
            }
        }
        if(l<=r)printf("%d\n",l);
        else printf("-1\n");
    }
    return 0;
}


