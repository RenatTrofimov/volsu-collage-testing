#pragma once

template <typename Type>
class IOperation {
protected:
    Type* result;
    Type* input;
public:
    IOperation(Type* result, Type* input) : result(result), input(input) {};
    virtual void execute() = 0;
};

template <typename Type>
class AddOperation : public IOperation<Type> {
public:
    AddOperation(Type* result, Type* input) : IOperation<Type>(result, input) {};
    void execute() override {
        *result = input[0] + input[1];
    }
};
template <typename Type>
class DivisionOperation : public IOperation<Type> {
public:
    DivisionOperation(Type* result, Type* input) : IOperation<Type>(result, input) {};
    void execute() override {
        *result = input[0] / input[1];
    }
};
template <typename Type>
class SubdivisionOperation : public IOperation<Type> {
public:
    SubdivisionOperation(Type* result, Type* input) : IOperation<Type>(result, input) {};
    void execute() override {
        *result = input[0] - input[1];
    }
};
template <typename Type>
class MultiplicationOperation : public IOperation<Type> {
public:
    MultiplicationOperation(Type* result, Type* input) : IOperation<Type>(result, input) {};
    void execute() override {
        *result = input[0] * input[1];
    }
};
