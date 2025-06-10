#include<iostream>
using namespace std;

class Queues {
private:
    int FRONT, REAR;
    static const int max = 5;
    int queue_array[5];

public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        // Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        // Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }

        queue_array[REAR] = num;
    }

    void remove() {
        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }

        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display() {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nElements in the queue are:\n";

        if (FRONT_position <= REAR_position) {
            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
        else {
            while (FRONT_position <= max - 1) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }

            FRONT_position = 0;

            while (FRONT_position <= REAR_position) {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};

int main() {
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "\nMenu\n";
            cout << "1. Insert\n";
            cout << "2. Delete\n";
            cout << "3. Display\n";
            cout << "4. Exit\n";
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

            switch (ch) {
                case '1':
                    q.insert();
                    break;
                case '2':
                    q.remove();
                    break;
                case '3':
                    q.display();
                    break;
                case '4':
                    return 0;
                default:
                    cout << "Invalid input. Please enter 1-4.\n";
            }
        }
        catch (exception &e) {
            cout << "Check for the values entered. Error: " << e.what() << endl;
        }
    }
}
