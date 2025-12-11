#include <bits/stdc++.h>
using namespace std;

int id; 
mt19937 Rd;

int rd(){
    int x=Rd();
    return x<0?-x:x;
}

void make_in(int id){
    printf("%d %d\n",rd(),id);
    return;
}

signed main(){
    freopen("id.txt","r",stdin);
    freopen("data.in","w",stdout);
    cin>>id;
    Rd.seed(id);
    make_in(id);
    fclose(stdout);
    fclose(stdin);
    system("std.exe");
    return 0;
}


