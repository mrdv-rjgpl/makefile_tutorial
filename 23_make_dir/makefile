#
# @brief: Makefile tutorial, with makefile dependency lists created in separate folder.
#
# This example pushes the generated makefile dependency lists to a new folder, make_dir.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

dir_sep = /

bin_dir   = bin$(dir_sep)
build_dir = build$(dir_sep)
main_dir  = main$(dir_sep)
#
# A variable is created for the folder containing the dependency lists.
#
make_dir  = make_deps$(dir_sep)
src_dir   = src$(dir_sep)
test_dir  = test$(dir_sep)

src_file_names  = $(wildcard $(src_dir)*.cpp)
main_file_names = $(wildcard $(main_dir)*.cpp)
test_file_names = $(wildcard $(test_dir)*.cpp)

make_types = debug run

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	cdflags   = -g
	make_type = debug
endif # MAKECMDGOALS

ifeq ($(filter run,$(MAKECMDGOALS)),run)
	cdflags   =
	make_type = run
endif # MAKECMDGOALS

#
# The makefile_dep variable is modified to include the make_dir variable.
#
makefile_dep    = $(make_dir)makefile_$(make_type).dep
obj_file_names  = $(patsubst $(src_dir)%.cpp, $(build_dir)%_$(make_type).o, $(src_file_names))
exe_file_names := $(patsubst $(main_dir)%.cpp, $(bin_dir)%_$(make_type).exe, $(main_file_names))
exe_file_names := $(patsubst $(test_dir)%.cpp, $(bin_dir)%_$(make_type).exe, $(test_file_names)) $(exe_file_names)
lst_file_names  = $(patsubst %.exe, %.lst, $(exe_file_names))

cwflags = -Wall -Werror
caflags = $(cdflags) $(cwflags)

all:
	echo "Compilation options: $(make_types)"

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
# The recipe for makefile_dep is modified to add its parent directory as an order-only prerequisite.
#
$(makefile_dep): | $(make_dir)
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names) $(test_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s.$(test_dir).$(build_dir)." -e "s/\.cpp/_$(make_type)\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

ifneq ($(make_type),)
-include $(makefile_dep)
endif # make_type

#
# The recipe for clean is modified to remove the make_dir directory.
#
clean:
	rm -rf $(bin_dir) $(build_dir) $(make_dir)
