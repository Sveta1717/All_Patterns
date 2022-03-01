#include "Library.h"

class Implementation 
{
public:
    virtual ~Implementation() 
    {
    }
    virtual string OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation
{
public:
    string OperationImplementation() const override 
    {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};

class ConcreteImplementationB : public Implementation
{
public:
    string OperationImplementation() const override 
    {
        return "ConcreteImplementationB: Here's the result on the platform B.\n";
    }
};

class Abstraction
{    
protected:
    Implementation* implementation_;

public:
    Abstraction(Implementation* implementation) : implementation_(implementation)
    {
    }

    virtual ~Abstraction() 
    {
    }

    virtual string Operation() const
    {
        return "Abstraction: Base operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

class ExtendedAbstraction : public Abstraction
{
public:
    ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation)
    {
    }
    string Operation() const override
    {
        return "ExtendedAbstraction: Extended operation with:\n" +
            this->implementation_->OperationImplementation();
    }
};

void ClientCodeBridge(const Abstraction& abstraction)
{   
    cout << abstraction.Operation();    
}
