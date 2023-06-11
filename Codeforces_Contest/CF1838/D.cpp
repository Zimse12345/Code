#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int N=1.01e6;
int n,q;
char s[N];
set<int> S;

signed main(){
    cin>>n>>q;
    scanf("%s",s+1);
    s[0]=')',s[n+1]='(';
    for(int i=0;i<=n;i++){
        if(s[i]==s[i+1])S.insert(i);
    }
    if(n&1){
        while(q--)printf("No\n");
        return 0;
    }
    while(q--){
        int i;
        cin>>i;
        if(s[i]==s[i-1])S.erase(i-1);
        else S.insert(i-1);
        if(s[i]==s[i+1])S.erase(i);
        else S.insert(i);
        if(s[i]=='(')s[i]=')';
        else s[i]='(';
        bool tag=true;
        if(!S.empty()){
            if(s[*S.begin()]==')')tag=0;
            if(s[*(--S.end())]=='(')tag=0;
        }
        if(tag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}



