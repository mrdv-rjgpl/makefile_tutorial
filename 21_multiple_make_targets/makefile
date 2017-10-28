#
# @brief: Makefile tutorial, with multiple options for the final deployment target
#
# Often, one will require separate compilation flags for separate execution environments. This makefile offers a
# distinction between debug and run executables.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

dir_sep = /

bin_dir   = bin$(dir_sep)
build_dir = build$(dir_sep)
main_dir  = main$(dir_sep)
src_dir   = src$(dir_sep)
test_dir  = test$(dir_sep)


src_file_names  = $(wildcard $(src_dir)*.cpp)
main_file_names = $(wildcard $(main_dir)*.cpp)
test_file_names = $(wildcard $(test_dir)*.cpp)

#
# A list of possible make types is collated for ease of reference.
#
make_types = debug run

#
# The variable MAKECMDGOALS contains the targets supplied from the command line. If the user commands a compilation of
# the debug executable, then the debug flag is set to -g, and the executable and object file names get the suffix
# '_debug' before the file extension.
#
ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	cdflags   = -g
	make_type = debug
endif # MAKECMDGOALS

#
# The variable MAKECMDGOALS contains the targets supplied from the command line. If the user commands a compilation of
# the run executable, then the debug flag is set to an empty string, and the executable and object file names get the
# suffix '_run' before the file extension.
#
ifeq ($(filter run,$(MAKECMDGOALS)),run)
	cdflags   =
	make_type = run
endif # MAKECMDGOALS

#
# The variables makefile_dep, obj_file_names, and exe_file_names are modified to include the make_type suffix for
# readability.
#
makefile_dep=makefile_$(make_type).dep
obj_file_names  = $(patsubst $(src_dir)%.cpp, $(build_dir)%_$(make_type).o, $(src_file_names))
exe_file_names := $(patsubst $(main_dir)%.cpp, $(bin_dir)%_$(make_type).exe, $(main_file_names))
exe_file_names := $(patsubst $(test_dir)%.cpp, $(bin_dir)%_$(make_type).exe, $(test_file_names)) $(exe_file_names)
#
# The list of listing files is simplified, to minimize the number of variables that need to be changed from target to
# target.
#
lst_file_names  = $(patsubst %.exe, %.lst, $(exe_file_names))

cwflags = -Wall -Werror
caflags = $(cdflags) $(cwflags)

#
# The recipe for all is modified to output the possible compilation types, as the user is no longer allowed to use the
# bare `make` command.
#
all:
	echo "Compilation options: $(make_types)"

#
# A recipe for make_types is added, with the dependencies that were previously attached to the recipe for all.
#
$(make_types): $(exe_file_names) $(lst_file_names) $(makefile_dep)

%$(dir_sep):
	mkdir $(@)

%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

$(bin_dir)%.exe: $(build_dir)%.o $(obj_file_names) | $(bin_dir)
	g++ -o $(@) $(^)

$(build_dir)%.o: | $(build_dir)
	g++ $(caflags) -c -o $(@) $(<)

#
# The recipe for makefile_dep is modified to add make_type to the output of the pre-requisite generation call.
#
$(makefile_dep):
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names) $(test_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s.$(test_dir).$(build_dir)." -e "s/\.cpp/_$(make_type)\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

-include $(makefile_dep)

#
# The clean recipe is modified to remove all files of the type makefile*.dep, instead of the specific variable
# makefile_dep, as that will no longer be exhaustive.
#
clean:
	rm -rf $(bin_dir) $(build_dir) makefile*.dep
