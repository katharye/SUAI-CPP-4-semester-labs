#include <fstream>
#include <iostream>
#include <limits>

#include "animals.h"
#include "cats.h"
#include "dogs.h"
#include "fishes.h"
#include "humans.h"
#include "mammals.h"

// Максимальное количество объектов в массиве
const int MAX_OBJECTS = 100;

Mammals* zoo[MAX_OBJECTS];
int object_count = 0;

void show_menu();
void create_mammal();
void display_all();
void save_to_file();
void load_from_file();
void clear_memory();
void display_single(int index);

// Очистка буфера ввода
void clear_input_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string input_string(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

float input_float(const std::string& prompt) {
    float value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число: ";
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

int input_int(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "Ошибка! Введите число: ";
        clear_input_buffer();
    }
    clear_input_buffer();
    return value;
}

void show_menu() {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║           МЕНЮ ПРОГРАММЫ (Вариант 11)              ║\n";
    std::cout << "╠════════════════════════════════════════════════════╣\n";
    std::cout << "║ 1. Создать собаку                                  ║\n";
    std::cout << "║ 2. Создать кота                                    ║\n";
    std::cout << "║ 3. Создать рыбу                                    ║\n";
    std::cout << "║ 4. Создать человека                                ║\n";
    std::cout << "║ 5. Показать всех созданных существ                 ║\n";
    std::cout << "║ 6. Показать конкретное существо по номеру          ║\n";
    std::cout << "║ 7. Сохранить текущий объект в файл                 ║\n";
    std::cout << "║ 8. Загрузить объект из файла                       ║\n";
    std::cout << "║ 9. Удалить все объекты из памяти                   ║\n";
    std::cout << "║ 0. Выход из программы                              ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";
}

// Создать млекопитающее (выбор типа)
void create_mammal() {
    if (object_count >= MAX_OBJECTS) {
        std::cout << "Достигнут лимит объектов (" << MAX_OBJECTS << ")!\n";
        return;
    }

    std::cout << "\n--- Создание нового объекта ---\n";
    std::cout << "1. Собака\n";
    std::cout << "2. Кот\n";
    std::cout << "3. Рыба\n";
    std::cout << "4. Человек\n";
    std::cout << "Выберите тип: ";

    int type = input_int("");

    std::string breed, name, color, owner_name;
    float size;
    std::string fio, nationality;
    int date[3];

    switch (type) {
        case 1:  // Собака
            std::cout << "\n=== Ввод данных для СОБАКИ ===\n";
            breed = input_string("Порода: ");
            name = input_string("Кличка: ");
            color = input_string("Окрас: ");
            owner_name = input_string("ФИО владельца: ");
            size = input_float("Размер (в дм): ");

            zoo[object_count] = new Dogs(breed, name, color, owner_name, size);
            std::cout << "Собака успешно создана!\n";
            break;

        case 2:  // Кот
            std::cout << "\n=== Ввод данных для КОТА ===\n";
            breed = input_string("Порода: ");
            name = input_string("Кличка: ");
            color = input_string("Окрас: ");
            owner_name = input_string("ФИО владельца: ");
            size = input_float("Размер (в см): ");

            zoo[object_count] = new Cats(breed, name, color, owner_name, size);
            std::cout << "Кот успешно создан!\n";
            break;

        case 3:  // Рыба
            std::cout << "\n=== Ввод данных для РЫБЫ ===\n";
            breed = input_string("Порода: ");
            name = input_string("Кличка: ");
            color = input_string("Окрас: ");
            owner_name = input_string("ФИО владельца: ");
            size = input_float("Размер (в см): ");

            zoo[object_count] = new Fishes(breed, name, color, owner_name, size);
            std::cout << "Рыба успешно создана!\n";
            break;

        case 4:  // Человек
            std::cout << "\n=== Ввод данных для ЧЕЛОВЕКА ===\n";
            fio = input_string("ФИО: ");
            nationality = input_string("Национальность: ");
            std::cout << "Дата рождения:\n";
            date[0] = input_int("  День (1-31): ");
            date[1] = input_int("  Месяц (1-12): ");
            date[2] = input_int("  Год: ");

            zoo[object_count] = new Humans(fio, date, nationality);
            std::cout << "Человек успешно создан!\n";
            break;

        default:
            std::cout << "Неверный выбор типа!\n";
            return;
    }

    object_count++;
}

// Показать всех созданных существ
void display_all() {
    if (object_count == 0) {
        std::cout << "\nСписок пуст! Создайте объекты сначала.\n";
        return;
    }

    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║           СПИСОК ВСЕХ СУЩЕСТВ (" << object_count << ")              ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";

    for (int i = 0; i < object_count; i++) {
        std::cout << "\n[Объект #" << (i + 1) << "]\n";
        zoo[i]->print_info();  // Полиморфизм: вызов виртуальной функции
    }
}

// Показать конкретное существо по номеру
void display_single(int index) {
    if (index < 0 || index >= object_count) {
        std::cout << "Неверный номер объекта!\n";
        return;
    }

    std::cout << "\n[Объект #" << (index + 1) << "]\n";
    zoo[index]->print_info();  // Полиморфизм
}

// Сохранить текущий объект в файл
void save_to_file() {
    if (object_count == 0) {
        std::cout << "\nНет объектов для сохранения!\n";
        return;
    }

    std::cout << "\nДоступные объекты для сохранения:\n";
    for (int i = 0; i < object_count; i++) {
        std::cout << (i + 1) << ". Объект #" << (i + 1) << "\n";
    }

    int index = input_int("\nВыберите номер объекта для сохранения: ") - 1;

    if (index < 0 || index >= object_count) {
        std::cout << "Неверный номер!\n";
        return;
    }

    std::string filename = input_string("Введите имя файла для сохранения: ");
    if (filename.empty()) {
        filename = "output.txt";
    }

    std::ofstream out(filename);
    if (!out.is_open()) {
        std::cout << "Ошибка открытия файла для записи!\n";
        return;
    }

    zoo[index]->save_to_file(out);  // Полиморфизм: вызов виртуальной функции
    out.close();

    std::cout << "Данные успешно сохранены в файл: " << filename << "\n";
}

// Загрузить объект из файла
void load_from_file() {
    if (object_count >= MAX_OBJECTS) {
        std::cout << "Достигнут лимит объектов!\n";
        return;
    }

    std::string filename = input_string("Введите имя файла для загрузки: ");
    if (filename.empty()) {
        filename = "output.txt";
    }

    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "Ошибка открытия файла для чтения!\n";
        return;
    }

    std::string type;
    std::getline(in, type);

    Mammals* loaded_object = nullptr;

    if (type == "DOGS") {
        loaded_object = new Dogs(in);
    } else if (type == "CATS") {
        loaded_object = new Cats(in);
    } else if (type == "FISHES") {
        loaded_object = new Fishes(in);
    } else if (type == "HUMANS") {
        loaded_object = new Humans(in);
    } else {
        std::cout << "Неизвестный тип объекта в файле: " << type << "\n";
        in.close();
        return;
    }

    in.close();

    if (loaded_object != nullptr) {
        zoo[object_count] = loaded_object;
        object_count++;
        std::cout << "Объект успешно загружен из файла: " << filename << "\n";
    } else {
        std::cout << "Ошибка загрузки объекта!\n";
    }
}

