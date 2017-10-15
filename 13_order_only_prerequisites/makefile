#
# @brief: Simple makefile tutorial, with directories added as order-only prerequisites for various steps in the
# compilation.
#
# In the previous example, we added the directories as prerequisites for the corresponding compilation steps. However,
# repeatedly running the command ```make``` in 12_directory_prerequisites/ will lead to repeated compilations of the
# executables, even when not required. This is due to time stamping issues with directories, and can be resolved with
# the use of order-only prerequisites
#
# In this example, we change the directory prerequisites' type from normal to order-only. Prior to this, every
# prerequisite in every makefile has been of the normal type. Order-only prerequisites are distinguished by the
# vertical line preceding them. Order-only prerequisites can be updated without triggering an update of the
# corresponding target. The advantage here is that the command ```make``` can be run multiple times without triggering
# a recompilation every time.
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
# The recipe for directory creation remains the same as before.
#
%$(dir_sep):
	mkdir $(@)

#
# The recipe for listing file generation now has the bin directory as an order-only prerequisite.
#
%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

#
# The recipe for executable file generation now has the bin directory as an order-only prerequisite.
#
$(bin_dir)%.exe: $(build_dir)%.o | $(bin_dir)
	g++ -o $(@) $(<)

#
# The recipe for object file generation now has the build directory as an order-only prerequisite.
#
$(build_dir)%.o: $(src_dir)%.cpp | $(build_dir)
	g++ -c -o $(@) $(<)

#
# The clean recipe remains the same as before.
#
clean:
	rm -rf $(bin_dir) $(build_dir)
