stream_extractordir = $(pluginsdir)/stream_extractor
stream_extractor_LTLIBRARIES =

libarchive_plugin_la_SOURCES = stream_extractor/archive.c
libarchive_plugin_la_CFLAGS = $(AM_CFLAGS) $(ARCHIVE_CFLAGS)
libarchive_plugin_la_LDFLAGS = $(AM_LDFLAGS) -rpath '$(stream_extractordir)'
libarchive_plugin_la_LIBADD = $(ARCHIVE_LIBS) /mingw64/lib/libz.dll.a /mingw64/lib/libbz2.dll.a /mingw64/lib/liblzma.dll.a /mingw64/lib/libb2.dll.a /mingw64/lib/liblz4.dll.a /mingw64/lib/libzstd.dll.a -lbcrypt /mingw64/lib/libcrypto.dll.a -liconv -lcharset /mingw64/lib/libexpat.dll.a /mingw64/lib/libpcre2-posix.dll.a
EXTRA_LTLIBRARIES += libarchive_plugin.la
stream_extractor_LTLIBRARIES += $(LTLIBarchive)
