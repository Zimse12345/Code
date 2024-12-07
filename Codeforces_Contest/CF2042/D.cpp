#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,ans[N];

struct node{
    int l,r,id;
    bool operator < (const node& _)const{return l>_.l;}
}a[N];
multiset<int> s;

void calc(){
    sort(a+1,a+n+1);
    s.clear();
    for(int i=1;i<=n;i++)s.insert(a[i].r);
    s.insert(2e9);
    for(int l=1,r;l<=n;){
        r=l;
        while(r<n&&a[r+1].l==a[r].l)++r;
        for(int i=l;i<=r;i++){
            s.erase(s.find(a[i].r));
            set<int>::iterator it=s.lower_bound(a[i].r);
            if(*it!=2e9)ans[a[i].id]+=*it-a[i].r;
            s.insert(a[i].r);
        }
        for(int i=l;i<=r;i++)s.erase(s.find(a[i].r));
        l=r+1;
    }
    return;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].l>>a[i].r;
            a[i].id=i;
            ans[i]=0;
        }
        calc();
        for(int i=1;i<=n;i++){
            swap(a[i].l,a[i].r);
            a[i].l=-a[i].l;
            a[i].r=-a[i].r;
        }
        calc();
        for(int i=1;i<=n;i++)printf("%d\n",ans[i]);
    }
    return 0;
}


