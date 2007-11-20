dnl @synopsis AX_CHECK_GLUT
dnl
dnl Check for GLUT. If GLUT is found, the required compiler and linker
dnl flags are included in the output variables "GLUT_CFLAGS" and
dnl "GLUT_LIBS", respectively. This macro adds the configure option
dnl "--with-apple-opengl-framework", which users can use to indicate
dnl that Apple's OpenGL framework should be used on Mac OS X. If
dnl Apple's OpenGL framework is used, the symbol
dnl "HAVE_APPLE_OPENGL_FRAMEWORK" is defined. If GLUT is not found,
dnl "no_glut" is set to "yes".
dnl
dnl @category InstalledPackages
dnl @author Braden McDaniel <braden@endoframe.com>
dnl @version 2004-11-15
dnl @license AllPermissive

AC_DEFUN([AX_CHECK_GLUT],
[AC_REQUIRE([AX_CHECK_GLU])dnl
AC_REQUIRE([AC_PATH_XTRA])dnl

if test "X$with_apple_opengl_framework" = "Xyes"; then
  GLUT_CFLAGS="${GLU_CFLAGS}"
  GLUT_LIBS="-framework GLUT -lobjc ${GL_LIBS}"
else
  GLUT_CFLAGS=${GLU_CFLAGS}
  GLUT_LIBS=${GLU_LIBS}

  #
  # If X is present, assume GLUT depends on it.
  #
  if test "X${no_x}" != "Xyes"; then
    GLUT_LIBS="${X_PRE_LIBS} -lXmu -lXi ${X_EXTRA_LIBS} ${GLUT_LIBS}"
  fi

  AC_LANG_PUSH(C)

  ax_save_CPPFLAGS="${CPPFLAGS}"
  CPPFLAGS="${GLUT_CFLAGS} ${CPPFLAGS}"

  AC_CACHE_CHECK([for GLUT library], [ax_cv_check_glut_libglut],
  [ax_cv_check_glut_libglut="no"
  ax_save_LIBS="${LIBS}"
  LIBS=""
  ax_check_libs="-lglut32 -lglut"
  for ax_lib in ${ax_check_libs}; do
    if test X$ax_compiler_ms = Xyes; then
      ax_try_lib=`echo $ax_lib | sed -e 's/^-l//' -e 's/$/.lib/'`
    else
      ax_try_lib="${ax_lib}"
    fi
    LIBS="${ax_try_lib} ${GLUT_LIBS} ${ax_save_LIBS}"
    AC_LINK_IFELSE(
    [AC_LANG_PROGRAM([[
# if HAVE_WINDOWS_H && defined(_WIN32)
#   include <windows.h>
# endif
# include <GL/glut.h>]],
                     [[glutMainLoop()]])],
    [ax_cv_check_glut_libglut="${ax_try_lib}"; break])

  done
  LIBS=${ax_save_LIBS}
  ])
  CPPFLAGS="${ax_save_CPPFLAGS}"
  AC_LANG_POP(C)

  if test "X${ax_cv_check_glut_libglut}" = "Xno"; then
    no_glut="yes"
    GLUT_CFLAGS=""
    GLUT_LIBS=""
  else
    GLUT_LIBS="${ax_cv_check_glut_libglut} ${GLUT_LIBS}"
  fi
fi

AC_SUBST([GLUT_CFLAGS])
AC_SUBST([GLUT_LIBS])
])dnl

