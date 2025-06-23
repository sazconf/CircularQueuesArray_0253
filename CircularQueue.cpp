#include<iostream>
#include<string>
#include<vector>

using namespace std;

/**
 * @mainpage Documentation for Circular Queue
 * 
 * @section Introduction
 * This program implements a circular queue using an array. It performs basic operations like insertion, deletion, and displaying the elements in the queue.
 * 
 * @section Operations
 * - Insert: Add an element to the queue.
 * - Delete: Remove an element from the queue.
 * - Display: Show all the elements currently in the queue.
 * 
 * @section HowToUse
 * 1. Insert an element into the queue.
 * 2. Delete an element from the queue.
 * 3. Display the current elements in the queue.
 * 4. Exit the program.
 * 
 * @author Md Sazzad Hossian Sohag
 * @author Nim: 20240140253
 * @author Class: E
 * 
 * @copyright Gibran@umy.ac.id (c) 2025
 * 
 * @file circularQueue.cpp
 * @brief A program to implement a circular queue using an array.
 * @version 0.1
 * @date 2025-06-23
 */

/**
 * @class Queue
 * @brief Class to perform operations on a circular queue.
 * 
 * The Queue class provides methods to insert, remove, and display elements in a circular queue implemented using an array. 
 * It handles overflow and underflow conditions.
 */
class Queue
{
private:
    static const int max = 5; /**< Maximum capacity of the queue */
    int FRONT; /**< Index pointing to the front element in the queue */
    int REAR;  /**< Index pointing to the rear element in the queue */
    int queue_array[max]; /**< Array to store the elements of the queue */

public:
    /**
     * @constructor
     * @brief Default constructor for Queue class.
     * Initializes the queue to an empty state with FRONT = -1 and REAR = -1.
     */
    Queue()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @destructor
     * @brief Destructor for Queue class.
     * Cleans up the resources used by the queue (if necessary).
     */
    ~Queue()
    {
        // Destructor: In this case, no specific cleanup is needed since no dynamic memory is used.
    }

    /**
     * @function
     * @brief Insert an element into the queue.
     * 
     * This function inserts an element at the rear of the queue. If the queue is full, it displays a message indicating overflow.
     */
    void insert()
    {
        int num;
        cout << "Enter a number: ";
        cin >> num;

        // Check for overflow condition
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n";
            return;
        }

        // First element insertion
        if (FRONT == -1)
        {
            FRONT = 0;
            REAR = 0;
        }
        else if (REAR == max - 1)     // Wrap around
            REAR = 0;
        else
            REAR = REAR + 1;

        queue_array[REAR] = num;      // Insert element at rear
    }

    /**
     * @function
     * @brief Remove an element from the queue.
     * 
     * This function removes the element from the front of the queue. If the queue is empty, it displays a message indicating underflow.
     */
    void remove()
    {
        // Check for underflow condition
        if (FRONT == -1)
        {
            cout << "Queue underflow\n";
            return;
        }

        cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

        // Reset queue if it becomes empty
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else if (FRONT == max - 1)    // Wrap around
            FRONT = 0;
        else
            FRONT = FRONT + 1;        // Move front forward
    }

    /**
     * @function
     * @brief Display the elements in the queue.
     * 
     * This function displays all the elements currently present in the queue. If the queue is empty, it will display an appropriate message.
     */
    void display()
    {
        // Check if queue is empty
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are:\n";

        // Case 1: FRONT is before REAR (normal order)
        if (FRONT <= REAR)
        {
            for (int i = FRONT; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        else
        {
            // Case 2: Circular wrap-around
            for (int i = FRONT; i < max; i++)
                cout << queue_array[i] << " ";
            for (int i = 0; i <= REAR; i++)
                cout << queue_array[i] << " ";
        }
        cout << endl;
    }

    /**
     * @var
     * @brief The maximum capacity of the queue (fixed size).
     */
    static const int max = 5;

    /**
     * @var
     * @brief Index of the front element in the queue.
     */
    int FRONT;

    /**
     * @var
     * @brief Index of the rear element in the queue.
     */
    int REAR;

    /**
     * @var
     * @brief Array that holds the elements of the queue.
     */
    int queue_array[max];
};

/**
 * @brief Main function that runs the circular queue operations.
 * 
 * This function provides a menu-based interface for the user to perform operations like inserting, deleting, and displaying elements in the queue.
 * It continues to run until the user chooses to exit.
 */
int main()
{
    Queue q;
    char ch;

    while (true)
    {
        cout << "\n=====================\n";
        cout << "Menu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            q.insert();    // Insert element into queue
            break;
        case '2':
            q.remove();    // Remove element from queue
            break;
        case '3':
            q.display();   // Display all elements in queue
            break;
        case '4':
            return 0;      // Exit the program
        default:
            cout << "Invalid option!!\n";
            break;
        }
    }
}
