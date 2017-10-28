#
# @brief: Makefile tutorial, with minor fix to prevent unwanted generation of empty makefile dependency list.
#
# The previous example results in the generation of a file makefile_.dep, on running the command `make`. This example
# fixes that problem by wrapping the include statement in a conditional.
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

make_types = debug run

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	cdflags   = -g
	make_type = debug
endif # MAKECMDGOALS

ifeq ($(filter run,$(MAKECMDGOALS)),run)
	cdflags   =
	make_type = run
endif # MAKECMDGOALS

makefile_dep=makefile_$(make_type).dep
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

$(makefile_dep):
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names) $(test_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s.$(test_dir).$(build_dir)." -e "s/\.cpp/_$(make_type)\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

#
# The include statement is wrapped in a conditional, checking for a non-empty value of make_type.
# Warning: The space between 'ifneq/ifeq' and its subsequent bracket is required, and make will throw an error if that
# is missed.
# Warning: Auto-indentation of this block results in the -include line being indented, but it should not be. Make will
# throw an error if that happens.
#
ifneq ($(make_type),)
-include $(makefile_dep)
endif # make_type

clean:
	rm -rf $(bin_dir) $(build_dir) makefile*.dep
