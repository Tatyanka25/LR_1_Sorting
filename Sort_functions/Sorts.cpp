#include <iostream>
#include <string>
#include <random>

template <typename T>  // ���������� ��������� ������� � ����� ���������� - ����� T
void bubble_sort(T* arr, int size) {  
	for (size_t i = 0; i < size - 1; ++i) {  // ���� ��� ������� �� ������� arr
		for (size_t j = 0; j < size - i - 1; ++j) {  // ��������� ���� ��� ��������� ��� ��������� �������
			if (arr[j] > arr[j + 1]) {  // ��������, ���� ������� ������� ������ ���������� ��������
				std::swap(arr[j], arr[j + 1]);  // ����� ������� ��������� � �������������� ������� swap �� ����������� ����������
			}
		}
	}
}

template <typename T>  // ���������� ��������� ������� � ����� ���������� - ����� T
void insertion_sort(T* arr, int size) {  
	for (int i = 1; i < size; ++i) {  // ���� ��� ������� �� ��������� ������� arr, ������� �� ������� ��������
		T key = arr[i];  // ���������� �������� �������� ������� � ���������� key
		int j = i - 1;  // ������������� ���������� j �� ��������� i - 1
		while (j >= 0 && arr[j] > key) {  // ���� while, ��������������, ���� �� ��������� ������ ������� � ������� ������� ������ key
			arr[j + 1] = arr[j];  // ����� ���� ������� ��������� ������
			j = j - 1;  // ���������� �������� j
		}
		arr[j + 1] = key;  // ������� key � ���������� ������� � ��������������� ����� �������
	}
}


int getRandom(int min, int maxx) {  
	static std::random_device rd;  // �������� ������������ ������� random_device
	static std::mt19937 gen(rd());  // �������� ������������ ������� mt19937 � ������������� � �������������� random_device
	std::uniform_int_distribution<int> distribution(min, maxx);  // �������� ������������ ������������� � ��������� ���������
	return distribution(gen);  // ������� ���������� ����� �� ��������� ���������
}

template <typename T> // ���������� ��������� ������� � ����� ���������� - ����� T
void quick_sort(T* arr, int min, int maxx) {  
	if (min < maxx) {  // �������� ������� ��������� ��� ����������
		int randomIndex = getRandom(min, maxx);  // ��������� ���������� ������� �������� ��� ������������� � �������� ��������
		T pivot = arr[randomIndex];  // ����������� �������� ��������
		int i = min, j = maxx;  // ������������� ���������� ��� ���������� �������
		while (i <= j) {  // ���� ���������� �������
			while (arr[i] < pivot) i++;  // ����� �������� ������ �������� �����
			while (arr[j] > pivot) j--;  // ����� �������� ������ �������� ������
			if (i <= j) {  // ���� ������� �� �����������
				std::swap(arr[i], arr[j]);  // ������ ������� ��������
				i++;  // ����������� ����� ������
				j--;  // ��������� ������ ������
			}
		}
		quick_sort(arr, min, j);  // ����������� ����� ��� ������ ����������
		quick_sort(arr, i, maxx);  // ����������� ����� ��� ������� ����������
	}
}


template <typename T> // ���������� ��������� ������� � ����� ���������� - ����� T
void print_array(T* arr, int size) {  
	std::cout << "Sorted array = " << "[ ";  // ����� ������ ���������
	for (int i = 0; i < size; i++) {  // ���� ��� ������� �� �������
		if (i != size - 1) {  // ��������, �� ��������� �� �������
			std::cout << arr[i] << ", ";  // ����� �������� ������� � �������, ���� ��� �� ��������� �������
		}
		else {
			std::cout << arr[i] << " ";  // ����� ���������� �������� ��� �������
		}
	}
	std::cout << "]" << std::endl;  // ����� ����������� ����� ���������
}

template <typename T> // ���������� ��������� ������� � ����� ���������� - ����� T
void fill_in_the_array(T* arr, int size, std::string type) {  
	std::cout << "Enter " << size << " " << type << "s: " << std::endl;  // ����� ��������� � �������� �� ���� size ��������� ���� type
	for (int i = 0; i < size; ++i) {  // ���� ��� ����� size ��������� � ������
		std::cin >> arr[i];  // ���� �������� �������
	}
}


