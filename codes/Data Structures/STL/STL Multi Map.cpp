//16
#include <multimap>

multimap<string,string> m;
m.emplace("key","val"); //Insert element in multimap
m.erase(it); //Erase element at iterator = it
m.erase(itBegin, itEnd); //Erase elements in range from itBegin to itEnd
m.erase("key"); //Erase all elements with key
m.clear(); //Erase all elements in multimap
int val = m.count("key"); //Return number of elements with key

//To get elements with same key
auto range = m.equal_range("key"); //Return a pair of begin-end iterators which holds elements equal to key
cout << "for key[key] -> ";
for(auto it=range.first; it!=range.end; it++)
	cout << (*it).second << " ";
cout << endl;
