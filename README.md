# rust-and-c
A very short demo of how to use Rust code as a static library for C projects

## Quick Demo

### Cargo.toml
Add to Cargo.toml the follow to make sure when building the cargo project to produce a static library with the name libtoddrustlibrary.a

```toml
[lib]
name = "toddrustlibrary"
crate-type = ["staticlib"]
```

### /src/lib.rs
In /src/lib.rs be sure to include `#[no_mangle]` before the function and to export the function for C with `pub extern "C"` such as 

```rust
#[no_mangle]
pub extern "C" fn add_these_ints(a: i32, b: i32) -> i32 {
    a + b
}
```

### Header file
The header file contains the definitions of the functions from lib.rs

```c
void hello_from_rust();
int add_these_ints(int a, int b);
```

### C code file
Include the header file in your C file and use as if it were native C code

```c
#include "my_rust_project.h"
```

### Makefile
The Makefile builds the libtoddrustlibrary.a static library and links it using `gcc`
```makefile
all: test.c
	cargo build --release && gcc test.c -L./target/release -ltoddrustlibrary -o test
```
use the Makefile with `make all` or `make clean`
