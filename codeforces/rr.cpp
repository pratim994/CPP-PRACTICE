#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

void roundRobin(vector<Process>& processes, int quantum) {
    int n = processes.size();
    queue<int> q;
    int currentTime = 0;
    int completed = 0;

    // Sort by arrival time (simple bubble sort for clarity)
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime) {
                swap(processes[j], processes[j+1]);
            }
        }
    }

    int index = 0;

    while(completed < n) {

        // Push processes that have arrived into queue
        while(index < n && processes[index].arrivalTime <= currentTime) {
            q.push(index);
            index++;
        }

        if(q.empty()) {
            currentTime++;
            continue;
        }

        int i = q.front();
        q.pop();

        if(processes[i].remainingTime > quantum) {
            currentTime += quantum;
            processes[i].remainingTime -= quantum;
        } 
        else {
            currentTime += processes[i].remainingTime;
            processes[i].remainingTime = 0;
            processes[i].completionTime = currentTime;
            completed++;
        }

        // Add newly arrived processes
        while(index < n && processes[index].arrivalTime <= currentTime) {
            q.push(index);
            index++;
        }

        // If process still has time left, push it back
        if(processes[i].remainingTime > 0) {
            q.push(i);
        }
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        processes[i].turnAroundTime = 
            processes[i].completionTime - processes[i].arrivalTime;

        processes[i].waitingTime = 
            processes[i].turnAroundTime - processes[i].burstTime;
    }
}

void printTable(vector<Process>& processes) {
    cout << "\n-----------------------------------------------------------------------------------\n";
    cout << "| ID | AT | BT | CT | TAT | WT |\n";
    cout << "-----------------------------------------------------------------------------------\n";

    for(auto &p : processes) {
        cout << "| " << p.id 
             << "  | " << p.arrivalTime
             << "  | " << p.burstTime
             << "  | " << p.completionTime
             << "  | " << p.turnAroundTime
             << "   | " << p.waitingTime
             << "  |\n";
    }

    cout << "-----------------------------------------------------------------------------------\n";
}

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> quantum;

    vector<Process> processes(n);

    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1;

        cout << "\nProcess " << i+1 << endl;
        cout << "Arrival Time: ";
        cin >> processes[i].arrivalTime;

        cout << "Burst Time: ";
        cin >> processes[i].burstTime;

        processes[i].remainingTime = processes[i].burstTime;
    }

    roundRobin(processes, quantum);

    cout << "\nRound Robin Scheduling Result:\n";
    printTable(processes);

    return 0;
}