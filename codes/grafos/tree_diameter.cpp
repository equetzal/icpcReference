#include <vector>
#include <queue>
#include <cstring>

int diameter[500010];

int bfs(int pos, vector< vector<int> > &graph){
	queue<int> q;
	vector<bool> visited(graph.size(),false);

	q.push(pos);
	visited[pos] = 1;

	int maxDist = 0, maxNode=-1;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		if(diameter[u]>maxDist){
			maxDist=diameter[u];
			maxNode=u;
		}
		for(auto i:graph[u]){
			if(!visited[i]){
				visited[i] = true;
				diameter[i] += diameter[u]+1;
				q.push(i);
			}
		}
	}

	return maxNode;
}


int treeDiameter(vector< vector<int> > &graph){
	memset(diameter, 0, sizeof(diameter));
	int extreme1 = bfs(0, graph);
	memset(diameter, 0, sizeof(diameter));
	int extreme2 = bfs(extreme1, graph);

	return diameter[extreme2];
}
