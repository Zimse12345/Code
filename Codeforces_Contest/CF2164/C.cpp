#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,inf=1.01e9;
int T,n,a[N],B[N],C[N],m;
struct node{
    int b,c;
    node(int b=0,int c=0):b(b),c(c){}
    bool operator < (const node& _)const{
        if(c>0&&_.c>0){
            return b<_.b;
        }
        if(c==0&&_.c==0){
            return b<_.b;
        }
        return c>_.c;
    }
}p[N];
multiset<int> s;

signed main(){
    cin>>T;
    while(T--){
        s.clear();
        s.insert(inf); 
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s.insert(a[i]);
        }
        for(int i=1;i<=m;i++)cin>>B[i];
        for(int i=1;i<=m;i++){
            cin>>C[i];
            p[i]=node(B[i],C[i]);
        }
        sort(p+1,p+m+1);
        int ans=0;
        for(int i=1,b,c;i<=m;i++){
            b=p[i].b,c=p[i].c;
            multiset<int>::iterator it=s.lower_bound(b);
            int x=*it;
            if(x==inf)continue;
            s.erase(it);
            if(c)s.insert(max(x,c));
            ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


