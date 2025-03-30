#include <iostream>
#include "Libs/Operations.h"
using namespace std;


int main(){
    int result = 0;
    int args[] = {1, 2};
    IOperation<int>* operation = new AddOperation<int>(&result, args);
    operation->execute();
    cout << result;
    return 0;
}
