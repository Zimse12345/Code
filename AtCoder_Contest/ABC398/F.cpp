#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,bd[N];
char str[N],s[N];

signed main(){
    cin>>n;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(int i=1;i<=n;i++)s[n-i+1]=s[n+i]=str[i];
    for(int i=2,j=0;i<=n*2;i++){
        while(j&&s[i]!=s[j+1])j=bd[j];
        if(s[i]!=s[j+1])j=0;
        else ++j;
        bd[i]=j;
//        printf("%c %d\n",s[i],bd[i]);
    }
    int ans=n-min(bd[n*2]-1,n);
    for(int i=1;i<=n;i++)printf("%c",str[i]);
    for(int i=ans-1;i>=1;i--)printf("%c",str[i]);
    printf("\n");
    return 0;
}


