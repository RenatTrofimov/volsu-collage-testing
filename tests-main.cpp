#define CATCH_CONFIG_MAIN 
#include <catch2/catch_test_macros.hpp>
#include "Libs/Operations.h"


TEST_CASE("Operation Test", "[factorial]") {
    
    int result = 0;
    int args[] = { 1, 2 };
    IOperation<int>* operation = new AddOperation<int>(&result, args);
    operation->execute();
    
    REQUIRE(result == 3);
}