#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

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

        virtual double perimeter(){
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
    

    class ShapeContainer {
    private:
        vector<Shape*> shapes;
    public:
        void add(Shape* shape) {
            shapes.push_back(shape);
        }

        void displayAll() const {
            for (const auto& shape : shapes) {
                cout << shape->getName() << " area: " << shape->area()  <<"\n";
                cout << shape->getName() << " perimeter: " << shape->perimeter() <<"\n";
            }
        }

        double totalArea() const {
            double total = 0;
            for (const auto& shape : shapes) {
                total += shape->area();
            }
            return total;
        }

        vector<Shape*> getGreaterThan(double area) {
            vector<Shape*> result;
            for (const auto& shape : shapes) {
                if (shape->area() > area) {
                    result.push_back(shape);
                }
            }
            return result;
        }

        ~ShapeContainer() {
            for (auto& shape : shapes) {
                delete shape;
                shape = nullptr;
            }
        }
    };
    
    class Square : public Shape {
    private:
        double side;
    public:
        Square(string name, double side) : Shape(name), side(side) {}

        double area() override {
            return side * side;
        }

        double perimeter() override {
            return 4 * side;
        }
    };

    class Rectangle : public Shape {
    private:
        double a, b;
    public:
        Rectangle(string name, double a, double b) : Shape(name), a(a), b(b) {}

        double area() override {
            return a * b;
        }

        double perimeter() override {
            return 2 * a + 2 * b;
        }
    };

    class Circle : public Shape {
    private:
        double radius;
    public:
        Circle(string name, double radius) : Shape(name), radius(radius) {}

        double area() override {
            return M_PI * radius * radius;
        }

        double perimeter() override {
            return 2 * M_PI * radius;
        }
    };

    class Ellipse : public Shape {
    private:
        double a, b;
    public:
        Ellipse(string name, double a, double b) : Shape(name), a(a), b(b) {}

        double area() override {
            return M_PI * a * b;
        }

        double perimeter() override {
            return M_PI * (1.5 * (a + b) - sqrt(a * b));
        }
    };
    ShapeContainer container;
    Square* square = new Square("Square 1", 5.0);
    Rectangle* rectangle = new Rectangle("Rectangle 1", 4.0, 3.0);
    Circle* circle = new Circle("Circle 1", 3.0);
    Ellipse* ellipse = new Ellipse("Ellipse 1", 4.0, 2.0);
    
    container.add(square);
    container.add(rectangle);
    container.add(circle);
    container.add(ellipse);
    
    cout << container.totalArea() << "/n";
    container.displayAll();
}

void zad2() {
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

    class NumericalAlgorithm {
    protected:
        Function* function;
        double epsilon;
    public:
        NumericalAlgorithm(Function* function, double epsilon = 0.01) : function(function), epsilon(epsilon) {}

        void setEpsilon(double epsilon) {
            this->epsilon = epsilon;
        }

        virtual double calculate() = 0;
    };

    class ZeroOfFunction : public NumericalAlgorithm {
    private:
        double a;
        double b;
    public:
        ZeroOfFunction(Function* function) : NumericalAlgorithm(function), a(-1.0), b(1.0) {}

        void setRange(double a, double b) {
            this->a = a;
            this->b = b;
        }

        double calculate() override {
            double c = a;
            while ((b-a) >= epsilon) {
                c = (a+b)/2;
                if (function->calculate(c) == 0.0)
                    break;
                else if (function->calculate(c) * function->calculate(a) < 0)
                    b = c;
                else
                    a = c;
            }
            return c;
        }
    };

    class Derivative : public NumericalAlgorithm {
    private:
        double x;
    public:
        Derivative(Function* function) : NumericalAlgorithm(function), x(0.0) {}

        void setX(double x) {
            this->x = x;
        }

        double calculate() override {
            double h = epsilon;
            return (function->calculate(x + h) - function->calculate(x - h)) / (2.0 * h);
        }   
    };
    Derivative test (new LinearFunction(12, 5));
    cout << test.calculate() << endl;
}

