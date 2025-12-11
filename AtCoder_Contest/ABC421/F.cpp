#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT)
#define int long long
using namespace std;
typedef long long LL;
const int N = 46656;
int read(){
    int x = 0,f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
class fhqTreap{
public:
    struct node{
        int l,r,v,ky,siz,sum,fa;
        node(int l=0,int r=0,int v=0,int ky=0,int siz=0,int sum=0,int fa=0):
            l(l),r(r),v(v),ky(ky),siz(siz),sum(sum),fa(fa){}
    };
    vector<node> t;
    vector<int> pos;
    int Root,Siz;
    
    inline void init(){
        srand(time(0));
        Root=Siz=0;
        t.push_back(node());
        return;
    }
    
    inline void update(int id){
        t[id].siz=t[t[id].l].siz+t[t[id].r].siz+1;
        t[id].sum=t[t[id].l].sum+t[t[id].r].sum+t[id].v;
        if(t[id].l)t[t[id].l].fa=id;
        if(t[id].r)t[t[id].r].fa=id;
        return;
    }
    
    inline void split_size(int id,int x,int& l,int& r){
    	if(!id){l=r=0;return;}
    	if(t[t[id].l].siz+1<=x){
    	    l=id;
            split_size(t[id].r,x-t[t[id].l].siz-1,t[id].r,r);
        }
    	else{
    	    r=id;
            split_size(t[id].l,x,l,t[id].l);
        }
    	update(id);
    	t[l].fa=t[r].fa=0;
        return;
    }
    
    inline int merge(int l,int r){
    	if(!l||!r)return l+r;
    	if(t[l].ky<t[r].ky){
            t[l].r=merge(t[l].r,r),update(l);
            return l;
        }
    	t[r].l=merge(l,t[r].l),update(r);
        return r;
    }
    
    inline void insert(int pre,int x){
        int l,r;
        t.push_back(node(0,0,x,rand(),1,x,0)),++Siz;
        pos.resize(x+1);
        pos[x]=Siz;
        split_size(Root,pre,l,r);
        Root=merge(merge(l,Siz),r);
        return;
    }
    
    inline int get_rk(int x){
        x=pos[x];
        int res=t[x].siz-t[t[x].r].siz;
        while(t[x].fa){
            int p=t[x].fa;
            if(t[p].r==x)res+=1+t[t[p].l].siz;
            x=p;
        }
        return res;
    }
    
    inline int update(int x,int y){
        x=get_rk(x),y=get_rk(y);
        if(x>y)swap(x,y);
        int l,mid,r;
        split_size(Root,y-1,mid,r);
        split_size(mid,x,l,mid);
        int res=t[mid].sum;
        Root=merge(l,r);
        return res;
    }
    
    inline void ck(int id){
        if(!id)return;
        ck(t[id].l),printf("%lld ",t[id].v),ck(t[id].r);
        return;
    }
};
fhqTreap tree;
inline void solve() {
    tree.init();
    int Q=0;
    cin>>Q;
    tree.insert(0,0);
    for(int i=1;i<=Q;i++){
        int ty=0,x=0,y=0;
        cin>>ty>>x;
        if(ty==1){
            int s=tree.get_rk(x);
            tree.insert(s,i);
        }
        else{
            cin>>y;
            printf("%lld\n",tree.update(x,y));
        }
    }
}
signed main() {
    int _ = 1; //cin >> _;
    while (_--) solve();
    return 0;
}

