// Author: Zimse
// Data: 2023-05-

#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)

namespace Zimse{const int INF=1.01e9,Mod=998244353;
int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
void WRI(int x){if(x<0)pc(45),x=-x;if(x>=10)WRI(x/10);pc(48+x%10);}
void write_(int x){WRI(x),pc(32);}void _write(int x){WRI(x),pc(10);}
void ifile(const char *x){freopen(x,"r",stdin);}
void ofile(const char *x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;
while(y){if(y&1)z=x*z%Mod;x=x*x%Mod,y/=2;}return z;}
inline void _max(int &x,int y){if(x<y)x=y;}
inline void _min(int &x,int y){if(y<x)x=y;}
inline void addmod(int &x,int y){(x+=y)%=Mod;}
}using namespace Zimse;using namespace std;

const int N=1.01e6;
int T,k,ans[256][256],n,m,v[N],A[N];

void check(){
    return;
    int sum=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        ++sum;
        int p=i;
        while(p>1&&ans[p-1][j]>ans[p][j])--p,++sum;
        p=i;
        while(p<n&&ans[p+1][j]>ans[p][j])++p,++sum;
        p=j;
        while(p>1&&ans[i][p-1]>ans[i][p])--p,++sum;
        p=j;
        while(p<m&&ans[i][p+1]>ans[i][p])++p,++sum;
    }
    printf("(%d,%d)\n",sum,k);
    if(sum!=k)printf("rm=%d\n",k-sum);
    return;
}

void ins(int p,int t){
    for(int i=1;i<=t;i++)ans[i][p]+=1000*i;
    return;
}

signed main(){
    for(int i=1;i<=200;i++)A[i]=(i&1);
    for(int i=1;i<=200;i++){
        A[i]+=10*i;
        for(int j=1;j<=200;j++){
            ++v[i];
            int x=j;
            while(x>1&&A[x-1]<A[x])--x,++v[i];
            x=j;
            while(x<200&&A[x+1]<A[x])++x,++v[i];
        }
        if(i!=1)v[i]-=v[1];
    }

    // ifile("chocolate.in");
    // ofile("chocolate.out");

    T=read();
    while(T--){
        k=read();
        int len=1,rm=k;
        while(len<200&&(len+1)*(len+2)/2<=k)++len;
        rm-=len*(len+1)/2;
        if(len+rm<=200){
            n=1,m=rm+len;
            int cur=0;
            printf("%d %d\n",n,m);
            for(int i=len;i>=1;i--)ans[1][++cur]=i;
            while(rm>0)--rm,ans[1][++cur]=1;
            check();
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)write_(ans[i][j]);
                pc(10);
            }
            continue;
        }
        n=min(200,k/200-1),m=200;
        printf("%d %d\n",n,m);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans[i][j]=1;
        rm=k-n*m;
        int p=1;
        while(rm>0&&p<n){
            for(int i=1;i<m;i++){
                ans[p][i]=2;
                if(p==1||p==n){
                    if(i==1)rm-=2;
                    else rm-=1;
                }
                else{
                    if(i==1)rm-=3;
                    else{
                        if(rm==1)ans[p][i-1]=3,ans[p][i]=1,rm-=1;
                        else rm-=2;
                    }
                }
                if(rm<=0)break;
            }
            if(rm==1)ans[p][m-1]=3,rm-=1;
            else if(rm==2)ans[p][m-3]=3,rm-=2;
            else if(rm==3)ans[p][m-2]=3,rm-=3;
            else if(rm==4)ans[p][m-3]=3,ans[p][m-5]=3,rm-=4;
            p+=2;
        }
        p=1;
        while(rm>0&&p<n){
            int t=1;
            while(t<=196&&(t+1)*(t+2)/2<=rm)++t;
            for(int i=1;i<=t;i++)ans[p][i]+=t-i+1+300;
            rm-=t*(t+1)/2,p+=2;
        }
        p=2;
        while(rm>0&&p<n-4){
            int t=1;
            while(t<=196&&(t+1)*(t+2)/2<=rm)++t;
            for(int i=1;i<=t;i++)ans[p][i]+=t-i+1;
            rm-=t*(t+1)/2,p+=2;
        }
        p=1;
        while(rm>0&&p<194){
            int t=3;
            while(t<=194&&(t+1)*(t+2)/2-(t)<=rm)t+=2;
            for(int i=1;i<=t;i++)ans[i][p]+=1000*i;
            rm-=t*(t-1)/2-(t-1),p+=1;
        }
        if(rm==0){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=200;j++)write_(ans[i][j]);
                pc(10);
            }
            check();
            continue;
        }
        rm=k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ans[i][j]=m-j+1;
                if(i&1)ans[i][j]+=500;
            }
        }
        rm-=4059800;
        p=1;
        while(rm>0&&p<=200){
            int t=3;
            while(t<200&&v[t+1]<=rm)t++;
            ins(p,t);
            rm-=v[t],p+=1;
        }
        check();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=200;j++)write_(ans[i][j]);
            pc(10);
        }
    }
    return 0;
}
