#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
struct node{
    int t,r;
    node(int t=0,int r=0):t(t),r(r){}
    bool operator < (const node& _)const{return r<_.r;} 
}a[N];
int T,n;
priority_queue<int> Q;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].r;
            cin>>a[i].t;
            a[i].r+=a[i].t;
        }
        sort(a+1,a+n+1);
        for(int i=1,s=0;i<=n;i++){
            s+=a[i].t;
            Q.push(a[i].t);
            if(s>a[i].r){
                s-=Q.top();
                Q.pop();
            }
            else ++ans;
        }
        printf("%lld\n",ans);
        while(!Q.empty())Q.pop();
    }
    return 0;
}


