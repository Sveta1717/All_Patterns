#include "Library.h"

class AbstractProductA 
{
public:
    virtual ~AbstractProductA() 
    {
    };
    virtual string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA // Конкретные продукты создаются соответствующими Конкретными Фабриками.
{
public:
    string UsefulFunctionA() const override
    {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA
{
    string UsefulFunctionA() const override
    {
        return "The result of the product A2.";
    }
};

 class AbstractProductB 
 {
   // Продукт B способен работать самостоятельно
public:
    virtual ~AbstractProductB()
    {
    };

    virtual string UsefulFunctionB() const = 0;   
    virtual string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB  // Конкретные Продукты создаются соответствующими Конкретными Фабриками.
{
public:
    string UsefulFunctionB() const override 
    {
        return "The result of the product B1.";
    }
   
    string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override
    {
        const string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
    string UsefulFunctionB() const override
    {
        return "The result of the product B2.";
    }
    
    // Продукт B2 может корректно работать только с Продуктом A2. Тем не менее, он
    // принимает любой экземпляр Абстрактного Продукта А в качестве аргумента.     
    string AnotherUsefulFunctionB(const AbstractProductA& collaborator) const override
    {
        const string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA* CreateProductA() const = 0;
    virtual AbstractProductB* CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA* CreateProductA() const override
    {
        return new ConcreteProductA1();
    }
    AbstractProductB* CreateProductB() const override 
    {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory 
{
public:
    AbstractProductA* CreateProductA() const override 
    {
        return new ConcreteProductA2();
    }
    AbstractProductB* CreateProductB() const override
    {
        return new ConcreteProductB2();
    }
};


void Client_Code(const AbstractFactory& factory) 
{
    const AbstractProductA* product_a = factory.CreateProductA();
    const AbstractProductB* product_b = factory.CreateProductB();
    cout << product_b->UsefulFunctionB() << "\n";
    cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}
