parser grammar AtemParser;

options {
	tokenVocab = AtemLexer;
}

program
	: statements? EOF;

statement
	:((
		declaration_statement |
		expression
	) Semicolon?) | Semicolon;

statements
	: statement+;

declaration_statement_or_list
	: declaration_statement | declaration_statement_list;

declaration_statement_list
	: LeftCurly declaration_statement (Comma declaration_statement)* Comma? RightCurly;

declaration_statement
	: declarator declaration_expression;

declarator
	: access_level_specifier? storage_level_specifier? declarator_name require_clause? declare_operator;

declare_operator
	: Colon (attributes? type_expression)? Assign;
empty_declare_operator
	: Colon Assign;

declarator_name
	: path_expression;

declaration_expression
	: package_declaration
	| project_declaration
	| module_declaration
	| namespace_declaration
	| function_declaration
	| variable_declaration
	| constant_declaration
	| alias_declaration
	| struct_declaration
	| class_declaration
	| protocol_declaration
	| union_declaration
	| enum_declaration
	| extension_declaration
	| test_declaration
	;

test_declaration
	: KeywordTest attributes? test_name? code_block_no_label;
test_name
	: string_literal;

struct_declaration
	: KeywordStruct udt_parameter_clause? attributes? final_specifier? extension_list? initializer_list? deinitializer_list? member_list;

class_declaration
	: KeywordClass udt_parameter_clause? attributes? final_specifier? extension_list? initializer_list? deinitializer_list? member_list;

extension_declaration
	: KeywordExtend path_expression KeywordWith attributes? extension_list? initializer_list? deinitializer_list? member_list enumerator_list?;

udt_parameter_clause
	: function_parameter_list;

final_specifier
	: KeywordFinal;
member_specifier
	: KeywordStatic
	| KeywordMutable
	| KeywordFinal
	;
member_specifiers
	: member_specifier+;

extension_list
	: KeywordExtend LeftCurly extension_item+ RightCurly;
extension_item
	: inherit_clause | impl_clause;

inherit_clause
	: KeywordInherit inherit_list;
inherit_list
	: LeftCurly inherit_items RightCurly | inherit_item;
inherit_item
	: path_expression inherit_member_list?;
inherit_items
	: inherit_item+;
inherit_member_list
	: LeftCurly inherit_members RightCurly;
inherit_member
	: inherit_type_override
	| inherit_variable_override
	| inherit_constant_override
	| inherit_function_override
	;
inherit_members
	: inherit_member+;
inherit_type_override
	: KeywordOverride inherit_declarator alias_declaration;
inherit_variable_override
	: KeywordOverride inherit_declarator variable_declaration getter_and_setter_list?;
inherit_constant_override
	: KeywordOverride inherit_declarator constant_declaration getter_list?;
inherit_function_override
	: KeywordOverride inherit_declarator function_declaration;
inherit_initializer_override
	: KeywordOverride empty_inherit_declarator initializer_declaration;
inherit_deinitializer_override
	: KeywordOverride empty_inherit_declarator deinitializer_declaration;
inherit_declarator
	: access_level_specifier? storage_level_specifier? member_specifiers? inherit_name require_clause? declare_operator;
empty_inherit_declarator
	: access_level_specifier? storage_level_specifier? member_specifiers? require_clause? empty_declare_operator;
inherit_name
	: Identifier;

impl_clause
	: KeywordImpl impl_list;
impl_list
	: LeftCurly impl_items RightCurly 
	| impl_item
	;
impl_item
	: path_expression impl_with_clause;
impl_items
	: impl_item+;
impl_with_clause
	: KeywordWith impl_member_list;
impl_member_list
	: LeftCurly impl_members RightCurly;
impl_member
	: associated_type_impl
	| associated_variable_impl
	| associated_constant_impl
	| associated_function_impl
	;
impl_members
	: impl_member+;
default_clause
	: Assign default_literal;
associated_type_impl
	: KeywordRequire associated_declarator alias_declaration | default_clause;
associated_variable_impl
	: KeywordRequire associated_declarator variable_declaration | default_clause getter_and_setter_list?;
associated_constant_impl
	: KeywordRequire associated_declarator constant_declaration | default_clause getter_list?;
associated_function_impl
	: KeywordRequire associated_declarator function_declaration | default_clause;
associated_initializer_impl
	: KeywordRequire empty_declare_operator initializer_declaration | default_clause;
