AC_PREREQ([2.63])
AC_INIT([SegFaultTest], [1.0], [Ryan.Hill@ed.ac.uk])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_MACRO_DIR([.buildutils/m4])
AC_CONFIG_SRCDIR([main.cpp])
AC_CONFIG_HEADERS([config.h])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])


################ Set flags

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

############### Get compiler informations
AC_LANG([C++])
AX_COMPILER_VENDOR
AC_DEFINE_UNQUOTED([CXX_COMP_VENDOR],["$ax_cv_cxx_compiler_vendor"],
      [vendor of C++ compiler that will compile the code])
AX_GXX_VERSION
AC_DEFINE_UNQUOTED([GXX_VERSION],["$GXX_VERSION"],
      [version of g++ that will compile the code])


############### OpenMP
AC_OPENMP
ac_openmp=no
if test "${ac_cv_prog_cxx_openmp}X" != "noX"; then
  ac_openmp=yes
  AM_CXXFLAGS="$OPENMP_CXXFLAGS $AM_CXXFLAGS"
  AM_LDFLAGS="$OPENMP_CXXFLAGS $AM_LDFLAGS"
fi

CXXFLAGS="$AM_CXXFLAGS $CXXFLAGS"
LDFLAGS="$AM_LDFLAGS $LDFLAGS"

##################### Compiler dependent choices

#Strip any optional compiler arguments from nvcc call (eg -ccbin) for compiler comparison
CXXBASE=${CXX}
CXXTEST=${CXX}
if echo "${CXX}" | grep -q "nvcc"; then
  CXXTEST="nvcc"
fi

case ${CXXTEST} in
  hipcc)
    CXXFLAGS="$CXXFLAGS -fno-strict-aliasing"
    CXXLD=${CXX}
    if test $ac_openmp = yes; then
       CXXFLAGS="$CXXFLAGS -Xcompiler -fopenmp"
    fi
    ;;
  *)
    CXXLD=${CXX}
    CXXFLAGS="$CXXFLAGS -fno-strict-aliasing"
    ;;
esac

############### Ouput
cwd=`pwd -P`; cd ${srcdir}; abs_srcdir=`pwd -P`; cd ${cwd}
CXXFLAGS="$AM_CXXFLAGS $CXXFLAGS"
LDFLAGS="$AM_LDFLAGS $LDFLAGS"
AM_CXXFLAGS="-I${abs_srcdir} $AM_CXXFLAGS"
AM_CFLAGS="-I${abs_srcdir} $AM_CFLAGS"
AM_LDFLAGS="-L${cwd}/SegFaultTest $AM_LDFLAGS"
AC_SUBST([CXXLD])
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_CXXFLAGS])
AC_SUBST([AM_LDFLAGS])
AC_SUBST([CXX])
AC_SUBST([CXXLD])
AC_SUBST([CXXFLAGS])
AC_SUBST([LDFLAGS])
AC_SUBST([LIBS])

git_commit=`cd $srcdir && ./scripts/configure.commit`

echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Summary of configuration for $PACKAGE
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
----- PLATFORM ----------------------------------------
architecture (build)        : $build_cpu
os (build)                  : $build_os
architecture (target)       : $target_cpu
os (target)                 : $target_os
compiler vendor             : ${ax_cv_cxx_compiler_vendor}
compiler version            : ${ax_cv_gxx_version}
----- BUILD OPTIONS -----------------------------------
Threading                   : ${ac_openmp}
Acceleration                : ${ac_ACCELERATOR}
----- BUILD FLAGS -------------------------------------
CXXFLAGS:
`echo ${AM_CXXFLAGS} ${CXXFLAGS} | tr ' ' '\n' | sed 's/^-/    -/g'`
LDFLAGS:
`echo ${AM_LDFLAGS} ${LDFLAGS} | tr ' ' '\n' | sed 's/^-/    -/g'`
LIBS:
`echo ${LIBS} | tr ' ' '\n' | sed 's/^-/    -/g'`
-------------------------------------------------------" > configure.summary

GRID_SUMMARY="`cat configure.summary`"
AM_SUBST_NOTMAKE([SUMMARY])
AC_SUBST([SUMMARY])

AC_CONFIG_FILES(Makefile)
AC_OUTPUT

echo ""
cat configure.summary
echo ""
