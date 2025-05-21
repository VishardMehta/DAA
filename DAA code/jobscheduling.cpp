#include <iostream>
using namespace std;

struct job {
    char id;
    int dead;
    int profit;
};

void sort_jobs(job j[], int n) {
    // sort by profit descending
    for (int i = 0; i < n - 1; i++) {
        for (int k = i + 1; k < n; k++) {
            if (j[k].profit > j[i].profit) {
                job temp = j[i];
                j[i] = j[k];
                j[k] = temp;
            }
        }
    }
}

int main() {
    job j[] = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int n = sizeof(j) / sizeof(j[0]);

    sort_jobs(j, n);

    int max_dead = 0;
    for (int i = 0; i < n; i++) {
        if (j[i].dead > max_dead)
            max_dead = j[i].dead;
    }

    char slot[max_dead];
    for (int i = 0; i < max_dead; i++)
        slot[i] = '-';

    int total = 0;

    for (int i = 0; i < n; i++) {
        for (int d = j[i].dead - 1; d >= 0; d--) {
            if (slot[d] == '-') {
                slot[d] = j[i].id;
                total += j[i].profit;
                break;
            }
        }
    }

    cout << "jobs done: ";
    for (int i = 0; i < max_dead; i++) {
        if (slot[i] != '-')
            cout << slot[i] << " ";
    }

    cout << "\ntotal profit: " << total << endl;

    return 0;
}
