#
# @brief: Simple makefile tutorial, with addition of listing file generation.
#
# In this example, we add the generation of listing files to the compilation process. Listing files are used to analyze
# the generated executable, and to debug the linking process, if required. In this case, since we are using the default
# linking process, the listing file provides information on how that process works, and provides us with a handy tool
# for when we are ready to write our own linking scripts.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# The variable cpp_file_names is created the same way as before.
#
cpp_file_names = $(wildcard *.cpp)

#
# The variable obj_file_names is created the same way as before.
#
obj_file_names = $(patsubst %.cpp, %.o, $(cpp_file_names))

#
# The variable exe_file_names is created the same way as before.
#
exe_file_names = $(patsubst %.cpp, %.exe, $(cpp_file_names))

#
# The variable lst_file_names is created to store the list of listing files. By convention, these files end with the
# extension '.lst'
#
lst_file_names = $(patsubst %.cpp, %.lst, $(cpp_file_names))

#
# The recipe for all has the variable lst_file_names added to it. Note that the executable files remain a dependency,
# as removing them would cause the generated executable files to be treated as an intermediate target, and removed at
# the end of the compilation.
#
all: $(exe_file_names) $(lst_file_names)

#
# A new recipe for generic listing file creation is added, using the 'objdump' utility for its purposes. The executable
# is parsed into its various sections, one by one, and those are then dumped into a human readable text file. A
# detailed explanation of the various sections in an executable will accompany our first attempt at tweaking the
# linking process, down the line.
#
# The first command dumps generic information about the executable to the listing file, while also ensuring that the
# listing file's earlier contents are overwritten. All of the subsequent commands append to the generated listing file.
#
%.lst: %.exe
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

#
# The recipe for executable file generation remains the same as before.
#
%.exe: %.o
	g++ -o $(@) $(<)

#
# The recipe for object file creation remains the same as before.
#
%.o: %.cpp
	g++ -c -o $(@) $(<)

#
# The clean recipe now includes the listing files.
#
clean:
	rm $(exe_file_names) $(lst_file_names)
