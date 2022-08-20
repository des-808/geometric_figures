#include<iostream>
#include<Windows.h>
#include <cmath>
#include <WinGDI.h>

#define M_PI       3.14159265358979323846   // pi
using namespace std;
namespace Geometry{
	enum Color {
		black	= 0x00000000,
		red		= 0x000000FF,
		green	= 0x0000FF00,
		blue	= 0x00FF0000,
		yellow	= 0x0000FFFF,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yelow = 0xEE,
		console_default = 0x07
	};
	enum Defaults {
		start_x_min = 100,
		start_y_min = 100,
		start_x_max = 800,
		start_y_max = 500,

		line_width_min = 1,
		line_width_max = 30,
		primary_size_min = 5,
		primary_size_max = 500,
		primary_angle_min = 0,
		primary_angle_max = 179

	};  
//TODO:
//	1. Во все геометрические фигуры добавить атрибут 'filled', который определяет, закрашена ли фигура,
//		или же отображается контуром;
//	2. В иерархию геометрических фигур добавить класс Circle.
//		Круг можно нарисовать используя функцию Circle из библиотеки WinGDI;
//	3. В иерархию геометрических фигур добавить иерархию треугольников.
//		Треугольник можно нарисовать используя функцию Polygon из библиотеки WinGDI;
//	4. Реализовать класс Паралелограмм;
//	5. В отдельной ветке нарисовать все эти фигуры используя библиотеку DirectX или OpenGL;
#define SHAPE_TAKE_PARAMETRES Color color,unsigned int start_x, unsigned int start_y,unsigned int line_width,bool filled = true
#define SHAPE_GIVE_PARAMETRES color,start_x, start_y,line_width, filled
	class Shape {
	protected:
		Color color;
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		bool filled;
	public:
		Color get_color()const { return color; }
		unsigned int get_start_x()const { return start_x; }
		unsigned int get_start_y()const { return start_y; }
		unsigned int get_line_widthy()const { return line_width; }
		//bool get_filled()const { return filled; }

		void set_start_x(unsigned int start_x) {
			if (start_x < Defaults::start_x_min)start_x = Defaults::start_x_min;
			if (start_x > Defaults::start_x_max)start_x = Defaults::start_x_max;
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y) {
			if (start_y < Defaults::start_y_min)start_y = Defaults::start_y_min;
			if (start_y > Defaults::start_y_max)start_y = Defaults::start_y_max;
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width) {
			if (line_width < Defaults::line_width_min)line_width = Defaults::line_width_min;
			if (line_width > Defaults::line_width_max)line_width = Defaults::line_width_max;
			this->line_width = line_width;
		}
		//void set_filled(bool filled) {this->filled = filled;}

		//Shape(Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width) :color(color){
		Shape(SHAPE_TAKE_PARAMETRES) :color(color) {
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
			this->filled = filled;
		}
		virtual ~Shape() {}
		//чисто виртуальные методы и делают класс абстрактным
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		virtual void info()const
		{
			cout << "Площадь фигуры:\t" << get_area() << endl;
			cout << "Периметр фигуры:\t" << get_perimeter() << endl;
			draw();
		}
	};

	//class Square :public Shape {
	//	double side;
	//public:
	//	double get_side()const {
	//		return side;
	//	}
	//	void set_side(double side) {
	//		if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
	//		if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
	//		this->side = side;
	//	}
	//	//Square(double side,Color color,unsigned int start_x, unsigned int start_y,unsigned int line_width)
	//	Square(double side, SHAPE_TAKE_PARAMETRES)
	//		//:Shape(color, start_x, start_y, line_width){
	//		:Shape(SHAPE_GIVE_PARAMETRES) {
	//		set_side(side);
	//	}
	//	~Square() {}
	//	double get_area()const
	//	{
	//		return side * side;
	//	}
	//	double get_perimeter()const
	//	{
	//		return side * 4;
	//	}
	//	void draw()const
	//	{
	//		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//		SetConsoleTextAttribute(hConsole, color);
	//		for (int i = 0; i < side; i++)
	//		{
	//			for (int j = 0; j < side; j++)
	//			{
	//				cout << "* ";
	//			}
	//			cout << endl;
	//		}
	//		SetConsoleTextAttribute(hConsole, Color::console_default);
	//	}
	//	void info()const
	//	{
	//		cout << typeid(*this).name() << endl;
	//		cout << "Длина стороны: " << get_side() << endl;
	//		Shape::info();
	//	}
	//};