// Удалить все объекты из памяти
void clear_memory() {
    if (object_count == 0) {
        std::cout << "\nНет объектов для удаления.\n";
        return;
    }

    for (int i = 0; i < object_count; i++) {
        delete zoo[i];  // Вызов виртуального деструктора
        zoo[i] = nullptr;
    }

    object_count = 0;
    std::cout << "Все объекты удалены из памяти!\n";
}

// Главная функция
int main() {
    std::cout << "\n╔════════════════════════════════════════════════════╗\n";
    std::cout << "║     ЛАБОРАТОРНАЯ РАБОТА №3 (Вариант 11)            ║\n";
    std::cout << "║     Иерархия классов: Млекопитающие                ║\n";
    std::cout << "╚════════════════════════════════════════════════════╝\n";

    int choice;

    do {
        show_menu();
        choice = input_int("\nВаш выбор: ");

        switch (choice) {
            case 1:
            case 2:
            case 3:
            case 4:
                // Прямой вызов создания с предвыбранным типом
                if (object_count >= MAX_OBJECTS) {
                    std::cout << "Достигнут лимит объектов!\n";
                } else {
                    // Перенаправляем в create_mammal с авто-выбором
                    std::cout << "\n--- Создание объекта ---\n";
                    std::string breed, name, color, owner_name;
                    float size;
                    std::string fio, nationality;
                    int date[3];

                    if (choice == 1)  // Собака
                    {
                        std::cout << "=== Ввод данных для СОБАКИ ===\n";
                        breed = input_string("Порода: ");
                        name = input_string("Кличка: ");
                        color = input_string("Окрас: ");
                        owner_name = input_string("ФИО владельца: ");
                        size = input_float("Размер (в дм): ");
                        zoo[object_count] = new Dogs(breed, name, color, owner_name, size);
                        std::cout << "Собака создана!\n";
                    } else if (choice == 2)  // Кот
                    {
                        std::cout << "=== Ввод данных для КОТА ===\n";
                        breed = input_string("Порода: ");
                        name = input_string("Кличка: ");
                        color = input_string("Окрас: ");
                        owner_name = input_string("ФИО владельца: ");
                        size = input_float("Размер (в см): ");
                        zoo[object_count] = new Cats(breed, name, color, owner_name, size);
                        std::cout << "Кот создан!\n";
                    } else if (choice == 3)  // Рыба
                    {
                        std::cout << "=== Ввод данных для РЫБЫ ===\n";
                        breed = input_string("Порода: ");
                        name = input_string("Кличка: ");
                        color = input_string("Окрас: ");
                        owner_name = input_string("ФИО владельца: ");
                        size = input_float("Размер (в см): ");
                        zoo[object_count] = new Fishes(breed, name, color, owner_name, size);
                        std::cout << "Рыба создана!\n";
                    } else if (choice == 4)  // Человек
                    {
                        std::cout << "=== Ввод данных для ЧЕЛОВЕКА ===\n";
                        fio = input_string("ФИО: ");
                        nationality = input_string("Национальность: ");
                        std::cout << "Дата рождения:\n";
                        date[0] = input_int("  День (1-31): ");
                        date[1] = input_int("  Месяц (1-12): ");
                        date[2] = input_int("  Год: ");
                        zoo[object_count] = new Humans(fio, date, nationality);
                        std::cout << "Человек создан!\n";
                    }
                    object_count++;
                }
                break;

            case 5:
                display_all();
                break;

            case 6:
                if (object_count == 0) {
                    std::cout << "\nСписок пуст!\n";
                } else {
                    int idx =
                        input_int("Введите номер объекта (1-" + std::to_string(object_count) + "): ") - 1;
                    display_single(idx);
                }
                break;

            case 7:
                save_to_file();
                break;

            case 8:
                load_from_file();
                break;

            case 9:
                clear_memory();
                break;

            case 0:
                std::cout << "\nВыход из программы...\n";
                break;

            default:
                std::cout << "Неверный выбор! Попробуйте снова.\n";
        }

    } while (choice != 0);

    // Очистка памяти перед выходом
    clear_memory();

    std::cout << "\nПрограмма завершена успешно!\n";

    return 0;
}