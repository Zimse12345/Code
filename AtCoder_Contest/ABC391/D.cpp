#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,w,s[N],q;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
};
vector<node> h[N];

signed main(){
    cin>>n>>w;
    for(int i=1,x,y;i<=n;i++){
        cin>>x>>y;
        h[x].push_back(node(y,i));
    }
    for(int i=1;i<=w;i++)if(h[i].size()){
        sort(h[i].begin(),h[i].end());
    }
    for(int i=0;i<=n;i++){
        int tag=1,t=0;
        for(int j=1;j<=w;j++){
            if(int(h[j].size())<=i){
                tag=0;
                break;
            }
            t=max(t,h[j][i].x);
        }
        if(!tag)break;
        for(int j=1;j<=w;j++)s[h[j][i].y]=t;
    }
    cin>>q;
    while(q--){
        int t,a;
        cin>>t>>a;
        if(s[a]==0||s[a]>t)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


