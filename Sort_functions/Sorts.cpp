#include <iostream>
#include <string>
#include <random>

template <typename T>  // Объявление шаблонной функции с одним параметром - типом T
void bubble_sort(T* arr, int size) {  
	for (size_t i = 0; i < size - 1; ++i) {  // Цикл для прохода по массиву arr
		for (size_t j = 0; j < size - i - 1; ++j) {  // Вложенный цикл для сравнения пар элементов массива
			if (arr[j] > arr[j + 1]) {  // Проверка, если текущий элемент больше следующего элемента
				std::swap(arr[j], arr[j + 1]);  // Обмен местами элементов с использованием функции swap из стандартной библиотеки
			}
		}
	}
}

template <typename T>  // Объявление шаблонной функции с одним параметром - типом T
void insertion_sort(T* arr, int size) {  
	for (int i = 1; i < size; ++i) {  // Цикл для прохода по элементам массива arr, начиная со второго элемента
		T k = arr[i];  // Сохранение текущего элемента массива в переменную k
		int j = i - 1;  // Инициализация переменной j со значением i - 1
		while (j >= 0 && arr[j] > k) {  // Цикл while, продолжающийся, пока не достигнут начало массива и текущий элемент больше k
			arr[j + 1] = arr[j];  // Сдвиг всех больших элементов вправо
			j = j - 1;  // Уменьшение значения j
		}
		arr[j + 1] = k;  // Вставка k в правильную позицию в отсортированной части массива
	}
}


int getRandom(int min, int maxx) {  
	static std::random_device rd;  // Создание статического объекта random_device
	static std::mt19937 gen(rd());  // Создание статического объекта mt19937 и инициализация с использованием random_device
	std::uniform_int_distribution<int> distribution(min, maxx);  // Создание равномерного распределения в указанном диапазоне
	return distribution(gen);  // Возврат случайного числа из заданного диапазона
}

template <typename T> // Объявление шаблонной функции с одним параметром - типом T
void quick_sort(T* arr, int min, int maxx) {  
	if (min < maxx) {  // Проверка наличия элементов для сортировки
		int randomIndex = getRandom(min, maxx);  // Получение случайного индекса элемента для использования в качестве опорного
		T pivot = arr[randomIndex];  // Определение опорного элемента
		int i = min, j = maxx;  // Инициализация переменных для разделения массива
		while (i <= j) {  // Цикл разделения массива
			while (arr[i] < pivot) i++;  // Поиск элемента больше опорного слева
			while (arr[j] > pivot) j--;  // Поиск элемента меньше опорного справа
			if (i <= j) {  // Если индексы не пересеклись
				std::swap(arr[i], arr[j]);  // Меняем местами элементы
				i++;  // Увеличиваем левый индекс
				j--;  // Уменьшаем правый индекс
			}
		}
		quick_sort(arr, min, j);  // Рекурсивный вызов для левого подмассива
		quick_sort(arr, i, maxx);  // Рекурсивный вызов для правого подмассива
	}
}


template <typename T> // Объявление шаблонной функции с одним параметром - типом T
void print_array(T* arr, int size) {  
	std::cout << "Sorted array = " << "[ ";  // Вывод начала сообщения
	for (int i = 0; i < size; i++) {  // Цикл для прохода по массиву
		if (i != size - 1) {  // Проверка, не последний ли элемент
			std::cout << arr[i] << ", ";  // вывод элемента массива с запятой, если это не последний элемент
		}
		else {
			std::cout << arr[i] << " ";  // вывод последнего элемента без запятой
		}
	}
	std::cout << "]" << std::endl;  // Вывод завершающей части сообщения
}

template <typename T> // Объявление шаблонной функции с одним параметром - типом T
void fill_in_the_array(T* arr, int size, std::string type) {  
	std::cout << "Enter " << size << " " << type << "s: " << std::endl;  // Вывод сообщения с запросом на ввод size элементов типа type
	for (int i = 0; i < size; ++i) {  // Цикл для ввода size элементов в массив
		std::cin >> arr[i];  // Ввод элемента массива
	}
}


