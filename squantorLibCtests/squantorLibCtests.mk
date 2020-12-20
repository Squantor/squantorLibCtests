# MIT License

# Copyright (c) 2020 Bart Bilos

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# project settings
#
# Version: 20200722

# include library settings
include squantorLibC/squantorLibC.mk

# project settings
TARGET = PC_bare

# project sources
FILES += $(PROJECT)/src/sqlibc_tests.c \
$(PROJECT)/src/strings.c \
$(PROJECT)/src/test_strlen.c \
$(PROJECT)/src/test_strcmp.c \
$(PROJECT)/src/test_strcpy.c \
$(PROJECT)/src/test_strncpy.c \
$(PROJECT)/src/test_strncmp.c \
$(PROJECT)/src/test_memset.c \
$(PROJECT)/src/test_memcmp.c \
$(PROJECT)/src/test_memcpy.c \
$(PROJECT)/src/test_memmove.c \
$(PROJECT)/src/test_memchr.c \
$(PROJECT)/src/test_tolower.c \
$(PROJECT)/src/test_toupper.c \
$(PROJECT)/src/test_strto_pre.c \
$(PROJECT)/src/test_strto_main.c \
$(PROJECT)/src/test_strtol.c \
$(PROJECT)/src/test_strtoul.c \
$(PROJECT)/src/test_strchr.c \
$(PROJECT)/src/test_strcat.c \
$(PROJECT)/src/test_strpbrk.c \
$(PROJECT)/src/test_strrchr.c \
$(PROJECT)/src/test_strspn.c \
$(PROJECT)/src/test_strstr.c

INCLUDES += -I$(PROJECT)/inc -IsquantorMinUnit/inc -IsquantorLibC/inc \
-IsquantorLibC/inc_internal


