#define CATCH_CONFIG_MAIN 
#include <catch2/catch_test_macros.hpp>
#include "Libs/Operations.h"
#include <fakeit.hpp>

template <typename Type>
class MockOperation : public IOperation<Type> {
public:
    MockOperation(Type* result, Type* input) : IOperation<Type>(result, input) {}

    // Переопределяем execute() с возможностью проверки вызова
    void execute() override {
        executeCalled = true;
        if (executeBehavior) {
            executeBehavior(*this->result, *this->input); // Кастомное поведение
        }
    }

    // Можно добавить проверки
    bool wasExecuteCalled() const { return executeCalled; }

    // Лямбда для задания поведения
    std::function<void(Type&, Type&)> executeBehavior;
    bool executeCalled = false;
};


TEST_CASE("Operation Test") {
    
    int result = 0;
    int args[] = { 1, 2 };
    IOperation<int>* operation = new AddOperation<int>(&result, args);
    operation->execute();
    
    REQUIRE(result == 3);
}

TEST_CASE("IOperation execute is called") {
    int result = 0;
    int input = 42;

    MockOperation<int> mockOp(&result, &input);
    mockOp.executeBehavior = [](int& res, int& in) { res = in * 2; }; // Задаем поведение

    mockOp.execute(); // Вызываем метод

    REQUIRE(mockOp.wasExecuteCalled()); // Проверяем, что метод вызван
    REQUIRE(result == 84); // Проверяем результат
}