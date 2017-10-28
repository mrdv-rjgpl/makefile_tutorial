#
# @brief: Makefile tutorial, with modifications of existing variables to eventually do away with the make_type
# variables.
#
# The next step towards allowing for multiple compilation targets is doing away with make_type. To that end, we modify
# the obj_file_names and exe_file_names variables to contain generic names, and modify the prerequisites accordingly.
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
obj_file_names  = $(patsubst $(src_dir)%.cpp, $(build_dir)%.o, $(src_file_names))
exe_file_names := $(patsubst $(main_dir)%.cpp, $(bin_dir)%.exe, $(main_file_names))
exe_file_names := $(patsubst $(test_dir)%.cpp, $(bin_dir)%.exe, $(test_file_names)) $(exe_file_names)
lst_file_names  = $(patsubst %.exe, %.lst, $(exe_file_names))

cwflags = -Wall -Werror

all:
	echo "Compilation options: $(make_types)"

$(make_type): $(patsubst %.exe,%_$(make_type).exe,$(exe_file_names)) \
	$(patsubst %.lst,%_$(make_type).lst,$(lst_file_names)) \
	$(makefile_dep)

%$(dir_sep):
	mkdir $(@)

%.lst: %.exe | $(bin_dir)
	objdump -f $(<) > $(@)
	objdump -s $(<) >> $(@)

$(bin_dir)%.exe: $(build_dir)%.o $(patsubst %.o,%_$(make_type).o,$(obj_file_names)) | $(bin_dir)
	g++ -o $(@) $(^)

$(build_dir)%.o: | $(build_dir)
	g++ $(cdflags) $(cwflags) -c -o $(@) $(<)

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
