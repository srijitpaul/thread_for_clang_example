#include <Threads.h>
#include <iostream>

class TestClass
{
public:
    int result=0;

    int sum(int a, int b, int c)
    {
        return a*b + c;
    }

    // Might be containers of types too...
    template<class T, class V>
    inline void runSum(T i, V j)
    {
        thread_for( i, j, 
        {
            for (int m = 0; m < 3; m++) 
            {
                for (int si = 0; si < m; si++) 
                {
                    result += sum(si, m, j);
                }
            }
        })
    }

};

int main(int argc, char** argv)
{
    TestClass t;
    t.runSum(2, 10);
    std::cout << t.result << std::endl; 
    return 0;
}
