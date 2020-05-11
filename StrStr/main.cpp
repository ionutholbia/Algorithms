#include <stdio.h>
#include <memory>

namespace Interview
{
    class String
    {
    private:
        std::unique_ptr<char[]> _str;
    public:
        String(const char* str)
        { 
            _str = std::make_unique<char[]>(strlen(str));
            memcpy(_str.get(), str, strlen(str));
        }
        
        int str(const char* substring)
        {
            auto strLenght = strlen(_str.get());
            auto subStrLenght = strlen(substring);

            if(strLenght == 0 || subStrLenght == 0 || subStrLenght > strLenght) return -1;

            for(int i = 0; i < strLenght - subStrLenght + 1; i++)
            {
                auto success = memcmp(_str.get() + i, substring, subStrLenght);
                if(success == 0) return i;
            }

            return -1;
        }
    };
}


int main(void)
{
    Interview::String str1("Hello World");
    printf("%d\n", str1.str("Hello"));

    Interview::String str4("Hello World");
    printf("%d\n", str4.str("World"));

    Interview::String str2("Interview with fb");
    printf("%d\n", str2.str("with"));

    Interview::String str3("Hello World");
    printf("%d\n", str3.str("something else"));

    return 0;
}