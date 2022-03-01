#include "Memento.h"
#include "Command.h"
#include "Chain_of_responsibility.h"
#include "Adapter.h"
#include "Composite.h"
#include "Strategy.h"
#include "Decorator.h"
#include "Facade.h"
#include "Iterator.h"
#include "Mediator.h"
#include "Observer.h"
#include "Singleton.h"
#include "Builder.h"
#include "Abstract_Factory.h"
#include "Bridge.h"
#include "Prototype.h"
#include "State.h"
#include "Factory Method.h"
#include "Flyweight.h"
#include "Template_Method.h"
#include "Proxy.h"
#include "Interpreter.h"
#include "Visitor.h"

int main()
{  
    setlocale(0, "");
 //   cout << "Memento\n";
 //   cout << "______________\n";
 //   Originator* originator = new Originator();
 //   CareTaker* caretaker = new CareTaker(originator);

 //   originator->setState(1);
 //   caretaker->save();

 //   originator->setState(2);
 //   caretaker->save();

 //   originator->setState(3);
 //   caretaker->undo();

 //   cout << "Actual state is " << originator->getState() << ".\n";

 //   delete originator;
 //   delete caretaker;

 //   //////////////////////////////////
 //   cout << "\n\nCommand\n";
 //   cout << "______________\n";   
 //   Invoker* invoker = new Invoker;
 //   invoker->SetOnStart(new SimpleCommand("Say Hi!"));
 //   Receiver* receiver = new Receiver;
 //   invoker->SetOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
 //   invoker->DoSomethingImportant();

 //   delete invoker;
 //   delete receiver;

 //   //////////////////////////////////////////
 //   cout << "\n\nChain of responsibility\n";
 //   cout << "________________________\n";    
 //   MonkeyHandler* monkey = new MonkeyHandler;
 //   SquirrelHandler* squirrel = new SquirrelHandler;
 //   DogHandler* dog = new DogHandler;
 //   monkey->SetNext(squirrel)->SetNext(dog);    
 //   //Клиент должен иметь возможность отправлять запрос любому обработчику, а не только первому в цепочке.     
 //   cout << "Chain: Monkey > Squirrel > Dog\n\n";
 //   ClientCode(*monkey);    
 //   cout << "\nSubchain: Squirrel > Dog\n\n";
 //   ClientCode(*squirrel);

 //   delete monkey;
 //   delete squirrel;
 //   delete dog;

 //   /////////////////////////
 //   cout << "\n\nAdapter\n";
 //   cout << "________________________\n";
 //   cout << "Client: I can work just fine with the Target objects:\n";
 //   Target* target = new Target;
 //   ClientCode(target);    
 //   Adaptee* adaptee = new Adaptee;
 //   cout << "\n\nClient: The Adaptee class has a weird interface. See, I don't understand it:\n";
 //   cout << "Adaptee: " << adaptee->SpecificRequest() << "\n\n";    
 //   cout << "Client: But I can work with it via the Adapter:\n";
 //   Adapter* adapter = new Adapter(adaptee);
 //   ClientCode(adapter);
 //   
 //   delete target;
 //   delete adaptee;
 //   delete adapter;

 //   ////////////////////////////////////////
 //   cout << "\n\nComposite\n";
 //   cout << "________________________\n";
 //   Component* simple = new Leaf;
 //   cout << "Client: I've got a simple component:\n";
 //   ClientCode(simple);   

 //  //сложные контейнеры.     
 //   Component* tree = new Composite;
 //   Component* branch1 = new Composite;

 //   Component* leaf_1 = new Leaf;
 //   Component* leaf_2 = new Leaf;
 //   Component* leaf_3 = new Leaf;
 //   branch1->Add(leaf_1);
 //   branch1->Add(leaf_2);
 //   Component* branch2 = new Composite;
 //   branch2->Add(leaf_3);
 //   tree->Add(branch1);
 //   tree->Add(branch2);
 //   cout << "\n\nClient: Now I've got a composite tree:\n";
 //   ClientCode(tree);
 //   
 //   cout << "\n\nClient: I don't need to check the components classes even when managing the tree:\n";
 //   ClientCode2(tree, simple);   

 //   delete simple;
 //   delete tree;
 //   delete branch1;
 //   delete branch2;
 //   delete leaf_1;
 //   delete leaf_2;
 //   delete leaf_3;

 //   ///////////////////////////////////////////
 //   cout << "\n\nDecorator\n";
 //   cout << "________________________\n";
 //   Drink* espresso = new Espresso;
 //   Drink* blackTea = new BlackTea(Size::L);
 //   Drink* greenTea = new GreenTea;

 //   espresso->print();
 //   blackTea->print();
 //   greenTea->print();

 //   cout << "================================================\n";

 //   Drink* capuccino = new SugarCondiment(new MilkCondiment(new Espresso));
 //   capuccino->print();

 //   Drink* chocolateCapuccino = new ChocolateCondiment(capuccino);
 //   chocolateCapuccino->print();

 //   Drink* extraSweetBlackTea = new SugarCondiment(new SugarCondiment(new SugarCondiment(new BlackTea(Size::L))));
 //   extraSweetBlackTea->print();

 //   Drink* glassOfMilk = new MilkCondiment(new MilkCondiment(new MilkCondiment));
 //   glassOfMilk->print();

 //   //////////////////////////////
 //   cout << "\n\nFacade\n";
 //   cout << "________________________\n";
 //   SkiResortFacade facade;
 //   double vacationPrice = facade.haveAVeryVeryNiceTime(177, 80, 43, 0, 5);        
 //   cout << "Price: " << vacationPrice << " UAH\n";

 //   //////////////////////////////
 //   cout << "\n\nIterator\n";
 //   cout << "________________________\n";
 //   ClientCode();

 //   ////////////////////////////////
 //   cout << "\n\nMediator\n";
 //   cout << "________________________\n";
 //   ClientsCode();

 //   ////////////////////////////////
 //   cout << "\n\nObserver\n";
 //   cout << "________________________\n";
 //   Client();

 //   ///////////////////////////////////////
 //   cout << "\n\nStrategy\n";
 //   cout << "________________________\n";
	//Duck* duck = new MallardDuck;
	//duck->PerformFly();
	//duck->PerformQuack();
	//duck->Swim();	
	//cout << "\n";	

	//duck = new RubberDuck;
	//duck->PerformFly();
	//duck->PerformQuack();	
	//cout << "\n";
	//
	//duck = new DecoyDuck;
	//duck->PerformFly();
	//duck->PerformQuack();	
	//cout << "\n";

	//duck->SetFlyBehavior(new JetPack);
	//duck->SetQuackBehavior(new Squeak);
	//duck->PerformFly();
	//duck->PerformQuack();

	/////////////////////////////////////////
	//cout << "\n\nSingleton\n";
	//cout << "________________________\n";
	//Singleton* s = Singleton::GetInstance();	
	//cout << s->GetData() << "\n";
	//s->SetData(75);
	//cout << s->GetData() << "\n";

	/////////////////////////////////////////
	//cout << "\n\nBuilder\n";
	//cout << "________________________\n";
	//Waiter waiter;
	//waiter.setPizzaBuilder(new HawaiianPizzaBuilder);
	//waiter.constructPizza();
	//Pizza* pizza = waiter.getPizza();

	/////////////////////////////////////////
	//cout << "\n\nAbstract Factory\n";
	//cout << "________________________\n";
	//cout << "Client: Testing client code with the first factory type:\n";
	//ConcreteFactory1* f1 = new ConcreteFactory1();
	//Client_Code(*f1);
	//delete f1;	
	//cout << "\nClient: Testing the same client code with the second factory type:\n";
	//ConcreteFactory2* f2 = new ConcreteFactory2();
	//Client_Code(*f2);
	//delete f2;

	/////////////////////////////////////////
	//cout << "\n\nBridge\n";
	//cout << "________________________\n";
	//Implementation* implementation = new ConcreteImplementationA;
	//Abstraction* abstraction = new Abstraction(implementation);
	//ClientCodeBridge(*abstraction);
	//cout << "\n";
	//delete implementation;
	//delete abstraction;

	//implementation = new ConcreteImplementationB;
	//abstraction = new ExtendedAbstraction(implementation);
	//ClientCodeBridge(*abstraction);

	//delete implementation;
	//delete abstraction;

	/////////////////////////////////////////
	//cout << "\n\nPrototype\n";
	//cout << "________________________\n";
	//vector<Warrior*> v;
	//v.push_back(Warrior::createWarrior(Infantryman_ID));
	//v.push_back(Warrior::createWarrior(Archer_ID));
	//v.push_back(Warrior::createWarrior(Horseman_ID));

	//for (int i = 0; i < v.size(); i++)
	//	v[i]->info();

	/////////////////////////////////////////
	//cout << "\n\nState\n";
	//cout << "________________________\n";
	//ShowState();

	/////////////////////////////////////////
	//cout << "\n\nFactory Method\n";
	//cout << "________________________\n";
	//cout << "App: Launched with the ConcreteCreator1.\n";
	//Creator* creator = new ConcreteCreator1();
	//Code(*creator);	
	//cout << "\nApp: Launched with the ConcreteCreator2.\n";
	//Creator* creator2 = new ConcreteCreator2();
	//Code(*creator2);

	//delete creator;
	//delete creator2;   

	/////////////////////////////////////////
	//cout << "\n\nFlyweight\n";
	//cout << "________________________\n";
	//FlyweightFactory* factory = new FlyweightFactory({ {"Chevrolet", "Camaro2018", "pink"},
	//	{"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"} });
	//factory->ListFlyweights();

	//AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "M5", "red");
	//AddCarToPoliceDatabase(*factory, "CL234IR", "James Doe", "BMW", "X1", "red");
	//factory->ListFlyweights();

	//delete factory;

	/////////////////////////////////////////
	//cout << "\n\nTemplate Method\n";
	//cout << "________________________\n";
	//cout << "Same client code can work with different subclasses:\n";
	//ConcreteClass1* concreteClass1 = new ConcreteClass1;
	//TemplateCode(concreteClass1);
	//cout << "\nSame client code can work with different subclasses:\n";
	//ConcreteClass2* concreteClass2 = new ConcreteClass2;
	//TemplateCode(concreteClass2);
	//delete concreteClass1;
	//delete concreteClass2;

	/////////////////////////////////////////
	//cout << "\n\nProxy\n";
	//cout << "________________________\n";
	//Image images[5];

	//for (int i; true;)
	//{
	//	cout << "Exit[0], Image[1-5]: ";
	//	cin >> i;
	//	if (i == 0)
	//		break;
	//	images[i - 1].draw();
	//}

	/////////////////////////////////////////
	//cout << "\n\nInterpreter\n";
	//cout << "________________________\n";
	//Evaluator sentence("w x z - +"); // w x z - + => w + x - z
	//static const int sequences[][3] =
	//{
	//	{ 5, 10, 42 }, // 5 + 10 - 42
	//	{ 1, 3, 2 }, // 1 + 3 - 2
	//	{ 7, 9, -5 }, // 7 + 9 - -5
	//};
	//for (size_t i = 0; i < 3; ++i)
	//{
	//	map<string, Expression*> variables;
	//	variables["w"] = new Number(sequences[i][0]);
	//	variables["x"] = new Number(sequences[i][1]);
	//	variables["z"] = new Number(sequences[i][2]);
	//	int result = sentence.interpret(variables);
	//	for (map<string, Expression*>::iterator it = variables.begin(); variables.end() != it; ++it)
	//		delete it->second;
	//	cout << "Interpreter result: " << result;
	//}

	///////////////////////////////////////
	cout << "\n\nVisitor\n";
	cout << "________________________\n";
	Element* list[] = { new This(), new That(), new TheOther() };
	UpVisitor up; 
	DownVisitor down; 
	for (int i = 0; i < 3; i++)
	{
		list[i]->accept(up);
	}
	for (int i = 0; i < 3; i++)
	{
		list[i]->accept(down);
	}

	cout << "\n\n";

}


