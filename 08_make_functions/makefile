#
# @brief: Simple makefile tutorial, with several make functions.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# In the previous example, we took the first step to making the makefile immune to the number of, and names of, files
# that need to be compiled. The next step is to use in-built make functions to dynamically generate a list of file
# names and derive the corresponding executable names from them.
#

#
# The variable cpp_file_names is created by searching through the current directory for files matching the pattern
# '*.cpp'. The wildcard function allows us to search for files whose names match the supplied regular expressions.
#
cpp_file_names = $(wildcard *.cpp)

#
# From the list of file names we now derive the corresponding executable file names. To do this, we use the patsubst
# function, which allows us to run a find-and-replace operation in a string. We parse the contents of cpp_file_names
# for space-separated words and replace each occurrence of '.cpp' with '.exe'. This produces the list of executable
# files.
#
# Note that we cannot directly use the expression $(wildcard *.exe) to create our list of executable files, as the
# executable files are created by the ` make ` command, and their existence is not guaranteed prior to running that
# command.
#
exe_file_names = $(patsubst %.cpp, %.exe, $(cpp_file_names))

#
# The recipe for all remains the same as before.
#
all: $(exe_file_names)

#
# The recipe for executable file generation remains the same as before.
#
%.exe: %.cpp
	g++ -o $(@) $(<)

#
# The clean recipe remains the same as before.
#
clean:
	rm $(exe_file_names)
