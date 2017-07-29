#
# @brief: Simple makefile tutorial, with split of compiling and linking.
#
# In this example, we separate the executable file creation into two steps: compilation of object files,
# and linking object files together to form executables.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# The variable cpp_file_names is created the same way as before.
#
cpp_file_names = $(wildcard *.cpp)

#
# The variable obj_file_names is created to store the list of object files. By convention, the object files end
# with the extension '.o'
#
obj_file_names = $(patsubst %.cpp, %.o, $(cpp_file_names))

#
# The variable exe_file_names is created the same way as before.
#
exe_file_names = $(patsubst %.cpp, %.exe, $(cpp_file_names))

#
# The recipe for all remains the same as before.
#
all: $(exe_file_names)

#
# The recipe for executable file generation now has the corresponding object file as a dependency. The command
# itself remains the same as before.
#
%.exe: %.o
	g++ -o $(@) $(<)

#
# A new recipe for object file creation is required. This calls g++ with the switch '-c', which tells the compiler to
# restrict itself to object file compilation.
#
%.o: %.cpp
	g++ -c -o $(@) $(<)

#
# The clean recipe remains the same as before. Note that since the object file are created as intermediate steps, and
# not listed as pre-requisites to 'all', the make system automatically deletes them after creating the executables.
# Hence, they need not be listed in the clean command. Later, we'll look at ensuring object file persistence, when
# needed.
#
clean:
	rm $(exe_file_names)
