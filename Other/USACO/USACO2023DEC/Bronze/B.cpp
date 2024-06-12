#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,a[N],m=N,x,y;
char s[N];

signed main(){
    cin>>n;
    scanf("%s",s+1);
    int tag=0,tag2=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1')tag=1;
        if(s[i]=='0')tag2=1;
    }
    if(!tag){
        printf("0\n");
        return 0;
    }
    if(!tag2){
        printf("1\n");
        return 0;
    }
    for(int i=1,t=0;i<=n+1;i++){
        if(s[i]=='1')++t;
        else if(t){
            if(t==i-1)x=t;
            else if(i==n+1)y=t;
            else a[t]++,m=min(m,t);
            t=0;
        }
    }
    if(m==N){
        if(x&&y){
            if(x>y)swap(x,y);
            x=x*2-1;
            printf("%d\n",1+(y+x-1)/x);
            return 0;
        }
        if(x||y){
            printf("1\n");
            return 0;
        }
        printf("0\n");
        return 0;
    }
    if(m%2==0)m--;
    if(x>=m)++a[x],x=0;
    if(y>=m)++a[y],x=0;
    for(int i=m;i>=1;i-=2){
        if(x*2-1>=i)++a[i],m=i,x=0;
        if(y*2-1>=i)++a[i],m=i,y=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans+=a[i]*((i+m-1)/m);
    printf("%d\n",ans);
    return 0;
}


