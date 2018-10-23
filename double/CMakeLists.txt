
PROJECT("double")

set(CMAKE_MSVCIDE_RUN_PATH ${PROJECT_SOURCE_DIR}/../data)

set(src 
	double_list.cpp
	double_receiver.cpp
	double_list.h
)


add_executable(${PROJECT_NAME}
	WIN32
	${src}
)

set_target_properties( ${PROJECT_NAME}
       PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
)
