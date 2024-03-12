#include <iostream>
#include <string>


using namespace std;

void zad1() {
    class Shape {
    public:
        Shape(string name) : name(name) {
            cout << "Shape constructor called\n";
        }

        virtual ~Shape() {
            cout << "Shape destructor called\n";
        }

        virtual double area(){
            return 0;
        }

        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }
    protected:
        string name;
    };
    class Rectangle : public Shape {
    public:
        Rectangle(string name, double width, double height) : Shape(name), width(width), height(height) {
            cout << "Rectangle constructor called\n";
        }
        ~Rectangle() {
            cout << "Rectangle destructor called\n";
        }
        double area() override {
            return width * height;
        }
    protected:
        double width, height;
            
    };
    class Square : protected Rectangle {
    public:
        Square(string name, double width) : Rectangle(name, width, width) {
            cout << "Square constructor called\n";
        }
        ~Square() {
            cout << "Square destructor called\n";
        }
        double area() override {
            return width * width;
        }
    };
    Rectangle rectangle("Rectangle", 5.0, 4.0);
    Square square("Square", 3.0);

    cout << "Rectangle area: " << rectangle.area() << endl;
    cout << "Square area: " << square.area() << endl;

    Shape& ref1 = rectangle;
    //Shape& ref2 = square;
    cout << "Rectangle casted to Shape area: " << ref1.area() << "\n";
    //cout << "Square casted to Shape area: " << ref2.area() << "\n";

    Shape* ptr1 = &rectangle;
    //Shape* ptr2 = &square;
    cout << "Rectangle casted to Shape area: " << ptr1->area() << "\n";
    //cout << "Square casted to Shape area: " << ptr2->area() << "\n";
    /*
    Konstruktory:
    Shape
    Rectangle
    Shape
    Rectangle
    Square
    */
}	

void zad2() {
    class Shape {
    public:
        Shape(string name) : name(name) {
            cout << "Shape constructor called\n";
        }

        virtual ~Shape() {
            cout << "Shape destructor called\n";
        }

        virtual double area() = 0;

        void setName(string name) {
            this->name = name;
        }
        string getName() {
            return name;
        }
    protected:
        string name;
    };

    class Circle : public Shape {
    public:
        Circle(string name, double radius) : Shape(name), radius(radius) {
            cout << "Circle constructor called\n";
        }
        ~Circle() {
            cout << "Circle destructor called\n";
        }
        double area() override {
            return 3.14 * radius * radius;
        }
    protected:
        double radius;
    };

    class Cylinder : public Circle { 
    public:
        Cylinder(string name, double radius, double height) : Circle(name, radius), height(height) {
            cout << "Cylinder constructor called\n";
        }
        ~Cylinder() {
            cout << "Cylinder destructor called\n";
        }
        double area() override {
            return 2 * 3.14 * radius * (radius + height);
        }
        double volume() {
            return 3.14 * radius * radius * height;
        }
    protected:
        double height;
    };

    Cylinder cylinder("Cylinder", 5.0, 4.0);
}

void zad3() {
    class Function {
    public:
        Function() = default;
        virtual ~Function() = default;
        virtual float calculate(float x) = 0;
    };

    class LinearFunction : public Function {
    public:
        LinearFunction(float a, float b) : a(a), b(b) {}
        float calculate(float x) override {
            return a * x + b;
        }
    private:
        float a, b;
    };

    LinearFunction test(1,5);
    cout << test.calculate(5) << endl;
}

void zad5() {
    class Rim {
    public:
        Rim() : weight(0), width(0), diameter(0) {}
        Rim(float weight, float width, float diameter) : weight(weight), width(width), diameter(diameter) {}

        float getWeight() { return weight; }
        float getWidth() { return width; }
        float getDiameter() { return diameter; }

    private:
        float weight;
        float width;
        float diameter;
    };

    class Tire {
    public:
        Tire() : weight(0), width(0), diameter(0) {}
        Tire(float weight, float width, float diameter) : weight(weight), width(width), diameter(diameter) {}

        float getWeight() { return weight; }
        float getWidth() { return width; }
        float getDiameter() { return diameter; }

    private:
        float weight;
        float width;
        float diameter;
    };

    class Wheel {
    public:
        Wheel() : total_mass(0), rolling_friction(0) {}

        void put_on_Rim(Rim& rim) {
            if (abs(rim.getWidth() - tire.getWidth()) <= 10 && abs(rim.getDiameter() - tire.getDiameter()) <= 10) {
                this->rim = rim;
                total_mass += rim.getWeight();
            } else {
                std::cout << "The rim is not compatible with the tire.\n";
            }
        }

        void mount_Tire(Tire& tire) {
            if (abs(rim.getWidth() - tire.getWidth()) <= 10 && abs(rim.getDiameter() - tire.getDiameter()) <= 10) {
                this->tire = tire;
                total_mass += tire.getWeight();
            } else {
                std::cout << "The tire is not compatible with the rim.\n";
            }
        }

        void calculateRollingFriction(float f, float N) {
            float R = rim.getDiameter() / 2;
            rolling_friction = f * N / R;
        }

        private:
            Rim rim;
            Tire tire;
            float total_mass;
            float rolling_friction;
        };
}
int main()
{
	do {
		int task;
		cout << "Podaj numer zadania: [1, 2, 3, 5] ";
		cin >> task;
		switch (task) {
		case 1:
			cout << "Zadanie 1" << endl;
			zad1();
			break;
		case 2:
			cout << "Zadanie 2" << endl;
			zad2();
			break;
        case 3:
            cout << "Zadanie 3" << endl;
            zad3();
            break;
        case 5:
            cout << "Zadanie 5" << endl;
            zad5();
            break;
		default:
			cout << "Nie ma takiego zadania" << endl;
			break;
		}
	} while (true);
	return 0;
}


