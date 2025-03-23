#include <bits/stdc++.h>
using namespace std;

const int N=1.01e3;
int T,n,A,B,x[N][N],ans;
char s[N][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>A>>B;
        for(int i=1;i<=n;i++){
            scanf("%s",s[i]+1);
            for(int j=1;j<=n;j++){
                if(s[i][j]=='W')x[i][j]=0;
                if(s[i][j]=='G')x[i][j]=1;
                if(s[i][j]=='B')x[i][j]=2;
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[i][j]>0){
                    --x[i][j],++ans;
                    if(i+B<=n&&j+A<=n)--x[i+B][j+A];
                }
                if(x[i][j]>0){
                    --x[i][j],++ans;
                    if(i-B<1||j-A<1||s[i-B][j-A]=='W')x[i][j]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)if(x[i][j]>0)ans=-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


