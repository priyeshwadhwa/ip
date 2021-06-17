#include <string>

class Foo
{
    public:
        Foo() {}
        explicit Foo(std::string _s):s(_s) {}
    private:
        std::string s;
};
int main()
{
    Foo f;
    Foo f1("java");
}