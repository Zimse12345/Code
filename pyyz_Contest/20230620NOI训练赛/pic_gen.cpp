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

const int N=1.01e6;
const int T[5]={10000,10000,1000,500,200};
const int min_N[5]={60,60,9000,9000,80000};
const int max_N[5]={100,100,10000,10000,100000};
const int m[5]={200,500,10000,40000,100000};
int id,n[N];

inline int rd(){
    int x=rand()%8192,y=rand()%8192;
    return x*8192+y;
}

signed main(){
    srand(time(0));
    iF("pre.txt");
    id=(read()+1)%5;
    fclose(stdin);
    oF("pre.txt");
    _wri(id);
    fclose(stdout);
    oF("pic.in");
    printf("%d 0.0 0.0 0.0 0.0 %d %d %d\n",T[id],min_N[id],max_N[id],m[id]);
    for(int i=1;i<=T[id];i++){
        n[i]=min_N[id]+rd()%(max_N[id]-min_N[id]+1);
        for(int j=1;j<=m[id];j++){
            int s=rd()%n[i]+1;
            while(s)pc(s%3+'a'),s/=3;
            pc(10);
        }
    }
    fclose(stdout);
    oF("pic.ans");
    for(int i=1;i<=T[id];i++)_wri(n[i]);
    return 0;
}