associated_deinitializer_impl
	: KeywordRequire empty_declare_operator deinitializer_declaration | default_clause;
associated_declarator
	: access_level_specifier? storage_level_specifier? member_specifiers? associated_name require_clause? declare_operator;
empty_associated_declarator
	: access_level_specifier? storage_level_specifier? member_specifiers? require_clause? empty_declare_operator;
associated_name
	: Identifier;

initializer_list: KeywordInit initializer_member_list;
initializer_member_list: LeftCurly initializer_members RightCurly;
initializer_member: member_specifiers? empty_declare_operator initializer_type function_body;
initializer_type: function_parameter_clause? function_specifiers? contract_list?;
initializer_members: initializer_member+;

deinitializer_list: KeywordDeinit deinitializer_member_list;
deinitializer_member_list: LeftCurly deinitializer_members RightCurly;
deinitializer_member: member_specifiers? empty_declare_operator deinitializer_type function_body;
deinitializer_type: function_parameter_clause? function_specifiers? contract_list?;
deinitializer_members: deinitializer_member+;

member_list
	: KeywordMember LeftCurly members RightCurly;
member 
	: member_type
	| member_variable
	| member_constant
	| member_function
	| member_nested_type
	;
members: member+;
member_nested_type
	: nested_class
	| nested_struct
	| nested_protocol
	| nested_union
	| nested_enum
	;
nested_class
	: member_declarator class_declaration;
nested_struct
	: member_declarator struct_declaration;
nested_protocol
	: member_declarator protocol_declaration;
nested_union
	: member_declarator union_declaration;
nested_enum
	: member_declarator enum_declaration;

member_type
	: member_declarator alias_declaration;
member_variable
	: member_declarator variable_declaration getter_and_setter_list?;
member_constant
	: member_declarator constant_declaration getter_list?;
member_function
	: member_declarator function_declaration;
member_declarator
	: access_level_specifier? storage_level_specifier? member_specifiers? member_name require_clause? declare_operator;
member_name
	: Identifier;
getter_and_setter_list
	: KeywordWith LeftCurly getter_and_setter_items RightCurly;
getter_list
	: KeywordWith LeftCurly getter_declaration RightCurly;
getter_and_setter_item
	: getter_declaration
	| setter_declaration
	;
getter_and_setter_items
	: getter_and_setter_item+;
getter_declaration
	: member_specifiers? empty_declare_operator KeywordGet getter_type function_body;
getter_type
	: function_specifiers? contract_list?;
setter_declaration
	: member_specifiers? empty_declare_operator KeywordSet setter_type function_body;
setter_type
	: setter_parameter_clause? function_specifiers? contract_list?;
setter_parameter_clause
	: setter_parameter;
setter_parameter
	: setter_parameter_name (Colon type_annotation)?;
setter_parameter_name
	: Identifier;

protocol_declaration
	: KeywordProtocol udt_parameter_clause? attributes? final_specifier? protocol_extend_list? protocol_requirement_list (KeywordWith Identifier)?;
protocol_extend_list
	: KeywordExtend LeftCurly RightCurly;
protocol_requirement_list
	: KeywordMember LeftCurly protocol_requirement_items RightCurly;
protocol_requirement_item
	: protocol_requirement_type
	| protocol_requirement_function
	| protocol_requirement_variable
	| protocol_requirement_constant
	| protocol_requirement_initializer
	| protocol_requirement_deinitializer
	;
protocol_requirement_items
	: protocol_requirement_item+;
protocol_requirement_type
	: requirement_declarator KeywordAlias KeywordType (requirement_default_clause type_expression)?;
protocol_requirement_function
	: requirement_declarator KeywordFunc attributes? function_type? (requirement_default_clause function_body)?;
protocol_requirement_variable
	: requirement_declarator KeywordVar requirement_getter_and_setter? (requirement_default_clause variable_declaration getter_and_setter_list?)?;
protocol_requirement_constant
	: requirement_declarator KeywordConst requirement_getter? (requirement_default_clause constant_declaration getter_list?)?;
protocol_requirement_initializer
	: empty_requirement_declarator KeywordInit (requirement_default_clause initializer_declaration)?;
protocol_requirement_deinitializer
	: empty_requirement_declarator KeywordDeinit (requirement_default_clause deinitializer_declaration)?;
