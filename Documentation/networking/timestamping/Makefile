# To compile, from the source root
#
#    make headers_install
#    make M=Documentation

# List of programs to build
hostprogs-y := hwtstamp_config timestamping txtimestamp

# Tell kbuild to always build the programs
always := $(hostprogs-y)

HOSTCFLAGS_timestamping.o += -I$(objtree)/usr/include
HOSTCFLAGS_txtimestamp.o += -I$(objtree)/usr/include
HOSTCFLAGS_hwtstamp_config.o += -I$(objtree)/usr/include
