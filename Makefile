# Makefile created by Gustavo Bacagine <gustavo.bacagine@protonmail.com>
# 
# This is a version of libconio for linux systems
# 
# Begin's date: 17/03/2021
# Date of last modification: 18/03/2021

TARGET = libconio.so
SRCDIR = src
INCDIR = include
LIBDIR = lib
OBJDIR = obj
OBJ    = $(addprefix $(OBJDIR)/,conio.o)
LIB    = $(LIBDIR)/$(TARGET)
INC    = -I $(INCDIR)
CC     = gcc

all: $(OBJDIR) $(LIBDIR) $(LIB)

$(OBJDIR):
	mkdir $@
$(LIBDIR):
	mkdir $@
$(LIB): $(OBJ)
	$(CC) -shared -o $@ $< 
$(OBJDIR)/conio.o: $(SRCDIR)/conio.c $(INCDIR)/conio.h
	$(CC) -fPIC -c $< $(INC) -o $@
install:
	cp include/conio.h /usr/include
	cp lib/libconio.so /usr/lib
uninstall:
	rm -rvf  /usr/include/conio.h
	rm -rvf  /usr/lib/libconio.so
clean:
	rm -rvf $(OBJDIR)
distclean: clean
	rm -rvf $(LIBDIR)

