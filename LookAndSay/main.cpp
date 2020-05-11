#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

std::string generateNextSequence(std::string sequence) {
    auto count = 1;
    auto currentNumber = sequence[0];

    std::string output;
    for(int index = 1; index < sequence.size(); index++)
    {
        if(currentNumber == sequence[index]) {
            count++;
            continue;
        } 

        output.append(std::to_string(count));
        output.push_back(currentNumber);
        currentNumber = sequence[index];
        count = 1;
    }

    output.append(std::to_string(count));
    output.push_back(currentNumber);

    return output;
}

std::vector<std::string> lookAndSay(int maxLines) 
{
    if(maxLines <= 0) return std::vector<std::string>();

    std::vector<std::string> output = {"1"};

    for(auto line = 1; line < maxLines; line++)
    {
        output.push_back(generateNextSequence(output[line - 1]));
    }

    return output;
}

int main()
{
    auto sequences = lookAndSay(30);
    for(auto i = 0; i < sequences.size(); i++) {
        std::cout<<sequences[i]<<"\n";
    }

    return 0;
}