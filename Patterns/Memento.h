// На C++ чаще всего реализуют с помощью сериализации.

#include "Library.h"

class Memento
{
private:
    int state; // состояние
    friend class Originator; // доступен только другу - создателю class Originator
    Memento(const int s) : state(s) {}
    void setState(const int s)
    {
        state = s;
    }
    int getState() {
        return state; // для возврата состояния
    }
};

class Originator // «Cоздатель», который использует объект «Xранитель».
{
public:
    void setState(const int s) // установили состояние на текущий момент
    {
        state = s;
        cout << "Set state to " << s << "\n";
    }
    int getState()
    {
        return state;
    }
    void setMemento(Memento* const m)
    {
        state = m->getState();
    }
    Memento* createMemento()
    {
        return new Memento(state);
    }

private:
    int state; // состояние Создателя хранится в одной переменной
};

class CareTaker // "Хранитель" отвечает за сохранность снимка, но не имеет к нему доступ
{
public:
    CareTaker(Originator* const o) : originator(o) {}
    ~CareTaker()
    {
        for (unsigned int i = 0; i < history.size(); i++)
        {
            delete history.at(i);
        }
        history.clear();
    }
    void save()   // cохраняет текущее состояние внутри снимка
    {
        cout << "Save state" << "\n";
        history.push_back(originator->createMemento());
    }
    void undo()  // возвращаемся к прежнему состоянию
    {
        if (history.empty())
        {
            cout << "Unable to undo state." << "\n";
            return;
        }
        Memento* m = history.back();
        originator->setMemento(m);
        cout << "Undo state" << "\n";
        history.pop_back();
        delete m;
    }

private:
    Originator* originator;
    vector<Memento*> history;
};

