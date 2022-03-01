#include "Library.h"

class Singleton
{
	static Singleton* instance;
	int data;

	// private:
	Singleton()
	{
		data = 50;
	}

public:
	static Singleton* GetInstance()
	{
		if (instance == nullptr)
			instance = new Singleton;
		return instance;
	}

	int GetData() const
	{
		return data;
	}

	void SetData(int value)
	{
		data = value;
	}
};
Singleton* Singleton::instance = nullptr; 
