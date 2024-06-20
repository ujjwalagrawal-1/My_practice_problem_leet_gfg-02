class Solution {
public:
    pair<int, int> getClosestDivisors(int num) {
        for (int i = sqrt(num); i > 0; --i) {
            if (num % i == 0) {
                return {i, num / i};
            }
        }
        return {1, num};
    }

    vector<int> closestDivisors(int num) {

        auto div1 = getClosestDivisors(num + 1);
        auto div2 = getClosestDivisors(num + 2);

        if (abs(div1.first - div1.second) < abs(div2.first - div2.second)) {
            return {div1.first, div1.second};
        } else {
            return {div2.first, div2.second};
        }
    }
};
