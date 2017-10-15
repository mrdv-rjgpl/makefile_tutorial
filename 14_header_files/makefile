#
# @brief: Simple makefile tutorial, with a directory of header files created.
#
# In this example, we add the header files for each C++ file, in a directory called 'include/'. No changes are made to
# the makefile. This example is a step in the direction of creating targeted executables for testing.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# The variable dir_sep remains the same as before.
#
dir_sep = /
#
# The variables for the directory names remain the same as before.
#
bin_dir   = bin$(dir_sep)
build_dir = build$(dir_sep)
src_dir   = src$(dir_sep)

#
# The variables cpp_file_names, obj_file_names, exe_file_names, and lst_file_names remain the same as before.
#
cpp_file_names = $(wildcard $(src_dir)*.cpp)
obj_file_names = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(cpp_file_names))
exe_file_names = $(patsubst $(src_dir)%.cpp, $(bin_dir)%.exe, $(cpp_file_names))
lst_file_names = $(patsubst $(src_dir)%.cpp, $(bin_dir)%.lst, $(cpp_file_names))

#
# The recipe for all remains the same as before.
#
all: $(exe_file_names) $(lst_file_names)

#
# The recipe for directory creation remains the same as before.
#
%$(dir_sep):
	mkdir $(@)

#
# The recipes for listing file generation, executable file generation, and object file generation remain the same as
# before.
#
%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

$(bin_dir)%.exe: $(build_dir)%.o | $(bin_dir)
	g++ -o $(@) $(<)

$(build_dir)%.o: $(src_dir)%.cpp | $(build_dir)
	g++ -c -o $(@) $(<)

#
# The clean recipe remains the same as before.
#
clean:
	rm -rf $(bin_dir) $(build_dir)
