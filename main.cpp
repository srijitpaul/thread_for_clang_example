class TestClass
{
public:
    void crash() {}

    template<typename T>
    void ompCrash()
    {
        #pragma omp parallel for schedule(static)
        {
            for (uint64_t i=0; i<10; ++i) 
                this->crash();
        }
    }

};

int main(int argc, char** argv)
{
    TestClass t;
    t.ompCrash<void>();
    return 0;
}

