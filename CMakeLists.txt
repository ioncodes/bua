cmake_minimum_required (VERSION 2.6)
project (bua)
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)
file(GLOB SOURCE
	"src/*.cpp"
	"include/bua/*.h*"
)
add_executable(bua ${SOURCE})
file(GLOB LIBS
		"lib/*"
	)
target_link_libraries(bua ${LIBS})