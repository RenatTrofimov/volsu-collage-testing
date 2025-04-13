#define CATCH_CONFIG_MAIN 
#include <catch2/catch_test_macros.hpp>
#include "Libs/Operations.h"
#include <fakeit.hpp>

template<typename Type>
class MockOperation : IOperation<Type> {
public:
    Type* getResult() {
        return this->result;
    }
    Type* getInput() {
        return this->input;
    }
    void setInput(Type *input) {
        (this->input) = input;
    }
    void setResult(Type *result) {
        (this->result) = result;
    }
    void execute() {

    }
};


TEST_CASE("Operation Test") {
    
    int result = 0;
    int args[] = { 1, 2 };
    IOperation<int>* operation = new AddOperation<int>(&result, args);
    operation->execute();
    
    REQUIRE(result == 3);
}

using namespace fakeit;

TEST_CASE("MockOperation mock with FakeIt") {
    
    int result = 0;
    int input = 42;
    Mock<MockOperation<int>> mockOp;
    
    mockOp.get().setInput(&input);
    mockOp.get().setResult(&result);

    // Настраиваем поведение execute()
    When(Method(mockOp, execute)).Do([&]() {
        int *input = mockOp.get().getInput();
        int* result = mockOp.get().getResult();
        *result = *input*2;
    });

    // Вызываем метод
    mockOp.get().execute();

    // Проверяем
    REQUIRE(result == 84);
    Verify(Method(mockOp, execute)).Once(); // Проверка вызова
}