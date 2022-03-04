# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PENTIUM4gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := C:/Users/Lab11306/Desktop/pruebas_linear_algebra_Intel_IPP/la_sample



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = pentium
CPU = PENTIUM4
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4 -nostdlib -fno-builtin -fno-defer-pop -fno-implicit-fp
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -IC:/WindRiver/intel/20160311-vxworks-6.9/ipp/include -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = -LC:/WindRiver/intel/20160311-vxworks-6.9/ipp/lib/ia32/mrtp -lippm_l -lippi_l -lipps_l -lippcore_l 

IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\"   -DIP_PORT_VXWORKS=69 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler =  -O2
DEBUGFLAGS_C++-Compiler =  -O2
DEBUGFLAGS_Linker =  -O2
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -O2
endif


#Project Targets
PROJECT_TARGETS = la_sample/$(MODE_DIR)/la_sample.out


#Rules

# la_sample
ifeq ($(DEBUG_MODE),1)
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -O2
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -O2
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -O2
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
la_sample/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -O2
endif
la_sample/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -IC:/WindRiver/intel/20160311-vxworks-6.9/ipp/include -I$(WIND_BASE)/target/h/wrn/coreip 
la_sample/$(MODE_DIR)/% : IDE_LIBRARIES = -LC:/WindRiver/intel/20160311-vxworks-6.9/ipp/lib/ia32/mrtp -lippm_l -lippi_l -lipps_l -lippcore_l 
la_sample/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\"   -DIP_PORT_VXWORKS=69 
la_sample/$(MODE_DIR)/% : PROJECT_TYPE = DKM
la_sample/$(MODE_DIR)/% : DEFINES = 
la_sample/$(MODE_DIR)/% : EXPAND_DBG = 0
la_sample/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
la_sample/$(MODE_DIR)/% : CPU = PENTIUM4
la_sample/$(MODE_DIR)/% : TOOL_FAMILY = gnu
la_sample/$(MODE_DIR)/% : TOOL = gnu
la_sample/$(MODE_DIR)/% : TOOL_PATH = 
la_sample/$(MODE_DIR)/% : CC_ARCH_SPEC = -mtune=pentium4 -march=pentium4 -nostdlib -fno-builtin -fno-defer-pop -fno-implicit-fp
la_sample/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
la_sample/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
la_sample/$(MODE_DIR)/% : LIBPATH = 
la_sample/$(MODE_DIR)/% : LIBS = 
la_sample/$(MODE_DIR)/% : OBJ_DIR := la_sample/$(MODE_DIR)

la_sample/$(MODE_DIR)/Objects/la_src/main.o : C:/Users/Lab11306/Desktop/pruebas_linear_algebra_Intel_IPP/la_src/main.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -ansi -fno-zero-initialized-in-bss  -Wall    -MD -MP $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_la_sample = la_sample/$(MODE_DIR)/Objects/la_src/main.o

ifeq ($(TARGET_JOBS),1)
la_sample/$(MODE_DIR)/la_sample.out : $(OBJECTS_la_sample)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmpentium $(OBJECTS_la_sample) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium -tags $(VSB_DIR)/tags/pentium/PENTIUM4/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccpentium $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall   $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccpentium -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_la_sample) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
la_sample/$(MODE_DIR)/la_sample.out : la_sample/$(MODE_DIR)/la_sample.out_jobs

endif
la_sample/$(MODE_DIR)/la_sample_compile_file : $(FILE) ;

_clean :: la_sample/$(MODE_DIR)/la_sample_clean

la_sample/$(MODE_DIR)/la_sample_clean : 
	$(TRACE_FLAG)if [ -d "la_sample" ]; then cd "la_sample"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := la_sample/$(MODE_DIR)/Objects/la_src/main.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1 &&\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
