#include <iostream>
#include <string>

class Car {
protected:
    std::string brand;
    int num_cylinders;
    double power;

public:
    Car(std::string brand, int num_cylinders, double power) 
        : brand(brand), num_cylinders(num_cylinders), power(power) {}

    void reassignPower(double new_power) {
        power = new_power;
    }

    void changePower(double power_change) {
        power += power_change;
    }

    void reassignBrand(std::string new_brand) {
        brand = new_brand;
    }

    void displayInfo() {
        std::cout << "Car Brand: " << brand << std::endl;
        std::cout << "Number of Cylinders: " << num_cylinders << std::endl;
        std::cout << "Power: " << power << " HP" << std::endl;
    }
};

class Lorry : public Car {
private:
    double cargo_capacity;

public:
    Lorry(std::string brand, int num_cylinders, double power, double cargo_capacity) 
        : Car(brand, num_cylinders, power), cargo_capacity(cargo_capacity) {}

    void changeCargoCapacity(double new_capacity) {
        cargo_capacity = new_capacity;
    }

    void displayInfo() {
        std::cout << "Lorry Brand: " << brand << std::endl;
        std::cout << "Number of Cylinders: " << num_cylinders << std::endl;
        std::cout << "Power: " << power << " HP" << std::endl;
        std::cout << "Cargo Capacity: " << cargo_capacity << " kg" << std::endl;
    }
};

int main() {
    Car car("Toyota", 4, 150);
    Lorry lorry("Volvo", 8, 300, 5000);

    std::cout << "Car Information:" << std::endl;
    car.displayInfo();

    std::cout << "\nLorry Information:" << std::endl;
    lorry.displayInfo();

    // Зміна потужності автомобіля
    car.changePower(20);
    std::cout << "\nUpdated Car Information after changing power:" << std::endl;
    car.displayInfo();

    // Зміна вантажопідйомності вантажівки
    lorry.changeCargoCapacity(6000);
    std::cout << "\nUpdated Lorry Information after changing cargo capacity:" << std::endl;
    lorry.displayInfo();

    return 0;
}

/*
#include <iostream>
#include <string>

// Клас кнопки
class Button {
private:
    int size;

public:
    Button(int size) : size(size) {}

    int getSize() const {
        return size;
    }
};

// Клас вікна
class Window {
private:
    int x, y;
    Button button;

public:
    Window(int x, int y, int buttonSize) : x(x), y(y), button(buttonSize) {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    const Button& getButton() const {
        return button;
    }

    ~Window() {
        std::cout << "Window destroyed" << std::endl;
    }
};

// Публічний похідний клас вікна з кнопкою меню
class MenuWindow : public Window {
private:
    std::string* menuText;

public:
    MenuWindow(int x, int y, int buttonSize, const std::string& menuText) 
        : Window(x, y, buttonSize), menuText(new std::string(menuText)) {}

    void printMenuText() const {
        std::cout << "Menu Text: " << *menuText << std::endl;
    }

    ~MenuWindow() {
        delete menuText;
        std::cout << "MenuWindow destroyed" << std::endl;
    }
};

int main() {
    Window mainWindow(100, 50, 30);
    std::cout << "Window coordinates: (" << mainWindow.getX() << ", " << mainWindow.getY() << ")" << std::endl;
    std::cout << "Button size: " << mainWindow.getButton().getSize() << std::endl;

    MenuWindow menuWindow(200, 100, 40, "File Edit View");
    std::cout << "\nMenuWindow coordinates: (" << menuWindow.getX() << ", " << menuWindow.getY() << ")" << std::endl;
    std::cout << "Button size: " << menuWindow.getButton().getSize() << std::endl;
    menuWindow.printMenuText();

    return 0;
}




#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Конструктор копіювання
    Person(const Person& other) : name(other.name), age(other.age) {}

    // Оператор присвоювання
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }

    // Функція для виводу в потік
    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os;
    }

    // Функція для введення з потоку
    friend std::istream& operator>>(std::istream& is, Person& person) {
        std::cout << "Enter name: ";
        is >> person.name;
        std::cout << "Enter age: ";
        is >> person.age;
        return is;
    }
};

class Student : public Person {
private:
    std::string university;

public:
    Student(const std::string& name, int age, const std::string& university)
        : Person(name, age), university(university) {}

    // Конструктор копіювання
    Student(const Student& other) : Person(other), university(other.university) {}

    // Оператор присвоювання
    Student& operator=(const Student& other) {
        if (this != &other) {
            Person::operator=(other);
            university = other.university;
        }
        return *this;
    }

    // Перевизначений вивід у потік
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << static_cast<const Person&>(student) << ", University: " << student.university;
        return os;
    }

    // Перевизначений ввід з потоку
    friend std::istream& operator>>(std::istream& is, Student& student) {
        is >> static_cast<Person&>(student);
        std::cout << "Enter university: ";
        is >> student.university;
        return is;
    }
};

int main() {
    Person person("John", 30);
    std::cout << "Enter student's details:" << std::endl;
    Student student("Unknown", 0, "Unknown");
    std::cin >> student;

    std::cout << "\nPerson: " << person << std::endl;
    std::cout << "Student: " << student << std::endl;

    // Копіювання об'єкта
    Student studentCopy = student;
    std::cout << "\nCopied student: " << studentCopy << std::endl;

    // Присвоювання об'єкта
    Person personCopy("Mary", 25);
    personCopy = person;
    std::cout << "Assigned person: " << personCopy << std::endl;

    return 0;
}
*/