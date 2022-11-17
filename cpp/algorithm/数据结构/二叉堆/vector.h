#ifndef VECTOR_H
#define VECTOR_H
template <typename Object>

void func()
{
	cout << "hello world" << endl;
}

class vector
{
public:
	vector(int initSize = 0,int element = 0):theSize(initSize),theCapacity(initSize + SPARE_CAPACITY)
	{
		objects = new Object[theCapacity];//Wrongly written theSize at the beginning
		for (int i = 0; i < theSize; i++) //Default initialized to 0
			objects[i] = element;
	}

	~vector()
	{
		delete[] objects;
	}

	vector(const vector& rhs)
	{
		operator = (rhs);
	}

	const vector& operator = (const vector& rhs)
	{
		if (this != &rhs)  // Don't copy yourself
		{
			delete[] objects;
			theSize = rhs.theSize;//protection in C++ is class level, not object level.
			theCapacity = rhs.theCapacity;
			objects = new Object[theCapacity];
			for (int k = 0; k < theSize; k++)
				objects[k] = rhs[k];
		}
		return *this;
	}

	void push_back(const Object & element)
	{
		if (theSize == theCapacity)//Expansion before insertion
			reserve(2 * theSize + 1);
		objects[theSize++] = element;
	}

	void pop_back()
	{
		theSize--;
	}

	void reserve(int C)
	{
		if (C < theSize)
			return;
		Object* oldObjects = objects;
		objects = new Object[C];   // reserve just allocate memory
		theCapacity = C;
		for (int k = 0; k < theSize; k++)
			objects[k] = oldObjects[k];
		delete[] oldObjects;
	}

	void resize(int S,int element = 0)//Inserts or removes the appropriate number of elements to have the size S
	{
		if (S > theCapacity)
			reserve(S * 2 + 1);
		if (S > theSize)
		{
			for (int k = theSize; k < S; k++)// insert
				objects[k] = element;
		}
		else if (S < theSize) // remove
		{
			while (theSize != S)
				pop_back();
		}
		theSize = S;
	}

	Object& operator [] (int index)
	{
		return *(objects + index);
	}

	int  size()
	{
		return theSize;
	}

	int capacity()
	{
		return theCapacity;
	}

	bool empty()
	{
		return theSize == 0;
	}

	const Object & back() // question: About the reference in C++?
	{
		return objects[theSize - 1];
	}

	typedef Object* iterator;
	typedef const Object* const_iterator;

	iterator end()
	{
		return &objects[theSize];
	}
	const_iterator cend() const
	{
		return &objects[theSize];  //The return value cannot be modified or used as an LValue
	}
	iterator begin()
	{
		return &objects[0];
	}
	const_iterator cbegin() const
	{
		return &objects[0];
	}

	enum{ SPARE_CAPACITY = 16};

private:
	int theSize;
	int theCapacity;
	Object* objects;
};

#endif