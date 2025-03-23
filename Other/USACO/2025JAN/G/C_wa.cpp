#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
int n,T;
int X,Y;
int s[MAXN],x[MAXN],y[MAXN];

double D(int x1, int y1, int x2, int y2){
	return sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
}

struct Node{
	int lx, rx;
	int ly, ry;
	Node(int lx=0,int rx=0,int ly=0,int ry=0) : lx(lx),rx(rx),ly(ly),ry(ry) {}

	int dis() const {
		double d1 = D(X,0,lx,0) + D(lx,0,0,ly) + D(ly,0,Y,0);
		double d2 = D(X,0,rx,0) + D(rx,0,0,ry) + D(ry,0,Y,0);
		return int(min(d1,d2));
	}

	bool operator < (const Node &t) const {
		return lx < t.lx;
	}
};

bool pd(Node a, Node b){
	if(a.rx <= b.lx && a.ry <= b.ly) return 0;
	if(a.lx >= b.rx && a.ly >= b.ry) return 0;
	return 1;
}

int dis2(Node pre, Node suc){
	double d1 = D(X,0,suc.lx,0) + D(suc.lx,0,0,pre.ry) + D(0,pre.ry,0,Y);
	double d2 = D(X,0,pre.rx,0) + D(pre.rx,0,0,suc.ly) + D(0,suc.ly,0,Y);
	return int(min(d1,d2));
}

set<Node> S;
multiset<int> S_ans;
bool ok = 1;

set<Node> S2;
multiset<int> S2_ans;

void insert(Node t){
	auto p = S.insert(t).first;
	S_ans.insert(p->dis());
	if(p != S.begin() && next(p) != S.end()){
		auto pre = prev(p), suc = next(p);
		S_ans.erase(S_ans.find(dis2(*pre,*suc)));
	}
	if(p != S.begin()) S_ans.insert(dis2(*prev(p),*p));
	if(next(p) != S.end()) S_ans.insert(dis2(*p,*next(p)));
}

void erase(Node t){
	auto p = S.find(t);
	S_ans.erase(S_ans.find(p->dis()));
	if(p != S.begin() && next(p) != S.end()){
		auto pre = prev(p), suc = next(p);
		S_ans.insert(dis2(*pre,*suc));
	}
	if(p != S.begin()) S_ans.erase(S_ans.find(dis2(*prev(p),*p)));
	if(next(p) != S.end()) S_ans.erase(S_ans.find(dis2(*p,*next(p))));
	S.erase(p);
}

void add(int x,int y){
	if(ok){
		if(pd(Node(X,X,Y,Y),Node(x,x,y,y))) ok = 0;
	}
	auto p = S.lower_bound(Node(x,0,0,0));
	Node now;
	vector<set<Node>::iterator> tmp;
	bool flag = 0;
	if(p == S.end() || x < p->lx || x > p->rx){
		now = Node(x,x,y,y);
	}
	else{
		flag = 1;
		now = *p;
		now.ly = min(now.ly,y);
		now.ry = max(now.ry,y);
		tmp.push_back(p);
	}
	for(auto it = flag?next(p):p;it != S.end();++it){
		if(pd(now, *it)){
			tmp.push_back(it);
			now.lx = min(now.lx, it->lx);
			now.rx = max(now.rx, it->rx);
			now.ly = min(now.ly, it->ly);
			now.ry = max(now.ry, it->ry);
		}
		else break;
	}
	if(p != S.begin()){
		for(auto it = prev(p);;--it){
			if(pd(now, *it)){
				tmp.push_back(it);
				now.lx = min(now.lx, it->lx);
				now.rx = max(now.rx, it->rx);
				now.ly = min(now.ly, it->ly);
				now.ry = max(now.ry, it->ry);
			}
			else break;
			if(it == S.begin()) break;
		}
	}

	for(auto p:tmp){
		erase(*p);
	}

	insert(now);
	return;
}

void add2(int x,int y){
	auto p = S2.lower_bound(Node(x,0,0,0));
	Node now;
	vector<set<Node>::iterator> tmp;
	bool flag = 0;
	if(p == S2.end() || x < p->lx || x > p->rx){
		now = Node(x,x,y,y);
	}
	else{
		flag = 1;
		now = *p;
		now.ly = min(now.ly,y);
		now.ry = max(now.ry,y);
		tmp.push_back(p);
	}
	for(auto it = flag?next(p):p;it != S2.end();++it){
		if(pd(now, *it)){
			tmp.push_back(it);
			now.lx = min(now.lx, it->lx);
			now.rx = max(now.rx, it->rx);
			now.ly = min(now.ly, it->ly);
			now.ry = max(now.ry, it->ry);
		}
		else break;
	}
	if(p != S2.begin()){
		for(auto it = prev(p);;--it){
			if(pd(now, *it)){
				tmp.push_back(it);
				now.lx = min(now.lx, it->lx);
				now.rx = max(now.rx, it->rx);
				now.ly = min(now.ly, it->ly);
				now.ry = max(now.ry, it->ry);
			}
			else break;
			if(it == S2.begin()) break;
		}
	}

	for(auto p:tmp){
		S2_ans.erase(S2_ans.find(p->dis()));
		S2.erase(p);
	}
	S2_ans.insert(now.dis());
	S2.insert(now);
	return;
}
int main(){
	scanf("%d%d",&n,&T);
	scanf("%d%d",&X,&Y);
	for(int i = 1;i <= n;++i) scanf("%d%d%d",s+i,x+i,y+i);
	S2.insert(Node(X,X,Y,Y));
	S2_ans.insert(Node(X,X,Y,Y).dis());

	int p = 1;
	for(int t = 0;t < T;++t){
		while(p <= n && s[p] <= t){
			add(x[p], y[p]);
			add2(x[p],y[p]);
			++p;
		}
		if(t == 4){
		}
		if(ok){
			printf("%d\n",Node(X,X,Y,Y).dis());
		}
		else{
			printf("%d\n",min(*S2_ans.begin(),*S_ans.begin()));
		}
	}
	return 0;
}
