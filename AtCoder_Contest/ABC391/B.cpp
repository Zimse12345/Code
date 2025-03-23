#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int n,m;
char s[N][N],t[N][N];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    for(int i=1;i<=m;i++)scanf("%s",t[i]+1);
    for(int a=1;a+m-1<=n;a++){
        for(int b=1;b+m-1<=n;b++){
            int tag=1;
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    if(s[a+i-1][b+j-1]!=t[i][j])tag=0;
                }
            }
            if(tag){
                printf("%d %d\n",a,b);
                return 0;
            }
        }
    }
    return 0;
}


