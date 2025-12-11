#include <bits/stdc++.h>
using namespace std;

const int N=1.01e5;
int n,k,x;
struct S{
    char s[60];
    int len;
    bool operator < (const S& _)const{
        for(int i=1;i<=min(len,_.len);i++){
            if(s[i]<_.s[i])return true;
            if(s[i]>_.s[i])return false;
        }
        return len<_.len;
    }
}str[N];
int cnt=0;
char a[100][100];
int id[100];

void dfs(int rm){
    if(!rm){
        ++cnt;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=strlen(a[id[i]]+1);j++){
                str[cnt].s[++str[cnt].len]=a[id[i]][j];
            }
        }
        return;
    }
    for(int i=1;i<=n;i++){
        id[rm]=i;
        dfs(rm-1);
    }
    return;
}

signed main(){
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
    dfs(k);
    sort(str+1,str+cnt+1);
    for(int i=1;i<=str[x].len;i++)printf("%c",str[x].s[i]);
    printf("\n");
    return 0;
}


