#include<iostream>
#include <cmath>
#define M_PI       3.14159265358979323846   // pi
using namespace std;

class Geometric_figures {
public:
	double r{};
	double height{};   // высота
	double width{};	// ширина

	const double& get_r()const { return r; }
	const double& get_height()const { return height; }
	const double& get_width()const { return width; }

	void set_r(double r){ this->r = r; }
	void set_height(double height){ this->height = height; }
	void set_width(double width){ this->width = width; }

	Geometric_figures() {
		cout << "Geometric_figuresConstructor0param:\t" << this << endl;
	}
	Geometric_figures(const double& r) {
		this->r = r;
		cout << "Geometric_figuresConstructor1param:\t" << this << endl;
	}
	Geometric_figures(const double& height, const double& width) {
		this->height = height;
		this->width = width;
		cout << "Geometric_figuresConstructor2param:\t" << this << endl;
	}
	  
	virtual ~Geometric_figures(){cout << "Geometric_figuresDEstructor:\t" << this << endl;}
	//virtual double perimeter() = 0;//периметр
	//virtual double square() = 0;	//площадь
	//virtual double perimeter(double r) = 0;//периметр
	//virtual double square(double r) = 0;	//площадь
	virtual double perimeter(double height, double width) = 0;//периметр
	virtual double square(double height, double width) = 0;	//площадь
};

class Square_figure : Geometric_figures {//квадрат
public:
	~Square_figure(){ cout << "Square_figureDEstructor:\t" << this << endl; }
	double perimeter( double width) {//периметр
		return width * 4;
	}

	double square( double width) {//площадь
		return width * width;
	}

};

class Rectangle : Geometric_figures {//прямоугольник
public:
	~Rectangle() { cout << "REctangleDEstructor:\t" << this << endl; }
	double perimeter(double height, double width) {//периметр
		return  2 *(height + width);
	}

	double square(double height, double width) {	//площадь
		return height * width;
	}
	
};

class Circle : Geometric_figures {//круг
public:
	~Circle(){ cout << "CirkleleDEstructor:\t" << this << endl; }
	double perimeter(double r) {//периметр
		return 2 * r * M_PI;
	}
	double square(double r) {	//площадь
		return r * r * M_PI;
	}
};

class Triangle : Geometric_figures {//треугольник

public:
	
	
	//double perimeter() const {//периметр
	//	return r * r * M_PI;
	//}

	double square() const {	//площадь
		return sqrt(3)*r*r/4;
	}

};


int main() {
	setlocale(LC_ALL, "Russian");
	
	/*Circle cirkle;
	cout<<cirkle.perimeter(6)<<endl;
	Square_figure kvadrat;
	cout << kvadrat.perimeter(6) << endl;*/


	

	Rectangle pryamougolnik;
	cout<<pryamougolnik.perimeter(12,13)<<endl;

	return 1;
}