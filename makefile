SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp, obj/%.o, $(SOURCES))
DEPENDS := $(patsubst src/%.cpp, deps/%.dep, $(SOURCES))
INCLUDES := -I./src

bin/program : $(OBJECTS)
	@mkdir -p bin
	@g++ $(OBJECTS) -o $@


obj/%.o : src/%.cpp 
	@mkdir -p ./obj
	g++ -c $< $(INCLUDES) -o $@

deps/%.dep : src/%.cpp
	@mkdir -p ./deps
	@g++ -MM $< -MT "$@ $(subst %.dep, %.o, $@)" -o $@ $(INCLUDES)

-include $(DEPENDS)

.PHONY : clean docs
clean :
	@echo "cleaning up"
	@rm -rf  deps obj bin docs/doxygen test_results.txt
	
docs : 
	@mkdir -p docs/doxygen
	@doxygen docs/doxygen_config/config
