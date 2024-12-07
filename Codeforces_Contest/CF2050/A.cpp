#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,ans,tag;
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans=tag=0;
        while(n--){
            scanf("%s",s+1);
            int len=strlen(s+1);
            if(len<=m&&tag==0)m-=len,++ans;
            else tag=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


