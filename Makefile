# Based on ./gtest-1.7.0/make/Makefile

TESTS = test_Vector3F test_Color test_Scene

SRC = .

INCLUDE = .

GTEST_DIR = ./gtest-1.7.0

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

CPPFLAGS += -isystem $(GTEST_DIR)/include -I$(INCLUDE)

#CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11
CXXFLAGS += -g -pthread -std=c++11

.PHONY : all clean image depend

all: rt

tests: $(TESTS)

SRCS = Camera.cc Color.cc Ray.cc rt.cc Scene.cc Vector3F.cc \

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
	./rt | pnmtopng > balls.png

docs:
	doxygen Doxyfile

depend:
	makedepend -- $(CXXFLAGS) -I. -- $(SRCS) $(TESTSRCS)

clean:
	rm -f *.o $(TESTS) gtest.a rt Makefile.bak balls.png -r docs

# DO NOT DELETE THIS LINE -- make depend depends on it

Camera.o: Camera.hh Vector3F.hh Ray.hh
Color.o: Color.hh
Ray.o: Ray.hh Vector3F.hh
rt.o: Scene.hh Color.hh Ray.hh Vector3F.hh Camera.hh Light.hh
Scene.o: Scene.hh Color.hh Ray.hh Vector3F.hh Camera.hh Light.hh
Vector3F.o: Vector3F.hh
