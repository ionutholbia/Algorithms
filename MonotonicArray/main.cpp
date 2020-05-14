#include <vector>

using namespace std;

bool isMonotonic(vector<int> array) {
    if(array.size() <= 1) return false;

    bool increasing = true;
    int startFrom = 0;

    for(auto iter = 0; iter < array.size(); iter++) {
        if(iter == array.size() - 1) return true;

        if(array[iter] == array[iter + 1]) continue;

        increasing = array[iter] < array[iter + 1];
        startFrom = iter + 1;
        break;
    }

    for(auto iter = startFrom; iter < array.size() - 1; iter++) {
        if(increasing) {
            if(array[iter] > array[iter + 1]) return false;
        }
        else {
            if(array[iter] < array[iter + 1]) return false;
        }
    }

    return true;
}

int main(void) {
    vector<int> test = {-1, -5, -10, -1100, -900, -1101, -1102, -9001};
    auto result = isMonotonic(test);
    return 0;
}