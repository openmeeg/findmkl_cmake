add_library(Hello
  Speaker.h
  Speaker.cpp)

target_compile_definitions(Hello PUBLIC ${BLA_DEFINITIONS})

install (TARGETS Hello DESTINATION bin)
install (FILES Speaker.h DESTINATION include)
