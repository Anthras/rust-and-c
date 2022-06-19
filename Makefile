all: test.c
	cargo build --release && gcc test.c -L./target/release -ltoddrustlibrary -o test

clean:
	rm test && rm -rf ./target
