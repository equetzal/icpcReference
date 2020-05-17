//10
#include <stack>

stack<int> s,p;
s.push(int(111)); //Receives an object copy
s.emplace(111); //Uses the constructor of the object
int val = s.top();
int sz = s.size();
s.pop();
s.empty();
s.swap(p); //Swap stack contents in O(1)
