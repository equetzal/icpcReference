//14
#include <stack>

stack<int> s,p;
stack<pair<int,int>> spii;
s.push(int(111)); //Receives an object copy
spii.push(make_pair(11,22));
s.emplace(111); //Uses the constructor of the object
spii.emplace(11,22);
int val = s.top(); //Return value of element at tio
int val = s.size(); //Return number of elements in stack
s.pop(); //Erase the element at the top of stack
bool val = s.empty(); //Return true if stack is empty
s.swap(p); //Swap stack contents in O(1)
s.clear() //Erase elements of stack
