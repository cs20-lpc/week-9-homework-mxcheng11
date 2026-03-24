#include <iostream>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
#include "QueueFactory.hpp"
#include <ctime>
#include <cstdlib>

using namespace std; 

int main()
{
    srand(time(0)); 
    
    // Simulation 1
    cout << " Simulation 1: Tix Counter (Max Size 10)" << endl;
    Queue<int>* q1 = QueueFactory<int>::GetQueue(10);
    
    for (int i = 0; i < 100; i++)
    {
        int randNum = (rand() % 3) - 1; 
        
        if (randNum < 0) // customer served (dequeue)
        {
            try 
            {
                if (q1->isEmpty())
                {
                    cout << "Queue is empty, no customers to serve." << endl;
                }
                else
                {
                    int servedCustomer = q1->front();
                    q1->dequeue();
                    cout << "Customer " << servedCustomer << " served and left.\n"
                    << "Queue length: " << q1->getLength() << endl;
                }
            }
            catch (const string& e)
            {
                cout << e << endl;
            }
        }
        else // new customer in line (enqueue)
        {
            try 
            {
                if (q1->getLength() == 10)
                {
                    cout << "Queue is full. Customer " << i << " turned away." << endl;
                }
                else
                {
                    q1->enqueue(i);
                    cout << "Customer " << i << " in line.\n" 
                    << "Queue length: " << q1->getLength() << endl;
                }
            }
            catch (const string& e)
            {
                cout << e << endl;
            }
        }
    }
    
    cout << "\n Simulation 2: Bank Service Line (no max size)" << endl;
    
    // Simulation 2: Bank service line with linked queue (no max size)
    Queue<string>* q2 = QueueFactory<string>::GetQueue();
    
    for (int i = 0; i < 100; i++)
    {
        int randNum = (rand() % 4) - 1; 
        
        if (randNum < 0) // customer served (dequeue)
        {
            try 
            {
                if (q2->isEmpty())
                {
                    cout << "Queue is empty, no customers to serve." << endl;
                }
                else
                {
                    string servedCustomer = q2->front();
                    q2->dequeue();
                    cout << servedCustomer << " served and left. Queue length: " << q2->getLength() << endl;
                }
            }
            catch (const string& e)
            {
                cout << e << endl;
            }
        }
        else // new customer in line (enqueue)
        {
            string customerName = "Customer " + to_string(i);
            q2->enqueue(customerName);
            cout << customerName << " in line. "
            << endl<< "Queue length: " << q2->getLength() << endl;
        }
    }
    
    // Clean up memory
    delete q1;
    delete q2;
    
    return 0;
}