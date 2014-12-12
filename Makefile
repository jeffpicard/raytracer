# Based on ./gtest-1.7.0/make/Makefile

TESTS = test_Vector3F test_Color test_Scene

SRC = .

INCLUDE = .

GTEST_DIR = ./gtest-1.7.0

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

CPPFLAGS += -isystem $(GTEST_DIR)/include -I$(INCLUDE)

CXXFLAGS += -g -pthread -std=c++11

.PHONY : all clean iamge depend

all: rt

tests: $(TESTS)

SRCS = Camera.cc Color.cc Ray.cc rt.cc Scene.cc Vector3F.cc scene_generator.cc

TESTSRC = test_Color.cc test_Scene.cc test_Vector3F.cc

OBJS= $(SRCS:.cc=.o)

TESTOBJS = $(TESTSRC:.CC=.O)

rt: $(OBJS)
	g++ -o rt $(OBJS)

test_Color: test_Color.o Color.o gtest.a
	g++ $(FLAGS) -isystem ${GTEST_DIR}/include -pthread $^ -o test_Color

test_Vector3F: test_Vector3F.o Vector3F.o gtest.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -Lpthread $^ -o $@

test_Scene: test_Scene.o Scene.o Vector3F.o Color.o Ray.o gtest.a Camera.o
	g++ $(FLAGS) -isystem ${GTEST_DIR}/include -pthread $^ -o test_Scene



gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^



image: rt
	./rt < scene_lab4.txt | pnmtopng > balls.png

docs:
	doxygen Doxyfile

depend:
	makedepend -- $(CXXFLAGS) -I. -- $(SRCS) $(TESTSRCS)

clean:
	rm -f *.o $(TESTS) gtest.a rt Makefile.bak balls.png
	rm -r docs

# DO NOT DELETE THIS LINE -- make depend depends on it

