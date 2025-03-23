#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],ans[N];
vector<int> p[N];

int ck(int v,int x){
    int t=0,pre=-n;
    for(unsigned i=0;i<p[v].size();i++){
        if(p[v][i]-pre>x)pre=p[v][i],++t;
    }
    return t;
}

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)if(p[i].size()){
        int x=n;
        while(x){
            int px=x,t=ck(i,x);
            for(int j=17;j>=0;j--){
                int d=(1<<j);
                if(px-d>0&&ck(i,px-d)==t)px-=d;
            }
            ans[px]+=t,ans[x+1]-=t;
            x=px-1;
        }
    }
    for(int i=1;i<=n;i++)ans[i]+=ans[i-1],printf("%d\n",ans[i]);
    return 0;
}