void zad4() {
    class no_real_solution : public std::runtime_error {
    public:
        no_real_solution(const string& message) : runtime_error(message) {}
    };
    struct BinomialSolver {
		double a, b, c;
		BinomialSolver(double a, double b, double c) : a(a), b(b), c(c), x1(0), x2(0) {
			solve();
		}

		double getDelta() {
			return b * b - 4 * a * c;
		}

		double x1, x2;
		void solve() {
			double delta = getDelta();
			if (delta > 0) {
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
			}
			else if (delta == 0) {
				x1 = -b / (2 * a);
                cout << "Istnieje jedno miejsce zerowe: " << x1 << "\n";
			}
			else {
				x1 = x2 = 0;
				throw no_real_solution("No real solution");
			}
		}

		double calculate(double x) {
			return a * x * x + b * x + c;
		}

		double getA() const {
			return a;
		}
		double getB() const {
			return b;
		}
		double getC() const {
			return c;
		}
		double getX1() const {
			return x1;
		}
		double getX2() const {
			return x2;
		}
	};

    try {
        BinomialSolver b1(1.0, -5.0, 4.0);
        cout << "Roots of the equation x*x - 5x + 4 = 0 are: " << endl;
        cout << "x1 = " << b1.getX1() << ", x2 = " << b1.getX2() << endl;
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }
    
    try {
        BinomialSolver b2(1.0, 2.0, 1.0);
        cout << "Roots of the equation x*x + 2x + 1 = 0 are: " << endl;
        cout << "x1 = " << b2.getX1() << ", x2 = " << b2.getX2() << endl;
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }
    
    try {
        BinomialSolver b3(6.0, 3.0, 9.0);
        cout << "Roots of the equation 6x*x + 3x + 9 = 0 are: " << endl;
        cout << "x1 = " << b3.getX1() << ", x2 = " << b3.getX2() << endl;
    } catch (const no_real_solution& e) {
        cout << e.what() << '\n';
    }

    try {
        BinomialSolver b4(3.0, 2.0, 10.0);
        cout << "Roots of the equation 6x*x + 3x + 9 = 0 are: " << endl;
        cout << "x1 = " << b4.getX1() << ", x2 = " << b4.getX2() << endl;
    } catch (const no_real_solution& e) {
        cout << e.what() << '\n';
    }
}

void zad6() {
    class Matrices {
    public:
        Matrices(int height, int width) : height(height), width(width) {
            matrix = new int*[height];
            for (int i = 0; i < height; ++i) {
                matrix[i] = new int[width];
            }
        }

        Matrices(const Matrices& m) : Matrices(m.height, m.width) {
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    matrix[i][j] = m.matrix[i][j];
                }
            }
        }

        Matrices(Matrices&& m) : height(m.height), width(m.width), matrix(m.matrix) {
            m.height = 0;
            m.width = 0;
            m.matrix = nullptr;
        }

        ~Matrices() {
            for (int i = 0; i < height; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        Matrices transpose_Matrix() {
            Matrices transposed(width, height);
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    transposed.matrix[j][i] = matrix[i][j];
                }
            }
            return transposed;
        }

        void multiply_Matrix(int scalar) {
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    matrix[i][j] *= scalar;
                }
            }
        }

        void print_Matrix() {
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        void fill_Matrix() {
            srand(time(0));
            for (int i = 0; i < height; ++i) {
                for (int j = 0; j < width; ++j) {
                    matrix[i][j] = rand() % 100;
                }
            }   
        }
        

    private:
        int height, width;
        int** matrix;
    };
    Matrices mtrx1(3, 3);
    mtrx1.fill_Matrix();
    mtrx1.print_Matrix();
    mtrx1.transpose_Matrix().print_Matrix();
    mtrx1.multiply_Matrix(2);
    mtrx1.print_Matrix();
    Matrices mtrx2 = mtrx1;
    Matrices mtrx3 = move(mtrx1);
    mtrx1.print_Matrix(); //pusta po przeniesieniu
    mtrx2.print_Matrix();
    mtrx3.print_Matrix();
}
    

int main() {
    do {
        int task;
        cout << "Wybierz zadanie [1,2,4,6]: ";
        cin >> task;
        switch (task)
        {
        case 1:
            cout << "Zadanie 1" << endl;
            zad1();
            break;
        case 2:
            cout << "Zadanie 2" << endl;
            zad2();
            break;
        case 4:
            cout << "Zadanie 4" << endl;
            zad4();
            break;
        case 6:
            cout << "Zadanie 6" << endl;
            zad6();
            break;
        default:
            cout << "Nie ma takiego zadania" << endl;
            break;
        }
    } while (true);
    return 0;
}