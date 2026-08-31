#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

#include "circularqueue.h"
#include "mergesort.h"

void printQuest2();
void printQuest1();
void printMain();
void printDataType();
void printDataTypeQueue();

void clear();
void clearBuffer();

void menuMain();
void menuQ1();
void menuQ2();

int enterLength();

template <typename T>
void runMergeSort();

template <typename T>
void runCircularQueue();

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    menuMain();
    return 0;
}

void printQuest2() {
    std::cout << "\n╔══════════════════════════╗";
    std::cout << "\n║          QUEST2          ║";
    std::cout << "\n╠══════════════════════════╣";
    std::cout << "\n║ 1 ┃ Create queue         ║";
    std::cout << "\n║ 2 ┃ Add element     (+)  ║";
    std::cout << "\n║ 3 ┃ Remove element  (-)  ║";
    std::cout << "\n║ 4 ┃ Emptiness check (!)  ║";
    std::cout << "\n║ 5 ┃ Show queue           ║";
    std::cout << "\n║   ┃                      ║";
    std::cout << "\n║ 0 ┃ Back                 ║";
    std::cout << "\n╚══════════════════════════╝";
    std::cout << "\nCHOICE: ";
}

void printQuest1() {
    std::cout << "\n╔══════════════════════════╗";
    std::cout << "\n║          QUEST1          ║";
    std::cout << "\n╠══════════════════════════╣";
    std::cout << "\n║ 1 ┃ Enter array          ║";
    std::cout << "\n║ 2 ┃ Print array          ║";
    std::cout << "\n║ 3 ┃ Sort array           ║";
    std::cout << "\n║ 4 ┃ Delete array         ║";
    std::cout << "\n║   ┃                      ║";
    std::cout << "\n║ 0 ┃ Back                 ║";
    std::cout << "\n╚══════════════════════════╝";
    std::cout << "\nCHOICE: ";
}

void printMain() {
    std::cout << "\n╔══════════════════════════╗";
    std::cout << "\n║           MENU           ║";
    std::cout << "\n╠══════════════════════════╣";
    std::cout << "\n║ 1 ┃ Quest 1              ║";
    std::cout << "\n║ 2 ┃ Quest 2              ║";
    std::cout << "\n║   ┃                      ║";
    std::cout << "\n║ 0 ┃ Exit                 ║";
    std::cout << "\n╚══════════════════════════╝";
    std::cout << "\nCHOICE: ";
}

void printDataType() {
    std::cout << "\n╔══════════════════════════╗";
    std::cout << "\n║     CHOOSE DATA TYPE     ║";
    std::cout << "\n╠══════════════════════════╣";
    std::cout << "\n║ 1 ┃ int                  ║";
    std::cout << "\n║ 2 ┃ float                ║";
    std::cout << "\n║ 3 ┃ char                 ║";
    std::cout << "\n║ 4 ┃ string               ║";
    std::cout << "\n║ 5 ┃ double               ║";
    std::cout << "\n╚══════════════════════════╝";
    std::cout << "\nCHOICE: ";
}

void printDataTypeQueue() {
    std::cout << "\n╔══════════════════════════╗";
    std::cout << "\n║     CHOOSE DATA TYPE     ║";
    std::cout << "\n╠══════════════════════════╣";
    std::cout << "\n║ 1 ┃ int                  ║";
    std::cout << "\n║ 2 ┃ float                ║";
    std::cout << "\n║ 3 ┃ char                 ║";
    std::cout << "\n║ 4 ┃ double               ║";
    std::cout << "\n╚══════════════════════════╝";
    std::cout << "\nCHOICE: ";
}

void clear() {
    std::cout << "\033[2J\033[1;1H";
    std::cout.flush();
}

void clearBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int enterLength() {
    int length;
    while (true) {
        std::cout << "Enter array length (>0): ";
        if (!(std::cin >> length && length > 0)) {
            clearBuffer();
            std::cout << "Invalid input\n";
        } else {
            break;
        }
    }
    return length;
}

void menuMain() {
    int choice = 9;

    while (choice != 0) {
        clear();
        printMain();
        std::cin >> choice;

        switch (choice) {
            case 1:
                clear();
                menuQ1();
                break;
            case 2:
                clear();
                menuQ2();
                break;
            case 0:
                break;
            default:
                std::cout << "Incorrect input\n";
                clearBuffer();
        }
    }
}

