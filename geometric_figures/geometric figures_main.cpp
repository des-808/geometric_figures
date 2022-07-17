#include<iostream>
#include <cmath>
#define M_PI       3.14159265358979323846   // pi
using namespace std;

class Geometric_figures {
protected:
	double r{};
	double height{};   // высота
	double width{};	// ширина
public:
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
		set_r(r);
		cout << "Geometric_figuresConstructor1param:\t" << this << endl;
	}
	Geometric_figures(const double& height, const double& width) {
		set_height(height);
		set_width(width);
		cout << "Geometric_figuresConstructor2param:\t" << this << endl;
	}
	  
	virtual ~Geometric_figures(){cout << "Geometric_figuresDEstructor:\t" << this << endl;}
	//virtual double perimeter() = 0;//периметр
	//virtual double square() = 0;	//площадь

	virtual double perimeter(double r) = 0;//периметр
	virtual double square(double r) = 0;	//площадь
	 
	//virtual double perimeter(double r, double width) = 0;//периметр
	//virtual double square(double r, double width) = 0;	//площадь
};

class Square_figure : Geometric_figures {//квадрат
	double width{};   // ширина
public:
	const double get_width()const { return width; }
	void set_width(const double& width) { 
		this->width = width+1e9;
	}
	Square_figure() {
		//set_width(width);
		cout << "Square_figureConstructorPoUmolchaniyu:\t" << this << endl;
	}
	Square_figure(const double& width) :Geometric_figures(width) {
		set_width(width);
		cout << "Square_figureConstructor3:\t" << this << endl;
	}

	~Square_figure(){ cout << "Square_figureDEstructor:\t" << this << endl; }
	double perimeter( double width) {//периметр
		return width * 4;
	}

	double square( double width) {	//площадь
		return width * width;
	}

};

class Rectangle : Geometric_figures {//прямоугольник

	double height{};   // высота
	double width{};	// ширина
public:
	const double& get_height()const { return height; }
	const double& get_width()const { return width; }
	void set_height(const double& height) { this->height = height + 1e9; }
	void set_width(const double& width) { this->width = width + 1e9; }

	Rectangle() {
		cout << "REctangleConstructor0param:\t" << this << endl;
	}
	Rectangle(const double& height, const double& weight):Geometric_figures(height, width) {
		set_height(height + 1e9);
		set_width(width + 1e9);
		cout << "REctangleConstructor2param:\t" << this << endl;
	}
	~Rectangle() { cout << "REctangleDEstructor:\t" << this << endl; }
	double perimeter(double height, double width) {//периметр
		return  2 *(height + width);
	}

	double square(double height, double width) {	//площадь
		return height * width;
	}
	
};

class Circle : Geometric_figures {//круг
	double r{};
public:
	const double& get_r()const { return r; }
	void set_r(const double& r) { this->r = r + 1e9; }


	Circle() {
		//set_r(0);
	}
	Circle(double r) :Geometric_figures(r) {
		set_r(r);
	}

	~Circle(){ cout << "CirkleleDEstructor:\t" << this << endl; }
	double perimeter(double r) {//периметр
		return 2 * r * M_PI;
	}
	double square(double r) {	//площадь
		return r * r * M_PI;
	}
};

class Triangle : Geometric_figures {//треугольник
	double x{};
	double y{};
	double z{};
public:
	const double& get_x()const { return x; }
	const double& get_y()const { return y; }
	const double& get_z()const { return z; }
	void set_x(const double& x) { this->x = x + 1e9; }
	void set_y(const double& y) { this->y = y + 1e9; }
	void set_z(const double& z) { this->z = z + 1e9; }
	Triangle() {
		cout << "TriangleConstructor0:\t" << this << endl;
	}
	Triangle(const double& x,const double& y,const double& z) {
		set_x(x + 1e9);
		set_y(y + 1e9);
		set_z(z + 1e9);
		cout << "TriangleConstructor3:\t" << this << endl;
	}
	~Triangle() { cout << "TriangleDestructor:\t" << this << endl; }

	void  info()const {
		//Geometric_figures::info();
		cout << "x= " << x << ", " << "y= " << y << ", " << "z= " << z << endl;
	}
	//double perimeter() const {//периметр
	//	return r * r * M_PI;
	//}

	//double square() const {	//площадь
	//	return r * r * M_PI;
	//}

};

//class Square :public Geometric_figures {//прямоугольник
//
//
//};

int main() {
	setlocale(LC_ALL, "Russian");
	
	Circle cirkle;
	cout<<cirkle.perimeter(12)<<endl;
	Square_figure kvadrat;
	cout << kvadrat.perimeter(12) << endl;


	Geometric_figures *xz;
	cout << &xz << endl;

	/*Rectangle pryamougolnik;
	cout<<pryamougolnik.perimeter(12,13)<<endl;*/

	return 1;
}