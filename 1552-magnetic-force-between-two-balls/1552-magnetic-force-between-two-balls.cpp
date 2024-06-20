typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int> &position, int mid, int m) {
        ll a = 0;
        ll b = 1;
        m--;
        while (b < position.size() && m > 0) {
            while (b < position.size() && position[b] - position[a] < mid) {
                b++;
            }
            if (b < position.size()) {
                m--;
                a = b;
                b++;
            }
            if(m == 0){
                break;
            }
        }
        return m <= 0;
    }

    int maxDistance(vector<int>& position, int m) {
        // Same like Aggressive Cow Problem 
        // in place of shelter there is can and in place of cow there is Ball

        sort(position.begin(), position.end()); // Sort the position array

        ll s = 1;
        ll e = position[position.size() - 1] - position[0];
        int answer = 0;

        while (s <= e) {
            ll mid = s + (e - s) / 2;
            if (isPossible(position, mid, m)) {
                answer = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }

        return answer;
    }
};
