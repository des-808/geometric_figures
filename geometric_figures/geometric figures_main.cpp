#include<iostream>
#include <cmath>
#define M_PI       3.14159265358979323846   // pi
using namespace std;

class Geometric_figures {
//protected:
public:
	double r;
	double height;   // высота
	double width;	// ширина

	const double& get_r()const { return r; }
	const double& get_height()const { return height; }
	const double& get_width()const { return width; }

	void set_r(double r){ this->r = r; }
	void set_height(double height){ this->height = height; }
	void set_width(double width){ this->width = width; }
	void set_two_param(double height, double width) { this->height = height; this->width = width;}

	/*Geometric_figures() {
		this->r = 0;
		this->height = 0;
		this->width = 0;
		cout << "Geometric_figuresConstructor0param:\t" << this << endl;
	}*/
	Geometric_figures( double r) {
		set_r(r);
		cout << "Geometric_figuresConstructor1param:\t" << this << endl;
	}
	Geometric_figures(double height,double width) {
		set_height(height);
		set_width(width);
		cout << "Geometric_figuresConstructor2param:\t" << this << endl;
	}
	Geometric_figures(double r, double height, double width) {
		set_r(r);
		set_height(height);
		set_width(width);
		cout << "Geometric_figuresConstructor3param:\t" << this << endl;
	}
	  
	virtual ~Geometric_figures(){cout << "Geometric_figuresDEstructor:\t" << this << endl;}
	virtual double perimeter() = 0;//периметр
	virtual double square() = 0;	//площадь

	//virtual double perimeter(double r) = 0;//периметр
	//virtual double square(double r) = 0;	//площадь
	 
	//virtual double perimeter(double r, double width) = 0;//периметр
	//virtual double square(double r, double width) = 0;   //площадь
};

class Square_figure : public  Geometric_figures {//квадрат
	//double width{};   // ширина
public:
	const double get_width()const { return width; }
	void set_width(const double& width) { this->width = width;}
	/*Square_figure() {
		set_width(width);
		cout << "Square_figureConstructorPoUmolchaniyu:\t" << this << endl;
	}*/
	Square_figure() :Geometric_figures(width) {
		set_width(width);
		cout << "Square_figureConstructor3:\t" << this << endl;
	}

	~Square_figure(){ cout << "Square_figureDEstructor:\t" << this << endl; }
	double perimeter( ) {//периметр
		return width * 4;
	}

	double square() {	//площадь
		return width * width;
	}

};

class Rectangle : public Geometric_figures {//прямоугольник

	//double height{};   // высота
	//double width{};	// ширина
public:
	const double& get_height()const { return height; }
	const double& get_width()const { return width; }
	void set_height(const double& height) { this->height = height; }
	void set_width(const double& width) { this->width = width; }
	void set_two_param(double height, double width) { this->height = height; this->width = width; }
	/*Rectangle() {
		cout << "REctangleConstructor0param:\t" << this << endl;
	}*/
	Rectangle():Geometric_figures(height, width) {
		set_height(height);
		set_width(width);
		cout << "REctangleConstructor2param:\t" << this << endl;
	}
	~Rectangle() { cout << "REctangleDEstructor:\t" << this << endl; }
	double perimeter() {//периметр
		return  2 *(height + width);
	}

	double square() {	//площадь
		return height * width;
	}
	
};

class Circle :public  Geometric_figures {//круг
	//double r{};
public:
	const double& get_r()const { return r; }
	void set_r(const double& r) { this->r = r; }


	//Circle() {
	//	//set_r(0);
	//}
	Circle() :Geometric_figures(r) {
		set_r(r);
	}

	~Circle(){ cout << "CirkleleDEstructor:\t" << this << endl; }
	double perimeter() {//периметр
		return 2 * r * M_PI;
	}
	double square() {	//площадь
		return r * r * M_PI;
	}
};

class Triangle :public  Geometric_figures {//треугольник
	/*double x{};
	double y{};
	double z{};*/
public:
	const double& get_x()const { return r; }
	const double& get_y()const { return height; }
	const double& get_z()const { return width; }
	void set_x(const double& r) { this->r = r; }
	void set_y(const double& height) { this->height = height; }
	void set_z(const double& width) { this->width = width; }
	/*Triangle() {
		cout << "TriangleConstructor0:\t" << this << endl;
	}*/
	Triangle():Geometric_figures(r,height,width) {
		set_x(r);
		set_y(height);
		set_z(width);
		cout << "TriangleConstructor3:\t" << this << endl;
	}
	~Triangle() { cout << "TriangleDestructor:\t" << this << endl; }

	//void  info()const {
	//	//Geometric_figures::info();
	//	cout << "x= " << x << ", " << "y= " << y << ", " << "z= " << z << endl;
	//}
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
	cirkle.set_r(8);
	cout<<"Периметр круга с радиусом " << cirkle.get_r() << "= " <<cirkle.perimeter() << endl;
	cout<<"Площадь  круга с радиусом " << cirkle.get_r() << "= " <<cirkle.square() << endl;

	Square_figure kvadrat;
	kvadrat.set_width(7);
	cout <<"Периметр квадрата со стороной :" << kvadrat.get_width() << "= " << kvadrat.perimeter() << endl;
	cout <<"Площадь  квадрата со стороной :" << kvadrat.get_width() << "= " << kvadrat.square() << endl;

	Rectangle pryamougolnik;
	pryamougolnik.set_two_param(6, 7);
	cout <<"Периметр прямоугольника со сторонами :" << pryamougolnik.get_height() << ", " << pryamougolnik.get_width() << "= " << pryamougolnik.perimeter() << endl;
	cout <<"Площадь  прямоугольника со сторонами :" << pryamougolnik.get_height() << ", " << pryamougolnik.get_width() << "= " << pryamougolnik.square() << endl;





	return 1;
}