add_executable(unittest_stuff
  string_tools_tests.cpp
)
target_link_libraries(unittest_stuff stuff)
create_test(unittest_stuff)