void menuQ1() {
    int choice;
    printDataType();
    std::cin >> choice;

    switch (choice) {
        case 1:
            clear();
            runMergeSort<int>();
            break;
        case 2:
            clear();
            runMergeSort<float>();
            break;
        case 3:
            clear();
            runMergeSort<char>();
            break;
        case 4:
            clear();
            runMergeSort<std::string>();
            break;
        case 5:
            clear();
            runMergeSort<double>();
            break;
        default:
            std::cout << "Incorrect input\n";
            clearBuffer();
    }
}

void menuQ2() {
    int choice;
    printDataTypeQueue();
    std::cin >> choice;

    switch (choice) {
        case 1:
            clear();
            runCircularQueue<int>();
            break;
        case 2:
            clear();
            runCircularQueue<float>();
            break;
        case 3:
            clear();
            runCircularQueue<char>();
            break;
        case 4:
            clear();
            runCircularQueue<double>();
            break;
        default:
            std::cout << "Incorrect input\n";
            clearBuffer();
    }
}

template <typename T>
void runMergeSort() {
    T* unsort_array = nullptr;
    T* sorted_array = nullptr;
    int length = 0;
    int choice = 9;

    while (choice != 0) {
        printQuest1();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    clear();
                    if (unsort_array) {
                        std::cout << "Array already exists!\n";
                        break;
                    }
                    length = enterLength();
                    unsort_array = new T[length];
                    std::cout << "Enter elements:\n";
                    for (int i = 0; i < length;) {
                        if (!(std::cin >> unsort_array[i])) {
                            std::cout << "Invalid input, try again\n";
                            clearBuffer();
                        } else {
                            i++;
                        }
                    }
                    clearBuffer();
                    break;
                }
                case 2: {
                    clear();
                    if (!unsort_array) {
                        std::cout << "Array is empty\n";
                        break;
                    }
                    for (int i = 0; i < length; i++) std::cout << unsort_array[i] << " ";
                    std::cout << "\n";
                    break;
                }
                case 3: {
                    clear();
                    if (!unsort_array) {
                        std::cout << "Array is empty\n";
                        break;
                    }
                    delete[] sorted_array;
                    sorted_array = merge_sort(unsort_array, length);
                    std::cout << "Sorted array:\n";
                    for (int i = 0; i < length; i++) std::cout << sorted_array[i] << " ";
                    std::cout << "\n";
                    break;
                }
                case 4: {
                    clear();
                    delete[] unsort_array;
                    delete[] sorted_array;
                    unsort_array = nullptr;
                    sorted_array = nullptr;
                    std::cout << "Deleted\n";
                    break;
                }
                default:
                    clear();
                    clearBuffer();
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    if (unsort_array) delete[] unsort_array;
    if (sorted_array) delete[] sorted_array;
}

template <typename T>
void runCircularQueue() {
    CircularQueue<T>* queue = nullptr;
    int choice = 9;

    while (choice != 0) {
        printQuest2();
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    clear();
                    int size;
                    std::cout << "Enter size: ";
                    size = enterLength();

                    if (queue) delete queue;
                    queue = new CircularQueue<T>(size);

                    for (int i = 0; i < size; i++) {
                        T val = static_cast<T>(rand() % 51);
                        (*queue) + val;
                    }
                    break;
                }
                case 2: {
                    clear();
                    if (!queue) {
                        std::cout << "Create queue first!\n";
                        break;
                    }
                    T val = static_cast<T>(rand() % 51);
                    std::cout << "Added: " << val << "\n";
                    (*queue) + val;
                    break;
                }
                case 3: {
                    clear();
                    if (!queue) {
                        std::cout << "Create queue first!\n";
                        break;
                    }
                    T val = (*queue) - 1;
                    std::cout << "Removed: " << val << "\n";
                    break;
                }
                case 4: {
                    clear();
                    if (!queue) {
                        std::cout << "Queue not created\n";
                    } else {
                        std::cout << (!(*queue) ? "Empty\n" : "Not empty\n");
                    }
                    break;
                }
                case 5: {
                    clear();
                    if (!queue) {
                        std::cout << "Create queue first!\n";
                        break;
                    }
                    queue->print();
                    std::cout << "\n";
                    break;
                }
                default:
                    clear();
                    clearBuffer();
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
    delete queue;
}