requirement_declarator
	: KeywordRequire Question? access_level_specifier? storage_level_specifier? member_specifiers? requirement_name require_clause? declare_operator;
empty_requirement_declarator
	: KeywordRequire Question? access_level_specifier? storage_level_specifier? member_specifiers? require_clause? empty_declare_operator;
requirement_name
	: Identifier;
requirement_default_clause
	: KeywordDefault Assign;
requirement_getter_and_setter
	: LeftCurly requirement_getter_and_setter_item (Comma requirement_getter_and_setter_item)+ Comma RightCurly;
requirement_getter
	: LeftCurly KeywordGet RightCurly;
requirement_getter_and_setter_item
	: KeywordGet
	| KeywordSet
	;

initializer_declaration
	: KeywordInit initializer_type code_block;
deinitializer_declaration
	: KeywordDeinit deinitializer_type code_block;

union_declaration: KeywordUnion attributes? final_specifier?;

enum_declaration
	: KeywordEnum udt_parameter_clause? attributes? final_specifier? extension_list? initializer_list? deinitializer_list? member_list? enumerator_list;
enumerator_list
	: LeftCurly enumeration_item (Comma enumeration_item)+ Comma? RightCurly;
enumeration_item
	: enumerator
	| member_variable
	| member_constant
	| member_function
	| member_nested_type
	;
enumerator
	: enumerator_name enumerator_associated_value_clause? enumerator_representation?;
enumerator_associated_value_clause
	: Colon LeftParenthese enumerator_associated_value_list? RightParenthese;
enumerator_associated_value_list
	: enumerator_associated_value (Comma enumerator_associated_value)*;
enumerator_associated_value:
	attributes? enumerator_associated_value_name (Colon type_annotation)? default_argument_clause?;
enumerator_associated_value_name
	: Identifier;
enumerator_representation
	: Assign expression;
enumerator_name
	: Identifier;

import_expression
	: KeywordImport import_kind? attributes? import_path_expression_list;

import_path_expression_list
	: import_path_expression 
	| LeftCurly import_path_expression+ RightCurly
	;
import_path_expression
	: import_path_expression_element (Dot import_path_expression_element)+ (Dot Mul)?;
import_path_expression_element
	: Identifier
	| import_element_list
	;
import_element_list
	: LeftCurly import_path_expression_element (Comma import_path_expression_element)+ Comma? RightCurly;

import_kind
	: KeywordAlias
	| KeywordStruct
	| KeywordClass
	| KeywordUnion
	| KeywordEnum
	| KeywordProtocol
	| KeywordConst
	| KeywordMutable
	| KeywordFunc
	;

project_declaration
	: KeywordProject attributes? aggregate_initialization_expression?;

package_declaration
	: KeywordPackage udt_parameter_clause? attributes? package_member_list?;

package_member_list
	: KeywordMember LeftCurly package_member+ RightCurly;
	
package_member
	: path_expression;

module_declaration
	: (KeywordModule udt_parameter_clause? attributes?) | (KeywordModule udt_parameter_clause? attributes? code_block_no_label);

namespace_declaration
	: KeywordNamespace udt_parameter_clause? attributes? code_block_no_label;

alias_declaration
	: KeywordAlias alias_kind type_expression;

alias_kind
    : KeywordType
    | KeywordFunc
    | KeywordVar
    | KeywordVal
    | KeywordProject
    | KeywordPackage
    | KeywordModule
    ;

access_level_specifier
	: KeywordPrivate | KeywordFilePrivate | KeywordInternal | KeywordPublic | KeywordOpen;

function_declaration
	: KeywordFunc attributes? function_type? function_body;

function_body
	: code_block 
	| expression
	;

contract_list
	: KeywordRequire LeftCurly contract+ RightCurly | KeywordRequire contract;

contract
	: contract_precondition 
	| contract_postcondition
	;

contract_precondition
	: KeywordExpect expression (KeywordWith expression)?;

contract_postcondition
	: KeywordEnsure (KeywordWith return_value_name declare_operator KeywordReturn) expression (KeywordWith expression)?;

return_value_name
	: Identifier;

function_name
	: Identifier;

function_type
	: function_parameter_and_return_type function_specifiers? contract_list?;

function_parameter_and_return_type
	: function_parameter_clause? Arrow function_result_clause?
	;

function_specifier
	: KeywordRecursive
	| KeywordThrows
	| KeywordPure
	;

