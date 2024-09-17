#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,q;
set<int> s;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        s.clear();
        for(int i=1,p;i<=m;i++){
            cin>>p;
            s.insert(p);
        }
        s.insert(0),s.insert(n+1);
        while(q--){
            int p;
            cin>>p;
            set<int>::iterator it=s.upper_bound(p);
            int R=*it;
            --it;
            int L=*it;
            if(L==0)printf("%d\n",R-1);
            else if(R==n+1)printf("%d\n",n-L);
            else printf("%d\n",(R-L)/2);
        }
    }
    return 0;
}