int main() {  // Основная функция программы
	std::string choise;  // Объявление переменной для выбора продолжения выполнения программы
	while (choise != "no") {  // Цикл для выполнения программы пока пользователь не введет "no"
		int size;  // Объявление переменной для размера массива
		std::string type, sort;  // Объявление переменных для типа элементов и выбора метода сортировки

		std::cout << "Enter the size of the array: ";  // Вывод сообщения о вводе размера массива
		while (!(std::cin >> size)) {
			std::cin.clear();  // Сбрасываем флаг ошибки ввода
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Очищаем буфер ввода
			std::cout << std::endl << "Mistake! Please enter an integer." << std::endl; // Сообщаем пользователю об ошибке
			std::cout << std::endl << "Enter the size of the array: ";  // Вывод сообщения о вводе размера массива
		}

		std::cout << "Enter the type of the elements (int, double, char, string): ";  // Вывод сообщения о выборе типа элементов
		std::cin >> type;  // Ввод типа элементов
		if (type != "int" && type != "double" && type != "char" && type != "string") { // Если пользователь ввел неподходящие слова
			do {
				std::cout << "Mistake! Try again."; // Сообщить пользователю об ошибке и предложить попробовать снова
				std::cout << "Enter the type of the elements (int, double, char, string): ";  // Вывод сообщения о выборе типа элементов
				std::cin >> type;  // Ввод типа элементов
				std::cout << std::endl << std::endl; // Вывод пустых строк для разделения итераций цикла
			} while (type != "int" && type != "double" && type != "char" && type != "string"); // Пока пользователь не введет нужное слово
		}

		std::cout << "Enter the sorting (bubble, insertion, quick): ";  // Вывод сообщения о выборе метода сортировки
		std::cin >> sort;  // Ввод выбора метода сортировки
		if (sort != "bubble" && sort != "insertion" && sort != "quick") { // Если пользователь ввел неподходящие слова
			do {
				std::cout << "Mistake! Try again."; // Сообщить пользователю об ошибке и предложить попробовать снова
				std::cout << "Enter the sorting (bubble, insertion, quick): ";  // Вывод сообщения о выборе метода сортировки
				std::cin >> sort;  // Ввод выбора метода сортировки
				std::cout << std::endl << std::endl; // Вывод пустых строк для разделения итераций цикла
			} while (sort != "bubble" && sort != "insertion" && sort != "quick"); // Пока пользователь не введет нужное слово
		}

		if (type == "int") {  // Если тип элементов - целые числа
			int* intArr = new int[size];  // Выделение памяти под массив целых чисел
			fill_in_the_array(intArr, size, type);  // Заполнение массива введенными данными
			if (sort == "bubble") bubble_sort(intArr, size);  // Если выбран метод пузырьковой сортировки
			else if (sort == "insertion") insertion_sort(intArr, size);  // Если выбран метод сортировки вставками
			else if (sort == "quick") quick_sort(intArr, 0, size - 1);  // Если выбран метод быстрой сортировки
			else {
				std::cout << "There is no such sorting. Try again!" << std::endl << std::endl;  // Вывод сообщения об ошибке выбора сортировки
				continue;  // Переход на следующую итерацию цикла
			}
			print_array(intArr, size);  // Вывод отсортированного массива
			delete[] intArr;  // Очистка памяти, выделенной для массива
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
		std::cout << std::endl << std::endl << "Do you want to continue? (yes or no): ";  // Запрос на продолжение выполнения программы
		std::cin >> choise;  // Ввод выбора продолжения
		std::cout << std::endl << std::endl;  // Вывод пустых строк для разделения итераций цикла
		if (choise != "yes" && choise != "no") { // Если пользователь ввел неподходящие слова
			do {
				std::cout << "Mistake! Try again." << std::endl; // Сообщить пользователю об ошибке и предложить попробовать снова
				std::cout << std::endl << std::endl << "Do you want to continue? (yes or no): "; // Запрос на продолжение выполнения программы
				std::cin >> choise;  // Ввод выбора продолжения
				std::cout << std::endl << std::endl; // Вывод пустых строк для разделения итераций цикла
			} while (choise != "yes" && choise != "no"); // Пока пользователь не введет нужное слово
		}
	}

	return 0;
}
