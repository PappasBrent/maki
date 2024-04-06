if(LLVM_EXTERNAL_LIT)
  get_filename_component(LLVM_LIT_TOOLS_DIR "${LLVM_EXTERNAL_LIT}" DIRECTORY)
  find_program(FILECHECK_PATH FileCheck HINTS "${LLVM_LIT_TOOLS_DIR}")
else()
  find_program(FILECHECK_PATH FileCheck)
endif()

if(FILECHECK_PATH STREQUAL "FILECHECK_PATH-NOTFOUND")
  message(FATAL_ERROR "Could not find FileCheck")
endif()

configure_lit_site_cfg(
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.site.cfg.py.in
  ${CMAKE_CURRENT_BINARY_DIR}/lit.site.cfg.py
  MAIN_CONFIG
  ${CMAKE_CURRENT_SOURCE_DIR}/lit.cfg.py
)

set(CPP2C_TEST_DEPENDS cpp2c)

add_lit_testsuite(check-cpp2c "Running cpp2c regression tests"
  ${CMAKE_CURRENT_BINARY_DIR}
  DEPENDS ${CPP2C_TEST_DEPENDS}
)

set_target_properties(check-cpp2c PROPERTIES FOLDER "Tests")

add_lit_testsuites(cpp2c ${CMAKE_CURRENT_SOURCE_DIR} DEPENDS ${CPP2C_TEST_DEPENDS})
