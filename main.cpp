#include <iostream>

using namespace std;

class IAplication {
public:
    virtual int run() = 0;
    virtual int stop() = 0;
};
class IStream{
public:
    virtual int get() = 0;
    virtual int set(int value) = 0;
};
class IStreamOutput : public IStream{

};
class IStreamInput : public IStream{

};
class IOperation{
    virtual bool execute() = 0;
};

int main(){
    
    return 0;
}
