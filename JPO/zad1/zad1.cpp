#include <iostream>
#include <memory>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <ctime>


using namespace std;

void zad1() {
	struct VerboseOBject {
		string name;
		VerboseOBject(string name) : name(name) {
			cout << "VerboseOBject: " << name << " created" << endl;
		}
		~VerboseOBject() {
			cout << "VerboseOBject: " << name << " destroyed" << endl;
		}
		void display() {
			cout << "Display method invoked: " + name << endl;
		}
	};

	VerboseOBject z1("zad1");
	unique_ptr<VerboseOBject> z2 = make_unique<VerboseOBject>("zad2");
	VerboseOBject* z3 = new VerboseOBject("zad3");
	//Obiekty utworza sie w kolejnosci z1, z2, z3, pierwszym zniszczonym obiektem bedzie z2, a potem z1, natomiast obiekt z3 nie zostanie 
	//zniszczony, poniewaz nie uzyto delete
}	

void zad2() {
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
			}
			else {
				x1 = x2 = 0;
				cout << "Brak miejsc zerowych" << endl;
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

	BinomialSolver b1(1.0, -5.0, 4.0);
	cout << "Roots of the equation x*x - 5x + 4 = 0 are: " << endl;
	cout << "x1 = " << b1.getX1() << ", x2 = " << b1.getX2() << endl;
	cout << "The value of the polynomial x*x - 5x + 4 at x = 1 is: ";
	cout << b1.calculate(1.0) << endl;
	cout << "The value of the polynomial x*x - 5x + 4 at x = 3 is: ";
	cout << b1.calculate(3.0) << endl;
	BinomialSolver b2(1.0, 2.0, 1.0);
	cout << "Roots of the equation x*x + 2x + 1 = 0 are: " << endl;
	cout << "x1 = " << b2.getX1() << ", x2 = " << b2.getX2() << endl;
	cout << "The value of the polynomial x*x + 2x + 1 at x = 1 is: ";
	cout << b2.calculate(1.0) << endl;
	cout << "The value of the polynomial x*x + 2x + 1 at x = -1 is: ";
	cout << b2.calculate(-1.0) << endl;
}

void zad3() {
	struct Complex {
		double real;
		double imaginary;

		Complex(double real, double imaginary) {
			this->real = real;
			this->imaginary = imaginary;
		}

		double modulus() {
			return sqrt(real * real + imaginary * imaginary);
		}

		Complex operator+(const Complex& other) {
			return Complex(real + other.real, imaginary + other.imaginary);
		}

		Complex operator*(const Complex& other) {
			return Complex(real * other.real - imaginary * other.imaginary,
				real * other.imaginary + imaginary * other.real);
		}
	};

	Complex sum(0, 0);
	Complex product(1, 0);
	Complex maxNumber(0, 0);

	int n;
	cout << "Podaj ilosc liczb zespolonych: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		double real, imaginary;
		cout << "Podaj czesc rzeczywista liczby zespolonej: ";
		cin >> real;
		cout << "Podaj czesc urojona liczby zespolonej: ";
		cin >> imaginary;
		Complex number(real, imaginary);

		sum = sum + number;
		product = product * number;

		if (number.modulus() > maxNumber.modulus()) {
			maxNumber = number;
		}
	}

	cout << "Suma: " << sum.real << " + " << sum.imaginary << "i" << endl;
	cout << "Iloczyn: " << product.real << " + " << product.imaginary << "i" << endl;
	cout << "Liczba o najwiekszym module: " << maxNumber.real << " + " << maxNumber.imaginary << "i" << " a jej wartosc to: " << maxNumber.modulus() << endl;
}

