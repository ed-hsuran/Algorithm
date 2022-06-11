//參考網址 維基百科
//https://zh.wikipedia.org/zh-tw/%E6%88%B4%E5%85%8B%E6%96%AF%E7%89%B9%E6%8B%89%E7%AE%97%E6%B3%95

#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

//Dijkstra--單源點對最小路徑

vector <pii> adj[5005];

void add_edge(int v1, int v2, int wgt){
	adj[v1].pb({v2, wgt});
	adj[v2].pb({v1, wgt});
}

vector <int> dijkstra(int v, int n){
	int inf = 1e7;
	vector <int>  dis(n, inf);
	vector <bool> visited(n, false);
	priority_queue <pii, vector<pii>, greater<pii> > pq;
	
	dis[v] = 0;
	pq.push({0, v});
	
	while (!pq.empty()){
		int dot = pq.top().s;
		pq.pop();
		if (visited[dot]) continue;
		visited[dot] = true;
		for (auto data: adj[dot]){
			int tmp_dot = data.f;
			int wgt = data.s;
			if (dis[tmp_dot] > dis[dot] + wgt){
				dis[tmp_dot] = dis[dot] + wgt;
				pq.push({dis[tmp_dot], tmp_dot});
			}
		}
	}
	return dis;
}

int main(){
	add_edge(0, 4, 1);
	add_edge(1, 3, 4);
	add_edge(2, 3, 5);
	add_edge(3, 4, 2);
	add_edge(0, 2, 3);
	add_edge(1, 2, 3);
	add_edge(1, 4, 3);
	add_edge(4, 5, 2);
	add_edge(0, 5, 12);
	auto dis = dijkstra(0, 6);
	for (int i: dis) cout << i << " ";
}
