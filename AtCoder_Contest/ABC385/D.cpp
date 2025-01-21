#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#define int long long

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
//#define int long long

using namespace std;

const int inf = 1.01e9;
const int mod = 998244353;
const int N = 5e5 + 10;

int n,m,sx,sy,id,cnt,vis[N];
map<int,int> _x,_y;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{return x<_.x;}
};
set<node> p[N];
void solve(){
    cin>>n>>m>>sx>>sy;
    for(int i=1,px,py;i<=n;i++){
        cin>>px>>py;
        if(!_x[px])_x[px]=++id;
        if(!_y[py])_y[py]=++id;
        p[_x[px]].insert(node(py,i));
        p[_y[py]].insert(node(px,i));
    }
    while(m--){
        char w;
        int len,L,R;
        cin>>w>>len;
        if(w=='L'||w=='R'){
            if(w=='L')L=sx-len,R=sx,sx-=len;
            else L=sx,R=sx+len,sx+=len;
            if(!_y[sy])continue;
            while(!p[_y[sy]].empty()){
                set<node>::iterator it=p[_y[sy]].lower_bound(node(L,0));
                if(it==p[_y[sy]].end()||it->x > R)break;
                if(!vis[it->y])vis[it->y]=1,++cnt;
                p[_y[sy]].erase(it);
            }
        }
        else{
            if(w=='D')L=sy-len,R=sy,sy-=len;
            else L=sy,R=sy+len,sy+=len;
            if(!_x[sx])continue;
            while(!p[_x[sx]].empty()){
                set<node>::iterator it=p[_x[sx]].lower_bound(node(L,0));
                if(it==p[_x[sx]].end()||it->x > R)break;
                if(!vis[it->y])vis[it->y]=1,++cnt;
                p[_x[sx]].erase(it);
            }
        }
    }
    printf("%lld %lld %lld\n",sx,sy,cnt);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
