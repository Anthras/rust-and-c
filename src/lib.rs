#[no_mangle]
pub extern "C" fn hello_from_rust() {
    println!("Hello! This function is called from Rust within C");
}

#[no_mangle]
pub extern "C" fn add_these_ints(a: i32, b: i32) -> i32 {
    a + b
}
