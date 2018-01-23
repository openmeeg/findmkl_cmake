add_library(myLib_Hello
  Speaker.h
  Speaker.cpp)

target_compile_definitions(myLib_Hello PUBLIC ${BLA_DEFINITIONS})

install (TARGETS myLib_Hello DESTINATION bin)
install (FILES Speaker.h DESTINATION include)
