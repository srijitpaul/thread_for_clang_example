AC_PREREQ([2.63])
AC_INIT([SegFaultTest], [1.0], [Ryan.Hill@ed.ac.uk])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_LANG([C++])

############### Checks for library functions
CXXFLAGS="$AM_CXXFLAGS $CXXFLAGS"
LDFLAGS="$AM_LDFLAGS $LDFLAGS"

############### Ouput
AC_SUBST([CXXLD])
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([CXX])
AC_SUBST([CXXFLAGS])
AC_SUBST([LDFLAGS])
AC_SUBST([LIBS])

echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Summary of configuration for $PACKAGE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
----- PLATFORM ----------------------------------------
architecture (build)        : $build_cpu
os (build)                  : $build_os
architecture (target)       : $target_cpu
os (target)                 : $target_os
----- BUILD FLAGS -------------------------------------
CXXFLAGS:
`echo ${AM_CXXFLAGS} ${CXXFLAGS} | tr ' ' '\n' | sed 's/^-/    -/g'`
LDFLAGS:
`echo ${AM_LDFLAGS} ${LDFLAGS} | tr ' ' '\n' | sed 's/^-/    -/g'`
LIBS:
`echo ${LIBS} | tr ' ' '\n' | sed 's/^-/    -/g'`
-------------------------------------------------------" > configure.summary

CONFIG_SUMMARY="`cat configure.summary`"
AM_SUBST_NOTMAKE([CONFIG_SUMMARY])
AC_SUBST([CONFIG_SUMMARY])

AC_CONFIG_FILES(Makefile)
AC_OUTPUT

echo ""
cat configure.summary
echo ""
