 
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <tuple>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <regex>
#include <string>
#include <sstream>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "..\..\..\catch\catch.hpp"

using namespace std;
using namespace Catch;

/* 

what is we need to break the file in chunks and perform these operations

multiple threads
multiple machines
map reduce model


read two csv files -- 
break the columns
perform the operation on the columns
store the result
sort the result
print output 
*/

struct Child {
    string name;
    uint32_t age;
    double height;

};

struct Clothes {
    uint32_t multiply;
    uint32_t divide;
};


class Solution {
    public:
    Solution(){}
    vector<Child> ReadChildData(string file)
    {
        enum  class ChildDataCSV : uint32_t{
            name,
            age,
            height
        };

        fstream f (file, ios_base::in);
        if(!f)
            throw std::runtime_error("Couldnot open the file");

        vector<Child> result;
        string line;
        while(std::getline(f, line))
        {
            stringstream iss(line);
            string word;
            Child child;
            enum ChildDataCSV rec_entry = ChildDataCSV::name;
            while(std::getline(iss, word, ','))
            {
                switch(rec_entry)
                {
                    case ChildDataCSV::name:
                        child.name = word;
                        rec_entry = ChildDataCSV::age;
                        break;
                    case ChildDataCSV::age:
                        child.age = std::stoi(word);
                        rec_entry = ChildDataCSV::height;
                        break;
                    case ChildDataCSV::height:
                        child.height = std::stod(word);
                        rec_entry = ChildDataCSV::name;
                        break;
                }
            }

            result.push_back(child);
        }


        return result;
    }

    vector<Clothes> ReadClothesData(string file);
};

TEST_CASE("test_success") {
    Solution s;
    REQUIRE(1==1);
    s.ReadChildData("child.csv");
}

TEST_CASE("test_failure") {
    Solution s;
    REQUIRE(1==1);
}






