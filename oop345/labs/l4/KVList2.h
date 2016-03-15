
#pragma once

template <typename K, typename V, int N>
class KVList {
    K k[N];
    V v[N];
    size_t count;

public:
    KVList()
    : count(0) { 

    }

    size_t size() const{ 
        return count;
    }

    const K& key(int i) const{
        if(i < count)
            return k[i];
    }

    const V& value(int i) const{ 
        if (i < count)
            return v[i];
    }

    KVList& add(const K& key, const V& val){ 
		{ 
            k[count] = key;
            v[count] = val;
            count++;
        }
    
        return *this;
    }

    int find(const K& key) const{
        for(size_t i = 0; i < count; i++){
            if(k[i] == key)
                return i;
        }
        return 0; 
    }

    KVList& replace(int i, const K& key, const V& val){ 
        if (i < count){
            k[i] = key;
            v[i] = val;
        }
        return *this;
    }

};