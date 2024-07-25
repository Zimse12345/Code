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

using namespace std;

const int inf = 1.5e9 + 7;
const int mod = 998244353;
const int N = 2e5 + 10, M = N << 1;
int n,t[N*30][2],mx[N*30],tot,a[N];
long long k;

void ins(int x){
    int id=0;
    for(int i=30;i>=0;i--){
        if(!(a[x]&(1<<i))){
            if(!t[id][0])t[id][0]=++tot;
            id=t[id][0];
        }
        else{
            if(!t[id][1])t[id][1]=++tot;
            id=t[id][1];
        }
        mx[id]=max(mx[id],x);
    }
    return;
}

int query(int x,int y){
    int id=0,res=0;
    for(int i=30;i>=0;i--){
        int A=(x&(1<<i))?1:0,B=(y&(1<<i))?1:0;
        if(A==0&&B==0)id=t[id][0];
        else if(A==1&&B==0)id=t[id][1];
        else if(A==0&&B==1)res=max(res,mx[t[id][0]]),id=t[id][1];
        else if(A==1&&B==1)res=max(res,mx[t[id][1]]),id=t[id][0];
        if(!id)break;
    }
    return res;
}

long long ck(int v){
    for(int i=0;i<=tot;i++)t[i][0]=t[i][1]=mx[i]=0;
    tot=0;
    long long res=0;
    int p=0;
    for(int i=1;i<=n;i++){
        
        p=max(p,query(a[i],v));
        res+=p;
        ins(i);
    }
    return res;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int L=1,R=(1<<30)-1,ans=0;
    while(L<=R){
        int M=(L+R)/2;
        if(ck(M)<k)ans=M,L=M+1;
        else R=M-1;
    }
    printf("%d\n",ans);
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T = 1;  cin >> T;
    while(T--) solve();
    return 0;
}