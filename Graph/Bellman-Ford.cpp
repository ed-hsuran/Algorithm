//參考網址 維基百科
//https://zh.wikipedia.org/zh-tw/%E8%B4%9D%E5%B0%94%E6%9B%BC-%E7%A6%8F%E7%89%B9%E7%AE%97%E6%B3%95

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
typedef pair <int, int> pii;

//Bellman-Ford--檢查負環(單源點對最短路徑)
//檢查*負環*，非負權邊

vector <int> dis;
vector <pii> adj[5005];

void add_edge(int v1, int v2, int wgt){
	adj[v1].pb({v2, wgt});
	adj[v2].pb({v1, wgt});
}

bool SPFA(int v, int n){
	int inf = 1e7;
	dis.assign(n, inf);
	queue <int> q;
	vector <int>  prev(n, n+1); //無向圖++
	vector <int>  relax(n, 0);
	vector <bool> inque(n, false);
	
	q.push(v);
	inque[v] = true;
	dis[v] = 0;
	
	while (!q.empty()){
		int dot = q.front();
		q.pop();
		inque[dot] = false;
		for (auto data: adj[dot]){
			if (prev[data.f] == dot) continue; //無向圖++
			if (dis[data.f] > dis[dot] + data.s){
				prev[data.f] = dot; //無向圖++
				prev[dot] = data.f; //無向圖++
				relax[data.f]++;
				if (relax[data.f] == n) return true;
				dis[data.f] = dis[dot] + data.s;
				if (!inque[data.f]){
					inque[data.f] = true;
					q.push(data.f);
				}
			}
		}
	}
	return false;
}

int main(){
	add_edge(0, 2, 2);
	add_edge(0, 4, 2);
	add_edge(0, 5, 5);
	add_edge(1, 4, 8);
	add_edge(1, 5, 4);
	add_edge(2, 3, -3);
	add_edge(2, 4, 9);
	add_edge(4, 5, 1);
	cout << "存在負環: " <<  (SPFA(0, 6)? "True" : "False") << '\n';
	for (int i=0; i<6; i++) cout << dis[i] << ' ';
}