	class Rectangle :public Shape
	{
	protected:
		double width;
		double height;
	public:
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		void set_width(double width)
		{
			if (width < Defaults::primary_size_min)width = Defaults::primary_size_min;
			if (width > Defaults::primary_size_max)width = Defaults::primary_size_max;
			this->width = width;
		}
		void set_height(double height)
		{
			if (height < Defaults::primary_size_min)height = Defaults::primary_size_min;
			if (height > Defaults::primary_size_max)height = Defaults::primary_size_max;
			this->height = height;
		}
		Rectangle(//double width, double height,Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width) :Shape(color, start_x, start_y, line_width)
			double width, double height, SHAPE_TAKE_PARAMETRES) :Shape(SHAPE_GIVE_PARAMETRES) {
			set_width(width);
			set_height(height);
		}
		~Rectangle() {}

		double get_area()const {
			return width * height;
		}
		double get_perimeter()const {
			return (width + height) * 2;
		}
		void draw()const
		{
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);*/
			//1)Получаем окно консоли
			HWND hConsole = GetConsoleWindow();	
			//2)Получаем контекст устройства для нашего окна консоли.
			HDC hdc = GetDC(hConsole);//то на чём будем рисовать
			//3)создаём карандаш
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
			//PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселов, RGB(...) - цвет.

			//SelectObject(hdc, hPen);//Выбираем созданный карандаш, чтобы им можно было рисовать.
			HBRUSH hBrush = CreateSolidBrush(filled?color: Color::black);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//SelectObject(hdc, hBrush);//Выбираем созданную кисть.
			//Кисть и карандаш выбираются для того, чтобы функция Rectangle понимала чем рисовать

			//выбираем чем и на чём будем рисовать
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//когда мы выбрали кем и на чём рисовать. Рисуем фигуру
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);//Рисует квадрат

