// Author:Zimse  Data:2023-06-
#include <bits/stdc++.h>
#define pc putchar
#define pb push_back
#define inv fpow
//#define int long long
//#define M ((L+R)/2)
namespace OI{const int INF=1.001e9,Mod=998244353;int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}void wr(int x)
{if(x<0)pc(45),x=-x;if(x>=10)wr(x/10);pc(48+x%10);}void wri(int x){
wr(x),pc(32);}void _wri(int x){wr(x),pc(10);}void iF(const char*x){
freopen(x,"r",stdin);}void oF(const char*x){freopen(x,"w",stdout);}
inline int fpow(long long x,int y=Mod-2){int z=1;while(y){if(y&1)z=
x*z%Mod;x=x*x%Mod,y/=2;}return z;}inline void _max(int&x,int y){if(
x<y)x=y;}inline void _min(int&x,int y){if(y<x)x=y;}inline void _mod
(int&x,int y){(x+=y)%=Mod;}}using namespace OI;using namespace std;

const int N=5.01e6;
int n,pre,mn,tag;
char str[N],s[N];

signed main(){
    iF("barca.in");
    oF("barca.out");
    
    n=read();
    scanf("%s",str+1);
    pre=-1,mn=INF,str[n+2]='1';
    for(int i=1;i<=n+2;i++)if(str[i]=='1'){
        if(pre<i-1)mn=min(mn,i-pre-2);
        pre=i;
    }
    if(mn<=0){
        for(int i=1;i<n;i++)if(str[i]=='0'&&str[i+1]=='0'){
            printf("No\n");
            return 0;
        }
        if(str[1]=='0'||str[n]=='0'){
            printf("No\n");
            return 0;
        }
        printf("Yes\n");
        for(int i=1;i<=n;i++)pc(str[i]=='1'?'B':'R');
        pc(10);
        return 0;
    }
    if(mn>=1){
        for(int i=1;i<=n+2;i++)s[i]=str[i];
        pre=-1,tag=1;
        for(int i=1;i<=n+2;i++)if(str[i]=='1'){
            if(pre<i-1){
                int len=i-pre-2;
                if(len%2==0){tag=0;break;}
                for(int j=i-1;j>pre+1;j-=2)str[j]='1';
            }
            pre=i;
        }
        if(tag){
            printf("Yes\n");
            for(int i=1;i<=n;i++)pc(str[i]=='1'?'B':'R');
            pc(10);
            return 0;
        }
        for(int i=1;i<=n+2;i++)str[i]=s[i];
    }
    if(mn>=2){
        for(int i=1;i<=n+2;i++)s[i]=str[i];
        char strn=str[n];
        pre=-1,tag=1;
        for(int i=1;i<=n+2;i++)if(str[i]=='1'){
            if(pre<i-1){
                int len=i-pre-2;
                if(len==3){tag=0;break;}
                str[i-1]='1';
                for(int j=i-2;j>pre+1;j-=2)str[j]='1';
                if(len&1)str[pre+2]='1';
            }
            pre=i;
        }
        str[n]=strn;
        if(tag){
            printf("Yes\n");
            for(int i=1;i<=n;i++)pc(str[i]=='1'?'B':'R');
            pc(10);
            return 0;
        }
        for(int i=1;i<=n+2;i++)str[i]=s[i];
    }
    if(mn>=3){
        char strn=str[n],strn1=str[n-1];
        pre=-1,tag=1;
        for(int i=1;i<=n+2;i++)if(str[i]=='1'){
            if(pre<i-1){
                int len=i-pre-2;
                str[i-1]=str[i-2]='1';
                for(int j=i-3;j>pre+1;j-=2)str[j]='1';
                if(len%2==0)str[pre+2]='1';
            }
            pre=i;
        }
        str[n]=strn,str[n-1]=strn1;
        if(tag){
            printf("Yes\n");
            for(int i=1;i<=n;i++)pc(str[i]=='1'?'B':'R');
            pc(10);
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

