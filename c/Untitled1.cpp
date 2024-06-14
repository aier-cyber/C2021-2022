#include <vector>
#include <stdio.h>
#include <map>
#include <cmath>
#include <numeric>
#include <string>
#include <functional>

class my_vec : public std::vector<int>
{
public:
	int sum()
	{
		return std::accumulate(this->begin(), this->end(), 0);
	}
};

class Cat
{
public:
	virtual void say() const
	{
		printf("Default:say\n");
	}
};

class Pip : public Cat
{
public:
	void say() const override
	{
		printf("Pip:say\n");
	}
};

class Mew : public Cat
{
public:
	void say() const override
	{
		printf("Mew:say\n");
	}
	void jump() const
	{
		printf("Mew:jump\n");
	}
};



class B
{
public:
	B() = default;
	~B() = default;
	void print()
	{
		printf("b\n");
	};
	virtual void print2()
	{
		printf("b\n");
	};

protected:

private:

};

class A : public B
{
public:
	A();
	A(int);
	A(const A&);
	~A() = default;

	A& operator=(const A&);
	const int& GetPriv() const;
	void print()
	{
		printf("a\n");
	};
	void print2() override
	{
		printf("a\n");
	};
	int pub;
private:
	int priv;


};

A::A()
	: pub(0), priv(1)
{
	//pub = 0;
	//priv = 1;
}

A::A(int x)
	: pub(x), priv(x)
{
	//pub = x;
	//priv = x;
}

A::A(const A& rh)
	:pub(rh.pub), priv(rh.priv)
{
	//operator=(rh);
	//this->operator=(rh);
	//*this = rh;
}

A& A::operator=(const A& rh)
{
	this->pub = rh.pub;
	this->priv = rh.priv;
	return *this;
}

const int& A::GetPriv() const
{
	return this->priv;
}

void feed(const Cat& cat)
{
	cat.say();

	const Mew* m = dynamic_cast<const Mew*>(&cat);
	if (m != nullptr)
	{
		m->jump();
	}
}

int main()
{
	Cat c;
	//c.say();
	feed(c);
	Pip p;
	//p.say();
	feed(p);
	Mew m;
	//m.say();
	feed(m);

	Cat* arr[3];
	arr[0] = &c;
	arr[1] = &p;
	arr[2] = &m;

	for (size_t i = 0; i < 3; i++)
	{
		feed(*(arr[i]));
	}



	my_vec v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (int& e : v)
	{
		e *= 2;
	}
	printf("%d", v.sum());

	int t(6);
	t = 7;

	//A a;
	//B b;

	//a.print();
	//b.print();

	//A* pa = &a;
	//B* pb = pa;

	//pa->print();
	//pb->print();

	//pa->print2();
	//pb->print2();

	return 0;
}
