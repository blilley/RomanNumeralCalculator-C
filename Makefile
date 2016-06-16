objects := $(patsubst src/%.c,src/%.o,$(wildcard src/*.c))
testObjects := $(patsubst test/%.c, test/%.o,$(wildcard test/*.c))

test: compile
	@echo "***Running Tests***\n"
	@output/testrunner

compile: $(objects) $(testObjects)
	@mkdir -p output
	@echo "Compiling..."
	@gcc -o output/testrunner $(objects) $(testObjects) `pkg-config --cflags --libs check`

clean:
	@echo "Cleaning output files and folders...\n"
	@rm -r -f src/*.o test/*.o output
