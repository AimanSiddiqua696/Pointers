#include <iostream>
#include <queue>
using namespace std;

struct PrintJob {
    int id;
    string name;
};

class PrinterQueue {
    queue<PrintJob> q;
    int jobCount;

public:
    PrinterQueue() {
        jobCount = 0;
    }

    // Add a print job
    void addJob(string name) {
        jobCount++;
        PrintJob job = {jobCount, name};
        q.push(job);
        cout << "Job " << job.id << " (" << job.name << ") added to queue\n";
    }

    // Process a print job
    void processJob() {
        if (q.empty()) {
            cout << "No jobs in queue\n";
            return;
        }
        PrintJob job = q.front();
        q.pop();
        cout << "Printing Job " << job.id << " (" << job.name << ")\n";
    }

    // View pending jobs
    void viewQueue() {
        if (q.empty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Pending Jobs: ";
        queue<PrintJob> temp = q;
        while (!temp.empty()) {
            PrintJob job = temp.front();
            temp.pop();
            cout << job.id << "(" << job.name << ") ";
        }
        cout << endl;
    }
};

int main() {
    PrinterQueue pq;

    pq.addJob("Document1");
    pq.addJob("Document2");
    pq.addJob("Document3");

    pq.viewQueue();

    pq.processJob();
    pq.processJob();

    pq.viewQueue();

    pq.processJob();
    pq.processJob(); // Test empty queue

    return 0;
}