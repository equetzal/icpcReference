//5
struct pairhash { template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const {
		return hash<T1>{}(p.first) ^ (hash<T2>{}(p.second) << 32);
	}
};
//1
unordered_map<pair<int, int>, int, hash_pair> umap;