Camera.o: Camera.hh Vector3F.hh Ray.hh /usr/include/boost/shared_ptr.hpp
Camera.o: /usr/include/boost/smart_ptr/shared_ptr.hpp
Camera.o: /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp
Camera.o: /usr/include/boost/config/select_compiler_config.hpp
Camera.o: /usr/include/boost/config/compiler/gcc.hpp
Camera.o: /usr/include/boost/config/select_platform_config.hpp
Camera.o: /usr/include/boost/config/posix_features.hpp /usr/include/unistd.h
Camera.o: /usr/include/features.h /usr/include/stdc-predef.h
Camera.o: /usr/include/getopt.h /usr/include/boost/config/suffix.hpp
Camera.o: /usr/include/boost/config/no_tr1/memory.hpp
Camera.o: /usr/include/boost/assert.hpp /usr/include/assert.h
Camera.o: /usr/include/boost/current_function.hpp
Camera.o: /usr/include/boost/checked_delete.hpp
Camera.o: /usr/include/boost/throw_exception.hpp
Camera.o: /usr/include/boost/exception/detail/attribute_noreturn.hpp
Camera.o: /usr/include/boost/detail/workaround.hpp
Camera.o: /usr/include/boost/config.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/shared_count.hpp
Camera.o: /usr/include/boost/smart_ptr/bad_weak_ptr.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/sp_counted_base.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/sp_has_sync.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/sp_counted_base_gcc_x86.hpp
Camera.o: /usr/include/boost/detail/sp_typeinfo.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/sp_counted_impl.hpp
Camera.o: /usr/include/boost/utility/addressof.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/sp_convertible.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/sp_nullptr_t.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/spinlock_pool.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/spinlock.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/spinlock_nt.hpp
Camera.o: /usr/include/boost/memory_order.hpp
Camera.o: /usr/include/boost/smart_ptr/detail/operator_bool.hpp
Color.o: Color.hh
Ray.o: Ray.hh Vector3F.hh
rt.o: scene_generator.hh Scene.hh Color.hh Ray.hh Vector3F.hh Camera.hh
rt.o: /usr/include/boost/shared_ptr.hpp
rt.o: /usr/include/boost/smart_ptr/shared_ptr.hpp
rt.o: /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp
rt.o: /usr/include/boost/config/select_compiler_config.hpp
rt.o: /usr/include/boost/config/compiler/gcc.hpp
rt.o: /usr/include/boost/config/select_platform_config.hpp
rt.o: /usr/include/boost/config/posix_features.hpp /usr/include/unistd.h
rt.o: /usr/include/features.h /usr/include/stdc-predef.h
rt.o: /usr/include/getopt.h /usr/include/boost/config/suffix.hpp
rt.o: /usr/include/boost/config/no_tr1/memory.hpp
rt.o: /usr/include/boost/assert.hpp /usr/include/assert.h
rt.o: /usr/include/boost/current_function.hpp
rt.o: /usr/include/boost/checked_delete.hpp
rt.o: /usr/include/boost/throw_exception.hpp
rt.o: /usr/include/boost/exception/detail/attribute_noreturn.hpp
rt.o: /usr/include/boost/detail/workaround.hpp /usr/include/boost/config.hpp
rt.o: /usr/include/boost/smart_ptr/detail/shared_count.hpp
rt.o: /usr/include/boost/smart_ptr/bad_weak_ptr.hpp
rt.o: /usr/include/boost/smart_ptr/detail/sp_counted_base.hpp
rt.o: /usr/include/boost/smart_ptr/detail/sp_has_sync.hpp
rt.o: /usr/include/boost/smart_ptr/detail/sp_counted_base_gcc_x86.hpp
rt.o: /usr/include/boost/detail/sp_typeinfo.hpp
rt.o: /usr/include/boost/smart_ptr/detail/sp_counted_impl.hpp
rt.o: /usr/include/boost/utility/addressof.hpp
rt.o: /usr/include/boost/smart_ptr/detail/sp_convertible.hpp
rt.o: /usr/include/boost/smart_ptr/detail/sp_nullptr_t.hpp
rt.o: /usr/include/boost/smart_ptr/detail/spinlock_pool.hpp
rt.o: /usr/include/boost/smart_ptr/detail/spinlock.hpp
rt.o: /usr/include/boost/smart_ptr/detail/spinlock_nt.hpp
rt.o: /usr/include/boost/memory_order.hpp
rt.o: /usr/include/boost/smart_ptr/detail/operator_bool.hpp Light.hh
Scene.o: Scene.hh Color.hh Ray.hh Vector3F.hh Camera.hh
Scene.o: /usr/include/boost/shared_ptr.hpp
Scene.o: /usr/include/boost/smart_ptr/shared_ptr.hpp
Scene.o: /usr/include/boost/config.hpp /usr/include/boost/config/user.hpp
Scene.o: /usr/include/boost/config/select_compiler_config.hpp
Scene.o: /usr/include/boost/config/compiler/gcc.hpp
Scene.o: /usr/include/boost/config/select_platform_config.hpp
Scene.o: /usr/include/boost/config/posix_features.hpp /usr/include/unistd.h
Scene.o: /usr/include/features.h /usr/include/stdc-predef.h
Scene.o: /usr/include/getopt.h /usr/include/boost/config/suffix.hpp
Scene.o: /usr/include/boost/config/no_tr1/memory.hpp
Scene.o: /usr/include/boost/assert.hpp /usr/include/assert.h
Scene.o: /usr/include/boost/current_function.hpp
Scene.o: /usr/include/boost/checked_delete.hpp
Scene.o: /usr/include/boost/throw_exception.hpp
Scene.o: /usr/include/boost/exception/detail/attribute_noreturn.hpp
Scene.o: /usr/include/boost/detail/workaround.hpp
Scene.o: /usr/include/boost/config.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/shared_count.hpp
Scene.o: /usr/include/boost/smart_ptr/bad_weak_ptr.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/sp_counted_base.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/sp_has_sync.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/sp_counted_base_gcc_x86.hpp
Scene.o: /usr/include/boost/detail/sp_typeinfo.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/sp_counted_impl.hpp
Scene.o: /usr/include/boost/utility/addressof.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/sp_convertible.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/sp_nullptr_t.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/spinlock_pool.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/spinlock.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/spinlock_nt.hpp
Scene.o: /usr/include/boost/memory_order.hpp
Scene.o: /usr/include/boost/smart_ptr/detail/operator_bool.hpp Light.hh
Vector3F.o: Vector3F.hh
scene_generator.o: scene_generator.hh Scene.hh Color.hh Ray.hh Vector3F.hh
scene_generator.o: Camera.hh /usr/include/boost/shared_ptr.hpp
scene_generator.o: /usr/include/boost/smart_ptr/shared_ptr.hpp
scene_generator.o: /usr/include/boost/config.hpp
scene_generator.o: /usr/include/boost/config/user.hpp
scene_generator.o: /usr/include/boost/config/select_compiler_config.hpp
scene_generator.o: /usr/include/boost/config/compiler/gcc.hpp
scene_generator.o: /usr/include/boost/config/select_platform_config.hpp
scene_generator.o: /usr/include/boost/config/posix_features.hpp
scene_generator.o: /usr/include/unistd.h /usr/include/features.h
scene_generator.o: /usr/include/stdc-predef.h /usr/include/getopt.h
scene_generator.o: /usr/include/boost/config/suffix.hpp
scene_generator.o: /usr/include/boost/config/no_tr1/memory.hpp
scene_generator.o: /usr/include/boost/assert.hpp /usr/include/assert.h
scene_generator.o: /usr/include/boost/current_function.hpp
scene_generator.o: /usr/include/boost/checked_delete.hpp
scene_generator.o: /usr/include/boost/throw_exception.hpp
scene_generator.o: /usr/include/boost/exception/detail/attribute_noreturn.hpp
scene_generator.o: /usr/include/boost/detail/workaround.hpp
scene_generator.o: /usr/include/boost/config.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/shared_count.hpp
scene_generator.o: /usr/include/boost/smart_ptr/bad_weak_ptr.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/sp_counted_base.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/sp_has_sync.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/sp_counted_base_gcc_x86.hpp
scene_generator.o: /usr/include/boost/detail/sp_typeinfo.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/sp_counted_impl.hpp
scene_generator.o: /usr/include/boost/utility/addressof.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/sp_convertible.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/sp_nullptr_t.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/spinlock_pool.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/spinlock.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/spinlock_nt.hpp
scene_generator.o: /usr/include/boost/memory_order.hpp
scene_generator.o: /usr/include/boost/smart_ptr/detail/operator_bool.hpp
scene_generator.o: Light.hh
