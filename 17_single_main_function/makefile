#
# @brief: Makefile tutorial, with single main executable generated from separate folders.
#
# This tutorial assumes that all C++ files in src/ are used as sources of functions by C++ files in main/, and that
# all executables are generated using exactly one C++ file in main/, and all C++ files in src/.
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
# The variable cpp_file_names is no longer used. Instead, we have src_file_names, containing the names of all C++ files
# in src/, and obj__file_names containing all object files created from src_file_names. We also have main_file_names,
# containing all of the C++ files in the folder main/, and exe_file_names and lst_file_names, derived from
# main_file_names.
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
# The recipe for executable generation is now modified to list all object files as prerequisites. Although this recipe
# theoretically would match any pattern ending with '.exe' to the corresponding pattern ending with '.o' (directory
# names taken into consideration, of course), only the files from main/ actually end up as executables. This is
# enforced during the creation of the variable exe_file_names, which excludes C++ file names from src/. Also, the
# compilation rule's last variable changes from '$(<)' to '$(^)' as instead of one object file, we now have multiple
# object files to link together.
# N.B. The variable '$(^)' appears to take only normal prerequisites, and not order-only prerequisites.
#
$(bin_dir)%.exe: $(build_dir)%.o $(obj_file_names) | $(bin_dir)
	g++ -o $(@) $(^)

#
# The recipe for object file generation remains the same. However, an identical recipe is added to generate object
# files from the contents of the directory main/. It is identical to the original recipe in every way, except for the
# pattern of the first prerequisite, which is changed from src_dir to main_dir.
#
$(build_dir)%.o: $(src_dir)%.cpp | $(build_dir)
	g++ -c -o $(@) $(<)

$(build_dir)%.o: $(main_dir)%.cpp | $(build_dir)
	g++ -c -o $(@) $(<)

#
# The recipe for the makefile dependency list generation is modified to account for the shift from cpp_file_names to
# src_file_names and main_file_names.
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
# The clean recipe now has the makefile_dep variable added to it.
#
clean:
	rm -rf $(bin_dir) $(build_dir) $(makefile_dep)
