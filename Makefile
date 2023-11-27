# for compiling sfml library

SHELL = /bin/sh

CXX = g++
CPPFLAGS = -Wall -g 

# DIRS
OBJDIR := obj
SRCDIR := .
DEPDIR := $(OBJDIR)/.deps
LIBS := -lsfml-graphics -lsfml-window -lsfml-system


BIN          = main
SRCS         = $(shell find $(SRCDIR) -name "*.cpp")
OBJS         = $(SRCS:%.cpp=$(OBJDIR)/%.o)
NODIROUTOBJS =
OUTSIDE_OBJS = $(NODIROUTOBJS:%=$(OBJDIR)/%)
OUTSIDE_DEPS = $(OUTSIDE_OBJS:$(OBJDIR)/%.o=%.d)

all: $(BIN)

$(BIN): $(OBJS) $(OUTSIDE_OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $(OBJS) $(OUTSIDE_OBJS) $(LIBS)

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$(shell basename $*).d
COMPILE.cpp = $(CXX) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

# Delete the built-in rules for building object file
# from .c files, so that our rule is used instead.
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp

# outside objs
# $(OBJDIR)/obj: src
#	$(COMPILE.cpp) -o $@ $<
#	$(CXX) -MT $@ -MMD -MP -MF $(DEPDIR)/$(shell basename $@).d $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(DEPDIR)/%.d | $(DEPDIR)
	$(COMPILE.cpp) -o $@ $< 

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRCS:%.cpp=$(DEPDIR)/%.d) $(OUTSIDE_DEPS:%=$(DEPDIR)/%)
$(DEPFILES):

include $(wildcard $(DEPFILES))

clean:
	# make sure the obj dir is not the same as the src dir
	rm -rvf $(BIN) $(OBJDIR)

.PHONY = all clean $(BIN)
