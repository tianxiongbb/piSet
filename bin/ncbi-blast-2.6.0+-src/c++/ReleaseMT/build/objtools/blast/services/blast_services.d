blast_services.o blast_services.d : \
 $(wildcard /data/tusers/yutianx/tongji2/Software/ncbi-blast-2.6.0+-src/c++/src/objtools/blast/services/blast_services.cpp) \
 $(wildcard /usr/include/stdc-predef.h) \
 $(wildcard $(includedir)/ncbi_pch.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_system.hpp) \
 $(wildcard $(includedir)/corelib/ncbitime.hpp) \
 $(wildcard $(includedir)/corelib/ncbistd.hpp) \
 $(wildcard $(includedir)/corelib/ncbistr.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_limits.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_limits.h) \
 $(wildcard $(includedir)/corelib/ncbitype.h) \
 $(wildcard $(includedir)/ncbiconf.h) \
 $(wildcard $(incdir)/ncbiconf_unix.h) \
 $(wildcard $(includedir)/common/ncbiconf_impl.h) \
 $(wildcard $(includedir)/common/ncbi_skew_guard.h) \
 $(wildcard /usr/include/inttypes.h) $(wildcard /usr/include/features.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/sys/cdefs.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/wordsize.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/gnu/stubs.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/gnu/stubs-64.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/stdint.h) $(wildcard /usr/include/stdint.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/wchar.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/limits.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include-fixed/syslimits.h) \
 $(wildcard /usr/include/limits.h) $(wildcard /usr/include/x86_64-linux-gnu/bits/posix1_lim.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/local_lim.h) \
 $(wildcard /usr/include/linux/limits.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/posix2_lim.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/xopen_lim.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/stdio_lim.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/float.h) $(wildcard /usr/include/wchar.h) \
 $(wildcard /usr/include/stdio.h) $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h) $(wildcard /usr/include/xlocale.h) \
 $(wildcard $(includedir)/corelib/ncbistl.hpp) \
 $(wildcard $(includedir)/common/ncbi_export.h) \
 $(wildcard /usr/include/c++/5/string) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/c++config.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/os_defines.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/cpu_defines.h) \
 $(wildcard /usr/include/c++/5/bits/stringfwd.h) $(wildcard /usr/include/c++/5/bits/memoryfwd.h) \
 $(wildcard /usr/include/c++/5/bits/char_traits.h) \
 $(wildcard /usr/include/c++/5/bits/stl_algobase.h) \
 $(wildcard /usr/include/c++/5/bits/functexcept.h) \
 $(wildcard /usr/include/c++/5/bits/exception_defines.h) \
 $(wildcard /usr/include/c++/5/bits/cpp_type_traits.h) \
 $(wildcard /usr/include/c++/5/ext/type_traits.h) \
 $(wildcard /usr/include/c++/5/ext/numeric_traits.h) \
 $(wildcard /usr/include/c++/5/bits/stl_pair.h) $(wildcard /usr/include/c++/5/bits/move.h) \
 $(wildcard /usr/include/c++/5/bits/concept_check.h) $(wildcard /usr/include/c++/5/type_traits) \
 $(wildcard /usr/include/c++/5/bits/stl_iterator_base_types.h) \
 $(wildcard /usr/include/c++/5/bits/stl_iterator_base_funcs.h) \
 $(wildcard /usr/include/c++/5/debug/debug.h) $(wildcard /usr/include/c++/5/bits/stl_iterator.h) \
 $(wildcard /usr/include/c++/5/bits/ptr_traits.h) \
 $(wildcard /usr/include/c++/5/bits/predefined_ops.h) \
 $(wildcard /usr/include/c++/5/bits/postypes.h) $(wildcard /usr/include/c++/5/cwchar) \
 $(wildcard /usr/include/c++/5/cstdint) $(wildcard /usr/include/c++/5/bits/allocator.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/c++allocator.h) \
 $(wildcard /usr/include/c++/5/ext/new_allocator.h) $(wildcard /usr/include/c++/5/new) \
 $(wildcard /usr/include/c++/5/exception) \
 $(wildcard /usr/include/c++/5/bits/atomic_lockfree_defines.h) \
 $(wildcard /usr/include/c++/5/bits/exception_ptr.h) \
 $(wildcard /usr/include/c++/5/bits/nested_exception.h) \
 $(wildcard /usr/include/c++/5/bits/localefwd.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/c++locale.h) \
 $(wildcard /usr/include/c++/5/clocale) $(wildcard /usr/include/locale.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/locale.h) $(wildcard /usr/include/c++/5/iosfwd) \
 $(wildcard /usr/include/c++/5/cctype) $(wildcard /usr/include/ctype.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/types.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/typesizes.h) $(wildcard /usr/include/endian.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/endian.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/byteswap.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/byteswap-16.h) \
 $(wildcard /usr/include/c++/5/bits/ostream_insert.h) \
 $(wildcard /usr/include/c++/5/bits/cxxabi_forced.h) \
 $(wildcard /usr/include/c++/5/bits/stl_function.h) \
 $(wildcard /usr/include/c++/5/backward/binders.h) \
 $(wildcard /usr/include/c++/5/bits/range_access.h) \
 $(wildcard /usr/include/c++/5/initializer_list) \
 $(wildcard /usr/include/c++/5/bits/basic_string.h) \
 $(wildcard /usr/include/c++/5/ext/atomicity.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/gthr.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/gthr-default.h) \
 $(wildcard /usr/include/pthread.h) $(wildcard /usr/include/sched.h) $(wildcard /usr/include/time.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/sched.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/time.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/timex.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/pthreadtypes.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/setjmp.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/atomic_word.h) \
 $(wildcard /usr/include/c++/5/ext/alloc_traits.h) \
 $(wildcard /usr/include/c++/5/bits/alloc_traits.h) \
 $(wildcard /usr/include/c++/5/ext/string_conversions.h) $(wildcard /usr/include/c++/5/cstdlib) \
 $(wildcard /usr/include/stdlib.h) $(wildcard /usr/include/x86_64-linux-gnu/bits/waitflags.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/waitstatus.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/sys/types.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/sys/select.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/select.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/sigset.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/sys/sysmacros.h) $(wildcard /usr/include/alloca.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/stdlib-float.h) \
 $(wildcard /usr/include/c++/5/cstdio) $(wildcard /usr/include/libio.h) $(wildcard /usr/include/_G_config.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/sys_errlist.h) \
 $(wildcard /usr/include/c++/5/cerrno) $(wildcard /usr/include/errno.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/errno.h) $(wildcard /usr/include/linux/errno.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/asm/errno.h) \
 $(wildcard /usr/include/asm-generic/errno.h) $(wildcard /usr/include/asm-generic/errno-base.h) \
 $(wildcard /usr/include/c++/5/bits/functional_hash.h) \
 $(wildcard /usr/include/c++/5/bits/hash_bytes.h) \
 $(wildcard /usr/include/c++/5/bits/basic_string.tcc) $(wildcard /usr/include/c++/5/algorithm) \
 $(wildcard /usr/include/c++/5/utility) $(wildcard /usr/include/c++/5/bits/stl_relops.h) \
 $(wildcard /usr/include/c++/5/bits/stl_algo.h) \
 $(wildcard /usr/include/c++/5/bits/algorithmfwd.h) \
 $(wildcard /usr/include/c++/5/bits/stl_heap.h) $(wildcard /usr/include/c++/5/bits/stl_tempbuf.h) \
 $(wildcard /usr/include/c++/5/bits/stl_construct.h) $(wildcard /usr/include/c++/5/random) \
 $(wildcard /usr/include/c++/5/cmath) $(wildcard /usr/include/math.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/math-vector.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/libm-simd-decl-stubs.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/huge_val.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/huge_valf.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/huge_vall.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/inf.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/nan.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/mathdef.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/bits/mathcalls.h) $(wildcard /usr/include/c++/5/limits) \
 $(wildcard /usr/include/c++/5/bits/random.h) $(wildcard /usr/include/c++/5/vector) \
 $(wildcard /usr/include/c++/5/bits/stl_uninitialized.h) \
 $(wildcard /usr/include/c++/5/bits/stl_vector.h) \
 $(wildcard /usr/include/c++/5/bits/stl_bvector.h) $(wildcard /usr/include/c++/5/bits/vector.tcc) \
 $(wildcard /usr/include/c++/5/bits/uniform_int_dist.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/opt_random.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/x86intrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/ia32intrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/mmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xmmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/mm_malloc.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/emmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/pmmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/tmmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/ammintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/smmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/popcntintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/wmmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/immintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avxintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx2intrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512fintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512erintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512pfintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512cdintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512vlintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512bwintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512dqintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512vlbwintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512vldqintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512ifmaintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512ifmavlintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512vbmiintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/avx512vbmivlintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/shaintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/lzcntintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/bmiintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/bmi2intrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/fmaintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/f16cintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/rtmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xtestintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/mm3dnow.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/prfchwintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/fma4intrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xopintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/lwpintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/tbmintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/rdseedintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/fxsrintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xsaveintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xsaveoptintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/adxintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/clwbintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/pcommitintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/clflushoptintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xsavesintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/xsavecintrin.h) \
 $(wildcard /usr/lib/gcc/x86_64-linux-gnu/5/include/mwaitxintrin.h) \
 $(wildcard /usr/include/c++/5/bits/random.tcc) $(wildcard /usr/include/c++/5/numeric) \
 $(wildcard /usr/include/c++/5/bits/stl_numeric.h) \
 $(wildcard /usr/include/c++/5/ext/concurrence.h) $(wildcard /usr/include/c++/5/typeinfo) \
 $(wildcard /usr/include/c++/5/bits/unique_ptr.h) $(wildcard /usr/include/c++/5/tuple) \
 $(wildcard /usr/include/c++/5/array) $(wildcard /usr/include/c++/5/stdexcept) \
 $(wildcard /usr/include/c++/5/bits/uses_allocator.h) \
 $(wildcard /usr/include/c++/5/bits/shared_ptr.h) \
 $(wildcard /usr/include/c++/5/bits/shared_ptr_base.h) \
 $(wildcard /usr/include/c++/5/bits/allocated_ptr.h) \
 $(wildcard /usr/include/c++/5/ext/aligned_buffer.h) \
 $(wildcard /usr/include/c++/5/backward/auto_ptr.h) \
 $(wildcard $(includedir)/corelib/tempstr.hpp) \
 $(wildcard $(includedir)/corelib/ncbiexpt.hpp) \
 $(wildcard $(includedir)/corelib/ncbidiag.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_stack.hpp) \
 $(wildcard $(includedir)/corelib/ncbistre.hpp) \
 $(wildcard $(includedir)/corelib/ncbictype.hpp) \
 $(wildcard /usr/include/c++/5/iostream) $(wildcard /usr/include/c++/5/ostream) \
 $(wildcard /usr/include/c++/5/ios) $(wildcard /usr/include/c++/5/bits/ios_base.h) \
 $(wildcard /usr/include/c++/5/bits/locale_classes.h) \
 $(wildcard /usr/include/c++/5/bits/locale_classes.tcc) \
 $(wildcard /usr/include/c++/5/system_error) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/error_constants.h) \
 $(wildcard /usr/include/c++/5/streambuf) $(wildcard /usr/include/c++/5/bits/streambuf.tcc) \
 $(wildcard /usr/include/c++/5/bits/basic_ios.h) \
 $(wildcard /usr/include/c++/5/bits/locale_facets.h) $(wildcard /usr/include/c++/5/cwctype) \
 $(wildcard /usr/include/wctype.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_base.h) \
 $(wildcard /usr/include/c++/5/bits/streambuf_iterator.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/ctype_inline.h) \
 $(wildcard /usr/include/c++/5/bits/locale_facets.tcc) \
 $(wildcard /usr/include/c++/5/bits/basic_ios.tcc) \
 $(wildcard /usr/include/c++/5/bits/ostream.tcc) $(wildcard /usr/include/c++/5/istream) \
 $(wildcard /usr/include/c++/5/bits/istream.tcc) $(wildcard /usr/include/c++/5/fstream) \
 $(wildcard /usr/include/c++/5/bits/codecvt.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/basic_file.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/c++io.h) \
 $(wildcard /usr/include/c++/5/bits/fstream.tcc) \
 $(wildcard /usr/include/c++/5/backward/strstream) \
 $(wildcard /usr/include/c++/5/backward/backward_warning.h) \
 $(wildcard /usr/include/c++/5/iomanip) $(wildcard /usr/include/c++/5/locale) \
 $(wildcard /usr/include/c++/5/bits/locale_facets_nonio.h) $(wildcard /usr/include/c++/5/ctime) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/time_members.h) \
 $(wildcard /usr/include/x86_64-linux-gnu/c++/5/bits/messages_members.h) \
 $(wildcard /usr/include/libintl.h) $(wildcard /usr/include/c++/5/bits/locale_facets_nonio.tcc) \
 $(wildcard /usr/include/c++/5/bits/locale_conv.h) \
 $(wildcard /usr/include/c++/5/bits/stringfwd.h) $(wildcard /usr/include/c++/5/bits/allocator.h) \
 $(wildcard /usr/include/c++/5/bits/codecvt.h) $(wildcard /usr/include/c++/5/bits/unique_ptr.h) \
 $(wildcard $(includedir)/corelib/ncbi_base64.h) \
 $(wildcard /usr/include/c++/5/list) $(wildcard /usr/include/c++/5/bits/stl_list.h) \
 $(wildcard /usr/include/c++/5/bits/list.tcc) $(wildcard /usr/include/c++/5/memory) \
 $(wildcard /usr/include/c++/5/bits/stl_raw_storage_iter.h) \
 $(wildcard /usr/include/c++/5/functional) \
 $(wildcard /usr/include/c++/5/bits/shared_ptr_atomic.h) \
 $(wildcard /usr/include/c++/5/bits/atomic_base.h) $(wildcard /usr/include/c++/5/deque) \
 $(wildcard /usr/include/c++/5/bits/stl_deque.h) $(wildcard /usr/include/c++/5/bits/deque.tcc) \
 $(wildcard /usr/include/c++/5/map) $(wildcard /usr/include/c++/5/bits/stl_tree.h) \
 $(wildcard /usr/include/c++/5/bits/stl_map.h) $(wildcard /usr/include/c++/5/bits/stl_multimap.h) \
 $(wildcard $(includedir)/corelib/ncbidiag.inl) \
 $(wildcard /usr/include/string.h) \
 $(wildcard $(includedir)/corelib/ncbimisc.hpp) \
 $(wildcard $(includedir)/corelib/ncbidbg.hpp) \
 $(wildcard $(includedir)/corelib/ncbierror.hpp) \
 $(wildcard $(includedir)/corelib/impl/ncbierror_impl.hpp) \
 $(wildcard /usr/include/c++/5/set) $(wildcard /usr/include/c++/5/bits/stl_set.h) \
 $(wildcard /usr/include/c++/5/bits/stl_multiset.h) \
 $(wildcard $(includedir)/corelib/impl/stringutf8_deprecated.hpp) \
 $(wildcard $(includedir)/corelib/impl/stringutf8_deprecated.inl) \
 $(wildcard $(includedir)/serial/iterator.hpp) \
 $(wildcard $(includedir)/corelib/ncbiutil.hpp) \
 $(wildcard $(includedir)/serial/impl/objecttype.hpp) \
 $(wildcard $(includedir)/serial/objectinfo.hpp) \
 $(wildcard $(includedir)/corelib/ncbiobj.hpp) \
 $(wildcard $(includedir)/corelib/ncbicntr.hpp) \
 $(wildcard $(includedir)/corelib/impl/ncbi_atomic_defs.h) \
 $(wildcard /usr/include/c++/5/atomic) \
 $(wildcard $(includedir)/corelib/ncbiatomic.hpp) \
 $(wildcard $(includedir)/corelib/ncbiatomic.h) \
 $(wildcard $(includedir)/corelib/ddumpable.hpp) \
 $(wildcard $(includedir)/serial/serialdef.hpp) \
 $(wildcard $(includedir)/serial/impl/continfo.hpp) \
 $(wildcard $(includedir)/serial/typeinfo.hpp) \
 $(wildcard $(includedir)/serial/impl/hookdata.hpp) \
 $(wildcard $(includedir)/serial/impl/hookdatakey.hpp) \
 $(wildcard $(includedir)/serial/impl/pathhook.hpp) \
 $(wildcard $(includedir)/serial/impl/hookfunc.hpp) \
 $(wildcard $(includedir)/serial/impl/objstrasnb.hpp) \
 $(wildcard $(includedir)/serial/impl/objstrasnb.inl) \
 $(wildcard $(includedir)/serial/impl/typeinfo.inl) \
 $(wildcard $(includedir)/serial/impl/typeref.hpp) \
 $(wildcard $(includedir)/serial/impl/typeref.inl) \
 $(wildcard $(includedir)/serial/impl/continfo.inl) \
 $(wildcard $(includedir)/serial/impl/ptrinfo.hpp) \
 $(wildcard $(includedir)/serial/impl/ptrinfo.inl) \
 $(wildcard $(includedir)/serial/impl/stdtypes.hpp) \
 $(wildcard $(includedir)/serial/serialbase.hpp) \
 $(wildcard $(includedir)/serial/exception.hpp) \
 $(wildcard $(includedir)/serial/error_codes.hpp) \
 $(wildcard $(includedir)/util/bitset/ncbi_bitset.hpp) \
 $(wildcard $(includedir)/util/bitset/bm.h) \
 $(wildcard /usr/include/c++/5/iterator) $(wildcard /usr/include/c++/5/bits/stream_iterator.h) \
 $(wildcard $(includedir)/util/bitset/bmconst.h) \
 $(wildcard $(includedir)/util/bitset/bmdef.h) \
 $(wildcard /usr/include/c++/5/climits) \
 $(wildcard $(includedir)/util/bitset/bmfwd.h) \
 $(wildcard $(includedir)/util/bitset/bmfunc.h) \
 $(wildcard /usr/include/memory.h) \
 $(wildcard $(includedir)/util/bitset/bmutil.h) \
 $(wildcard $(includedir)/util/bitset/encoding.h) \
 $(wildcard $(includedir)/util/bitset/bmalloc.h) \
 $(wildcard $(includedir)/util/bitset/bmblocks.h) \
 $(wildcard $(includedir)/util/bitset/bmundef.h) \
 $(wildcard $(includedir)/util/bitset/bmserial.h) \
 $(wildcard /usr/include/c++/5/cassert) $(wildcard /usr/include/assert.h) \
 $(wildcard $(includedir)/util/bitset/bmtrans.h) \
 $(wildcard $(includedir)/util/bitset/bmalgo_impl.h) \
 $(wildcard $(includedir)/serial/impl/stdtypes.inl) \
 $(wildcard $(includedir)/serial/impl/classinfo.hpp) \
 $(wildcard $(includedir)/serial/impl/classinfob.hpp) \
 $(wildcard $(includedir)/serial/impl/stdtypeinfo.hpp) \
 $(wildcard $(includedir)/serial/impl/memberlist.hpp) \
 $(wildcard $(includedir)/serial/impl/item.hpp) \
 $(wildcard $(includedir)/serial/serialutil.hpp) \
 $(wildcard $(includedir)/serial/impl/memberid.hpp) \
 $(wildcard $(includedir)/serial/impl/memberid.inl) \
 $(wildcard $(includedir)/serial/impl/item.inl) \
 $(wildcard $(includedir)/serial/impl/memberlist.inl) \
 $(wildcard $(includedir)/serial/impl/classinfob.inl) \
 $(wildcard $(includedir)/serial/impl/member.hpp) \
 $(wildcard $(includedir)/serial/impl/member.inl) \
 $(wildcard $(includedir)/serial/impl/classinfo.inl) \
 $(wildcard $(includedir)/serial/impl/choice.hpp) \
 $(wildcard $(includedir)/serial/impl/variant.hpp) \
 $(wildcard $(includedir)/serial/impl/variant.inl) \
 $(wildcard $(includedir)/serial/impl/choice.inl) \
 $(wildcard $(includedir)/serial/impl/enumerated.hpp) \
 $(wildcard $(includedir)/serial/enumvalues.hpp) \
 $(wildcard $(includedir)/serial/impl/objectinfo.inl) \
 $(wildcard $(includedir)/objects/seq/Seq_data.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_data_.hpp) \
 $(wildcard $(includedir)/objects/seq/IUPACaa.hpp) \
 $(wildcard $(includedir)/objects/seq/IUPACaa_.hpp) \
 $(wildcard $(includedir)/objects/seq/IUPACna.hpp) \
 $(wildcard $(includedir)/objects/seq/IUPACna_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI2na.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI2na_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI4na.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI4na_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI8aa.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI8aa_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI8na.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBI8na_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIeaa.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIeaa_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIpaa.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIpaa_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIpna.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIpna_.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIstdaa.hpp) \
 $(wildcard $(includedir)/objects/seq/NCBIstdaa_.hpp) \
 $(wildcard $(includedir)/objects/seq/Bioseq.hpp) \
 $(wildcard $(includedir)/objects/seq/Bioseq_.hpp) \
 $(wildcard $(includedir)/objects/seq/Seqdesc.hpp) \
 $(wildcard $(includedir)/objects/seq/Seqdesc_.hpp) \
 $(wildcard $(includedir)/objects/seq/GIBB_method.hpp) \
 $(wildcard $(includedir)/objects/seq/GIBB_method_.hpp) \
 $(wildcard $(includedir)/objects/seq/GIBB_mod.hpp) \
 $(wildcard $(includedir)/objects/seq/GIBB_mod_.hpp) \
 $(wildcard $(includedir)/objects/seq/GIBB_mol.hpp) \
 $(wildcard $(includedir)/objects/seq/GIBB_mol_.hpp) \
 $(wildcard $(includedir)/objects/seq/Heterogen.hpp) \
 $(wildcard $(includedir)/objects/seq/Heterogen_.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_inst.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_inst_.hpp) \
 $(wildcard $(includedir)/objects/seq/Delta_seq.hpp) \
 $(wildcard $(includedir)/objects/seq/Delta_seq_.hpp) \
 $(wildcard $(includedir)/objects/seq/Delta_ext.hpp) \
 $(wildcard $(includedir)/objects/seq/Delta_ext_.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Na_strand.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Na_strand_.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_ext.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_ext_.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_literal.hpp) \
 $(wildcard $(includedir)/objects/seq/Seq_literal_.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Seq_id.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Seq_id_.hpp) \
 $(wildcard $(includedir)/serial/serializable.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Textseq_id.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Textseq_id_.hpp) \
 $(wildcard $(includedir)/objtools/blast/services/blast_services.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Seq_interval.hpp) \
 $(wildcard $(includedir)/objects/seqloc/Seq_interval_.hpp) \
 $(wildcard $(includedir)/objects/blast/blast__.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_resul_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_resul_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_resul_reque.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_resul_reque_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_statu_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_statu_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_statu_reque.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_statu_reque_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_strat_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_strat_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_request.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_request_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_strat_reque.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_searc_strat_reque_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_windo_taxid_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blas_get_windo_taxid_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_alignment_for_query.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_alignment_for_query_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_archive.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_archive_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_cutoff.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_cutoff_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_database.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_database_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_residue_type.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_residue_type_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_database_info.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_database_info_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_seqtech.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_seqtech_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_error.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_error_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_error_code.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_error_code_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_error_flags.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_error_flags_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_finish_params_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_finish_params_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_parameters.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_parameters_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_value.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_value_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_strand_type.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_strand_type_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_frame_type.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_frame_type_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_databa_ex_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_databa_ex_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_databases_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_databases_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_matrices_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_matrices_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_parameter_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_parameter_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_paramsets_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_paramsets_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_programs_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_programs_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_queries_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_queries_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_seq_parts_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_seq_parts_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_sequenc_request.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_sequenc_request_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_sequences_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_get_sequences_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_ka_block.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_ka_block_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_mask.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_mask_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_matrix_id.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_matrix_id_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_parameter.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_parameter_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_parameter_info.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_parameter_info_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_phi_alignments.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_phi_alignments_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_program_info.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_program_info_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_queries.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_queries_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_queue_search_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_queue_search_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_queue_search_reques.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_queue_search_reques_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_range.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_range_.hpp) \
 $(wildcard $(includedir)/util/range.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_reply_body.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_reply_body_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_request_body.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_request_body_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_result_types.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_result_types_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_seq_part_data.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_seq_part_data_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_simple_alignment.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_simple_alignment_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_simple_results.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_simple_results_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_subject.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_subject_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_task_info.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast4_task_info_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_finish_params_reques.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_finish_params_reques_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_databa_ex_reques.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_databa_ex_reques_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_proto_info_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_proto_info_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_proto_info_reque.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_proto_info_reque_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_reque_info_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_reque_info_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_reque_info_reque.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_reque_info_reque_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_searc_info_reply.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_searc_info_reply_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_searc_info_reque.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_searc_info_reque_.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_seq_parts_reques.hpp) \
 $(wildcard $(includedir)/objects/blast/Blast_get_seq_parts_reques_.hpp) \
 $(wildcard $(includedir)/objects/blast/NCBI_Blast4_module.hpp) \
 $(wildcard $(includedir)/objects/blast/names.hpp) \
 $(wildcard $(includedir)/objects/scoremat/PssmWithParameters.hpp) \
 $(wildcard $(includedir)/objects/scoremat/PssmWithParameters_.hpp) \
 $(wildcard $(includedir)/objects/blast/blastclient.hpp) \
 $(wildcard $(includedir)/objects/blast/blastclient_.hpp) \
 $(wildcard $(includedir)/serial/rpcbase.hpp) \
 $(wildcard $(includedir)/corelib/ncbimtx.hpp) \
 $(wildcard $(includedir)/corelib/ncbithr_conf.hpp) \
 $(wildcard /usr/include/x86_64-linux-gnu/sys/errno.h) \
 $(wildcard $(includedir)/corelib/guard.hpp) \
 $(wildcard $(includedir)/corelib/ncbimtx.inl) \
 $(wildcard $(includedir)/connect/ncbi_conn_stream.hpp) \
 $(wildcard $(includedir)/connect/ncbi_ftp_connector.h) \
 $(wildcard $(includedir)/connect/ncbi_connutil.h) \
 $(wildcard $(includedir)/connect/ncbi_buffer.h) \
 $(wildcard $(includedir)/connect/connect_export.h) \
 $(wildcard $(includedir)/connect/ncbi_connection.h) \
 $(wildcard $(includedir)/connect/ncbi_connector.h) \
 $(wildcard $(includedir)/connect/ncbi_core.h) \
 $(wildcard $(includedir)/connect/ncbi_types.h) \
 $(wildcard $(includedir)/connect/ncbi_socket.h) \
 $(wildcard $(includedir)/connect/ncbi_memory_connector.h) \
 $(wildcard $(includedir)/connect/ncbi_namedpipe_connector.hpp) \
 $(wildcard $(includedir)/connect/ncbi_namedpipe.hpp) \
 $(wildcard $(includedir)/connect/ncbi_core_cxx.hpp) \
 $(wildcard $(includedir)/corelib/ncbireg.hpp) \
 $(wildcard $(includedir)/connect/ncbi_pipe_connector.hpp) \
 $(wildcard $(includedir)/connect/ncbi_pipe.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_process.hpp) \
 $(wildcard $(includedir)/corelib/interprocess_lock.hpp) \
 $(wildcard $(includedir)/connect/ncbi_service_connector.h) \
 $(wildcard $(includedir)/connect/ncbi_http_connector.h) \
 $(wildcard $(includedir)/connect/ncbi_service.h) \
 $(wildcard $(includedir)/connect/ncbi_server_info.h) \
 $(wildcard $(includedir)/connect/ncbi_host_info.h) \
 $(wildcard $(includedir)/connect/ncbi_socket_connector.h) \
 $(wildcard $(includedir)/util/icanceled.hpp) \
 $(wildcard $(includedir)/connect/ncbi_util.h) \
 $(wildcard $(includedir)/serial/objistr.hpp) \
 $(wildcard $(includedir)/corelib/ncbimempool.hpp) \
 $(wildcard $(includedir)/util/strbuffer.hpp) \
 $(wildcard $(includedir)/util/util_exception.hpp) \
 $(wildcard $(includedir)/util/bytesrc.hpp) \
 $(wildcard $(includedir)/corelib/reader_writer.hpp) \
 $(wildcard $(includedir)/util/strbuffer.inl) \
 $(wildcard $(includedir)/serial/impl/objlist.hpp) \
 $(wildcard $(includedir)/serial/impl/objlist.inl) \
 $(wildcard $(includedir)/serial/objhook.hpp) \
 $(wildcard $(includedir)/serial/impl/objstack.hpp) \
 $(wildcard $(includedir)/serial/impl/objstack.inl) \
 $(wildcard $(includedir)/serial/objectiter.hpp) \
 $(wildcard $(includedir)/serial/impl/objectiter.inl) \
 $(wildcard $(includedir)/serial/impl/objistr.inl) \
 $(wildcard $(includedir)/serial/objostr.hpp) \
 $(wildcard $(includedir)/corelib/ncbifloat.h) \
 $(wildcard $(includedir)/serial/impl/objostr.inl) \
 $(wildcard $(includedir)/serial/serial.hpp) \
 $(wildcard $(includedir)/util/retry_ctx.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_url.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_param.hpp) \
 $(wildcard $(includedir)/corelib/ncbiapp.hpp) \
 $(wildcard $(includedir)/corelib/ncbiargs.hpp) \
 $(wildcard $(includedir)/corelib/ncbienv.hpp) \
 $(wildcard $(includedir)/corelib/metareg.hpp) \
 $(wildcard $(includedir)/corelib/version.hpp) \
 $(wildcard $(includedir)/corelib/ncbithr.hpp) \
 $(wildcard $(includedir)/corelib/ncbi_safe_static.hpp) \
 $(wildcard $(includedir)/corelib/impl/ncbi_param_impl.hpp) \
 $(wildcard $(includedir)/serial/rpcbase_impl.hpp)
