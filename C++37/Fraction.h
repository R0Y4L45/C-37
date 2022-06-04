#pragma once


class Fraction
{
	int _numerator = 0; // suret
	int _denominator = 0; // mexrec

public:


#pragma region Constructors


	Fraction() = default;

	Fraction(int num, int den)
	{
		setNum(num);
		setDen(den);
	}

	Fraction(Fraction& other)
	{
		_numerator = other._numerator;
		_denominator = other._denominator;
	}

	Fraction(Fraction&& other) noexcept
	{
		_denominator = other._denominator;
		_numerator = other._numerator;
	}

#pragma endregion 



#pragma region Assigment 


	Fraction& operator=(const Fraction& other)
	{
		_denominator = other._denominator;
		_numerator = other._numerator;
	}

	Fraction& operator=(const Fraction&& other) noexcept
	{
		_denominator = other._denominator;
		_numerator = other._numerator;
		other._denominator;
		other._numerator;
	}


#pragma endregion 


#pragma region Setters


	void setNum(int num)
	{
		_numerator = num;
	}

	void setDen(int den)
	{
		_denominator = den;
	}


#pragma endregion



#pragma region Getters

	const int getNum(int num) const
	{
		return _numerator;
	}

	const int getDen(int den) const
	{
		return _denominator;
	}


#pragma endregion



#pragma region Operators


	Fraction operator+(Fraction& other)
	{
		Fraction res;

		if (_denominator + other._denominator == 0)
		{
			if (_numerator + other._numerator == 0)
				res._numerator = 0;
			else
				res._numerator = 1;
			res._denominator = 0;
		}
		else
		{
			res._numerator = _numerator + other._numerator;
			res._denominator = _denominator + other._denominator;

			if ((_numerator + other._numerator < 0) && (_denominator + other._denominator < 0))
			{
				res._numerator *= -1;
				res._denominator *= -1;
			}
		}
		return res;
	}

	Fraction operator-(Fraction& other)
	{
		Fraction res;
		
		if (_denominator - other._denominator == 0)
		{
			if (_numerator - other._numerator == 0)
				res._numerator = 0;
			else
				res._numerator = 1;
			res._denominator = 0;
		}
		else
		{
			res._numerator = _numerator - other._numerator;
			res._denominator = _denominator - other._denominator;

			if ((_numerator - other._numerator < 0) && (_denominator - other._denominator < 0))
			{
				res._numerator *= -1;
				res._denominator *= -1;
			}
		}
		return res;
	}


	Fraction operator*(Fraction& other)
	{
		Fraction res;

		if (_denominator * other._denominator == 0)
		{
			if (_numerator * other._numerator == 0)
				res._numerator = 0;
			else
				res._numerator = 1;
			res._denominator = 0;
		}
		else
		{
			res._numerator = _numerator * other._numerator;
			res._denominator = _denominator * other._denominator;

			if ((_numerator * other._numerator < 0) && (_denominator * other._denominator < 0))
			{
				res._numerator *= -1;
				res._denominator *= -1;
			}
		}
		return res;
	}


	Fraction operator/(Fraction& other)
	{
		Fraction res;
		if (other._denominator == 0 || other._numerator == 0)
		{
			res._numerator = 1;
			res._denominator *= 0;
		}
		else
		{
			res._numerator = _numerator / other._numerator;
			res._denominator = _denominator / other._denominator;
			if (res._numerator < 0 && res._denominator < 0)
			{
				res._numerator *= -1;
				res._denominator *= -1;
			}
		}
		return res;
	}

	friend istream& operator>>(istream& in, Fraction& f)
	{
		cout << "Enter numerator : ";
		in >> f._numerator;
		cout << "Enter denominator : ";
		in >> f._denominator;
		return in;
	}


	friend ostream& operator<<(ostream& out, Fraction& f)
	{
		if (f._numerator == 0 && f._denominator == 0 || f._numerator == 0)
			out << 0;
		else if (f._denominator == 0)
			out << "Zero divison error...\n";
		else
			out << f._numerator << '/' << f._denominator << endl;

		return out;
	}

	Fraction& operator++()
	{
		++_numerator;
		++_denominator;
		return *this;
	}

	Fraction& operator--()
	{
		--_numerator;
		--_denominator;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction temp;
		temp._numerator = _numerator++;
		temp._denominator = _denominator++;
		return temp;
	}

	Fraction operator--(int)
	{
		Fraction temp;
		temp._numerator = _numerator--;
		temp._denominator = _denominator--;
		return temp;
	}


#pragma endregion 



#pragma region TypeConversion

	
	explicit operator bool()
	{
		if (_denominator != 0 && _numerator != 0)
			return true;
		return false;
	}

	operator float()
	{
		return (float) _numerator / _denominator;
	}


#pragma endregion



	void Simplify()
	{
		if (_numerator != 0 && _denominator != 0 && _numerator != _denominator)
		{
			int i = 2, num = _numerator;
			for (size_t i = 2; i < num + 1; i++)
				if ((_denominator % i) == 0 && (_numerator % i) == 0)
				{
					_denominator /= i;
					_numerator /= i;
					--i;
				}
			cout << endl << _numerator << '/' << _denominator << '\n';
		}
		else if (_numerator == 0)
			cout << 0;
		else if (_denominator == 0)
			cout << "\nError Zero Division...\n";
		else if (_numerator == _denominator)
			cout << 1;
	}
	
	
	
	
	// Kəsri ixtisar edir
};
