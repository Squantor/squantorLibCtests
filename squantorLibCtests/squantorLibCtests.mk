# SPDX-License-Identifier: MIT
# Copyright (c) 2021 Bart Bilos
# For conditions of distribution and use, see LICENSE file

# project settings
#
# Version: 20201220

# include library settings
include squantorLibC/squantorLibC.mk
include squantorMinUnit/squantorMinUnit.mk

# project settings
TARGET = PC_bare

# project sources
FILES += $(PROJECT)/src/sqlibc_tests.cpp \
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

INCLUDES += -I$(PROJECT)/inc


