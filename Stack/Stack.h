#pragma once
template <class T>
class TStack
{
	int MaxSize; // Максимальный размер стека
	int Size;    // Число элементов стека
	T *Stack;    // Массив стека
public:
	TStack(const int  MS = 10);
	TStack(const TStack <T> &tmp);
	~TStack();
	TStack& operator= (const TStack &tmp);
	//	bool operator ==(const TStack &tmp);
	//	bool operator !=(const TStack &tmp);
	void Push(const T elem);
	T Pop();
	T Top() const;
	void Clear();
	bool IsEmpty() const;
	bool IsFull() const;


};

template <class T>
TStack <T>::TStack(const int MS)
{
	if (MS < 0)
		throw - 1;
	MaxSize = MS;
	Stack = new T[MaxSize];
	Size = 0;
}

template <class T>
TStack <T>::TStack(const TStack <T> &tmp)
{
	MaxSize = tmp.MaxSize;
	Size = tmp.Size;
	Stack = new T[MaxSize];
	for (int i = 0; i < Size; i++)
		Stack[i] = tmp.Stack[i];
}

template <class T>
TStack <T> ::~TStack()
{
	delete[] Stack;
}

template <class T>
TStack <T> &TStack <T> ::operator= (const TStack &tmp)
{
	if (MaxSize != tmp.MaxSize)
	{
		delete[] Stack;
		Stack = new T[tmp.MaxSize];
	}
	MaxSize = tmp.MaxSize;
	Size = tmp.Size;
	for (int i = 0; i < Size; i++)
		Stack[i] = tmp.Stack[i];
	return *this;
}

/*template <class T>
bool TStack <T> ::operator==(const TStack <T> &tmp)
{
if (Size!=tmp.)

}

template <class T>
bool TStack <T> ::operator!=(const TStack <T> &tmp)
{

}*/
template <class T>
void TStack<T> ::Push(const T elem)
{
	if (MaxSize == Size)
		throw "Stack is full";
	else
	{
		Stack[Size] = elem;
		Size++;
	}
}

template <class T>
T TStack <T>::Pop()
{
	if (Size == 0)
		throw "Stack is empty";
	else
	{
		Size--;
		return Stack[Size];
	}
}

template <class T>
T TStack<T>::Top() const
{
	if (Size == 0)
		throw "Stack is empty";
	else
		return Stack[Size - 1];
}

template <class T>
void TStack <T>::Clear()
{
	Size = 0;
}
template <class T>
bool TStack <T>::IsEmpty() const
{
	return (Size == 0);
}

template <class T>
bool TStack <T>::IsFull() const
{
	return (Size == MaxSize);
}
