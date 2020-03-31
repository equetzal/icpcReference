#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

const int MAXN = 4010;
std::vector<int> adj[MAXN];
std::vector<bool> used(MAXN), visit(MAXN);
int match[MAXN], dist[MAXN];

void bfs(int n1, int n2) {
  std::fill(dist, dist + n1, -1);
  std::queue<int> q;
  for (int u = 0; u < n1; u++) {
    if (!used[u]) {
      q.push(u);
      dist[u] = 0;
    }
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = 0; j < (int)adj[u].size(); j++) {
      int v = match[adj[u][j]];
      if (v >= 0 && dist[v] < 0) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

bool dfs(int u) {
  visit[u] = true;
  for (int j = 0; j < (int)adj[u].size(); j++) {
    int v = match[adj[u][j]];
    if (v < 0 || (!visit[v] && dist[v] == dist[u] + 1 && dfs(v))) {
      match[adj[u][j]] = u;
      used[u] = true;
      return true;
    }
  }
  return false;
}

int hopcroft_karp(int n1, int n2) {
  std::fill(match, match + n2, -1);
  std::fill(used.begin(), used.end(), false);
  int res = 0;
  for (;;) {
    bfs(n1, n2);
    std::fill(visit.begin(), visit.end(), false);
    int f = 0;
    for (int u = 0; u < n1; u++) {
      if (!used[u] && dfs(u)) {
        f++;
      }
    }
    if (f == 0) {
      return res;
    }
    res += f;
  }
  return res;
}

int main() {
  int n1 = 3, n2 = 4;
  adj[0].push_back(1);
  adj[1].push_back(0);
  adj[1].push_back(1);
  adj[1].push_back(2);
  adj[2].push_back(2);
  adj[2].push_back(3);
  cout << "Matched " << hopcroft_karp(n1, n2) << " pair(s):" << endl;
  for (int i = 0; i < n2; i++) {
    if (match[i] != -1) {
      cout << match[i] << " " << i << endl;
    }
  }
  return 0;
}