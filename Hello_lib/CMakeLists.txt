add_library(Hello_lib
  Speaker.h
  Speaker.cpp)

target_compile_definitions(Hello_lib PUBLIC ${BLA_DEFINITIONS})

install (TARGETS Hello_lib DESTINATION bin)
install (FILES Speaker.h DESTINATION include)
