#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
char s[2][N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        scanf("%s",s[0]+1);
        scanf("%s",s[1]+1);
        int ans=0;
        for(int i=1;i<=n-2;i++){
            if(s[0][i]=='x'&&s[0][i+2]=='x'&&s[0][i+1]=='.'
            &&s[1][i]=='.'&&s[1][i+1]=='.'&&s[1][i+2]=='.')++ans;
            if(s[1][i]=='x'&&s[1][i+2]=='x'&&s[1][i+1]=='.'
            &&s[0][i]=='.'&&s[0][i+1]=='.'&&s[0][i+2]=='.')++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}


