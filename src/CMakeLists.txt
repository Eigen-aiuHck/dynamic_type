add_library(dynamic_type STATIC types.cpp
                                ${PROJECT_SOURCE_DIR}/include/types.hpp)
target_include_directories(dynamic_type PUBLIC ${PROJECT_SOURCE_DIR}/include/)

target_compile_definitions(dynamic_type PUBLIC dataBase__type_entry_PUBLIC)
target_compile_definitions(dynamic_type PRIVATE dataBase__type_entry_PRIVATE)

target_compile_features(dynamic_type PRIVATE cxx_std_20)
target_compile_features(dynamic_type PUBLIC cxx_std_17)
target_compile_options(dynamic_type PRIVATE)
