add_library(Hello_lib
  Speaker.h
  Speaker.cpp)

target_compile_definitions(Hello_lib PUBLIC ${BLA_DEFINITIONS})

target_include_directories(Hello_lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${BLA_INCLUDE_DIR})

add_library(Hello_lib::Hello_lib ALIAS Hello_lib)

install (TARGETS Hello_lib DESTINATION bin)
install (FILES Speaker.h DESTINATION include)
