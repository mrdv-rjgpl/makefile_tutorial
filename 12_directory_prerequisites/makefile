#
# @brief: Simple makefile tutorial, with directories added as prerequisites for various steps in the compilation.
#
# In this example, we remove the previous assumption of pre-existing directories, and instead add them as prerequisites
# for the corresponding object files, executables, and listing files.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# A variable dir_sep is created, to simplify the multiple references to the directory separation character, for cross
# OS compatibility down the line.
#
dir_sep = /
#
# The variables for the directory names now refer to the dir_sep variable, for simplicity.
#
bin_dir   = bin$(dir_sep)
build_dir = build$(dir_sep)
src_dir   = src$(dir_sep)

#
# The variable cpp_file_names remains the same as before.
#
cpp_file_names = $(wildcard $(src_dir)*.cpp)

#
# The variables obj_file_names, exe_file_names, and lst_file_names remain the same as before.
#
obj_file_names = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(cpp_file_names))
exe_file_names = $(patsubst $(src_dir)%.cpp, $(bin_dir)%.exe, $(cpp_file_names))
lst_file_names = $(patsubst $(src_dir)%.cpp, $(bin_dir)%.lst, $(cpp_file_names))

#
# The recipe for all remains the same as before.
#
all: $(exe_file_names) $(lst_file_names)

#
# A new recipe for directory creation is added, matching any pattern that ends with the dir_sep character.
#
%$(dir_sep):
	mkdir $(@)

#
# The recipe for listing file generation now has the bin directory as a prerequisite.
#
%.lst: %.exe $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

#
# The recipe for executable file generation now has the bin directory as a prerequisite.
#
$(bin_dir)%.exe: $(build_dir)%.o $(bin_dir)
	g++ -o $(@) $(<)

#
# The recipe for object file generation now has the build directory as a prerequisite.
#
$(build_dir)%.o: $(src_dir)%.cpp $(build_dir)
	g++ -c -o $(@) $(<)

#
# The clean recipe is now simplified to remove the folders themselves, as they are recreated with every compilation.
#
clean:
	rm -rf $(bin_dir) $(build_dir)
