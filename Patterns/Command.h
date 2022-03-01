// Паттерн можно часто встретить в C++ коде, особенно когда нужно откладывать выполнение команд, 
//выстраивать их в очереди, а также хранить историю и делать отмену.
//Признаки применения паттерна : Классы команд построены вокруг одного действия и имеют очень узкий контекст.
//Объекты команд часто подаются в обработчики событий элементов GUI. 
//Практически любая реализация отмены использует принципа команд.

#include "Library.h"

class Command 
{
public:
    virtual ~Command() 
    {
    }
    virtual void Execute() const = 0;
};

 // Некоторые команды способны выполнять простые операции самостоятельно.
 
class SimpleCommand : public Command
{
private:
    string pay_load_;

public:
    explicit SimpleCommand(string pay_load) : pay_load_(pay_load) 
    {
    }
    void Execute() const override
    {
        cout << "SimpleCommand: See, I can do simple things like printing (" << this->pay_load_ << ")\n";
    }
};

/**
 * Классы Получателей содержат некую важную бизнес-логику. Они умеют выполнять
 * все виды операций, связанных с выполнением запроса. Фактически, любой класс
 * может выступать Получателем.
 */
class Receiver
{
public:
    void DoSomething(const string& a)
    {
        cout << "Receiver: Working on (" << a << ".)\n";
    }
    void DoSomethingElse(const std::string& b)
    {
        cout << "Receiver: Also working on (" << b << ".)\n";
    }
};

 //Но есть и команды, которые делегируют более сложные операции другим объектам, называемым «получателями».

class ComplexCommand : public Command
{   
private:
    Receiver* receiver_;
      //Данные о контексте, необходимые для запуска методов получателя.    
    string a_;
    string b_;    
     //Сложные команды могут принимать один или несколько объектов-получателей вместе с любыми данными о контексте через конструктор.
     
public:
    ComplexCommand(Receiver* receiver, string a, string b) : receiver_(receiver), a_(a), b_(b) 
    {
    }   
     // Команды могут делегировать выполнение любым методам получателя.
     
    void Execute() const override 
    {
        cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
        this->receiver_->DoSomething(this->a_);
        this->receiver_->DoSomethingElse(this->b_);
    }
};

 //Отправитель связан с одной или несколькими командами. Он отправляет запрос команде.
 
class Invoker 
{   
private:
    Command* on_start_;    
    Command* on_finish_;  

     // Инициализация команд     
public:
    ~Invoker() {
        delete on_start_;
        delete on_finish_;
    }

    void SetOnStart(Command* command) {
        this->on_start_ = command;
    }
    void SetOnFinish(Command* command) {
        this->on_finish_ = command;
    }
     // Отправитель не зависит от классов конкретных команд и получателей.
     // Отправитель передаёт запрос получателю косвенно, выполняя команду.
     
    void DoSomethingImportant() {
        cout << "Invoker: Does anybody want something done before I begin?\n";
        if (this->on_start_) {
            this->on_start_->Execute();
        }
        cout << "Invoker: ...doing something really important...\n";
        cout << "Invoker: Does anybody want something done after I finish?\n";
        if (this->on_finish_) {
            this->on_finish_->Execute();
        }
    }
};



