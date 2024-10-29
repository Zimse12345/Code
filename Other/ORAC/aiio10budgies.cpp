#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,ans;
struct node{
    int l,r;
    node(int l=0,int r=0):l(l),r(r){}
    bool operator < (const node& _)const{return r<_.r;}
}s[N];

signed main(){
    freopen("shotin.txt","r",stdin);
    freopen("shotout.txt","w",stdout);
    
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i].l>>s[i].r;
    sort(s+1,s+n+1);
    for(int i=1,p=-1;i<=n;i++){
        if(s[i].l>p){
            p=s[i].r;
            ++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}


