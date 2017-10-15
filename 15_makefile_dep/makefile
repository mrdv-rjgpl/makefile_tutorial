#
# @brief: Simple makefile tutorial, with a second makefile dependency list auto-generated.
#
# In this example, we add an empty makefile.dep file, and include it in the makefile. Over the next few tutorials, we
# will turn this file into something useful.
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
# A new variable for the makefile dependency list is created, with the required file name stored.
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
# The recipe for all has the makefile_dep variable added as a prerequisite.
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
# A recipe for creating the makefile dependency list is added. For now, this file is empty, barring some comments
# inserted at the beginning. The fist command in this recipe deletes the previous makefile dependency list, if it
# exists, and creates a new, empty, file with the same name. The second command does the actual writing (appending to
# the pre-existing empty file).
#
$(makefile_dep):
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)

#
# The clean recipe now has the makefile_dep variable added to it.
#
clean:
	rm -rf $(bin_dir) $(build_dir) $(makefile_dep)
