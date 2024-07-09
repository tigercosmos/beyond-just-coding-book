class FooTest;

class Foo
{
public:
    int public_sum(int a, int b);

private:
    int private_sum(int a, int b);

    friend FooTest; // for unit test
};