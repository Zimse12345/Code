#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <math.h>
#include <functional> 

#define endl '\n'
#define pii pair<int, int>
#define pdd pair<double, double> 
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define codeforces cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false)
#define bendl(x) x.begin(), x.end()
#define siz(x) ((int)(x).size())
#define int long long

using namespace std;

const int inf = 1 << 30;
const int mod = 998244353;
const int N = 1.01e6;
int n,x[N],q,ans;
struct node{
    int l,r,p;
    node(int l=0,int r=0,int p=0):l(l),r(r),p(p){}
    bool operator < (const node& _)const{return r<_.r;}
};
set<node> s;

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        s.insert(node(i,i,x[i]));
    }
    cin>>q;
    while(q--){
        int t,g;
        cin>>t>>g;
        set<node>::iterator it=s.lower_bound(node(t,t,0));
        node p=*it;
        if(p.p+(t-p.l)<g){
            s.erase(it);
            if(t>p.l)s.insert(node(p.l,t-1,p.p));
            p.p+=(t-p.l),p.l=t;
            while(p.p<g){
                if(p.r==n)ans+=(p.r-p.l+1)*(g-p.p),p.p=g;
                else{
                    it=s.upper_bound(p);
                    int st=min(g-p.p,it->p-(p.p+p.r-p.l)-1);
                    ans+=(p.r-p.l+1)*st,p.p+=st;
                    if(p.p+p.r-p.l==it->p-1){
                        p.r=it->r;
                        s.erase(it);
                    }
                }
            }
            s.insert(p);
        }
        else if(p.p+(t-p.l)>g){
            s.erase(it);
            if(t<p.r)s.insert(node(t+1,p.r,p.p+t+1-p.l));
            p.r=t;
            while(p.p+p.r-p.l>g){
                if(p.l==1)ans+=(p.r-p.l+1)*(p.p+p.r-p.l-g),p.p-=(p.p+p.r-p.l-g);
                else{
                    it=s.lower_bound(p),--it;
                    int st=min(p.p+p.r-p.l-g,p.p-(it->p+it->r-it->l)-1);
                    ans+=(p.r-p.l+1)*st,p.p-=st;
                    if(p.p==it->p+it->r-it->l+1){
                        p.l=it->l,p.p=it->p;
                        s.erase(it);
                    }
                }
            }
            s.insert(p); 
        }
    }
    printf("%lld\n",ans);
    return; 
}

signed main(){
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}