int main() {  // �������� ������� ���������
	std::string choise;  // ���������� ���������� ��� ������ ����������� ���������� ���������
	while (choise != "no") {  // ���� ��� ���������� ��������� ���� ������������ �� ������ "no"
		int size;  // ���������� ���������� ��� ������� �������
		std::string type, sort;  // ���������� ���������� ��� ���� ��������� � ������ ������ ����������

		std::cout << "Enter the size of the array: ";  // ����� ��������� � ����� ������� �������
		while (!(std::cin >> size)) {
			std::cin.clear();  // ���������� ���� ������ �����
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ������� ����� �����
			std::cout << std::endl << "Mistake! Please enter an integer." << std::endl; // �������� ������������ �� ������
			std::cout << std::endl << "Enter the size of the array: ";  // ����� ��������� � ����� ������� �������
		}

		std::cout << "Enter the type of the elements (int, double, char, string): ";  // ����� ��������� � ������ ���� ���������
		std::cin >> type;  // ���� ���� ���������
		if (type != "int" && type != "double" && type != "char" && type != "string") { // ���� ������������ ���� ������������ �����
			do {
				std::cout << "Mistake! Try again."; // �������� ������������ �� ������ � ���������� ����������� �����
				std::cout << "Enter the type of the elements (int, double, char, string): ";  // ����� ��������� � ������ ���� ���������
				std::cin >> type;  // ���� ���� ���������
				std::cout << std::endl << std::endl; // ����� ������ ����� ��� ���������� �������� �����
			} while (type != "int" && type != "double" && type != "char" && type != "string"); // ���� ������������ �� ������ ������ �����
		}

		std::cout << "Enter the sorting (bubble, insertion, quick): ";  // ����� ��������� � ������ ������ ����������
		std::cin >> sort;  // ���� ������ ������ ����������
		if (sort != "bubble" && sort != "insertion" && sort != "quick") { // ���� ������������ ���� ������������ �����
			do {
				std::cout << "Mistake! Try again."; // �������� ������������ �� ������ � ���������� ����������� �����
				std::cout << "Enter the sorting (bubble, insertion, quick): ";  // ����� ��������� � ������ ������ ����������
				std::cin >> sort;  // ���� ������ ������ ����������
				std::cout << std::endl << std::endl; // ����� ������ ����� ��� ���������� �������� �����
			} while (sort != "bubble" && sort != "insertion" && sort != "quick"); // ���� ������������ �� ������ ������ �����
		}

		if (type == "int") {  // ���� ��� ��������� - ����� �����
			int* intArr = new int[size];  // ��������� ������ ��� ������ ����� �����
			fill_in_the_array(intArr, size, type);  // ���������� ������� ���������� �������
			if (sort == "bubble") bubble_sort(intArr, size);  // ���� ������ ����� ����������� ����������
			else if (sort == "insertion") insertion_sort(intArr, size);  // ���� ������ ����� ���������� ���������
			else if (sort == "quick") quick_sort(intArr, 0, size - 1);  // ���� ������ ����� ������� ����������
			else {
				std::cout << "There is no such sorting. Try again!" << std::endl << std::endl;  // ����� ��������� �� ������ ������ ����������
				continue;  // ������� �� ��������� �������� �����
			}
			print_array(intArr, size);  // ����� ���������������� �������
			delete[] intArr;  // ������� ������, ���������� ��� �������
		}
		else if (type == "double") {
			double* doubleArr = new double[size];
			fill_in_the_array(doubleArr, size, type);
			if (sort == "bubble") bubble_sort(doubleArr, size);
			else if (sort == "insertion") insertion_sort(doubleArr, size);
			else if (sort == "quick") {
				quick_sort(doubleArr, 0, size - 1);
			}
			else {
				std::cout << "There is no such sorting. Try again!" << std::endl << std::endl;
				continue;
			}
			print_array(doubleArr, size);
			delete[] doubleArr;
		}
		else if (type == "string") {
			std::string* stringArr = new std::string[size];
			fill_in_the_array(stringArr, size, type);
			if (sort == "bubble") bubble_sort(stringArr, size);
			else if (sort == "insertion") insertion_sort(stringArr, size);
			else if (sort == "quick") quick_sort(stringArr, 0, size - 1);
			else {
				std::cout << "There is no such sorting. Try again!" << std::endl << std::endl;;
				continue;
			}
			print_array(stringArr, size);
			delete[] stringArr;
		}
		else if (type == "char") {
			char* charArr = new char[size];
			fill_in_the_array(charArr, size, type);
			if (sort == "bubble") bubble_sort(charArr, size);
			else if (sort == "insertion") insertion_sort(charArr, size);
			else if (sort == "quick") quick_sort(charArr, 0, size - 1);
			else {
				std::cout << "There is no such sorting. Try again!" << std::endl << std::endl;
				continue;
			}
			print_array(charArr, size);
			delete[] charArr;
		}
		else {
			std::cout << "Invalid type";
		}
		std::cout << std::endl << std::endl << "Do you want to continue? (yes or no): ";  // ������ �� ����������� ���������� ���������
		std::cin >> choise;  // ���� ������ �����������
		std::cout << std::endl << std::endl;  // ����� ������ ����� ��� ���������� �������� �����
		if (choise != "yes" && choise != "no") { // ���� ������������ ���� ������������ �����
			do {
				std::cout << "Mistake! Try again." << std::endl; // �������� ������������ �� ������ � ���������� ����������� �����
				std::cout << std::endl << std::endl << "Do you want to continue? (yes or no): "; // ������ �� ����������� ���������� ���������
				std::cin >> choise;  // ���� ������ �����������
				std::cout << std::endl << std::endl; // ����� ������ ����� ��� ���������� �������� �����
			} while (choise != "yes" && choise != "no"); // ���� ������������ �� ������ ������ �����
		}
	}

	return 0;
}