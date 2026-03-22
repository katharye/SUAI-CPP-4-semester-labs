#include <iostream>
#include <limits>
#include "linkedlist"
#include "time"

using namespace std;

int showMainMenu() {
    int choice;
    cout << "\n========================================\n";
    cout << "        LABORATORY WORK #2              \n";
    cout << "        Operator Overloading            \n";
    cout << "========================================\n";
    cout << "1. Task 1: Linked List\n";
    cout << "2. Task 2: Time Class\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
    cout << "Your choice: ";
    
    while (!(cin >> choice)) {
        cout << "Error! Enter a number: ";
        
    }
    
    
    return choice;
}

void showLinkedListMenu() {
    cout << "\n--- MENU: LINKED LIST ---\n";
    cout << "1. ++ (prefix) - add element to BEGINNING\n";
    cout << "2. ++ (postfix) - add element to END\n";
    cout << "3. -- (prefix) - remove FIRST element\n";
    cout << "4. -- (postfix) - remove LAST element\n";
    cout << "5. Show current list\n";
    cout << "6. Create new list (specified size)\n";
    cout << "7. Copy list (copy constructor)\n";
    cout << "8. Assign list (operator=)\n";
    cout << "0. Back to main menu\n";
    cout << "========================================\n";
}

void runLinkedListMenu() {
    LinkedList list;
    int choice;
    
    do {
        showLinkedListMenu();
        cout << "Your choice: ";
        
        while (!(cin >> choice)) {
            cout << "Error! Enter a number: ";
            
        }
        
        
        switch (choice) {
            case 1: {
                ++list;
                cout << "Element added to BEGINNING\n";
                break;
            }
            case 2: {
                list++;
                cout << "Element added to END\n";
                break;
            }
            case 3: {
                if (list.isEmpty()) {
                    cout << "List is empty! Nothing to remove\n";
                } else {
                    --list;
                    cout << "FIRST element removed\n";
                }
                break;
            }
            case 4: {
                if (list.isEmpty()) {
                    cout << "List is empty! Nothing to remove\n";
                } else {
                    list--;
                    cout << "LAST element removed\n";
                }
                break;
            }
            case 5: {
                cout << "Current list: ";
                list.printLinkedList();
                break;
            }
            case 6: {
                int count;
                cout << "Enter number of elements: ";
                while (!(cin >> count) || count < 0) {
                    cout << "Error! Enter a positive number: ";
                    
                }
                
                list = LinkedList(count);
                cout << "List created\n";
                break;
            }
            case 7: {
                LinkedList copied(list);
                cout << "Original: ";
                list.printLinkedList();
                cout << "Copy:     ";
                copied.printLinkedList();
                break;
            }
            case 8: {
                LinkedList assigned;
                assigned = list;
                cout << "Original:  ";
                list.printLinkedList();
                cout << "Assigned:  ";
                assigned.printLinkedList();
                break;
            }
            case 0: {
                cout << "Returning to main menu...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Try again\n";
            }
        }
    } while (choice != 0);
}

void showTimeMenu() {
    cout << "\n--- MENU: TIME CLASS ---\n";
    cout << "1. Create time (hours, minutes, seconds)\n";
    cout << "2. Operator + (add seconds)\n";
    cout << "3. Operator - (subtract seconds)\n";
    cout << "4. Operator * (multiply all fields)\n";
    cout << "5. Operator / (divide all fields)\n";
    cout << "6. Show current time\n";
    cout << "7. Copy time (copy constructor)\n";
    cout << "8. Assign time (operator=)\n";
    cout << "9. Check explicit (demonstration)\n";
    cout << "0. Back to main menu\n";
    cout << "========================================\n";
}

void runTimeMenu() {
    Time currentTime;
    int choice;
    
    do {
        showTimeMenu();
        cout << "Your choice: ";
        
        while (!(cin >> choice)) {
            cout << "Error! Enter a number: ";
            
        }
        
        
        switch (choice) {
            case 1: {
                int h, m, s;
                cout << "Enter hours: ";
                while (!(cin >> h)) {
                    cout << "Error! Enter a number: ";
                    
                }
                cout << "Enter minutes: ";
                while (!(cin >> m)) {
                    cout << "Error! Enter a number: ";
                    
                }
                cout << "Enter seconds: ";
                while (!(cin >> s)) {
                    cout << "Error! Enter a number: ";
                    
                }
                
                currentTime = Time(h, m, s);
                cout << "Time created\n";
                break;
            }
            case 2: {
                int value;
                cout << "Enter seconds to add: ";
                while (!(cin >> value)) {
                    cout << "Error! Enter a number: ";
                    
                }
                
                Time result = currentTime + value;
                cout << "Initial: ";
                currentTime.print_time();
                cout << "Result (+ " << value << " sec): ";
                result.print_time();
                break;
            }
            case 3: {
                int value;
                cout << "Enter seconds to subtract: ";
                while (!(cin >> value)) {
                    cout << "Error! Enter a number: ";
                    
                }
                
                Time result = currentTime - value;
                cout << "Initial: ";
                currentTime.print_time();
                cout << "Result (- " << value << " sec): ";
                result.print_time();
                break;
            }
            case 4: {
                int value;
                cout << "Enter multiplier: ";
                while (!(cin >> value)) {
                    cout << "Error! Enter a number: ";
                    
                }
                
                Time result = currentTime * value;
                cout << "Initial: ";
                currentTime.print_time();
                cout << "Result (* " << value << "): ";
                result.print_time();
                break;
            }
            case 5: {
                int value;
                cout << "Enter divisor: ";
                while (!(cin >> value)) {
                    cout << "Error! Enter a number: ";
                    
                }
                
                Time result = currentTime / value;
                cout << "Initial: ";
                currentTime.print_time();
                cout << "Result (/ " << value << "): ";
                result.print_time();
                if (value == 0) {
                    cout << "Division by zero! Time unchanged\n";
                }
                break;
            }
            case 6: {
                cout << "Current time: ";
                currentTime.print_time();
                break;
            }
            case 7: {
                Time copied(currentTime);
                cout << "Original: ";
                currentTime.print_time();
                cout << "Copy:     ";
                copied.print_time();
                break;
            }
            case 8: {
                Time assigned;
                assigned = currentTime;
                cout << "Original:  ";
                currentTime.print_time();
                cout << "Assigned:  ";
                assigned.print_time();
                break;
            }
            case 9: {
                cout << "\n=== Explicit Demonstration ===\n";
                cout << "Time t(5);     // Valid (explicit call)\n";
                cout << "Time t = 5;    // Error (explicit forbids)\n";
                cout << "\nCreating Time(5):\n";
                Time t(5);
                cout << "Result: ";
                t.print_time();
                cout << "(default args: minutes=59, seconds=59)\n";
                break;
            }
            case 0: {
                cout << "Returning to main menu...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Try again\n";
            }
        }
    } while (choice != 0);
}

int main() {
    int mainChoice;
    
    do {
        mainChoice = showMainMenu();
        
        switch (mainChoice) {
            case 1: {
                runLinkedListMenu();
                break;
            }
            case 2: {
                runTimeMenu();
                break;
            }
            case 0: {
                cout << "\n========================================\n";
                cout << "                 CLOSING                \n";
                cout << "========================================\n";
                break;
            }
            default: {
                cout << "Invalid choice! Try again\n";
            }
        }
    } while (mainChoice != 0);
    
    return 0;
}