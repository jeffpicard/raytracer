# Based on ./gtest-1.7.0/make/Makefile

TESTS = test_Vector3F test_Color test_Scene

GTEST_DIR = ./gtest-1.7.0

FLAGS = -W -std=c++11

all: $(TESTS) Ray.o Scene.o Camera.o rt



gtest.a: 
	g++ $(FLAGS) -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
            -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv gtest.a gtest-all.o





Vector3F.o: Vector3F.cc Vector3F.hh
	g++ $(FLAGS) -c Vector3F.cc

test_Vector3F.o: test_Vector3F.cc
	g++ $(FLAGS) -I${GTEST_DIR}/include -c test_Vector3F.cc

test_Vector3F: test_Vector3F.o Vector3F.o gtest.a
	g++ $(FLAGS) -isystem ${GTEST_DIR}/include -pthread $^ -o test_Vector3F







Color.o: Color.cc Color.hh
	g++ $(FLAGS) -c Color.cc

test_Color.o: test_Color.cc
	g++ $(FLAGS) -I${GTEST_DIR}/include -c test_Color.cc

test_Color: test_Color.o Color.o gtest.a
	g++ $(FLAGS) -isystem ${GTEST_DIR}/include -pthread $^ -o test_Color




test_Scene.o: test_Scene.cc
	g++ $(FLAGS) -I${GTEST_DIR}/include -c test_Scene.cc

test_Scene: test_Scene.o Scene.o Vector3F.o Color.o Ray.o gtest.a Camera.o
	g++ $(FLAGS) -isystem ${GTEST_DIR}/include -pthread $^ -o test_Scene





Ray.o: Ray.cc Ray.hh
	g++ $(FLAGS) -c Ray.cc

Scene.o: Scene.cc Scene.hh Vector3F.o Color.o Ray.o Camera.o
	g++ $(FLAGS) -c Scene.cc

Camera.o: Camera.cc Camera.hh Vector3F.o Ray.o
	g++ $(FLAGS) -c Camera.cc



rt.o: rt.cc
	g++ $(FLAGS) -c rt.cc

rt: rt.o Scene.o Vector3F.o Color.o Ray.o Camera.o
	g++ $(FLAGS) $^ -o rt




clean:
	rm *.o
