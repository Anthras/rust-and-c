#include <stdio.h>
#include "my_rust_project.h"

void hello_from_c() {
    printf("Hello from C\n\n");
}

int main() {
    hello_from_c();
    
    hello_from_rust();

    printf("\nUsing add_these_ints(2,3) from Rust gives %d\n", add_these_ints(2,3));

    return 0;
}
