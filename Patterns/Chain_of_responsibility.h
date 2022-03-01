//встречается в C++ не так уж часто, для его применения нужна цепь объектов, например, связанный список.
//Признаки применения паттерна : Цепочку обязанностей можно определить по спискам обработчиков или проверок, 
//через которые пропускаются запросы.Особенно если порядок следования обработчиков важен.

#include "Library.h"

//Интерфейс Обработчика объявляет метод построения цепочки обработчиков. Он же объявляет метод для выполнения запроса.
 
class Handler
{
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual string Handle(std::string request) = 0;
};
//Поведение цепочки по умолчанию может быть реализовано внутри базового класса обработчика.
 
class AbstractHandler : public Handler
{    
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr)
    {
    }
    Handler* SetNext(Handler* handler) override 
    {
        this->next_handler_ = handler;
        // Возврат обработчика отсюда позволит связать обработчики простым способом,
        // вот так: $monkey->setNext($squirrel)->setNext($dog);
        return handler;
    }
    string Handle(string request) override
    {
        if (this->next_handler_)
        {
            return this->next_handler_->Handle(request);
        }

       // return {};
    }
};
// Все Конкретные Обработчики либо обрабатывают запрос, либо передают его следующему обработчику в цепочке.
 
class MonkeyHandler : public AbstractHandler 
{
public:
    string Handle(std::string request) override
    {
        if (request == "Banana")
        {
            return "Monkey: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class SquirrelHandler : public AbstractHandler
{
public:
    string Handle(std::string request) override
    {
        if (request == "Nut")
        {
            return "Squirrel: I'll eat the " + request + ".\n";
        }
        else 
        {
            return AbstractHandler::Handle(request);
        }
    }
};

class DogHandler : public AbstractHandler
{
public:
    string Handle(std::string request) override
    {
        if (request == "MeatBall") 
        {
            return "Dog: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::Handle(request);
        }
    }
};

 //Обычно клиентский код приспособлен для работы с единственным обработчиком. В
 // большинстве случаев клиенту даже неизвестно, что этот обработчик является частью цепочки.
 
void ClientCode(Handler& handler) 
{
    vector<std::string> food = { "Nut", "Banana", "Cup of coffee" };
    for (const std::string& f : food) 
    {
        cout << "Client: Who wants a " << f << "?\n";
        const string result = handler.Handle(f);
        if (!result.empty())
        {            
            cout << "  " << result;
        }
        else
        {
            cout << "  " << f << " was left untouched.\n";
        }
    }
}
 //Другая часть клиентского кода создает саму цепочку.
 
