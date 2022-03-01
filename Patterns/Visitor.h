#include "Library.h"

class Element
{
public:
    virtual void accept(class Visitor& v) = 0;
};

class This : public Element
{
public:
   void accept(Visitor& v);
    string thiss()
    {
        return "This";
    }
};

class That : public Element
{
public:
    void accept(Visitor& v);
    string that()
    {
        return "That";
    }
};

class TheOther : public Element
{
public:
    void accept(Visitor& v);
    string theOther()
    {
        return "TheOther";
    }
};

class Visitor
{
public:
    virtual void visit(This* e) = 0;
    virtual void visit(That* e) = 0;
    virtual void visit(TheOther* e) = 0;
};

void This::accept(Visitor& v)
{
    v.visit(this);
}

void That::accept(Visitor& v)
{
    v.visit(this);
}

void TheOther::accept(Visitor& v)
{
    v.visit(this);
}

class UpVisitor : public Visitor
{
    void visit(This* e)
    {
        cout << "do Up on " + e->thiss() << "\n";
    }

    void visit(That* e)
    {
        cout << "do Up on " + e->that() << "\n";
    }

    void visit(TheOther* e)
    {
        cout << "do Up on " + e->theOther() << "\n";
    }
};

class DownVisitor : public Visitor
{
    void visit(This* e)
    {
        cout << "do Down on " + e->thiss() << "\n";
    }

    void visit(That* e)
    {
        cout << "do Down on " + e->that() << "\n";
    }

    void visit(TheOther* e)
    {
        cout << "do Down on " + e->theOther() << "\n";
    }
};
