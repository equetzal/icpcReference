//15
#include <queue>

queue<int> q,p;
queue<pair<int,int>> qpii;
q.push(int(111)); //Receives an object copy
qpii.push(make_pair(11,22);
q.emplace(111); //Uses the constructor of the object
qpii.emplace(11,22);
int val = q.front(); //Acces head element
int val = q.back(); //Access tail element
int sz = q.size();
q.pop();
q.empty();
q.swap(p); //Swap queue contents in O(1)
q.clear(); //Erase elements of queue
