#include <vector>
#include <iostream>
#include <queue>
#include <memory>

using namespace std;

class QueueData {
public:
    QueueData(int cellNumber, int rolls) : cellNumber_(cellNumber), rolls_(rolls) {}
    int cellNumber_;
    int rolls_;
};

int isAJump(int element, vector<vector<int>>& laddersOrSnakes) {
    for(int iter = 0; iter < laddersOrSnakes.size(); iter++) {
        if (laddersOrSnakes[iter][0] == element) return laddersOrSnakes[iter][1];
    }

    return 0;
}

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    const int boardSize = 100;
    const int dieMax = 6;

    queue<QueueData*> dataQueue;
    vector<bool> visited(boardSize + 1, false);

    dataQueue.push(new QueueData(1, 0));
    visited[1] = true;

    while(!dataQueue.empty())
    {
        std::unique_ptr<QueueData> element(dataQueue.front());
        dataQueue.pop();

        for (int i = element->cellNumber_ + 1; i <= element->cellNumber_ + dieMax; i++) {
            if(visited[i]) continue;

            if(i == boardSize) return element->rolls_ + 1;

            int cellNumber = i;
            auto jump = isAJump(i, ladders);
            if(jump != 0) {
                cellNumber = jump;
            }
            else {
                jump = isAJump(i, snakes);
                if(jump != 0) cellNumber = jump;           
            }
            if(jump == boardSize) return element->rolls_ + 1;

            auto rolls = element->rolls_ + 1;
            dataQueue.push(new QueueData(cellNumber, rolls));
            visited[i] = true;
        }
    }

    return -1;
}

int main()
{
    {
        vector<vector<int>> ladders = {{32, 62}, {42, 68}, {12, 98}};
        vector<vector<int>> snakes = {{95, 13}, {97, 25}, {93, 37}, {79, 27}, {75, 19}, {49, 47}, {67, 17}};

        int result = quickestWayUp(ladders, snakes);
        cout<<"Result: "<<result<<"\n";
    }

    {
        vector<vector<int>> ladders = {{3,5},{7,8},{44,56},{36,54},{88,91},{77,83},{2,4},{9,99},{45,78},{31,75}};
        vector<vector<int>> snakes = {{10,6},{95,90},{96,30},{97,52},{98,86}};

        int result = quickestWayUp(ladders, snakes);
        cout<<"Result: "<<result<<"\n";
    }
    {
        vector<vector<int>> ladders = {{3,54},{37,100}};
        vector<vector<int>> snakes = {{56,33}};

        int result = quickestWayUp(ladders, snakes);
        cout<<"Result: "<<result<<"\n";
    }

    return 0;
}
