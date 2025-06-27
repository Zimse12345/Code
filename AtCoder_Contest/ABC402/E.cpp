#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,x,vis[6000][1000];
double ans,f[6000][1000];

struct prb{
    int c;
    double s,p;
    prb(int c=0,double s=0,double p=0):c(c),s(s),p(p){}
}a[N];

double dfs(int rm,int z){
    if(vis[rm][z]++)return f[rm][z];
    for(int i=0;i<n;i++)if(!(z&(1<<i))){
        if(rm>=a[i].c){
            f[rm][z]=max(f[rm][z],a[i].p*(a[i].s+dfs(rm-a[i].c,z|(1<<i)))+(1.0-a[i].p)*dfs(rm-a[i].c,z));
        }
    }
    return f[rm][z];
}

signed main(){
    cin>>n>>x;
    for(int i=0;i<n;i++)cin>>a[i].s>>a[i].c>>a[i].p,a[i].p/=100.0;
    printf("%.9lf\n",dfs(x,0));
    return 0;
}


