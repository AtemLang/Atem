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
		"module/ast/types/atemc.ast.types.stmtast.ixx" 
		"module/ast/types/atemc.ast.types.exprast.ixx" 
		"module/ast/types/atemc.ast.types.declstmtast.ixx"
		"module/ast/types/atemc.ast.types.unaryexprast.ixx"
		"module/ast/types/atemc.ast.types.binaryexprast.ixx"
		"module/atemc.ixx" 
		"module/exception/atemc.exception.ixx"
		"module/exception/atemc.exception.abstractexception.ixx"
		"module/exception/atemc.exception.internalexception.ixx"
		"module/exception/atemc.exception.parseexception.ixx"
		"module/exception/atemc.exception.semanticexception.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.abstracttype.ixx" 
		"module/semantic/types/visitor/atemc.semantic.types.visitor.ixx"
		"module/semantic/types/atemc.semantic.types.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.ixx" 
		"module/semantic/types/concrete/atemc.semantic.types.concrete.integertype.ixx" 
		"module/semantic/types/concrete/atemc.semantic.types.concrete.booleantype.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.floatingpointtype.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.unittype.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.pointertype.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.compositetype.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.functiontype.ixx"
		"module/semantic/types/concrete/atemc.semantic.types.concrete.typetype.ixx"
		"module/ast/types/atemc.ast.types.unaryexprast.ixx" 
		"module/ast/types/atemc.ast.types.ternaryexprast.ixx" 
		"module/ast/types/atemc.ast.types.ifexprast.ixx"
		"module/ast/types/atemc.ast.types.forexprast.ixx"
		"module/ast/types/atemc.ast.types.whileexprast.ixx"
		"module/ast/types/atemc.ast.types.repeatwhileexprast.ixx"
		"module/ast/operators/atemc.ast.operators.ixx"
		"module/ast/operators/atemc.ast.operators.abstractoperator.ixx"
)

target_compile_options(atemc PRIVATE /EHsc /experimental:module)

find_package(clipp CONFIG REQUIRED)
find_package(matchit CONFIG REQUIRED)
find_package(antlr4-runtime CONFIG REQUIRED)
find_package(concurrencpp CONFIG REQUIRED)
find_package(stdexec CONFIG REQUIRED)
find_package(unifex CONFIG REQUIRED)
find_package(Microsoft.GSL CONFIG REQUIRED)
find_package(nameof CONFIG REQUIRED)
find_package(stxxl CONFIG REQUIRED)

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

llvm_map_components_to_libnames(
	llvm_libs 
	CodeGen
	Core
	Demangle
	Extensions
	FileCheck
	Passes
	IRReader
	TransformUtils
)

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
		stxxl
        ${llvm_libs}
)

target_include_directories(atemc PRIVATE ${LLVM_INCLUDE_DIRS})
target_include_directories(atemc PRIVATE "/")
target_include_directories(atemc PRIVATE "${_VCPKG_INSTALLED_DIR}/x64-windows/include/antlr4-runtime")

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET atemc PROPERTY CXX_STANDARD 23)
endif()
