//19
#include <vector>

vector<int> v,p;
vector<pair<int,int>> vpii;
v.push_back(int(111)); //Insert value at end of vector
v.pop_back(); //Erase the element at end of vector
int val = v.back(); //Return value at end of vector
int val = v.front(); //Return value at begin of vector
v.insert(v.begin()+pos, int(111); //Insert element before pos in O(pos)
vpii.insert(v.begin()+pos, make_pair(11,22));
v.emplace(v.begin()+pos, 111); //Insert, but uses constructor after pos arg
vpii.emplace(v.begin()+pos, 11,22);
v.erase(v.begin()+pos); //Erase element at pos in O(n)
v.clear(); //Clear the contents of a vector O(n)
int val = v.size(); //Return size of vector -> cast size_t to int
bool val = v.emtpy(); //Return true if vector is empty
v.resize(5); //If arg is smaller than size, it cuts the vector, if not, expand array with default init
v.resize(5,0); //If arg si larger than size, init values with 2nd arg
v.swap(p); //Swap vector contents in O(1)
