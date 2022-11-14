#include <iostream> 
#include <fstream>
#include <string>


#include "myReadyQueue.h"
#include "myProcess.h"
#include "Scheduler.h"

using namespace std;
int main(int argc, char* argv[]) {

    string file;
    int pid, arrival, burst, priority, Algo, quantum_size;
    ReadyQueue* readyQueue = new ReadyQueue();
    cout << "Enter File Name: ";
    cin >> file;
    ifstream data(file);
    if (!data) {
        cout << "Unable to open the file";
        exit(1);
    }

    int count = 0;
    while (data >> pid >> arrival >> burst >> priority) {
        readyQueue->enqueue(new Process(pid, arrival, burst, priority));
        count++;
    }


    Scheduler scheduler;
    cout << "Enter 1 For FCFS:\nEnter 2 for ROUND ROBIN:\nEnter 3 for SRTF:\n";
    cin >> Algo;
    switch (Algo) {
    case 1:
        cout << "**************************************************************************" << endl;
        cout << "**********************************     FCFS    ***************************" << endl;
        cout << "**************************************************************************" << endl;
        scheduler.fcfsSchedule(readyQueue);
        break;
    case 2:
        cout << "Enter Quantum Size: ";
        cin >> quantum_size;
        cout << "**************************************************************************" << endl;
        cout << "********************************** ROUND ROBIN ***************************" << endl;
        cout << "************************** (No. of Task=" << count << " Quantum=" << quantum_size << ") *******************" << endl;
        cout << "**************************************************************************" << endl;
        scheduler.rrSchedule(readyQueue, quantum_size);
        break;
    case 3:
        cout << "*************************************************************************" << endl;
        cout << "**********************************     SRTF    **************************" << endl;
        cout << "*************************************************************************" << endl;
        scheduler.srtfSchedule(readyQueue);
        break;
    default:
        cout << "Invalid Input please enter 1-3 only";
        exit(1);
    }

}