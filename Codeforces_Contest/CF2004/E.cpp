#include <bits/stdc++.h>
using namespace std;

const int N=1.01e7;
int T,n,sg[N];
int p[1000000];
int prime[N],pr[N],pc;

inline int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}

signed main(){
    for(int i=2;i<N;i++){
        if(!pr[i])pr[i]=i,prime[++pc]=i;
        for(int j=1;j<=pc&&i*prime[j]<N;j++){
            pr[i*prime[j]]=prime[j];
            if(pr[i]==prime[j])break;
        }
    }
    int cnt=1;
    sg[1]=1,p[1]=1;
    for(int i=3;i<=10000000;i+=2){
        sg[i]=2;
        if(pr[i]==i)sg[i]=++cnt;
        else while(1){
            if(p[sg[i]]&&i%p[sg[i]]>0)++sg[i];
            else break;
        }
        if(sg[i]>0&&!p[sg[i]])p[sg[i]]=i;
    }
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        while(n--){
            int x;
            cin>>x;
            ans^=sg[x];
        }
        if(ans)printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}