void zad4() {
	struct BinomialSolver {
		double a, b, c, eps;
		BinomialSolver(double a, double b, double c, double eps) : a(a), b(b), c(c), eps(eps), x1(0), x2(0), max(0) {
			solve();
		}

		double getDelta() {
			return b * b - 4 * a * c;
		}

		double x1, x2, max;
		void solve() {
			double delta = getDelta();
			if (delta > 0) {
				x1 = (-b - sqrt(delta)) / (2 * a);
				x2 = (-b + sqrt(delta)) / (2 * a);
			}
			else if (delta == 0) {
				x1 = -b / (2 * a);
			}
			else {
				x1 = x2 = 0;
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
	double a, b, c, eps;
	cout << "Podaj wartosc a" << endl;
	cin >> a;
	cout << "Podaj wartosc b" << endl;
	cin >> b;
	cout << "Podaj wartosc c" << endl;
	cin >> c;
	cout << "Podaj wartosc eps" << endl;
	cin >> eps;
	eps = -floor(log10(eps));
	BinomialSolver solver(a, b, c, eps);
	cout << setprecision(eps) << (solver.getX1()>solver.getX2() ? solver.getX1() : solver.getX2()) << endl;
}

void zad8() {
	class BSTree {
	private:
		struct Node {
			int value;
			Node* left;
			Node* right;

			Node(int value) {
				this->value = value;
				left = nullptr;
				right = nullptr;
			}
		};

		Node* root;

		void insert(Node* node, int value) {
			if (value < node->value) {
				if (node->left == nullptr) {
					node->left = new Node(value);
				}
				else {
					insert(node->left, value);
				}
			}
			else {
				if (node->right == nullptr) {
					node->right = new Node(value);
				}
				else {
					insert(node->right, value);
				}
			}
		}

		bool contains(Node* node, int value) const {
			if (node == nullptr) {
				return false;
			}
			else if (value == node->value) {
				return true;
			}
			else if (value < node->value) {
				return contains(node->left, value);
			}
			else {
				return contains(node->right, value);
			}
		}

		void clear(Node* node) {
			if (node == nullptr) {
				return;
			}

			clear(node->left);
			clear(node->right);
			delete node;
		}

		void printInOrder(Node* node) const {
			if (node == nullptr) {
				return;
			}

			printInOrder(node->left);
			cout << node->value << " ";
			printInOrder(node->right);
		}

	public:
		BSTree() {
			root = nullptr;
		}

		~BSTree() {
			clear(root);
		}

		bool isEmpty() const {
			return root == nullptr;
		}

		void insert(int value) {
			if (root == nullptr) {
				root = new Node(value);
			}
			else {
				insert(root, value);
			}
		}

		bool contains(int value) const {
			return contains(root, value);
		}

		void clear() {
			clear(root);
			root = nullptr;
		}

		void printInOrder() const {
			printInOrder(root);
			cout << endl;
		}
	};
	BSTree bst;
	cout << (bst.isEmpty() ? "Tree is empty" : "Tree is not empty ") << endl;
	bst.insert(5);
	bst.insert(3);
	bst.insert(7);
	bst.insert(4);
	bst.insert(2);
	cout << (bst.isEmpty() ? " Tree is empty " : "Tree is not empty ") << endl;
	cout << "Tree contains element with the value of 3: " << bst.contains(3) << endl;
	cout << "Tree contains element with the value of 9: " << bst.contains(9) << endl;
	bst.printInOrder();
	bst.clear();
	cout << (bst.isEmpty() ? "Tree is empty " : " Tree is not empty ") << endl;

	//Modyfikatorem const mozemy oznaczyc funkcje contains i printInOrder, poniewaz nie modyfikuja one obiektu klasy BSTree
}

void zad13() {
	class Sorting {
	public:
		static void bubbleSort(float arr[], int n) {
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < n - i - 1; j++) {
					if (arr[j] > arr[j + 1]) {
						swap(arr[j], arr[j + 1]);
					}
				}
			}
		}

		static void heapSort(float arr[], int n) {
			for (int i = n / 2 - 1; i >= 0; i--) {
				heapify(arr, n, i);
			}

			for (int i = n - 1; i > 0; i--) {
				swap(arr[0], arr[i]);
				heapify(arr, i, 0);
			}
		}

		static void heapify(float arr[], int n, int i) {
			int largest = i;
			int l = 2 * i + 1;
			int r = 2 * i + 2;

			if (l < n && arr[l] > arr[largest]) {
				largest = l;
			}

			if (r < n && arr[r] > arr[largest]) {
				largest = r;
			}

			if (largest != i) {
				swap(arr[i], arr[largest]);
				heapify(arr, n, largest);
			}
		}

		static void quickSort(float arr[], int low, int high) {
			if (low < high) {
				int pi = partition(arr, low, high);

				quickSort(arr, low, pi - 1);
				quickSort(arr, pi + 1, high);
			}
		}

		static int partition(float arr[], int low, int high) {
			float pivot = arr[high];
			int i = (low - 1);

			for (int j = low; j <= high - 1; j++) {
				if (arr[j] < pivot) {
					i++;
					swap(arr[i], arr[j]);
				}
			}
			swap(arr[i + 1], arr[high]);
			return (i + 1);
		}

		static double measure(float* Data, int Size, void(*sort)(float[], int)) {
			using chrono::high_resolution_clock;
			using chrono::duration_cast;
			using chrono::duration;
			using chrono::milliseconds;

			auto t1 = high_resolution_clock::now();
			sort(Data, Size);
			auto t2 = high_resolution_clock::now();
			duration<double, milli> ms_double = t2 - t1;

			return ms_double.count();

		}

		static double measure(float* Data, int Size, void(*sort)(float[], int, int)) {
			using chrono::high_resolution_clock;
			using chrono::duration_cast;
			using chrono::duration;
			using chrono::milliseconds;


			auto t1 = high_resolution_clock::now();
			sort(Data, 0, Size - 1);
			auto t2 = high_resolution_clock::now();
			duration<double, milli> ms_double = t2 - t1;

			return ms_double.count();
		}
	};

	const int numArrays = 1000;
	const int arraySize = 300;
	const int valueRange = 1000;

	float data[numArrays][arraySize];
	float data1[numArrays][arraySize];
	float data2[numArrays][arraySize];
	float sum = 0;
	for (int i = 0; i < numArrays; ++i) {
		for (int j = 0; j < arraySize; ++j) {
			float value = rand() % valueRange;
			data[i][j] = value;
			data1[i][j] = value;
			data2[i][j] = value;
		}
	}

	for (int i = 0; i < numArrays; ++i) {
		sum = sum + Sorting::measure(data[i], arraySize, Sorting::bubbleSort);
	}
	cout << "BubbleSort " << sum / numArrays << "ms" << endl;

	sum = 0;
	for (int i = 0; i < numArrays; ++i) {
		sum = sum + Sorting::measure(data1[i], arraySize, Sorting::heapSort);
	}
	cout << "HeapSort " << sum / numArrays << "ms" << endl;


	sum = 0;
	for (int i = 0; i < numArrays; ++i) {
		sum = sum + Sorting::measure(data2[i], arraySize, Sorting::quickSort);
	}
	cout << "QuickSort " << sum / numArrays << "ms" << endl;
	//Wyniki sa zblizone do siebie, ale najbardziej optymalnym algorytmem sortowania jest heapsort, nastepnie bubblesort, a najmniej optymalnym quicksort(w tym przypadku)
}

int main()
{
	do {
		int task;
		cout << "Podaj numer zadania: [1, 2, 3, 4, 8, 13] ";
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
		case 4:
			cout << "Zadanie 4" << endl;
			zad4();
			break;
		case 8:
			cout << "Zadanie 8" << endl;
			zad8();
			break;
		case 13:
			cout << "Zadanie 13" << endl;
			zad13();
			break;
		default:
			cout << "Nie ma takiego zadania" << endl;
			break;
		}
	} while (true);
	return 0;
}


