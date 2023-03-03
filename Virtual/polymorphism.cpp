#include <iostream>
//Есть поваренная книга, где в начале книги общее описание, как варить любую крупу,
//а дальше для каждой крупы отдельный рецепт
//
//Вопрос: Как вы будете варить гречку?


// Ответ, по умолчанию будет - любую крупу (т.е. ссылка на Base для Derived будет давать родительский f() = 1)
// Но если мы хотим варить гречку зачем любая, нам нужно именно гречка, чтобы получить ее рецепт
// нужно написать virtual (необходимо и достаточно у Base), тогда f() = 2

// Выбирает самая нижняя при virtual и самая верхняя без virtual

// virtual - динамический полиморфизм, так как выбор идет в RUNTIME

// polymorphic type - если есть хотя бы один virtual

struct Base{
//    void f(){
//        std::cout<<"1";
//    }
    virtual void f() const{ // тут может произойти каст к конст

        std::cout<<"1";
    }
//    virtual void f() const final{ // если хотим запретить переопределение дальше по наследникам
//
//        std::cout<<"1";
//    }
};

struct Derived:public Base{
//    void f(){ // если указать, что это константный метод, то он перестанет быть virtual, так как отошли от изначального
//        std::cout<<"2";
//    }
    void f() const override{ // c++11 override
        std::cout<<"2";
    }
};

// начиная с с++11 лучше писать override, чтобы явно показать, что функция переопределена и были если что заметны ошибки
// типов при компиляции (если они есть)

// Пример для общего использования virtual
// выше классы с виртуальными методами speak и getname
//void report(Animal &animal)
//{
//    std::cout << animal.getName() << " says " << animal.speak() << '\n';
//}
//
//int main()
//{
//    Cat cat("Matros");
//    Dog dog("Barsik");
//
//    report(cat);
//    report(dog);
//}

int main(){
    Base b;
    b.f();
    Derived d;
    d.f();
    Base& bb = d;
    bb.f();//без virtual выведится 1, так как приоритет выше у родительской
    // в Java такого нет, там было бы 2
    // Причем
    Base bbb=d;
    bbb.f();
}