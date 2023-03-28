#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

inline int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')y=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    return x*y;
}

int T;
int a[4][16],sum[4],ans[4][16],cnt;

bool dfs(int I,int p,int tag){
    if(p>9)return true;
    if(!a[I][p])return dfs(I,p+1,tag);
    if(a[I][p]>=3){
        a[I][p]-=3;
        int res=dfs(I,p,tag);
        a[I][p]+=3;
        if(res)return true;
    }
    if(a[I][p]&&a[I][p+1]&&a[I][p+2]&&a[I][p]<=a[I][p+1]){
        a[I][p]--,a[I][p+1]--,a[I][p+2]--;
        int res=dfs(I,p,tag);
        a[I][p]++,a[I][p+1]++,a[I][p+2]++;
        if(res)return true;
    }
    if(tag&&a[I][p]>=2){
        a[I][p]-=2;
        int res=dfs(I,p,0);
        a[I][p]+=2;
        if(res)return true;
    }
    return false;
}

int ck(){
    int t=1;
    for(int i=0;i<4;i++)for(int j=1;j<=9;j++)if(a[i][j]){
        if(a[i][j]^2)t=0;
    }
    if(t)return 1;
    t=0;
    int tt=0;
    for(int i=1;i<4;i++){
        if(a[i][1])++t;
        if(a[i][9])++t;
        if(a[i][1]==2||a[i][9]==2)tt=1;
    }
    for(int i=1;i<=7;i++){
        if(a[0][i])++t;
        if(a[0][i]==2)tt=1;
    }
    if(t==13&&tt==1)return 1;
    int cnt2=0,cnt3=0,tag=1;
    for(int i=1;i<=7;i++)if(a[0][i]){
        if(a[0][i]==2)++cnt2;
        else if(a[0][i]==3)++cnt3;
        else tag=0;
    }
    if(!tag)return 0;
    for(int i=1;i<4;i++){
        if(sum[i]%3==0||sum[i]%3==2){
            if(dfs(i,1,sum[i]%3?1:0)){
                if(sum[i]%3)++cnt2;
                cnt3+=sum[i]/3;
            }
            else tag=0;
        }
        else tag=0;
    }
    if(!tag)return 0;
    if(cnt2==1&&cnt3==4)return 1;
    return 0;
}

int main(){
    // freopen("mahjong.in","r",stdin);
    // freopen("mahjong.out","w",stdout);
    
    T=read();
    while(T--){
        for(int i=0;i<4;i++){
            sum[i]=0;
            for(int j=1;j<=10;j++)a[i][j]=0,ans[i][j]=0;
        }
        cnt=0;
        int x=13;
        while(x--){
            char c=getchar();
            while(c<'0'||c>'9')c=getchar();
            int typ=getchar();
            if(typ=='m')typ=1;
            else if(typ=='s')typ=2;
            else if(typ=='p')typ=3;
            else typ=0;
            a[typ][c-'0']++,sum[typ]++;
        }
        for(int typ=0;typ<4;typ++){
            for(int i=1;i<=9;i++){
                if(!typ&&i>7)continue;
                if(a[typ][i]==4)continue;
                ++a[typ][i],++sum[typ];
                int res=ck();
                ans[typ][i]=res;
                cnt+=res;
                --a[typ][i],--sum[typ];
            }
        }
        if(!cnt){
            putchar('N');
            putchar('o');
            putchar('o');
            putchar('t');
            putchar('e');
            putchar('n');
            putchar('\n');
        }
        else{
            printf("%d",cnt);
            for(int i=1;i<4;i++){
                for(int j=1;j<=10;j++){
                    if(ans[i][j]){
                        putchar(' ');
                        putchar('0'+j);
                        if(i==1)putchar('m');
                        else if(i==2)putchar('s');
                        else putchar('p');
                    }
                }
            }
            for(int j=1;j<=7;j++){
                if(ans[0][j])putchar(' '),putchar('0'+j),putchar('c');
            }
            putchar('\n');
        }
    }
    return 0;
}

