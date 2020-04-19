#include<bits/stdc++.h>
using namespace std;

//https://codelearn.io/learningtask/index/thuat-toan-nang-cao?taskid=134601

//DFS Recursion
vector<bool> visited;
bool FindPathRecursion(int n, vector<vector<int>> edges, int u, int v)
{
	if (u == v)
		return true;

	for (int i = 0; i < edges.size(); i++) {
		if (edges[i][0] == u && !visited[u]) {
			visited[u] = true;
			if (FindPathRecursion(n, edges, edges[i][1], v))
				return true;
			visited[u] = false;
		}
	}
	return false;
}

//DFS Stack
bool FindPath(int n, vector<vector<int>> edges, int u, int v)
{
  stack<int> st;
	vector<int> visited;
	for (int i = 0; i <= n; i++)
		visited.push_back(false);
	st.push(u);

	while (!st.empty()) {
		int s = st.top();
		st.pop();
		visited[s] = true;
		if (s == v)
			return true;

		for (int i = 0; i < edges.size(); i++) {
			if (edges[i][0] == s && !visited[edges[i][1]])
				st.push(edges[i][1]);
		}
	}
	return false;
}

int main() {
	int n, e, u, v;
	cin >> n >> e >> u >> v;

	vector<vector<int>> edges;
	int ui, vi;
	for (int i = 0; i < e; i++) {
		cin >> ui >> vi;
		vector<int> edge;
		edge.push_back(ui);
		edge.push_back(vi);
		edges.push_back(edge);
	}

	// for (int i = 0; i <= n; i++)
	// 	visited.push_back(false);

	cout << FindPath(n, edges, u, v);

	return 0;
}