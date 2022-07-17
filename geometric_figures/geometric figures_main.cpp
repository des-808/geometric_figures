#include<iostream>
#include <cmath>
#define M_PI       3.14159265358979323846   // pi
using namespace std;

class Geometric_figures {
protected:
	double r;
	double height;   // высота
	double width;	// ширина
public:
	const double& get_r()const { return r; }
	const double& get_height()const { return height; }
	const double& get_width()const { return width; }
	//void set_r(const double& r){ this->r = r; }
	void set_r(const double& r){ this->r = r; }
	void set_height(const double& height){ this->height = height; }
	void set_width(const double& width){ this->width = width; }
	void set_two_param(const double& height, const  double& width) { this->height = height; this->width = width;}

	Geometric_figures( double r) {
		set_r(r);/*cout << "Geometric_figuresConstructor1param:\t" << this << endl;*/
	}
	Geometric_figures(double height,double width) {
		set_height(height);  set_width(width);
		/*cout << "Geometric_figuresConstructor2param:\t" << this << endl;*/
	}
	Geometric_figures(double r, double height, double width) {
		set_r(r);  set_height(height);   set_width(width);
		/*cout << "Geometric_figuresConstructor3param:\t" << this << endl;*/
	}
	  
	virtual ~Geometric_figures(){/*cout << "Geometric_figuresDEstructor:\t" << this << endl;*/}
	virtual double perimeter() = 0;//периметр
	virtual double square() = 0;	//площадь

	/*Geometric_figures& operator()(double r ) {
		this->set_r(r);
		return *this;
	}
	Geometric_figures& operator()(double height, double width) {
		this->set_height(height);
		this->set_width(width);
		return *this;
	}*/
};

class Square_figure : public  Geometric_figures {//квадрат
public:
	const double get_width()const { return width; }
	void set_width(const double& width) { this->width = width;}
	
	Square_figure() :Geometric_figures(width) {
		set_width(width);
		/*cout << "Square_figureConstructor3:\t" << this << endl;*/
	}

	~Square_figure(){ /*cout << "Square_figureDEstructor:\t" << this << endl;*/ }
	double perimeter( ) {//периметр
		return width * 4;
	}

	double square() {	//площадь
		return width * width;
	}
};

class Rectangle : public Geometric_figures {//прямоугольник
public:
	const double& get_height()const { return height; }
	const double& get_width()const { return width; }
	void set_height(const double& height) { this->height = height; }
	void set_width(const double& width) { this->width = width; }
	void set_two_param(const double& height, const double& width) { this->height = height; this->width = width; }
	
	Rectangle():Geometric_figures(height, width) {
		set_height(height);
		set_width(width);
		/*cout << "REctangleConstructor2param:\t" << this << endl;*/
	}
	~Rectangle() { /*cout << "REctangleDEstructor:\t" << this << endl;*/ }
	double perimeter() {//периметр
		return  2 *(height + width);
	}

	double square() {	//площадь
		return height * width;
	}
};

class Circle :public  Geometric_figures {//круг
public:
	const double& get_r()const { return r; }
	//void set_r(const double& r) { this->r = r; }
	void set_r(double r) { this->r = r; }

	Circle() :Geometric_figures(r) {
		set_r(r);
	}

	~Circle(){ /*cout << "CirkleleDEstructor:\t" << this << endl;*/ }
	double perimeter() {//периметр
		return 2 * r * M_PI;
	}
	double square() {	//площадь
		return r * r * M_PI;
	}
};

class Triangle :public  Geometric_figures {//треугольник

public:
	const double& get_r()const { return r; }
	void set_r(const double& r) { this->r = r; }

	Triangle():Geometric_figures(r) {
		set_r(r);
		/*cout << "TriangleConstructor1:\t" << this << endl;*/
	}
	~Triangle() { /*cout << "TriangleDestructor:\t" << this << endl;*/ }

	double perimeter() {//периметр
		return r * r * M_PI;
	}

	double square() {	//площадь
		return sqrt(3) * r * r / 4;
	}

};


int main() {
	setlocale(LC_ALL, "Russian");

	Circle cirkle;
	cirkle.set_r(8);
	cout<<"Периметр	    круга с радиусом :" << cirkle.get_r() << "= " <<cirkle.perimeter() << endl;
	cout<<"Площадь		    круга с радиусом :" << cirkle.get_r() << "= " <<cirkle.square() << endl;

	Square_figure kvadrat;
	kvadrat.set_width(7);
	cout <<"Периметр	квадрата со стороной :" << kvadrat.get_width() << "= " << kvadrat.perimeter() << endl;
	cout <<"Площадь		квадрата со стороной :" << kvadrat.get_width() << "= " << kvadrat.square() << endl;

	Rectangle pryamougolnik;
	pryamougolnik.set_two_param(6, 7);
	cout <<"Периметр прямоугольника со сторонами :" << pryamougolnik.get_height() << ", " << pryamougolnik.get_width() << "= " << pryamougolnik.perimeter() << endl;
	cout <<"Площадь  прямоугольника со сторонами :" << pryamougolnik.get_height() << ", " << pryamougolnik.get_width() << "= " << pryamougolnik.square() << endl;

	Triangle treugolnik;
	treugolnik.set_r(100);
	cout << "Площадь		    треугольника  :" << treugolnik.get_r() << "= " << treugolnik.square() << endl;


	return 1;
}