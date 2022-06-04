#include <bits/stdc++.h>
using namespace std;

//歐拉路徑--最小字典序範例

//無向，只存在0或2點之出入度為奇數，其餘皆為偶數
//有向，所有點出度 = 入度

multiset <int> mp[5005];
stack <int> traversal;

void add_edge(int v1, int v2){
	mp[v1].insert(v2);
	mp[v2].insert(v1);
}

void travel(int prev){
	while (!mp[prev].empty()){
		int now = *mp[prev].begin();
		mp[prev].erase(mp[prev].find(now));
		mp[now].erase(mp[now].find(prev));
		travel(now);
	}
	traversal.push(prev);
}

void Euler_Path(){
	while (!traversal.empty()){
		cout << traversal.top() << ' ';
		traversal.pop();
	}
}

int main(){
	add_edge(1, 3);
	add_edge(2, 4);
	add_edge(1, 5);
	add_edge(3, 5);
	add_edge(1, 2);
	travel(1);
	Euler_Path();
}