function_specifiers
	: function_specifier+;

function_result_clause
	: function_return_list;

function_return_list
	: function_return_value (Comma function_return_value)*;

function_return_value
	: attributes? function_return_value_name (Colon type_annotation)? default_return_value_clause?;

function_return_value_name
	: Identifier;

default_return_value_clause
	: Assign expression;

function_parameter_clause
	: function_parameter_list;

function_parameter_list
	: function_parameter (Comma function_parameter)*;

function_parameter
	: attributes? function_parameter_label? function_parameter_name (Colon type_annotation)? default_argument_clause?;

function_parameter_label
	: Identifier;
function_parameter_name
	: Identifier;
default_argument_clause
	: Assign expression;

type_annotation
	: attributes? type_expression;

variable_declaration
	: KeywordVar storage_level_specifier? expression;

constant_declaration
	: KeywordVal storage_level_specifier? expression;

storage_level_specifier
	: KeywordGlobal
	| KeywordStatic
	| KeywordThreadLocal
	;

closure_expression
	: KeywordFunc? capture_list? function_type? code_block;

capture_list
	: LeftSquare capture_list_items RightSquare;
capture_list_items
	: capture_list_item+;
capture_list_item
	: Identifier;

defer_kind
	: KeywordSuccess | KeywordFail;

code_block_no_label
	: LeftCurly statements? RightCurly;

code_block
	: (code_block_name Colon)? LeftCurly statements? RightCurly;

code_block_name
	: Identifier;

attribute
	: At attribute_name;
attributes
	: attribute+;
attribute_name
	: path_expression;

function_call_operator
	: function_call_argument_clause? trailing_closures
	| function_call_argument_clause
	;

function_call_argument_clause
	: LeftParenthese function_call_argument_list? RightParenthese;

function_call_argument_list
	: function_call_argument (Comma function_call_argument)*;

function_call_argument
	: argument_name? (
		Identifier |
		expression
	);

argument_name
	: Identifier Assign;
argument_names
	: argument_name+;

trailing_closures
	: closure_expression labeled_trailing_closures+;

labeled_trailing_closure
	: Identifier Assign closure_expression;

labeled_trailing_closures
	: labeled_trailing_closure+;

operator
	: arithmetic_operator
	| negation_operator
	| assignment_operator
	| comparison_operator
	| unary_bit_operator
	| binary_bit_operator
	| unary_boolean_operator
	| binary_boolean_operator
	| range_operator
	| reflect_operator
	| reify_operator
	| pointer_operator
	| inject_operator
	| unary_optional_unwrapping_operator
	| binary_optional_unwrapping_operator
	| pipeline_operator
	| array_index_operator
	;

add_operator
	: Add 
	| OverflowingAdd 
	| SaturatingAdd 
	;

subtract_operator
	: Sub 
	| OverflowingSub 
	| SaturatingSub
	;

multiply_operator
	: Mul 
	| OverflowingMul 
	| SaturatingMul
	;

divide_operator
	: Divide 
	| RemainderDivide
	;

power_operator
	: Power 
	| OverflowingPower 
	| SaturatingPower
	;

arithmetic_operator
	: add_operator
	| subtract_operator
	| multiply_operator
	| divide_operator
	| power_operator
	;

negation_operator
	: Sub 
	| OverflowingSub
	;

assignment_operator
	: Assign
	| AddAssign 
	| OverflowingAddAssign 
	| SaturatingAddAssign
	| SubAssign 
	| OverflowingSubAssign 
	| SaturatingSubAssign
	| MulAssign 
	| OverflowingMulAssign 
	| SaturatingMulAssign
	| PowerAssign 
	| OverflowingPowerAssign 
	| SaturatingPowerAssign
	| DivideAssign 
	| RemainderDivideAssign
	| BitLeftShiftAssign 
	| SaturatingBitLeftShiftAssign 
	| BitRightShiftAssign
	| BitAndAssign 
	| BitOrAssign 
	| BitNotAssign
	;

comparison_operator
	: GreaterThan 
	| LessThan 
	| GreaterThanOrEqual 
	| LessThanOrEqual 
	| Equal 
	| NotEqual 
	| ThreeWayComparison
	;	

binary_boolean_operator
	: KeywordAnd 
	| KeywordOr
	;

unary_boolean_operator
	: KeywordNot;