			//Удаляем созданную кисть и карандаш:
			DeleteObject(hBrush);
			DeleteObject(hPen);
			//Освобождаем контекст устройства:
			ReleaseDC(hConsole, hdc);
		}

		void info()const{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольника:\t" << get_width() << endl;
			cout << "Длина прямоугольника:\t" << get_height() << endl;
			Shape::info();
		}
	};

	class Square :public Rectangle {
	public:
		Square(double side, SHAPE_TAKE_PARAMETRES):Rectangle(side, side, SHAPE_GIVE_PARAMETRES) {}
		~Square(){}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_width() << endl;
			Shape::info();
		}

	};

	class Circle :public Shape{
	double r;
public:
	double get_r()const{return r;}
	void set_r(double r){if(r>Defaults::primary_size_max)r = Defaults::primary_size_max;
						 if(r<Defaults::primary_size_min)r = Defaults::primary_size_min;
						 this->r = r;
	}



	Circle(double r, SHAPE_TAKE_PARAMETRES) :Shape(SHAPE_GIVE_PARAMETRES) { set_r(r); }
	~Circle() {}

	//double get_area()const {return M_PI * r * r;}
	double get_area()const {return M_PI * pow(r,2);}
	double get_perimeter()const {return 2*M_PI*r;}

	void draw()const{
		//1)Получаем окно консоли
		HWND hConsole = GetConsoleWindow();
		//2)Получаем контекст устройства для нашего окна консоли.
		HDC hdc = GetDC(hConsole);//то на чём будем рисовать
		//3)создаём карандаш
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
		//PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселов, RGB(...) - цвет.
		HBRUSH hBrush = CreateSolidBrush(filled ? color :Color:: black);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
		//Кисть и карандаш выбираются для того, чтобы функция Rectangle понимала чем рисовать
		//выбираем чем и на чём будем рисовать
		SelectObject(hdc, hPen);//Выбираем созданный карандаш, чтобы им можно было рисовать.
		SelectObject(hdc, hBrush);//Выбираем созданную кисть.
		//когда мы выбрали кем и на чём рисовать. Рисуем фигуру
		::Ellipse(hdc,start_x,start_y, start_x + r*2,start_y+ r * 2);//Рисует квадрат
		//Удаляем созданную кисть и карандаш:
		DeleteObject(hBrush);
		DeleteObject(hPen);
		//Освобождаем контекст устройства:
		ReleaseDC(hConsole, hdc);
	}
	virtual void info()const
	{
		cout << "Площадь круга:\t" << get_area() << endl;
		cout << "Периметр круга:\t" << get_perimeter() << endl;
		Shape::info();
		draw();
	}


};

	class Triangle:public Shape{
	public:
		Triangle(SHAPE_TAKE_PARAMETRES) :Shape(SHAPE_GIVE_PARAMETRES){}
		~Triangle() {}
		virtual double get_height()const = 0;
	};


	class Equilaterial_Triangle :public Triangle {
		double side;
	public:
		double get_side()const { return side; }
		void set_side(double side) {
				if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
				if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
				this->side = side;
		}

		Equilaterial_Triangle(double side, SHAPE_TAKE_PARAMETRES) :Triangle(SHAPE_GIVE_PARAMETRES) {
			set_side(side);
		}
		~Equilaterial_Triangle(){}

		double get_height()const	{	return side * sqrt(3) / 2;	}
		double get_area()const		{	return side * get_height() / 2;}
		double get_perimeter()const {	return side * 3;}


		void draw()const {
			//1)Получаем окно консоли
			HWND hConsole = GetConsoleWindow();
			//2)Получаем контекст устройства для нашего окна консоли.
			HDC hdc = GetDC(hConsole);//то на чём будем рисовать
			//3)создаём карандаш
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
			//PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселов, RGB(...) - цвет.
			HBRUSH hBrush = CreateSolidBrush(filled ? color : Color::black);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//HBRUSH hBrush = CreateSolidBrush(color);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//Кисть и карандаш выбираются для того, чтобы функция Rectangle понимала чем рисовать
			//выбираем чем и на чём будем рисовать
			SelectObject(hdc, hPen);//Выбираем созданный карандаш, чтобы им можно было рисовать.
			SelectObject(hdc, hBrush);//Выбираем созданную кисть.
			//когда мы выбрали кем и на чём рисовать. Рисуем фигуру
			POINT point[] = {
				{start_x,start_y + get_height() },
				{start_x + side,start_y + get_height()},
				{start_x + side / 2,start_y}
			};
			::Polygon(hdc,point,3);//Рисует квадрат
			//Удаляем созданную кисть и карандаш:
			DeleteObject(hBrush);
			DeleteObject(hPen);
			//Освобождаем контекст устройства:
			ReleaseDC(hConsole, hdc);
		}

		virtual void info()const
		{
			cout << "Площадь треугольника:\t" << get_area() << endl;
			cout << "Периметр треугольника:\t" << get_perimeter() << endl;
			Shape::info();
			draw();
		}
	}
	
	
	;class Isosceles_Triangle :public Triangle {
		double base;
		double side;
	public:
		double get_base()const { return base; }
		double get_side()const { return side; }
		void set_base(double base) {
			if (base > Defaults::primary_size_max)base = Defaults::primary_size_max;
			if (base < Defaults::primary_size_min)base = Defaults::primary_size_min;
			this->base = base;
		}
		void set_side(double side) {
			if (side > Defaults::primary_size_max)side = Defaults::primary_size_max;
			if (side < Defaults::primary_size_min)side = Defaults::primary_size_min;
			this->side = side;
		}

		Isosceles_Triangle(double base,double side, SHAPE_TAKE_PARAMETRES) :Triangle(SHAPE_GIVE_PARAMETRES) {
			set_base(base);
			set_side(side);
		}
		~Isosceles_Triangle() {}

		double get_height()const	{	return sqrt(pow(side, 2) - pow(base/2, 2));}
		double get_area()const		{	return side * side / 2;}
		double get_perimeter()const {	return side * 2+base;}


		void draw()const {
			//1)Получаем окно консоли
			HWND hConsole = GetConsoleWindow();
			//2)Получаем контекст устройства для нашего окна консоли.
			HDC hdc = GetDC(hConsole);//то на чём будем рисовать
			//3)создаём карандаш
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
			//PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселов, RGB(...) - цвет.
			HBRUSH hBrush = CreateSolidBrush(filled ? color : Color::black);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//HBRUSH hBrush = CreateSolidBrush(color);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//Кисть и карандаш выбираются для того, чтобы функция Rectangle понимала чем рисовать
			//выбираем чем и на чём будем рисовать
			SelectObject(hdc, hPen);//Выбираем созданный карандаш, чтобы им можно было рисовать.
			SelectObject(hdc, hBrush);//Выбираем созданную кисть.
			//когда мы выбрали кем и на чём рисовать. Рисуем фигуру
			POINT point[] = {
				{start_x,start_y + get_height() },
				{start_x + base,start_y + get_height()},
				{start_x + base / 2,start_y}
			};
			
			::Polygon(hdc, point, 3);//Рисует квадрат
			//Удаляем созданную кисть и карандаш:
			DeleteObject(hBrush);
			DeleteObject(hPen);
			//Освобождаем контекст устройства:
			ReleaseDC(hConsole, hdc);
		}
		virtual void info()const
		{
			cout << "Площадь треугольника:\t" << get_area() << endl;
			cout << "Периметр треугольника:\t" << get_perimeter() << endl;
			Shape::info();
			draw();
		}
	};



	/*Right

    scalene*/

	;class Paralelogramm :public Rectangle {
		int angle;
	public:
		double get_angle()const { return angle; }
		void set_angle(double angle) {
			if (angle > Defaults::primary_angle_max)angle = Defaults::primary_angle_max;
			if (angle < Defaults::primary_angle_min)angle = Defaults::primary_angle_min;
			this->angle = angle;
		}
		

		Paralelogramm(int angle, SHAPE_TAKE_PARAMETRES) :Rectangle(SHAPE_GIVE_PARAMETRES) {
			set_angle(angle);
		}
		~Paralelogramm() {}
		double D;
		double get_diagonal()const	{	return sqrt(((width * width) + (height * height)) - (2 * (width * height)) * cos(angle));
		}
		/*double get_height()const	{	return sqrt(pow(side, 2) - pow(base/2, 2));}
		double get_area()const		{	return side * side / 2;}
		double get_perimeter()const {	return side * 2+base;}*/


		void draw()const {
			//1)Получаем окно консоли
			HWND hConsole = GetConsoleWindow();
			//2)Получаем контекст устройства для нашего окна консоли.
			HDC hdc = GetDC(hConsole);//то на чём будем рисовать
			//3)создаём карандаш
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
			//PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселов, RGB(...) - цвет.
			HBRUSH hBrush = CreateSolidBrush(filled ? color : Color::black);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//HBRUSH hBrush = CreateSolidBrush(color);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
			//Кисть и карандаш выбираются для того, чтобы функция Rectangle понимала чем рисовать
			//выбираем чем и на чём будем рисовать
			SelectObject(hdc, hPen);//Выбираем созданный карандаш, чтобы им можно было рисовать.
			SelectObject(hdc, hBrush);//Выбираем созданную кисть.
			//когда мы выбрали кем и на чём рисовать. Рисуем фигуру
			POINT point[] = {
				{start_x,start_y + get_height() },
				{start_x + angle,start_y + get_height()},
				{start_x + angle / 2,start_y}
			};
			
			::Polygon(hdc, point, 3);//Рисует квадрат
			//Удаляем созданную кисть и карандаш:
			DeleteObject(hBrush);
			DeleteObject(hPen);
			//Освобождаем контекст устройства:
			ReleaseDC(hConsole, hdc);
		}
		virtual void info()const
		{
			cout << "Площадь треугольника:\t" << get_area() << endl;
			cout << "Периметр треугольника:\t" << get_perimeter() << endl;
			Shape::info();
			draw();
		}
	};

}
int main() {
	setlocale(LC_ALL, "Russian");
	//Shape shape(Color::console_blue, 0, 0, 1);
	//Geometry::Square square(5, Geometry::Color::console_yelow, 100, 100, 3);
	//square.info();
	/*cout <<"Длинна стороны: " << square.get_side() << endl;
	cout <<"Площадь квадрата: " << square.get_area() << endl;
	cout <<"Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();*/

	Geometry::Rectangle rect (100, 70, Geometry::Color::blue, 400, 400, 2,false);
	rect.info();

	/*Geometry::Square square( 40, Geometry::Color::green, 0, 500, 3,false);
	square.info();*/
	/*Geometry::Circle circle(147, Geometry::Color::red, 700, 250, 1,false);
	circle.info();*/
	/*Geometry::Equilaterial_Triangle triangl(300, Geometry::Color::yellow, 400, 700, 4,false);
	triangl.info();*/
	Geometry::Isosceles_Triangle is_triangl(100,300, Geometry::Color::blue, 400, 700, 2,false);
	is_triangl.info();





	char r;cin >> r;
	return 1;
}