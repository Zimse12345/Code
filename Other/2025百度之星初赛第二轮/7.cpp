#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,f[N][30],ans,sz[N],p[N],len,tag[N],dep[N],r[N];
vector<int> g[N];

int read(){int x=0
,y=1;char c=getchar();while(c<48||57<c){if(c==45)y=-1;c=getchar();}
while(47<c&&c<58)x=x*10+c-48,c=getchar();return x*y;}
void wr(int x)
{if(x<0)putchar(45),x=-x;if(x>=10)wr(x/10);putchar(48+x%10);}
void _wri(int x){wr(x),putchar(10);}

signed main(){
    r[0]=1;
    for(int i=1;i<N;i++)r[i]=r[i/2]+1;
    n=read();
    ++n;
    if(n>1){
        read();
        _wri(0);
    }
    len=2;
    p[1]=1,p[2]=2;
    sz[1]=2,sz[2]=1;
    dep[1]=1,dep[2]=2;
    tag[0]=tag[1]=tag[2]=1;
    for(int i=3;i<=n;i++){
        sz[i]=1;
        f[i][0]=read();
        dep[i]=dep[f[i][0]]+1;
        g[f[i][0]].push_back(i);
        for(int j=1;j<=r[dep[i]];j++)f[i][j]=f[f[i][j-1]][j-1];
        if(tag[f[i][0]]){
            if(f[i][0]==p[len]){
                p[++len]=i;
                tag[i]=1;
            }
            else{
                while(p[len-1]!=f[i][0]){
                    tag[p[len]]=0;
                    --len;
                    sz[p[len]]=1;
                    for(unsigned j=0;j<g[p[len]].size();j++)sz[p[len]]+=sz[g[p[len]][j]];
                }
                ans=max(ans,sz[p[len]]);
                tag[p[len]]=0,tag[i]=1;
                p[len]=i;
            }
        }
        else{
            int x=i;
            for(int j=r[dep[i]];j>=0;j--)if(!tag[f[x][j]])x=f[x][j];
            ++sz[x];
            ans=max(ans,sz[x]);
        }
        _wri(ans);
    }
    return 0;
}


