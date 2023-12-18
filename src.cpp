#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Родительский класс FoodItem
class FoodItem {
    // Защищенные поля
protected:
    string title;
    int srok_godnosti;

public:
    // Конструктор класса
    FoodItem(const string& title, const int& srok_godnosti): title(title), srok_godnosti(srok_godnosti) {};

    // Виртуальный метод для вывода информации о продукте
    virtual void displayInfo() const {
        cout << "Наименование продукта: " << title << endl;
        cout << "Срок годности: " << srok_godnosti << " суток" << endl;
    };

    // Метод для установки значения наименования продукта
    void setTitle(const string& title_p) {
        title = title_p;
    }

    // Метод для установки значения срока годности продукта
    void setSrokGodnosti(const int& srok_p) {
        srok_godnosti = srok_p;
    }

    virtual ~FoodItem() {};
};

// Дочерний класс Vegetable
class Vegetable : public FoodItem {
protected:
    string type;

public:
    Vegetable(const string& title, const int& srok_godnosti, const string& type) : FoodItem(title, srok_godnosti), type(type) {};

    // Переопределенный метод родительского класса
    void displayInfo() const override {
        cout << "Наименование продукта: " << title << endl;
        cout << "Срок годности: " << srok_godnosti << " суток" << endl;
        cout << "Тип овоща: " << type<< endl;
    }

    ~Vegetable() {};
};

// Дочерний класс Dairy
class Dairy : public FoodItem {
protected:
    int fat;

public:
    Dairy(const string& title, const int& srok_godnosti, const int& fat) : FoodItem(title, srok_godnosti), fat(fat) {};

    // Переопределенный метод родительского класса
    void displayInfo() const override {
        cout << "Наименование продукта: " << title << endl;
        cout << "Срок годности: " << srok_godnosti << " суток" << endl;
        cout << "Жирность: " << fat << "%" << endl;
    }

    ~Dairy() {};

};

// Функция для изменения базового класса
void modifyFoods(FoodItem* ptr) {
    ptr->setTitle("Печенье");
    ptr->setSrokGodnosti(20);
}

int main()
{
    system("chcp 1251 > nul");

    vector<FoodItem*> foods; // Объявление вектора для хранения экземпляров класса продуктов

    // Добавление объектов в вектор
    foods.push_back(new FoodItem("Кукурузные палочки", 120));
    foods.push_back(new FoodItem("Мясо птицы", 7));
    foods.push_back(new Vegetable("Морковь", 20, "Корнеплод"));
    foods.push_back(new Vegetable("Тыква", 30, "Тыквенные"));
    foods.push_back(new Dairy("Молоко", 7, 4));
    foods.push_back(new Dairy("Сметана", 14, 20));

    // Вывод информации о каждом объекте в векторе
    for (const auto i : foods) {
        i->displayInfo();
    }

    cout << endl;

    // Изменение базового класса
    for (const auto i : foods) {
        modifyFoods(i);
        i->displayInfo();
        delete i;
    }

    system("pause > nul");
}

