#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1e9+9;
struct arr{
    
}
int n,c,a[N][2],g[N][5],f1[N],f2[N],ans;
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return qp(x,Mod-2);}
inline void add(int& x,int y){x=(x+y)%Mod;return;}

signed main(){
    n=read(),c=read();
    g[0][3]=1;
    for(int i=1;i<=n;i++){
        g[i][0]=(g[i-1][0]*(c-3+(c-4)*(c-4))+(g[i-1][1]+g[i-1][2])*2*(c-3)+g[i-1][3]+g[i-1][4])%Mod;
        g[i][1]=(g[i-1][0]*(c-3)*(c-3)+g[i-1][2]*(2*c-5)+g[i-1][1]*(c-2)+g[i-1][4])%Mod;
        g[i][2]=(g[i-1][0]*(c-3)*(c-3)+g[i-1][1]*(2*c-5)+g[i-1][2]*(c-2)+g[i-1][3])%Mod;
        g[i][3]=(g[i-1][0]*(c-2)*(c-3)+g[i-1][2]*2*(c-2)+g[i-1][4])%Mod;
        g[i][4]=(g[i-1][0]*(c-2)*(c-3)+g[i-1][1]*2*(c-2)+g[i-1][3])%Mod;
    }
    for(int i=1;i<=n;i++)a[i][0]=read();
    for(int i=1;i<=n;i++)a[i][1]=read();
    int pre=0;
    for(int i=1;i<=n;i++)if(a[i][0]||a[i][1]){
        if(a[i][0]==0){
            if(!pre){
                for(int j=1;j<=c;j++)if(j!=a[i][1]){
                    f1[j]=(g[i-1][0]*(c-2)*(c-3)+(g[i-1][1]+g[i-1][2])*2*(c-2)+g[i-1][3]+g[i-1][4])%Mod;
                }
            }
            else{
                int sum=0;
                for(int j=1;j<=c;j++)f2[j]=0,add(sum,f1[j]);
                for(int j=1;j<=c;j++)if(j!=a[i][1]){
                    int x=j,y=a[i][1],z=a[pre][0],t=i-pre;
                    if(!a[pre][0])swap(x,y),z=a[pre][1];
                    if(z==x)add(f2[j],(sum-f1[y])*g[t][1]+f1[y]*g[t][3]);
                    else if(z==y)add(f2[j],(sum-f1[x])*g[t][2]+f1[x]*g[t][4]);
                    else add(f2[j],(sum-f1[x]-f1[y])*g[t][0]+f1[x]*g[t][2]+f1[y]*g[t][1]);
                }
                for(int j=1;j<=c;j++)f1[j]=f2[j];
            }
        }
        else if(a[i][1]==0){
            if(!pre){
                for(int j=1;j<=c;j++)if(j!=a[i][0]){
                    f1[j]=(g[i-1][0]*(c-2)*(c-3)+(g[i-1][1]+g[i-1][2])*2*(c-2)+g[i-1][3]+g[i-1][4])%Mod;
                }
            }
            else{
                int sum=0;
                for(int j=1;j<=c;j++)f2[j]=0,add(sum,f1[j]);
                for(int j=1;j<=c;j++)if(j!=a[i][0]){
                    int x=a[i][0],y=j,z=a[pre][0],t=i-pre;
                    if(!a[pre][0])swap(x,y),z=a[pre][1];
                    if(z==x)add(f2[j],(sum-f1[y])*g[t][1]+f1[y]*g[t][3]);
                    else if(z==y)add(f2[j],(sum-f1[x])*g[t][2]+f1[x]*g[t][4]);
                    else add(f2[j],(sum-f1[x]-f1[y])*g[t][0]+f1[x]*g[t][2]+f1[y]*g[t][1]);
                }
                for(int j=1;j<=c;j++)f1[j]=f2[j];
            }
        }
        else{
            if(!pre){
                for(int j=1;j<=c;j++)if(j==a[i][1]){
                    f1[j]=(g[i-1][0]*(c-2)*(c-3)+(g[i-1][1]+g[i-1][2])*2*(c-2)+g[i-1][3]+g[i-1][4])%Mod;
                }
            }
            else{
                int sum=0;
                for(int j=1;j<=c;j++)f2[j]=0,add(sum,f1[j]);
                int x=a[i][0],y=a[i][1],z=a[pre][0],t=i-pre,j=a[i][1];
                if(!a[pre][0])swap(x,y),z=a[pre][1];
                if(z==x)add(f2[j],(sum-f1[y])*g[t][1]+f1[y]*g[t][3]);
                else if(z==y)add(f2[j],(sum-f1[x])*g[t][2]+f1[x]*g[t][4]);
                else add(f2[j],(sum-f1[x]-f1[y])*g[t][0]+f1[x]*g[t][2]+f1[y]*g[t][1]);
                for(int j=1;j<=c;j++)f1[j]=f2[j];
            }
        }
        pre=i;
    }
    for(int i=1;i<=c;i++){
        ans=(ans+f1[i]*(g[n-pre][0]*(c-2)*(c-3)%Mod+(g[n-pre][1]+g[n-pre][2])*2*(c-2)%Mod+g[n-pre][3]+g[n-pre][4]))%Mod;
    }
    ans=(ans+Mod)%Mod;
    printf("%lld\n",ans);
    return 0;
}