binary_bit_operator
	: BitAnd 
	| BitOr 
	| BitLeftShift 
	| SaturatingBitLeftShift 
	| BitRightShift
	| BitXor
	;

unary_bit_operator:
	BitNot;

pointer_operator
	: PointerType 
	| PointerDeref 
	| ObjectAddress
	;

reflect_operator
	: Reflect;
reify_operator
	: Reify;
inject_operator
	: Inject;

range_operator
	: ClosedRange 
	| RightOpenRange 
	| LeftOpenRange 
	| OpenedRange
	;

binary_optional_unwrapping_operator
	: DefaultUnwrapping;
unary_optional_unwrapping_operator
	: Question | Bang;

arrow_operator
	: Arrow;

try_operator
	: KeywordTry (Question | Bang)?;

type_casting_operator
	: KeywordIs 
	| KeywordAs (Question | Bang)?;

await_operator
	: KeywordAwait;

async_operator
	: KeywordAsync;

pipeline_operator
	: PlaceholderPipeline
	| LeftThreadingPipeline
	;

array_index_operator
	: LeftSquare expression (Comma expression)* Comma? RightSquare;

tuple_index_operator
	: Dot LeftSquare expression (Comma expression)* Comma? RightSquare;

builtin_function_operator
	: Builtin;

packifying_operator
	: LeftSquare Colon RightSquare
	;

builtin_function_name
	: BuiltinCompileError
	| BuiltinCompileInfo
	| BuiltinCompileWarning
	| BuiltinPanic
	| BuiltinReturnAddress
	;

capture_operator
	: Capture;

expression
	: LeftParenthese expression RightParenthese											#parentheses_expression_
	| literal_expression																#literal_expression_
	| expression Comma expression														#comma_expression_
	| expression Dot path_expression_element											#field_expression_
	| Dot path_expression_element														#anonymous_field_expression_
	| expression function_call_operator													#member_function_call_expression_
	| expression unary_optional_unwrapping_operator										#unary_optional_unwrapping_expression_
	| expression binary_optional_unwrapping_operator expression							#binary_optional_unwrapping_expression_
	| expression function_call_operator													#function_call_expression_
	| expression arithmetic_operator expression 										#arithmetic_expression_
	| negation_operator expression														#negation_expression_
	| path_expression																	#path_expression_
	| expression array_index_operator													#array_index_expression_
	| expression tuple_index_operator													#tuple_index_expression_
	| expression assignment_operator expression											#assignment_expression_
	| expression comparison_operator expression											#comparison_expression_
	| try_operator expression															#try_expression_
	| expression KeywordCatch (pattern (Comma pattern)* require_clause?)?
	  ((KeywordThen expression) | (code_block))											#catch_expression_
	| async_operator expression															#async_expression_
	| await_operator expression															#await_expression_
	| expression range_operator expression												#double_sided_range_expression_
	| range_operator expression															#right_sided_range_expression_
	| expression range_operator															#left_sided_range_expression_
	| expression binary_bit_operator expression 										#bit_expression_
	| unary_bit_operator expression														#bit_expression_
	| expression binary_boolean_operator expression										#boolean_expression_
	| unary_boolean_operator expression													#boolean_expression_
	| import_expression																	#import_expression_
	| expression type_casting_operator type_expression									#type_cast_expression_
	| closure_expression																#closure_expression_
	| expression Dot KeywordInit														#init_expression_
	| Dot KeywordInit																	#anonymous_init_expression_
	| expression Dot KeywordDeinit														#deinit_expression_
	| Dot KeywordDeinit																	#anonymous_deinit_expression_
	| expression Dot KeywordSelf														#self_expression_
	| KeywordSelf																		#self_expression_
	| code_block_expression																#code_block_expression_
	| type_expression																	#type_expression_
	| KeywordUnreachable																#unreachable_expression_
	| KeywordFallthrough																#fallthrough_expression_
	| KeywordThrow expression															#throw_expression_
	| KeywordReturn expression?															#return_expression_
	| KeywordBreak code_block_name (KeywordWith expression)?        					#break_expression_
	| KeywordBreak expression															#break_expression_
	| KeywordContinue code_block_name?													#continue_expression_
	| KeywordAssert expression (KeywordWith expression)?								#assert_expression_
	| KeywordAssume expression															#assume_expression_
	| KeywordComptime expression														#comptime_expression_
	| expression reflect_operator														#reflect_expression_
	| reify_operator LeftCurly expression RightCurly									#reify_expression_
	| expression inject_operator expression												#inject_expression_
	| inject_operator expression														#inplace_inject_expression_
	| reflect_operator LeftCurly statements RightCurly									#fragment_expression_
	| expression PointerDeref															#dereference_expression_
	| expression ObjectAddress															#object_address_expression_
	| Reify expression?																	#placeholder_expression_
	| expression pipeline_operator expression											#pipeline_expression_
	| expression KeywordWith LeftCurly expression+ RightCurly							#with_expression_
	| KeywordUse declaration_statement_or_list KeywordIn expression						#use_in_expression_
	| KeywordUsing expression															#using_expression_
	| KeywordDefer defer_kind? expression_or_block										#defer_expression_
	| declaration_expression															#declaration_expression_
	| if_expression																		#if_expression_
	| while_expression						 											#while_expression_
	| repeat_while_expression															#repeat_while_expression_
	| for_expression																	#for_expression_
	| expression KeywordMatch (match_case | (LeftCurly match_case+ RightCurly))
	  (KeywordElse expression_or_block)?												#match_expression_
	| builtin_function_operator builtin_function_name function_call_operator			#builtin_function_call_expression_
	| Underscore																		#wildcard_expression_
	| KeywordAsm LeftParenthese string_literal RightParenthese							#assembly_expression_
	| type_expression aggregate_initialization_expression								#aggregate_initialization_expression_
	| capture_operator LeftCurly expression RightCurly									#capture_expression_
	| ClosedRange expression															#pack_expansion_expression_
	| expression packifying_operator													#packifying_expression_
	;

