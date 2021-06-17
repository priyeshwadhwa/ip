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
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "..\..\catch\catch.hpp"
using namespace std;
using namespace Catch;


class LimpingDog {
    public:
        int countSteps(int time)
        {
            //1 1 2 1
            // 47 steps -- 59 sec
            // 42 sec rest  -- total 101 sec for 47 steps
            int steps = 47 * (time / 101);

            time = time % 101;

            if(time >= 59)
            {
                steps +=  47; // in rest cycle
            }
            else
            {
                steps += 4 * (time / 5);
                time = time % 5;
                if(time == 4 ) steps += 3;
                else if ( time == 3 || time==2) steps+=2;
                else if(time == 1) steps+=1;
            }
            return steps;            
        }
        
};
TEST_CASE("description") {
    LimpingDog ld;
    REQUIRE(ld.countSteps(2) == 2);

    REQUIRE(ld.countSteps(2) == 2);
    REQUIRE(ld.countSteps(6) == 5);

    REQUIRE(ld.countSteps(80) == 47);
    REQUIRE(ld.countSteps(104) == 50); // failing test case.. . the rest doesn't reset the walk
     
    REQUIRE(ld.countSteps(806000) == 376000);

    REQUIRE(ld.countSteps(54321) == 25346);

      
}