dnl configure.ac
dnl
dnl xfce4-cpugraph-plugin - A new system load XFce4 panel-plugin.
dnl
dnl 2004 Alexander Nordfelth <alex.nordfelth@telia.com>
dnl

m4_define([cpugraph_version],[1.0.0])

AC_INIT([xfce4-cpugraph-plugin], [cpugraph_version],
	[xfce-goodies-dev@lists.berlios.de])
AC_USE_SYSTEM_EXTENSIONS()

CPUGRAPH_VERSION=cpugraph_version()
AM_INIT_AUTOMAKE([xfce4-cpugraph-plugin], [$CPUGRAPH_VERSION])
AM_CONFIG_HEADER([config.h])

AM_MAINTAINER_MODE

dnl Check for basic programs
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_INTLTOOL
AM_PROG_CC_C_O

dnl Check for standard header files
AC_HEADER_STDC

dnl configure the panel plugin
XDT_CHECK_PACKAGE([LIBXFCEGUI4], [libxfcegui4-1.0], [4.3.20])
XDT_CHECK_PACKAGE([LIBXFCE4PANEL], [libxfce4panel-1.0], [4.3.20])
XDT_CHECK_PACKAGE([GTK], [gtk+-2.0], [2.12.0])

dnl translations
XDT_I18N([@LINGUAS@])

dnl Check for debugging support
XDT_FEATURE_DEBUG()

AC_OUTPUT([
Makefile
panel-plugin/Makefile
po/Makefile.in
])