aggregate_initialization_expression
	: Dot KeywordInit aggregate_initialization_list;

aggregate_initialization_list
	: LeftCurly aggregate_initialization_member+ RightCurly;

aggregate_initialization_member
	: Dot aggregate_member Assign expression
	| Dot expression aggregate_initialization_list
	;

aggregate_member
	: expression;

code_block_expression: code_block;

require_clause: KeywordRequire expression;

then_expression_or_block
	: KeywordThen expression
	| code_block
	;
then_expression_or_then_block
	: KeywordThen expression 
	| KeywordThen code_block
	;
expression_or_block
	: expression 
	| code_block
	;
then_type_expression_or_block
	: KeywordThen type_expression 
	| code_block
	;
type_expression_or_block
	: type_expression 
	| code_block
	;
then_type_expression_or_then_block
	: KeywordThen expression 
	| KeywordThen code_block
	;

using_clause
	: KeywordUsing Identifier
	;

in_clause
	: Identifier KeywordIn attributes? expression
	;

if_clause
	: KeywordIf expression
	;

else_clause
	: KeywordElse expression_or_block
	;

final_clause
	: KeywordFinal expression_or_block
	;

else_type_clause
	: KeywordElse type_expression_or_block
	;

final_type_clause
	: KeywordFinal type_expression_or_block
	;

if_expression
	: KeywordIf expression using_clause? (Comma expression using_clause?)* then_expression_or_block  
	else_clause?
	;

while_expression
	: KeywordWhile KeywordEach? expression using_clause? (Comma expression using_clause?)* then_expression_or_block  
	then_expression_or_then_block?
    final_clause?
	;

repeat_while_expression
	: KeywordRepeat KeywordEach? then_expression_or_block  
	KeywordWhile expression using_clause? (Comma expression using_clause?)*
	then_expression_or_then_block?
	final_clause?
	;

for_expression
	: KeywordFor KeywordEach? in_clause using_clause? (Comma in_clause using_clause?)* if_clause? require_clause?
	then_expression_or_block 
	then_expression_or_then_block?
	else_clause?
	final_clause?
	;

if_type_expression
	: KeywordIf expression using_clause? (Comma expression using_clause?)* then_type_expression_or_block  
	else_type_clause?
	;

while_type_expression
	: KeywordWhile KeywordEach? expression using_clause? (Comma expression using_clause?)* then_type_expression_or_block  
	then_type_expression_or_then_block?
    final_type_clause?
	;

repeat_while_type_expression
	: KeywordRepeat KeywordEach? then_expression_or_block  
	KeywordWhile expression using_clause? (Comma expression using_clause?)*
	then_type_expression_or_then_block?
	final_type_clause?
	;

