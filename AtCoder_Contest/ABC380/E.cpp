#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>
#include <cstring>

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
const int N = 1e6 + 10;
int n,q,t[N],col[N],len[N];
set<int> s;
void solve(){
    cin>>n>>q;
    for(int i=0;i<=n+1;i++){
        s.insert(i);
        col[i]=i,t[i]=1,len[i]=1; 
    }
    while(q--){
        int ty,x,c;
        cin>>ty>>x;
        if(ty==2){
            printf("%d\n",t[x]);
        }
        else{
            cin>>c;
            set<int>::iterator it=s.upper_bound(x),p;
            --it;
            t[col[*it]]-=len[*it];
            col[*it]=c;
            t[c]+=len[*it];
            p=it,++p;
            if(col[*p]==c)len[*it]+=len[*p],s.erase(p);
            p=it,--p;
            if(col[*p]==c)len[*p]+=len[*it],s.erase(it);
        }
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    // codeforces;
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
