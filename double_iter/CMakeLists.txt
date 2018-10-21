
PROJECT("double_iter")

set(CMAKE_MSVCIDE_RUN_PATH ${PROJECT_SOURCE_DIR}/../data)

set(src 
	double_list_iter.cpp
	double_receiver_iter.cpp
	double_list_iter.h
)


add_executable(${PROJECT_NAME}
	WIN32
	${src}
)
