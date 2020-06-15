//13
#include <map>

map<int,string> m,p;
map<pair<int,int>,string> mpii;
m[111] = "val"; //Insert, or replace element in map
auto val = m[111]; //Return element with key 111, if no key create key with default val
m.erase(111); //Erase element with key 111
m.merge(p); //Insert or replace p elements into s in O(|S|log(|P|+|S|))
int val = s.count(111); //Return number of elements in map with key 111
set<map>::iterator it = s.find(111); //Return m.end() if not found, or map iterator if found
auto it = m.lower_bound(111); //Return first not-less element than key in O(logN)
auto it = m.upper_bound(111); //Return first element greater than key in O(logN)
s.swap(p); //Swap map contents in O(1)
