#
# @brief: Makefile tutorial, with merged recipes for object file generation.
#
# This tutorial merges the recipes for object file generation, as they are identical to each other. The recipe's use
# of the $(<) variable in the absence of explicitly listed prerequisites is to be noted here. The prerequisites for the
# object file compilation are sourced from the makefile dependency list.
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
main_dir  = main$(dir_sep)
src_dir   = src$(dir_sep)

#
# The variable makefile_dep remains the same as before.
#
makefile_dep=makefile.dep

#
# The variables for the file names remain the same as before.
#
src_file_names  = $(wildcard $(src_dir)*.cpp)
obj_file_names  = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(src_file_names))
main_file_names = $(wildcard $(main_dir)*.cpp)
exe_file_names  = $(patsubst $(main_dir)%.cpp, $(bin_dir)%.exe, $(main_file_names))
lst_file_names  = $(patsubst $(main_dir)%.cpp, $(bin_dir)%.lst, $(main_file_names))

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
# The recipe for listing file generation remains the same as before.
#
%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

#
# The recipe for executable generation remains the same as before.
#
$(bin_dir)%.exe: $(build_dir)%.o $(obj_file_names) | $(bin_dir)
	g++ -o $(@) $(^)

#
# The recipes for object file generation are merged into a single recipe, relying on the makefile dependency list to
# determine the correct C++ files to be used in the compilation command.
#
$(build_dir)%.o: | $(build_dir)
	g++ -c -o $(@) $(<)

#
# The recipe for the makefile dependency list generation remains the same.
#
$(makefile_dep):
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s/\.cpp/\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

#
# The inclusion of the makefile dependency list remains the same.
#
-include $(makefile_dep)

#
# The clean recipe remains the same.
#
clean:
	rm -rf $(bin_dir) $(build_dir) $(makefile_dep)
