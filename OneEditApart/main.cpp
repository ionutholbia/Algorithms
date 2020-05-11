#include <iostream>
#include <string>

bool OneEditApart(std::string s1, std::string s2)
{
    int diff = s1.size() - s2.size();
    if(diff != 0 && diff != -1 && diff != 1) return false;

    bool change = false;
    bool add = false;

    if(diff != 0) {
        add = true;
    }

    for(int i = 0; i < s1.size(); i++)
    {
        if(i == s2.size()) break;
        
        if(s1[i] != s2[i]) {
            if(s1[i + 1] != s2[i] && s2[i + 1] != s1[i])
            {
                if(change == true) return false;

                change = true;
            }
        }

        if(change && add) return false;
    }

    if(diff == 0 && !change) return false;

    return !(change & add);
}



int main(void)
{
    std::cout<<OneEditApart("geeks", "geek")<<"\n";
    std::cout<<OneEditApart("geeks", "geeks")<<"\n";
    std::cout<<OneEditApart("geaks", "geeks")<<"\n";
    std::cout<<OneEditApart("peaks", "geeks")<<"\n";
    std::cout<<OneEditApart("geeks", "geek")<<"\n";
    std::cout<<OneEditApart("geek", "geeks")<<"\n";
    std::cout<<OneEditApart("geek", "geeksss")<<"\n";
    std::cout<<OneEditApart("", "")<<"\n";

    return 0;
}