#if 0

#endif

template<classs K, Class V, int N>

class KVList {

	K k[N];
	V v[N];
	
	size_t count;
	public:
	
	KVList():count(0){
	
	} //default constructor - adopts a safe empty state
	
	size_t size(){
	
	
	return count
	} const //- returns the number of entires in the key-value list
	
	const K& key(int i) const {
	
	return k[i];
	} //- returns an unmodifiable reference to the key of element i in the list
	
	const V& value(int i) const{
	
	return v[i];
	}
	// - returns an unmodifiable reference to the value of element i in the list
	
	KVList& add(const K&, const V&){
	if(count < N){
		k[count] == kk;
		v[count] == vv;
		count++;
	}
	
	return* this;
	}// - adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
	
	int find(const K& k) const{
		for(int ret = 0; ret < count; ret++){
			if(kk==k[ret])
				return ret;
		}
		return 0;
	
	} //- returns the index of the first element in the list with a key equal to k - defaults to 0
	
	KVList& replace(int i, const K& k, const V& v){
		if(i <count){
		k[i]==kk, v[i]==vv;
		
		}
		return* this;
	}//- replaces element i in the list with the key and value received and returns a reference to the current object Main Program
													

}