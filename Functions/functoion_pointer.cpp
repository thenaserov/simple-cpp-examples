#include <stdio.h>

void add(int a, int b) {
    printf("%d + %d = %d\\n", a, b, a + b);
}

void subtract(int a, int b) {
    printf("%d - %d = %d\\n", a, b, a - b);
}

int main() {
    void (*func_ptr)(int, int);
    int a = 10, b = 5;
    char op = '+';

    if (op == '+') {
        func_ptr = &add;
    } else if (op == '-') {
        func_ptr = &subtract;
    }

    func_ptr(a, b);

    return 0;
}
