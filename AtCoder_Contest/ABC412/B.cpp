#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
char s[N],t[N];
int vis[N];

signed main(){
    scanf("%s",s+1);
    scanf("%s",t+1);
    int n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=m;i++)vis[t[i]]=1;
    for(int i=2;i<=n;i++){
        if('A'<=s[i]&&s[i]<='Z'){
            if(!vis[s[i-1]]){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}


