#ifndef __COMPLEX__
#define __COMPLEX__

class complex;
complex&
	__doapl(complex * ths, const complex& r);
complex&
	__doami(complex * ths, const complex& r);
complex&
	__doaml(complex * ths, const complex& r);


class complex
{
public:
	complex (double r = 0, double i = 0)
		: re (r), im (i)
	{  }
	complex& operator += (const complex&);
	complex& operator -= (const complex&);
	complex& operator *= (const complex&);
	complex& operator /= (const complex&);
	double real() const { return re; }
	double imag() const { return im; }

private:
	double re, im;

	friend complex& __doapl(complex *, const complex&);
	friend complex& __doami(complex *, const complex&);
	friend complex& __doaml(complex *, const complex&);
};

inline complex&
__doapl(complex* ths, const complex& r){
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}

inline complex&
complex::operator += (const complex& r){
	return __doapl(this, r);
}

inline complex&
__doami(complex * ths, const complex & r){
	ths->re -= r.re;
	ths->im -= r.im;
	return * ths;
}

inline complex&
complex::operator -= (const complex & r){
	return __doami(this, r);
}

inline complex&
__doaml(complex * ths, const complex & r){
	ths->re *= ths->re * r.re - ths->im * r.im;
	ths->im *= ths->im * r.re + ths->re * r.im;
	return * ths;
}

inline complex&
complex::operator *= (const complex & r){
	return __doaml(this, r);
}

inline complex
operator + (const complex & x, const complex & y){
	return complex (x.real() + y.real(), x.imag() + y.imag());
}

inline complex
operator + (const double x, const complex & y){
	return complex (x + y.real(), y.imag());
}

inline complex
operator + (const complex & x, const double y){
	return complex (x.real() + y, x.imag());
}

inline complex
operator + (const complex & x){
	return x;
}

inline complex
operator - (const complex & x){
	return complex (-x.real(), -x.imag());
}

inline complex
operator - (const complex & x, const complex & y){
	return complex (x.real() - y.real(), x.imag() - y.imag());
}

inline complex
operator - (const double x, const complex & y){
	return complex (x - y.real(), y.imag());
}

inline complex
operator - (const complex & x, const double y){
	return complex (x.real() - y, x.imag());
}

inline complex
operator * (const complex & x, const complex & y){
	return complex ( x.real() * y.real() - x.imag() * y.imag(), x.imag() * y.real() + x.real() * y.imag() );
}

inline complex
operator * (const double x, const complex & y){
	return complex (x * y.real(), x * y.imag());
}

inline complex
operator * (const complex & x, const double y){
	return complex ( x.real() * y, x.imag() * y );
}

inline complex
operator / (const complex & x, const double y){
	return complex ( x.real() / y, x.imag() / y );
}

inline bool
operator == (const complex & x, const complex & y){
	return x.real() == y.real() && x.imag() == y.imag();
}

inline bool
operator == (const double x, const complex & y){
	return y.real() == x && y.imag() == 0;
}

inline bool
operator == (const complex & x, const double y){
	return x.real() == y && x.imag() == 0;
}

inline bool
operator != (const complex & x, const complex & y){
	return x.real() != y.real() || x.imag() != y.imag();
}

inline bool
operator != (const complex & x, const double y){
	return x.imag() != 0 || x.real() != y;
}

inline bool
operator != (const double x, const complex & y){
	return y.imag() != 0 || y.real() != x;
}

#include <cmath>

inline complex
polar (const double r, const double t){
	return complex ( r * cos(t), r * sin(t) );
}

inline complex
conj (const complex & x){
	return complex ( x.real(), -x.imag() );
}

inline double
norm (const complex & x){
	return x.real() * x.real() + x.imag() * x.imag();
}
#endif /* ifndef __COMPLEX */
