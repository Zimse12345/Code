#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,to[N][26],cnt[N],t;
char s[N];
int ans;

signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);
        int p=0;
        for(int j=1;j<=len;j++){
            int c=s[j]-'a';
            if(!to[p][c])to[p][c]=++t;
            p=to[p][c];
            ans+=cnt[p]*2+1,++cnt[p];
            ans%=998244353;
        }
    }
    printf("%d\n",ans);
    return 0;
}


