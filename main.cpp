#include <iostream>
#include <string>
using namespace std;

class iStream{

public:

	virtual void put() = 0;

};

class iConvectorable{
public:
	virtual void convert() = 0;
};

class Item{
	
};

class ConvectorItemToString: iConvectorable{
	Item* item;
	string* aString;
public:
	ConvectorItemToJson(Item* item, string* aString){
		this->item =  item;
		this->aString =  aString;
	}
	virtual void convert() = 0;
};

class ConvectorStringToItem: iConvectorable{
	Item* item;
	string* aString;
public:
	ConvectorStringToItem(Item* item, string* aString){
		this->item =  item;
		this->json =  aString;
	}
	virtual void convert() = 0;
};


class ItemToConsoleOutStream:public iStream{
	Item* item;
public:
	StreamWithItem(Item* item){
		this->item = item;
	}
	void put() override {
		//cout << item << endl;
	}
};
class ItemFromConsoleInStream:public iStream{
	Item* item;
public:
	StreamWithItem(Item* item){
		this->item = item;
	}
	void put() override {
		//cout << item << endl;
	}
};

class iTask{
public:
	virtual void execute() = 0;
};

class TaskPrintHelloWorld: public iTask{

public:

	void execute() override{
		cout << "hello world!" << endl;
	}

};

int main(){

iTask *aTask = new TaskPrintHelloWorld;
aTask->execute();

return 0;

}

