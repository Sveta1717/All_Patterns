#include "Library.h"

class Product
{
public:
    virtual ~Product()
    {
    }
    virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    string Operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};
class ConcreteProduct2 : public Product
{
public:
    string Operation() const override 
    {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator 
{    
public:
    virtual ~Creator()
    {
    };
    virtual Product* FactoryMethod() const = 0;

    string SomeOperation() const
    {        
        Product* product = this->FactoryMethod();// Вызываем фабричный метод, чтобы получить объект-продукт.       
        string result = "Creator: The same creator's code has just worked with " + product->Operation(); // работаем с этим продуктом.
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator
{    
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

void Code(const Creator& creator)
{
    cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.SomeOperation() << "\n";
    
}