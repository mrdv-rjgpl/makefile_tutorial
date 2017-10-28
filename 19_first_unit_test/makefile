#
# @brief: Makefile tutorial, with test directory.
#
# A separate folder is created for test harnesses, with a simple test file contained within.
#
# N.B. From this tutorial onwards, comments will be limited to pointing out changes in the makefile.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

dir_sep = /

bin_dir   = bin$(dir_sep)
build_dir = build$(dir_sep)
main_dir  = main$(dir_sep)
src_dir   = src$(dir_sep)
#
# A test directory is added.
#
test_dir  = test$(dir_sep)

makefile_dep = makefile.dep

src_file_names  = $(wildcard $(src_dir)*.cpp)
obj_file_names  = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(src_file_names))
main_file_names = $(wildcard $(main_dir)*.cpp)
#
# The list of test file names is generated.
#
test_file_names = $(wildcard $(test_dir)*.cpp)
#
# The executables list is updated with the required test executables.
#
exe_file_names := $(patsubst $(main_dir)%.cpp, $(bin_dir)%.exe, $(main_file_names))
exe_file_names := $(patsubst $(test_dir)%.cpp, $(bin_dir)%.exe, $(test_file_names)) $(exe_file_names)
lst_file_names  = $(patsubst $(main_dir)%.cpp, $(bin_dir)%.lst, $(main_file_names))

all: $(exe_file_names) $(lst_file_names) $(makefile_dep)

%$(dir_sep):
	mkdir $(@)

%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

$(bin_dir)%.exe: $(build_dir)%.o $(obj_file_names) | $(bin_dir)
	g++ -o $(@) $(^)

$(build_dir)%.o: | $(build_dir)
	g++ -c -o $(@) $(<)

#
# The makefile dependency list is updated with the list of test files.
#
$(makefile_dep):
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names) $(test_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s.$(test_dir).$(build_dir)." -e "s/\.cpp/\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

-include $(makefile_dep)

clean:
	rm -rf $(bin_dir) $(build_dir) $(makefile_dep)