for_type_expression
	: KeywordFor in_clause using_clause? (Comma in_clause using_clause?)* if_clause? require_clause?
	then_type_expression_or_block 
	then_type_expression_or_then_block?
	else_type_clause?
	final_type_clause?
	;

match_case
	: match_case_label Colon (expression | code_block)
	;
match_case_label
	: attributes? match_item_list
	;
match_item_list
	: pattern require_clause? (Comma pattern require_clause?)*
	;

type_expression
	: Identifier																										#identifier_type_expression_
	| RightParenthese type_expression LeftParenthese																	#parentheses_type_expression_
	| path_expression function_call_operator																			#function_call_type_expression_
	| path_expression																									#path_type_expression_
	| type_expression array_index_operator																				#array_index_type_expression_
	| type_expression tuple_index_operator																				#tuple_index_type_expression_
	| basic_type																										#basic_type_type_expression_
	| tuple_type																										#tuple_type_type_expression_
	| optional_type																										#optional_type_type_expression_
	| collection_type																									#collection_type_type_expression_
	| any_type																											#any_type_type_expression_
	| some_type																											#some_type_type_expression_
	| const_type																										#const_type_type_expression_
	| if_type_expression																								#if_type_expression_
	| while_type_expression																								#while_type_expression_
	| repeat_while_type_expression																						#repeat_while_type_expression_
	| for_type_expression																								#for_type_expression_
	| code_block_expression																								#code_block_type_expression_
	| KeywordUnreachable																								#unreachable_type_expression_
	| KeywordFallthrough																								#fallthrough_type_expression_
	| KeywordThrow expression																							#throw_type_expression_
	| KeywordReturn type_expression?																					#return_type_expression_
	| KeywordBreak code_block_name? (KeywordWith type_expression)?														#break_type_expression_
	| KeywordBreak expression																							#break_type_expression_
	| KeywordContinue code_block_name?																					#continue_type_expression_
	| KeywordComptime type_expression																					#comptime_type_expression_
	| builtin_function_operator builtin_function_name function_call_operator											#builtin_function_call_type_expression_
	| Underscore																										#wildcard_type_expression_
	| type_expression PointerType (KeywordAlign LeftParenthese expression RightParenthese)?								#pointer_type_type_expression_
	| reify_operator LeftCurly expression RightCurly																	#reify_type_expression_
	| capture_operator LeftCurly expression RightCurly																	#capture_type_expression_
	;

basic_type
	: never_type
	| integer_type
	| floating_point_type
	| boolean_type
	| byte_type
	| unit_type
	| character_type
	| string_type
	| comptime_type
	| type_type
	| pack_type
	;

pack_type
	: LeftCurly RightCurly
	| LeftCurly pack_type_element (Comma pack_type_element)* Comma RightCurly
	| LeftCurly ClosedRange RightCurly
	;

pack_type_element
	: type_expression
	;

collection_type
	: static_array_type
	| dynamic_array_type
	| map_type
	| set_type
	;

never_type
	: KeywordNever;

tuple_type
    : LeftParenthese tuple_type_element (Comma tuple_type_element)* Comma? RightParenthese
	| LeftParenthese ClosedRange RightParenthese
	;

tuple_type_element
    : attributes? type_expression (Assign expression)?
	| Identifier Colon attributes? type_expression (Assign expression)?;

optional_type
	: Question type_expression;

any_type
	: KeywordAny type_expression;

some_type
	: KeywordSome type_expression;

static_array_type
    : LeftSquare expression (Comma expression)* Comma? RightSquare static_array_element_type;

static_array_element_type
	: type_expression;

dynamic_array_type
    : LeftSquare RightSquare dynamic_array_element_type;

dynamic_array_element_type
	: type_expression;

map_type
	: LeftSquare map_key_type Colon map_value_type RightSquare;

map_key_type
	: type_expression;

map_value_type
	: type_expression;

set_type
	: LeftSquare set_element_type RightSquare;

set_element_type
	: type_expression;

const_type
	: KeywordConst type_expression;

simple_type
	: integer_type 
	| floating_point_type 
	| boolean_type 
	| byte_type 
	| unit_type 
	| character_type 
	| string_type 
	| comptime_type
	;

integer_type
	: KeywordUsize
	| KeywordInt
	| KeywordUInt
	;

