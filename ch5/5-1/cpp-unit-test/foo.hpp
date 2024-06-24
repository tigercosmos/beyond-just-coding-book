class FooTest;

class Foo
{
public:
    int PublicSum(int a, int b);

private:
    int _PrivateSum(int a, int b);

    friend FooTest;
};