add_executable (
	atemc 		
        "module/atemc.main.ixx"
		"module/ast/atemc.ast.ixx" 
		"module/codegen/atemc.codegen.ixx"
		"module/frontend/atemc.frontend.ixx"
		"module/optimizer/atemc.optimizer.ixx"
		"module/utils/atemc.utils.ixx"
		"module/semantic/atemc.semantic.ixx"
		"grammar/AtemLexer.cpp"
		"grammar/AtemParser.cpp"
		"grammar/AtemParserBaseListener.cpp"
		"grammar/AtemParserBaseVisitor.cpp"
		"grammar/AtemParserListener.cpp"
		"grammar/AtemParserVisitor.cpp"
		"grammar/AtemLexer.h"
		"grammar/AtemParser.h"
		"grammar/AtemParserBaseListener.h"
		"grammar/AtemParserBaseVisitor.h"
		"grammar/AtemParserListener.h"
		"grammar/AtemParserVisitor.h"
		"module/ast/types/atemc.ast.types.ixx"
		"module/ast/types/atemc.ast.types.moduleast.ixx"
		"module/ast/types/atemc.ast.types.abstractast.ixx" 
		"module/basic/atemc.basic.sourcelocation.ixx" 
		"module/basic/atemc.basic.ixx" 
		"module/ast/builder/atemc.ast.builder.ixx" 
		"module/ast/visitor/atemc.ast.visitor.ixx" 
		"module/basic/atemc.basic.object.ixx"
)

target_compile_options(atemc PRIVATE /EHsc)

find_package(clipp CONFIG REQUIRED)
find_package(matchit CONFIG REQUIRED)
find_package(antlr4-runtime CONFIG REQUIRED)
find_package(concurrencpp CONFIG REQUIRED)
find_package(stdexec CONFIG REQUIRED)
find_package(unifex CONFIG REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(nameof CONFIG REQUIRED)

find_package(LLVM CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
add_definitions(${LLVM_DEFINITIONS})

set(Boost_INCLUDE_DIR ${_VCPKG_INSTALLED_DIR}/x64-windows/include)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost REQUIRED)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif ()

target_link_libraries(
	atemc PRIVATE 
		clipp::clipp
        matchit::matchit
		antlr4_shared
		concurrencpp::concurrencpp
		STDEXEC::stdexec
		unifex::unifex
		Microsoft.GSL::GSL
		nameof::nameof
        ${llvm_libs}
)

target_include_directories(atemc PRIVATE ${LLVM_INCLUDE_DIRS})
target_include_directories(atemc PRIVATE "/")
target_include_directories(atemc PRIVATE "${_VCPKG_INSTALLED_DIR}/x64-windows/include/antlr4-runtime")

llvm_map_components_to_libnames(llvm_libs Support Core IRReader)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET atemc PROPERTY CXX_STANDARD 23)
endif()
