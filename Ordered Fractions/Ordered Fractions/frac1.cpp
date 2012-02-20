/*
ID:   pinepar1
PROG: frac1
LANG: C++
*/
#include<iostream>
#include<set>

//#define FILEIO

#ifdef FILEIO
	#include<fstream>
	std::ifstream fin("frac1.in",std::ios::in);
	std::ofstream fout("frac1.out",std::ios::out);
	#define in fin
	#define out fout
#else
	#define in std::cin
	#define out std::cout
#endif

class Fractal{
	friend std::ostream& operator<<(std::ostream& os,const Fractal& fractal);
public:
	Fractal(int numerator,int denominator){
		this->numerator=numerator;
		this->denominator=denominator;
		reduce();
	}
	bool operator<(const Fractal& another) const{
		return numerator*another.denominator<another.numerator*denominator;
	}
private:
	void reduce(){
		int divisor=gcd(numerator,denominator);
		numerator/=divisor;
		denominator/=divisor;
	}
	int gcd(int smaller,int bigger){
		if(smaller==0)
			return bigger;
		return gcd(bigger%smaller,smaller);
	}
	int numerator,denominator;
};

std::ostream& operator<<(std::ostream& os,const Fractal& fractal){
	return os<<fractal.numerator<<"/"<<fractal.denominator;
}

int main(){
	int n;
	in>>n;
	std::set<Fractal> fractals;
	for(int denominator=1;denominator<=n;denominator++)
		for(int numerator=0;numerator<=denominator;numerator++)
			fractals.insert(Fractal(numerator,denominator));
	for(std::set<Fractal>::const_iterator iter=fractals.begin();iter!=fractals.end();iter++)
		out<<*iter<<std::endl;
#ifdef FILEIO
	fin.close();
	fout.close();
#endif
	return 0;
}