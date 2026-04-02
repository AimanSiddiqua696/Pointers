
int main() {
    priority_queue<Job, vector<Job>, Compare> pq;

    pq.push({1, 5});  // Job 1, priority 5
    pq.push({2, 10}); // Job 2, priority 10
    pq.push({3, 1});  // Job 3, priority 1

    while (!pq.empty()) {
        cout << "Job " << pq.top().id << " with priority " << pq.top().priority << endl;
        pq.pop();
    }

    return 0;
}