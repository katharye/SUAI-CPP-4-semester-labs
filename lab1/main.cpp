#include <iostream>

#include "node.h"
#include "queue.h"
#include "queue1_private.h"
#include "queue1_protected.h"
#include "queue1_public.h"

void showMenu();

int main() {
    Queue1_public queue;
    Queue1_protected queue_protected;
    Queue1_private queue_private;

    Queue* copy1 = nullptr;
    Queue* copy2 = nullptr;
    Queue* copy3 = nullptr;

    int choice, value;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Введите значение элемента очереди: ";
                if (!(std::cin >> value)) {
                    std::cout << "Неверный формат! Нужно ввести целое число!\n";
                } else {
                    queue.getInQueue(value);            // public
                    queue_protected.getInQueue(value);  // protected
                    queue_private.getInQueue(value);    // private
                    std::cout << "Число добавлено в очередь!\n";
                }
                break;
            case 2:
                if (queue.isEmpty()) {
                    std::cout << "Очередь пуста! Перед извлечением элементов, добавьте их в очередь!\n";
                } else {
                    std::cout << "Извлечённый элемент: " << queue.getOutOfQueue() << "\n";  // public
                    std::cout << "Извлечённый элемент: " << queue_protected.getOutOfQueue() << "\n";  // protected
                    std::cout << "Извлечённый элемент: " << queue_private.getOutOfQueue() << "\n";  // private
                }
                break;
            case 3:
                queue.print();            // public
                queue_protected.print();  // protected
                queue_private.print();    // private
                break;

            case 4:
                queue.printResult();
                queue_protected.printResult();
                queue_private.printResult();
                break;

            case 5:
                if (copy1) delete copy1;
                if (copy2) delete copy2;
                if (copy3) delete copy3;

                copy1 = queue.copyQueue();            // public
                copy2 = queue_protected.copyQueue();  // protected
                copy3 = queue_private.copyQueue();    // private

                std::cout << "Копия создана\n";
                break;

            case 6:
                if (copy1 && copy2 && copy3) {
                    Queue* merged1 = queue + *copy1;
                    Queue* merged2 = queue_protected + *copy2;
                    Queue* merged3 = queue_private + *copy3;

                    std::cout << "Результат слияния:\n";
                    merged1->print();
                    merged2->print();
                    merged3->print();

                    delete merged1;
                    delete merged2;
                    delete merged3;
                } else {
                    std::cout << "Сначала создайте копию (пункт 5)\n";
                }
                break;

            case 7:
                std::cout << "Выход..." << std::endl;
                break;

            default:
                std::cout << "Такого номера нет в меню" << std::endl;
                break;
        }
    } while (choice != 7);

    if (copy1) delete copy1;
    if (copy2) delete copy2;
    if (copy3) delete copy3;

    return 0;
}

void showMenu() {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1 - Добавление элемента очереди\n";
    std::cout << "2 - Извлечение элемента очереди\n";
    std::cout << "3 - Вывод очереди на экран\n";
    std::cout << "4 - Вычисление требуемого значения\n";
    std::cout << "5 - Создание копии очереди\n";
    std::cout << "6 - Слияние оригинальной очереди с копией\n";
    std::cout << "7 - Выход из программы\n";
    std::cout << "Выбор: ";
}
