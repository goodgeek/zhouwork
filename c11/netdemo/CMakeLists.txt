PROJECT(main)
SET(SRC_LIST main.cpp logger.cpp tcpserver.cpp threadnet.cpp sealbase.cpp)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lpthread -g")
ADD_EXECUTABLE(main ${SRC_LIST})
