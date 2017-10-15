#
# @brief: Makefile tutorial, with a second makefile dependency list auto-generated.
#
# In this example, we add auto-generated dependencies to the makefile dependency list, using the -MM switch in the GNU
# compiler.
#
# The -MM switch allows us to list out the various header files necessary for the compilation of an object file. In
# addition to this, we use the -MT switch to indicate the precise target name that we want the compiler to output
# during this operation.
#
# This system can be tested by running ```make```, followed by ```touch include/add_two_numbers.hpp```, and then
# ```make``` again. The second ```make``` command will result in the recompilation of build/add_two_numbers.o, the
# executable bin/add_two_numbers.exe, and the listing file bin/add_two_numbers.lst. Running this sequence of commands
# on previous tutorials will result in nothing on the second command. This makes our make system sensitive to changes
# in the header file, which is useful when the only change made is a macro redefinition, or the like.
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
# The variable makefile_dep remains the same as before.
#
makefile_dep=makefile.dep

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
all: $(exe_file_names) $(lst_file_names) $(makefile_dep)

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
# The recipe for the makefile dependency list generation is modified to include the auto-generated prerequisites from
# the -MM switch of the GNU compiler. The first '-e' switch in the sed command uses '.' instead of '/' as a delimiter,
# because the variables src_dir and build_dir contain '/', and there is no easy way to add a '\' to that. Instead,
# we modify the delimiter itself, to allow the use of '/' in the patterns. The second '-e' switch does not contain any
# '/' characters, and hence, the default '/' delimiter is used. The usage of '$$' is to pass the string '$x' to the
# underlying shell for use in the for loop.
#
# Normally, each shell command is executed by a different instance of the shell, which would cause problems during the
# execution of the for loop. Hence, it is denoted as a single line command, with the use of '\' at the end of each line
# for readability.
#
$(makefile_dep):
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(cpp_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s/\.cpp/\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

#
# The inclusion of the makefile dependency list remains the same.
#
-include $(makefile_dep)

#
# The clean recipe now has the makefile_dep variable added to it.
#
clean:
	rm -rf $(bin_dir) $(build_dir) $(makefile_dep)
