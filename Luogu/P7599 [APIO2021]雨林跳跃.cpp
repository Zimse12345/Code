#include <cstdio>
#include <vector>
#include <cassert>

void init(int N, std::vector<int> H);
int minimum_jumps(int A, int B, int C, int D);

const int NN=2e5+7;
int n,h[NN],lpos[NN],rpos[NN],to[NN][20],rto[NN][20],mx[NN][20],mxpos[NN][20];
int stk[NN],top,_lg2[NN];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};

node qmax(int L,int R){
	int len=R-L+1,d=_lg2[len];
	L=L+(1<<d)-1;
	if(mx[L][d]<mx[R][d])return node(mx[R][d],mxpos[R][d]);
	else return node(mx[L][d],mxpos[L][d]);
}

void init(int N, std::vector<int> H) {
	n=N;
	for(int i=1;i<=n;i++)h[i]=H[i-1];
	for(int i=1;i<=n;i++){
		while(top&&h[i]>h[stk[top]])--top;
		lpos[i]=stk[top],stk[++top]=i;
	}
	top=0;
	for(int i=n;i>=1;i--){
		while(top&&h[i]>h[stk[top]])--top;
		rpos[i]=stk[top],stk[++top]=i;
	}
	for(int i=1;i<=n;i++){
		to[i][0]=h[lpos[i]]<h[rpos[i]]?rpos[i]:lpos[i];
		rto[i][0]=rpos[i];
		mx[i][0]=h[i],mxpos[i][0]=i;
	}
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++)to[j][i]=to[to[j][i-1]][i-1],rto[j][i]=rto[rto[j][i-1]][i-1];
		for(int j=(1<<i),j2=(1<<(i-1));j<=n;j++,j2++){
			if(mx[j][i-1]>mx[j2][i-1])mx[j][i]=mx[j][i-1],mxpos[j][i]=mxpos[j][i-1];
			else mx[j][i]=mx[j2][i-1],mxpos[j][i]=mxpos[j2][i-1];
		}
	}
	_lg2[1]=0;
	for(int i=2;i<=n;i++)_lg2[i]=_lg2[i/2]+1;
	return;
}

int minimum_jumps(int A, int B, int C, int D) {
	++A,++B,++C,++D;
	int X=C,Rmx=qmax(C,D).x;
	for(int i=19;i>=0;i--){
		if(X>=(1<<i)&&mx[X][i]<=Rmx)X=X-(1<<i);
	}
	if(h[X]>Rmx){
		A=std::max(A,X+1);
		if(B<A)return -1;
	}
	int S=qmax(A,B).y,ps=0;
	if(C<=rpos[S]&&rpos[S]<=D)return 1;
	for(int i=19;i>=0;i--){
		int p=to[S][i];
		if(p&&h[p]<Rmx&&rpos[p]<=C)ps+=(1<<i),S=p;
	}
	int SS=S,_ps=ps;
	for(int i=19;i>=0;i--){
		int p=rto[S][i];
		if(!p||p>=C)continue;
		ps+=(1<<i),S=p; 
	}
	++ps;
	SS=to[SS][0];
	if(SS){
		if(C<=rpos[SS]&&rpos[SS]<=D)ps=std::min(ps,_ps+2);
	}
	return ps;
}
//
//int main() {
//  int N, Q;
//  assert(2 == scanf("%d %d", &N, &Q));
//  std::vector<int> H(N);
//  for (int i = 0; i < N; ++i) {
//    assert(1 == scanf("%d", &H[i]));
//  }
//  init(N, H);
//
//  for (int i = 0; i < Q; ++i) {
//    int A, B, C, D;
//    assert(4 == scanf("%d %d %d %d", &A, &B, &C, &D));
//    printf("%d\n", minimum_jumps(A, B, C, D));
//  }
//  return 0;
//}

