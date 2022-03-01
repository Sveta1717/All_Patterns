// Можно часто встретить в C++ коде, особенно там, где требуется конвертация разных типов данных
//или совместная работа классов с разными интерфейсами.
// Признаки применения паттерна : Адаптер получает конвертируемый объект в конструкторе или 
//через параметры своих методов.Методы Адаптера обычно совместимы с интерфейсом одного объекта.
//Они делегируют вызовы вложенному объекту, превратив перед этим параметры вызова в формат, 
//поддерживаемый вложенным объектом.

#include "Library.h"

class Target {
public:
    virtual ~Target() = default;

    virtual string Request() const
    {
        return "Target: The default target's behavior.";
    }
};

 // Адаптируемый класс содержит некоторое полезное поведение, но его интерфейс несовместим с существующим клиентским
//  кодом. Адаптируемый класс нуждается в некоторой доработке, прежде чем клиентский код сможет его использовать.
 
class Adaptee 
{
public:
    string SpecificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Адаптер делает интерфейс Адаптируемого класса совместимым с целевым интерфейсом.
 
class Adapter : public Target {
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    string Request() const override
    {
        string to_reverse = this->adaptee_->SpecificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

// Клиентский код поддерживает все классы, использующие целевой интерфейс.
 
void ClientCode(const Target* target)
{
    cout << target->Request();
}
