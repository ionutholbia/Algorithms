#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

pair<string, vector<int>> findFirstSubstring(const string& str, int wantedCount) {
    unordered_map<string, int> subStrsCount;
    vector<pair<string, vector<int>>> subStrs;

    int startIndex = 0;
    for(auto index = 1; index < str.size(); index++) {
        if(str[startIndex] == str[index]) {
            string currentSubStr;
    
            for (auto i = 0; i < index; i++)
            {
                if(str[i] == str[index + i]) currentSubStr.push_back(str[i]);
                else break;

                if(subStrsCount.find(currentSubStr) == subStrsCount.end()) {
                    subStrs.push_back(pair<string, vector<int>>(currentSubStr, index));
                    subStrsCount[currentSubStr] = 2;
                }
                else subStrsCount[currentSubStr]++;
            }      
        }
    }

    for(auto str : subStrs) {
        if(subStrsCount[str.first] == wantedCount) return str;
    }

    return {};
}

vector<string> patternMatcher(string pattern, string str) {
    int nrOfX = 0;
    int nrOfY = 0;

    for(auto i : pattern) {
        if(pattern[i] == 'x') nrOfX++;
        else nrOfY++;
    }

    int intFirstPatternCount = pattern[0] == 'x' ? nrOfX : nrOfY;

    auto firstStr = findFirstSubstring(str, intFirstPatternCount);
    if(firstStr.first.size() == 0) return {};

    auto var = "";
    
}


int main(void)
{
    patternMatcher("xxyxxy", "gogopowerrangergogopowerranger");
    return 0;
}