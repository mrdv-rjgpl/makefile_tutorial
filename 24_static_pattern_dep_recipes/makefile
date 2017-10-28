#
# @brief: Makefile tutorial, with static pattern recipe for dependency lists.
#
# The previous tutorial does not allow for multiple targets to be supplied in the same make command. This can only be
# done by removing the dependency on make_type, and including different makefile dependency lists based on the
# requirements.
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
# The recipe for makefile dependency lists is modified to be solely dependent on the pattern in the makefile. This is
# the first step towards allowing multiple make targets to be compiled at the same time.
#
$(make_dir)makefile_%.dep: | $(make_dir)
	> $(@)
	echo "# WARNING: This file is auto-generated! Do not edit unless you know what you are doing!" >> $(@)
	echo "" >> $(@)
	for x in $(src_file_names) $(main_file_names) $(test_file_names); \
		do g++ -MT `echo $$x | sed -e "s.$(src_dir).$(build_dir)." -e "s.$(main_dir).$(build_dir)." -e "s.$(test_dir).$(build_dir)." -e "s/\.cpp/_$(*)\.o/"` -MM $$x >> $(@); \
		echo "" >> $(@); \
	done

ifneq ($(make_type),)
-include $(makefile_dep)
endif # make_type

clean:
	rm -rf $(bin_dir) $(build_dir) $(make_dir)
