#
# @brief: Makefile tutorial, with fixes to allow for multiple make platforms at the same time.
#
# The previous example, when compiled with multiple platforms supplied as an input, compiles only the last one in the
# list of conditionals in the makefile. This makefile removes that deficiency with target specific variable names as
# well.
#
# @author: Mardava Gubbi <mrdv.rjgpl@gmail.com>
#

dir_sep = /

bin_dir   = bin$(dir_sep)
build_dir = build$(dir_sep)
main_dir  = main$(dir_sep)
make_dir  = make_deps$(dir_sep)
src_dir   = src$(dir_sep)
test_dir  = test$(dir_sep)

src_file_names   = $(wildcard $(src_dir)*.cpp)
main_file_names  = $(wildcard $(main_dir)*.cpp)
obj_file_names   = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(src_file_names))
test_file_names  = $(wildcard $(test_dir)*.cpp)
exe_file_names  := $(patsubst $(main_dir)%.cpp, $(bin_dir)%.exe, $(main_file_names))
exe_file_names  := $(patsubst $(test_dir)%.cpp, $(bin_dir)%.exe, $(test_file_names)) $(exe_file_names)

make_types = debug run

cwflags = -Wall -Werror

ifeq ($(filter debug,$(MAKECMDGOALS)),debug)
	cdflags_debug = -g
-include $(make_dir)makefile_debug.dep
endif # MAKECMDGOALS

ifeq ($(filter run,$(MAKECMDGOALS)),run)
	cdflags_run   =
-include $(make_dir)makefile_run.dep
endif # MAKECMDGOALS

all:
	echo "Compilation options: $(make_types)"

%$(dir_sep):
	mkdir $(@)

$(make_types):

%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

$(make_dir)makefile_%.dep: $(make_dir)
	> $(@)
	echo "Generating makefile dependency list $(*)..."
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	echo "$(*): \$$(patsubst %.exe,%_$(*).exe,\$$(exe_file_names)) \$$(patsubst %.exe,%_$(*).lst,\$$(exe_file_names))" >> $(@)
	echo "" >> $(@)
	echo "\$$(bin_dir)%_$(*).exe: \$$(build_dir)%_$(*).o \$$(patsubst %.o,%_$(*).o,\$$(obj_file_names)) | \$$(bin_dir)" >> $(@)
	echo "\tg++ -o \$$(@) \$$(^)" >> $(@)
	echo "" >> $(@)
	echo "\$$(build_dir)%_$(*).o: | \$$(build_dir)" >> $(@)
	echo "\tg++ \$$(cdflags_$(*)) \$$(cwflags) -c -o \$$(@) \$$(<)" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names) $(test_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s.$(test_dir).$(build_dir)." -e "s/\.cpp/_$(*)\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

clean:
	rm -rf $(bin_dir) $(build_dir) $(make_dir)
