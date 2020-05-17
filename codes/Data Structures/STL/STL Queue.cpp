//11
#include <queue>

queue<int> q,p;
q.push(int(111)); //Receives an object copy
q.emplace(111); //Uses the constructor of the object
int val = q.front(); //Acces head element
int val = q.back(); //Access tail element
int sz = q.size();
q.pop();
q.empty();
q.swap(p); //Swap queue contents in O(1)
