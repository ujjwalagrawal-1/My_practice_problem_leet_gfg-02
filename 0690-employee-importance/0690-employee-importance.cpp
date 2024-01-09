class Solution {
public:
    void solve(vector<Employee*> &employees, int id, int &sum, int index) {
        if (index >= employees.size()) {
            return;
        }

        Employee* pe = employees[index];
        if (pe->id == id) {
            sum += pe->importance;
            for (int subordinateId : pe->subordinates) {
                solve(employees, subordinateId, sum, 0);
            }
        } else {
            solve(employees, id, sum, index + 1);
        }
    }

    int getImportance(vector<Employee*> &employees, int id) {
        int sum = 0;
        solve(employees, id, sum, 0);
        return sum;
    }
};
