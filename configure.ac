AC_INIT([topd],[0.0.1],[bug-report@address])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
# Checks for programs.
AC_PROG_CXX
# Checks for libraries
# Check for SDL
SDL_VERSION=[1.2.15]
AM_PATH_SDL($SDL_VERSION, :, AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!]))
CPPFLAGS="$CPPFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"
# Checks for header les.
# Checks for typedefs, structures, and compiler characteristics.
# Checks for library functions.
# Output les.
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
