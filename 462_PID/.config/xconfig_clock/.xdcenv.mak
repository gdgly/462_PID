#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /Users/JacobFaseler/ti/simplelink_msp432p4_sdk_3_30_00_13/source;/Users/JacobFaseler/ti/simplelink_msp432p4_sdk_3_30_00_13/kernel/tirtos/packages;/Users/JacobFaseler/Github/462_PID/clock_MSP_EXP432P401R_tirtos_ccs/.config
override XDCROOT = /Applications/ti/ccs920/xdctools_3_60_01_27_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /Users/JacobFaseler/ti/simplelink_msp432p4_sdk_3_30_00_13/source;/Users/JacobFaseler/ti/simplelink_msp432p4_sdk_3_30_00_13/kernel/tirtos/packages;/Users/JacobFaseler/Github/462_PID/clock_MSP_EXP432P401R_tirtos_ccs/.config;/Applications/ti/ccs920/xdctools_3_60_01_27_core/packages;..
HOSTOS = MacOS
endif
