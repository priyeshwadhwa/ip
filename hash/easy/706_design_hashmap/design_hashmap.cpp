 
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <unordered_set>
#include <regex>
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;

//All keys and values will be in the range of [0, 1,000,000].
//The number of operations will be in the range of [1, 10,000].

class MyHashMap {

    vector<vector<pair<int,int>>> map;
    static const int kSize = 10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() :map(kSize, vector<pair<int,int>>())
    {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &_arr = map[key % kSize];

        for(auto &e: _arr)
        {
            if(e.first == key)
            {
                e.second= value;
                return;
            }
        }
        _arr.emplace_back(key,value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &_arr = map[key % kSize];
        for(auto e: _arr)
        {
            if(e.first == key)
                return e.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &_arr = map[key % kSize];
        auto end = remove_if(_arr.begin(), _arr.end(), [key](auto &i) {
            return i.first == key;
        });
        _arr.erase(end, _arr.end());
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

TEST_CASE("test_") {
    MyHashMap* obj = new MyHashMap();
    int key =1 , value =100;
     obj->put(key,value);
     int param_2 = obj->get(key);
     obj->remove(key);
     param_2 = obj->get(key);


}

