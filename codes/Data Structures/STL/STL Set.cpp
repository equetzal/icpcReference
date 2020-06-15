//15
#include <set>

set<int> s,p;
set<pair<int,int>> spii;
s.insert(int(111)); //Insert value in vector
spii.insert(make_pair(11,22));
s.emplace(111); //Insert but with constructor
spii.emplace(11,22);
s.erase(111); //Erase element with value 111
s.merge(p); //Insert p elements into s in O(|S|log(|P|+|S|))
int val = s.count(111); //Return number of elements in set with value 111
set<int>::iterator it = s.find(111); //Return s.end() if not found, or set iterator if found
auto it = s.lower_bound(111); //Return first not-less element than arg in O(logN)
auto it = s.upper_bound(111); //Return first element greater than arg in O(logN)
s.swap(p); //Swap set contents in O(1)
