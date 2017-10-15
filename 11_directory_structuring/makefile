#
# @brief: Simple makefile tutorial, with single level directories for storing source files and executables.
#
# In this example, we add a simple directory structure to our system. As the size of the code base grows, it becomes
# useful to segregate source files from header files, and header files from generated object files and executables. In
# this example, we move our source files into 'src/'. We redirect our object files to be created in a temporary folder
# called 'build/', and our executables and listing files to be created in a folder called 'bin/'. We do not yet have
# header files to worry about, so no directory is made for them. We also assume the existence of the directories before
# the start of the compilation, so as to simplify the makefile.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

#
# Variables for the directory names are created below, one for the source directory, one for the build directory, and
# one for the executable directory. The directory delimiter '/' is added to these variables to allow for cross OS
# compatibility down the line.
#
bin_dir   = bin/
build_dir = build/
src_dir   = src/

#
# The variable cpp_file_names is now changed to source from the source directory.
#
cpp_file_names = $(wildcard $(src_dir)*.cpp)

#
# The variables obj_file_names, exe_file_names, and lst_file_names must now replace the folder names along with the
# file extensions.
#
obj_file_names = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(cpp_file_names))
exe_file_names = $(patsubst $(src_dir)%.cpp, $(bin_dir)%.exe, $(cpp_file_names))
lst_file_names = $(patsubst $(src_dir)%.cpp, $(bin_dir)%.lst, $(cpp_file_names))

#
# The recipe for all has the variable lst_file_names added to it. Note that the executable files remain a dependency,
# as removing them would cause the generated executable files to be treated as an intermediate target, and removed at
# the end of the compilation.
#
all: $(exe_file_names) $(lst_file_names)

#
# The recipe for listing file generation remains the same as before, as the directories for listing files and
# executables are the same.
#
%.lst: %.exe
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

#
# The recipe for executable file generation must now take the directory structure into account.
#
$(bin_dir)%.exe: $(build_dir)%.o
	g++ -o $(@) $(<)

#
# The recipe for object file generation must now take the directory structure into account.
#
$(build_dir)%.o: $(src_dir)%.cpp
	g++ -c -o $(@) $(<)

#
# The clean recipe now includes the listing files.
#
clean:
	rm $(exe_file_names) $(lst_file_names)
