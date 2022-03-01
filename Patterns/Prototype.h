#include "Library.h"

enum Warrior_ID { Infantryman_ID, Archer_ID, Horseman_ID };

class Warrior; 
typedef map<Warrior_ID, Warrior*> Registry;

Registry& getRegistry()
{
    static Registry _instance;
    return _instance;
}

// ≈динственное назначение этого класса - помощь в выборе нужного конструктора при создании прототипов
class Dummy
{ 
};

class Warrior
{
public:
    virtual Warrior* clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior()
    {
    }
    
    static Warrior* createWarrior(Warrior_ID id)
    {
        Registry& r = getRegistry();
        if (r.find(id) != r.end())
            return r[id]->clone();
        return 0;
    }

protected:    
    static void addPrototype(Warrior_ID id, Warrior* prototype)  // ƒобавление прототипа в множество прототипов
    {
        Registry& r = getRegistry();
        r[id] = prototype;
    }
    
    static void removePrototype(Warrior_ID id) // ”даление прототипа из множества прототипов
    {
        Registry& r = getRegistry();
        r.erase(r.find(id));
    }
};

class Infantryman : public Warrior
{
public:
    Warrior* clone()
    {
        return new Infantryman(*this);
    }

    void info()
    {
        cout << "Infantryman" << "\n";
    }

private:
    Infantryman(Dummy)
    {
        Warrior::addPrototype(Infantryman_ID, this);
    }

    Infantryman()
    {
    }
    static Infantryman prototype;
};

class Archer : public Warrior
{
public:
    Warrior* clone() 
    {
        return new Archer(*this);
    }

    void info()
    {
        cout << "Archer" << "\n";
    }
private:
    Archer(Dummy) 
    {
        addPrototype(Archer_ID, this);
    }
    Archer()
    {
    }
    static Archer prototype;
};

class Horseman : public Warrior
{
public:
    Warrior* clone()
    {
        return new Horseman(*this);
    }
    void info() 
    {
        cout << "Horseman" << "\n";
    }
private:
    Horseman(Dummy)
    {
        addPrototype(Horseman_ID, this);
    }
    Horseman()
    {
    }
    static Horseman prototype;
};


Infantryman Infantryman::prototype = Infantryman(Dummy());
Archer Archer::prototype = Archer(Dummy());
Horseman Horseman::prototype = Horseman(Dummy());