floating_point_type
	: KeywordFloat16 
	| KeywordFloat32 
	| KeywordFloat64 
	| KeywordFloat80 
	| KeywordFloat128
	;

boolean_type
	: KeywordBool;

byte_type
	: KeywordByte;

unit_type
	: KeywordUnit;

character_type
	: KeywordChar8 
	| KeywordChar16 
	| KeywordChar32
	;

string_type
	: KeywordString;

comptime_type
	: KeywordCompileTimeChar 
	| KeywordCompileTimeFloat 
	| KeywordCompileTimeInt 
	| KeywordCompileTimeString
	;

type_type
	: KeywordType;

tuple_literal
	: LeftParenthese RightParenthese
	| LeftParenthese tuple_element (Comma tuple_element)* Comma? RightParenthese
	;

tuple_element
	: (Dot Identifier Assign)? expression;

path_expression
	: (KeywordGlobal Dot)? path_expression_element (Dot path_expression_element)*?;
path_expression_element
	: Identifier
	| KeywordSuper
	| KeywordThis
	| KeywordOuter
	| KeywordModule
	| KeywordPackage
	;

literal_expression
	: literal;

literal
	: numeric_literal
	| boolean_literal
	| string_literal
	| char_literal
	| null_literal
	| undefined_literal
	| default_literal
	| array_literal
	| tuple_literal
	| pack_literal
	;

pack_literal
	: LeftCurly RightCurly
	| LeftCurly pack_element (Comma pack_element)* Comma? RightCurly
	;

pack_element
	: expression
	;

numeric_literal
	: integer_literal
	| floating_point_literal
	;

integer_literal
	: DecimalDigits
	| DecimalLiteral
	| BinaryLiteral
	| OctalLiteral
	| HexadecimalLiteral
	;

floating_point_literal
	: FloatingPointLiteral;

boolean_literal
	: KeywordTrue 
	| KeywordFalse
	;

null_literal
	: KeywordNull;

undefined_literal
	: KeywordUndefined;

default_literal
	: KeywordDefault;

array_literal
	: LeftCurly (expression (Comma expression)* Comma?)? RightCurly;

// String Literals
string_literal
	: extended_string_literal
	| interpolated_string_literal
	| static_string_literal;

extended_string_literal
	: MultiLineExtendedStringOpen QuotedMultiLineExtendedText+
		MultiLineExtendedStringClose
	| SingleLineExtendedStringOpen QuotedSingleLineExtendedText+
		SingleLineExtendedStringClose;

static_string_literal
	: SingleLineStringOpen QuotedSingleLineText* SingleLineStringClose
	| MultiLineStringOpen QuotedMultiLineText* MultiLineStringClose;

interpolated_string_literal
	: SingleLineStringOpen (
		QuotedSingleLineText
		| InterpolataionSingleLine (
			expression
			| tuple_element (Comma tuple_element)* Comma?
		) RightCurly
	)* SingleLineStringClose
	| MultiLineStringOpen (
		QuotedMultiLineText
		| InterpolataionMultiLine (
			expression
			| tuple_element (Comma tuple_element)* Comma?
		) RightCurly
	)* MultiLineStringClose;

char_literal
	: CharLiteralOpen ValidChar CharLiteralClose;

pattern
	: wildcard_pattern (Colon type_annotation)?										#wildcard_pattern_
	| identifier_pattern (Colon type_annotation)?									#identifier_pattern_
	| value_binding_pattern (Colon type_annotation)?								#value_binding_pattern_
	| tuple_pattern																	#tuple_pattern_
	| enumerator_pattern															#enumerator_pattern_
	| optional_pattern																#optional_pattern_
	| KeywordIs type_expression 													#is_pattern_
	| pattern KeywordAs type_expression												#as_pattern_
	| expression																	#expression_pattern_
	;

tuple_pattern_element_list
	: tuple_pattern_element (Comma tuple_pattern_element)* Comma?;
tuple_pattern_element
	: pattern | Identifier Colon pattern;

wildcard_pattern
	: Underscore;
identifier_pattern
	: Identifier;
value_binding_pattern
	: KeywordLet KeywordVar pattern | KeywordLet pattern;
tuple_pattern
	: LeftParenthese tuple_pattern_element_list? RightParenthese;
enumerator_pattern
	: type_expression? Dot enumerator_name tuple_pattern?;
optional_pattern
	: Identifier Question;
expression_pattern
	: expression;