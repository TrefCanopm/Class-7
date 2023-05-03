#include <iostream> 
using namespace std;

template <class T>
class Plenty
{
protected:
	int size;
	T* data;
public:
	Plenty(int s)
	{
		size = s;
		data = new T[size];
		for (int k = 0; k < s; k++)
			data[k] = 0;
	}
	Plenty(const Plenty<T>& p)
	{
		size = p.size;
		data = new T[size];
		for (int k = 0; k < size; k++)
			data[k] = p.data[k];
	}

	Plenty& operator = (const Plenty<T>&p)
	{
		if (this == &p) return *this;
		if (size > p.size)
		{
			for (int i = 0; i < p.size; i++)
			{
				data[i] = p.data[i];
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				data[i] = p.data[i];
			}
		}
		return *this;
	}
	Plenty& operator-(const Plenty<T>& p)
	{
		if (size != p.size)
		{
			cout << "" << endl;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				data[i] -= p.data[i];
			}
			return *this;
		}
	}

	T& operator[](int index)
	{
		if (index < size) return data[index];
		else cout << "" << endl;
	}
	T operator() ()
	{
		return size;
	}

	friend ostream& operator<<(ostream& out, const Plenty<T>& p)
	{
		for (int i = 0; i < p.size;++i)
		{
			out << p.data[i] << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, Plenty<T>& p)
	{
		for (int i = 0; i < p.size; ++i)
		{
			in >> p.data[i];
		}
		return in;
	}

	~Plenty()
	{
		delete[] data;
		size = 0;
	}
};

class Money
{
protected:
	long rubles;
	int kopecks;
public:
	Money()
	{
		rubles = 0;
		kopecks = 0;
	}
	Money(long r, int k)
	{
		rubles = r;
		if (k < 100)
		{
			kopecks = k;
		}
		else
		{
			rubles = rubles + k / 100;
			kopecks = k % 100;
		}
	}
	Money(const Money& m)
	{
		rubles = m.rubles;
		kopecks = m.kopecks;
	}
	Money& operator = (const Money& m)
	{
		Money p;
		p.rubles = m.rubles;
		p.kopecks = m.kopecks;
		return p;
	}

	friend std::ostream& operator << (std::ostream& out, const Money& p)
	{
		return(out << p.rubles << ", " << p.kopecks);
	}
	friend std::istream& operator >> (std::istream& in, Money& p)
	{
		in >> p.rubles;
		in >> p.kopecks;
		return in;
	}

	~Money() {};
};

int main()
{
	Plenty<int> P(5);
	cin >> P;
	cout << P << endl;
	Plenty <int> Pl(10);
	Pl = P;
	cout << Pl << endl;
	cout << P[2] << endl;
	cout << "size = " << P() << endl;

	Money m;
	cin >> m;
	cout << m;

	return 0;
}