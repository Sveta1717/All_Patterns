#include "Library.h"

struct Expression
{
	virtual int interpret(map<string, Expression*> variables) = 0;
	virtual ~Expression() {}
};

class Number : public Expression
{
private:
	int number;
public:
	Number(int number) { this->number = number; }
	int interpret(map<string, Expression*> variables) { return number; }
};

class Operation
{
protected:
	Expression* leftOperand;
	Expression* rightOperand;
public:
	Operation(Expression* left, Expression* right)
	{
		leftOperand = left;
		rightOperand = right;
	}

	~Operation()
	{
		delete leftOperand;
		delete rightOperand;
	}
};

struct Plus : public Expression, public Operation
{
	Plus(Expression* left, Expression* right) :Operation(left, right) {}
	int interpret(map<string, Expression*> variables)
	{
		return leftOperand->interpret(variables) + rightOperand->interpret(variables);
	}
};

struct Minus : public Expression, public Operation
{
	Minus(Expression* left, Expression* right) :Operation(left, right) {}
	int interpret(map<string, Expression*> variables)
	{
		return leftOperand->interpret(variables) - rightOperand->interpret(variables);
	}
};

class Variable : public Expression
{
private:
	string name;
public:
	Variable(string name) { this->name = name; }
	int interpret(map<string, Expression*> variables)
	{
		if (variables.end() == variables.find(name)) return 0;
		return variables[name]->interpret(variables);
	}
};

class Evaluator : public Expression
{
private:
	Expression* syntaxTree;
public:
	Evaluator(string expression)
	{
		list<Expression*> expressionStack;
		size_t last = 0;
		for (size_t next = 0; last != string::npos; last = (string::npos == next) ? next : (1 + next))
		{
			next = expression.find(' ', last);
			string token(expression.substr(last, (string::npos == next) ?
				(expression.length() - last) : (next - last)));
			if (token == "+")
			{
				Expression* right = expressionStack.back();
				expressionStack.pop_back();
				Expression* left = expressionStack.back();
				expressionStack.pop_back();
				Expression* subExpression = new Plus(right, left);
				expressionStack.push_back(subExpression);
			}
			else if (token == "-")
			{
				Expression* right = expressionStack.back();
				expressionStack.pop_back();
				Expression* left = expressionStack.back();
				expressionStack.pop_back();
				Expression* subExpression = new Minus(left, right);
				expressionStack.push_back(subExpression);
			}
			else
			{
				expressionStack.push_back(new Variable(token));
			}
		}
		syntaxTree = expressionStack.back();
		expressionStack.pop_back();
	}

	~Evaluator()
	{
		delete syntaxTree;
	}

	int interpret(map<string, Expression*> context)
	{
		return syntaxTree->interpret(context);
	}
};
