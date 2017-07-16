CPP  = g++
CC   = g++

ifndef SRCDIR
SRCDIR := $(PWD)
endif

ifndef OBJDIR
OBJDIR := $(PWD)
endif
OBJDIR_OLD := $(OBJDIR)

ifndef BINDIR
BINDIR = $(OBJDIR)
endif

SUBDIRS = backend subsystem

INCLUDE =
LIBS =
SOURCE = $(wildcard $(SRCDIR)/*.cpp)
OBJ    = $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SOURCE))) \
	 $(patsubst %.cpp, $(OBJDIR)/%.o, $(foreach subdir, $(SUBDIRS), $(wildcard $(subdir)/*.cpp)))
BIN    = $(BINDIR)/apping

CXXFLAGS =
CFLAGS   = -Wall -std=c++0x

MAKE = make
MKDIR = mkdir -p
RM = rm -f

export CPP CC INCLUDE LIBS CXXFLAGS CFLAGS MAKE MKDIR RM


all:	$(SUBDIRS) $(BIN)

$(SUBDIRS):ECHO
	@${MKDIR} $(OBJDIR_OLD)/$@
#	OBJDIR=$(OBJDIR_OLD)/$@  ${MAKE} -C $@

ECHO:
	@echo $(SUBDIRS)

$(OBJDIR_OLD)/%.o:$(SRCDIR)/%.cpp
	${CC} $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BIN): $(OBJ)
	${CPP} $(CXXFLAGS) $(LIBS) -o $@ $^

clean:
	${RM} $(OBJ) $(BIN)

.PHONY: all ECHO clean
