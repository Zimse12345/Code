#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <math.h>

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
int a[5];

struct node{
    string s;
    int r;
    bool operator < (const node& _)const{
        if(r==_.r)return s<_.s;
        return r>_.r;
    }
}p[40];

void solve(){
    for(int i=0;i<5;i++)cin>>a[i];
    for(int i=1;i<32;i++){
        string s;
        int r=0;
        for(int j=0;j<5;j++)if((1<<j)&i){
            r+=a[j];
            if(j==0)s=s+"A";
            if(j==1)s=s+"B";
            if(j==2)s=s+"C";
            if(j==3)s=s+"D";
            if(j==4)s=s+"E";
        }
        p[i].s=s;
        p[i].r=r;
    }
    sort(p+1,p+32);
    for(int i=1;i<32;i++){
        cout<<p[i].s<<endl;
    }
}

signed main(){

    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
  
    
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}
