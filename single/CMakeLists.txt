PROJECT("single")

set(src
	single_list.cpp
	single_list.h
	single_receiver.cpp
)

add_executable(${PROJECT_NAME}
	WIN32
	${src}	
)

set_target_properties( ${PROJECT_NAME}
       PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
)
