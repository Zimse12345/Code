#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],ans[N],t,cnt[N],vis[N];

struct node{
    int v,pos;
    node(int v=0,int pos=0):v(v),pos(pos){}
    bool operator < (const node &_)const{
        if(v==_.v)return pos<_.pos;
        return v<_.v; 
    }
};
set<node> s1,s2;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],++cnt[a[i]],vis[i]=0;
        t=0;
        s1.clear();
        s2.clear();
        for(int i=1;i<=n;i++){
            s1.insert(node(-a[i],i));
            s2.insert(node(a[i],i));
            --cnt[a[i]];
            if(!cnt[a[i]])while(!vis[a[i]]){
                if(t%2==0){
                    set<node>::iterator it=s1.begin();
                    if(!vis[-it->v]&&(it->pos)>ans[t])ans[++t]=it->pos;
                    s1.erase(it);
                }
                else{
                    set<node>::iterator it=s2.begin();
                    if(!vis[it->v]&&(it->pos)>ans[t])ans[++t]=it->pos;
                    s2.erase(it);
                }
                vis[a[ans[t]]]=1;
            }
        }
        printf("%d\n",t);
        for(int i=1;i<=t;i++)printf("%d ",a[ans[i]]);
        printf("\n");
        for(int i=1;i<=n;i++)cnt[i]=0;
    }
    return 0;
}


