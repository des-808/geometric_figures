#include<iostream>
#include<Windows.h>
#include <cmath>
#include <WinGDI.h>

#define M_PI       3.14159265358979323846   // pi
using namespace std;
namespace Geometry{
	enum Color {
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,

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
		primary_size_max = 500
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
#define SHAPE_TAKE_PARAMETRES Color color,unsigned int start_x, unsigned int start_y,unsigned int line_width
#define SHAPE_GIVE_PARAMETRES color,start_x, start_y,line_width
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
		bool get_filled()const { return filled; }

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
		void set_filled(bool filled) {
			this->filled = filled;
		}

		//Shape(Color color, unsigned int start_x, unsigned int start_y, unsigned int line_width) :color(color){
		Shape(SHAPE_TAKE_PARAMETRES) :color(color) {
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
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
		double width;
		double height;
		bool filled;
	public:
		double get_width()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		bool get_filled()const
		{
			return filled;
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
		void set_filled(bool filled)
		{
			this->filled = filled;
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
			HBRUSH hBrush = CreateSolidBrush(color);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
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
	bool  get_filled()const{return filled;}
	void set_r(double r){this->r = r;}

	void set_filled(bool filled){this->filled = filled;}
	Circle(double xz, SHAPE_TAKE_PARAMETRES) :Shape(SHAPE_GIVE_PARAMETRES) { this->r = xz; }
	~Circle() {}

	double get_area()const {return 1;}
	//double get_area()const {return r * r;}
	double get_perimeter()const {return 2;}
	//double get_perimeter()const {return (r + r) * 2;}

	void draw()const{
		//1)Получаем окно консоли
		HWND hConsole = GetConsoleWindow();
		//2)Получаем контекст устройства для нашего окна консоли.
		HDC hdc = GetDC(hConsole);//то на чём будем рисовать
		//3)создаём карандаш
		HPEN hPen = CreatePen(PS_SOLID, line_width, color);//Карандаш рисует контур фигуры
		//PS_SOLID - сплошная линия, 5 - толщина линии 5 пикселов, RGB(...) - цвет.
		HBRUSH hBrush = CreateSolidBrush(color);//Создаем кисть. Кисть закрашивает замкнутые фигуры.
		//Кисть и карандаш выбираются для того, чтобы функция Rectangle понимала чем рисовать

		//выбираем чем и на чём будем рисовать
		SelectObject(hdc, hPen);//Выбираем созданный карандаш, чтобы им можно было рисовать.
		SelectObject(hdc, hBrush);//Выбираем созданную кисть.
		//когда мы выбрали кем и на чём рисовать. Рисуем фигуру

		//temp_shape.right = y1 + (x2 - x1);
		//Ellipse(backbuffDC, temp_shape.left, temp_shape.top, temp_shape.right, temp_shape.bottom);
		
		//(start_y + (start_x - r));
		::Ellipse(hdc, 499,499, 500, 500);//Рисует квадрат
		//::Ellipse(hdc,start_x,start_y, start_x + (start_y-120),start_y+(start_x-120));//Рисует квадрат
		//::Ellipse(hdc, start_x, start_y, start_x + 100, start_y+100);//Рисует квадрат
		//::Ellipse(hdc, start_x, start_y, start_x + 5, start_y+5);//Рисует квадрат

		//Удаляем созданную кисть и карандаш:
		DeleteObject(hBrush);
		DeleteObject(hPen);
		//Освобождаем контекст устройства:
		ReleaseDC(hConsole, hdc);
	}
	virtual void info()const
	{
		//cout << "Площадь фигуры:\t" << get_area() << endl;
		//cout << "Периметр фигуры:\t" << get_perimeter() << endl;
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

	Geometry::Rectangle rect (100, 70, Geometry::Color::blue, 500, 300, 5);
	rect.info();

	Geometry::Square square( 40, Geometry::Color::green, 0, 400, 5);
	square.info();


	Geometry::Circle circle( 1200.0, Geometry::Color::red, 400, 400, 5);
	circle.info();



	return 1;
}