#include<iostream>
using namespace std;

class RoundRobin{

private:
    int numberOfProcesses;
    int processes[20]; //max limit is 20 processes
    int burstTime[20];
    int waitingTime[20];
    int turnAroundTime[20];
    int timeQuantum;

public:
    RoundRobin(){
        numberOfProcesses = 4;
        timeQuantum = 3;
        for(int i = 1; i <= 4; i++){
            processes[i] = i;
        }
        cout << "Enter the burst time for the 4 processes: ";
        for(int i = 0; i < 4; i++){
            cin >> burstTime[i] ;
        }
    }

    void funcWaitingTime() {
        int remBurstTime[numberOfProcesses];
        for (int i = 0; i < numberOfProcesses; i++) {

            // initializing the remaining time for all processes
            remBurstTime[i] = burstTime[i];
        }
        int t = 0;
        while (true) {
            bool check = true;
            for (int i = 0; i < numberOfProcesses; i++) {
                if (remBurstTime[i] > 0) {
                    check = false;

                    if (remBurstTime[i] > timeQuantum) {
                        t += timeQuantum;
                        remBurstTime[i] -= timeQuantum;
                    } else {
                        t = t + remBurstTime[i];
                        waitingTime[i] = t - burstTime[i];
                        remBurstTime[i] = 0;
                    }
                }
            }
            if (check)
                break;
        }
    }

    void funcTurnAroundTime(){
        for (int i = 0; i < numberOfProcesses ; i++)
            turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }

    void AvgTime(){
        int totalWaitingTime = 0,  totalTurnAroundTime = 0;
        funcWaitingTime();
        funcTurnAroundTime();
        cout << "Processes "<< " Burst time " << " Waiting time " << " Turn around time" << endl;
        for (int i=0; i < numberOfProcesses; i++)
        {
            totalWaitingTime = totalWaitingTime + waitingTime[i];
            totalTurnAroundTime = totalTurnAroundTime + turnAroundTime[i];
            cout << " " << i+1 << "\t\t\t" << burstTime[i] << "\t\t\t " << waitingTime[i]
            << "\t\t\t " << turnAroundTime[i] << endl;
        }
        cout << "Average waiting time = " << (float)totalWaitingTime / (float)numberOfProcesses << endl;
        cout << "Average turn around time = " << (float)totalTurnAroundTime / (float)numberOfProcesses << endl;
    }
};


int main() 
{
	RoundRobin obj = RoundRobin();
    obj.AvgTime();
	return 0; 
} 