#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n;
map<int,int> mp;

struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x>_.x;}
}a[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)a[i]=node(0,i);
        mp.clear();
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            if(v<u)swap(u,v);
            mp[u*(n+1)+v]=1;
            ++a[u].x,++a[v].x;
        }
        sort(a+1,a+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(i>2&&j>3)break;
                int u=a[i].y,v=a[j].y,w=a[i].x+a[j].x-1;
                if(v<u)swap(u,v);
                if(mp[u*(n+1)+v]>0)--w;
                ans=max(ans,w);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


