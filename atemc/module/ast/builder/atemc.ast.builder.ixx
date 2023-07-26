export module atemc.ast.builder;

import <memory>;
import <any>;
import <map>;
import <tuple>;

import <antlr4-runtime.h>;

import atemc.ast.types;
import atemc.basic;
import atemc.exception;
import atemc.grammar.basevisitor;
import atemc.grammar.parser;
import atemc.semantic.types;

export namespace atemc
{
	using namespace antlrcpp;

	class ASTBuilder : public AtemParserBaseVisitor
	{
		AtemParser* parser_ = nullptr;

	public:
		explicit ASTBuilder(AtemParser* parser) : parser_(parser) {}

		auto buildRootSourceFileProjectDeclaration(AtemParser::ProgramContext* ctx, std::shared_ptr<RawSourceFile> root_source_file_ptr)
			-> std::shared_ptr<ProjectDeclarationExprAST>
		{
			for(const auto& stmt : ctx->statements()->statement())
			{
				if(auto project_ctx = stmt->declaration_statement()->declaration_expression()->project_declaration())
				{
					auto project_ast_ptr = std::any_cast<std::shared_ptr<ProjectDeclarationExprAST>>
						(this->visitProject_declaration(project_ctx));
					return project_ast_ptr;
				}
			}
			throw ParseException("The root source file MUST ONLY contain one project declaration");
		}
		auto visitProgram(AtemParser::ProgramContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitStatement(AtemParser::StatementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitStatements(AtemParser::StatementsContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclaration_statement_or_list(AtemParser::Declaration_statement_or_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclaration_statement_list(AtemParser::Declaration_statement_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclaration_statement(AtemParser::Declaration_statementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclarator(AtemParser::DeclaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclare_operator(AtemParser::Declare_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEmpty_declare_operator(AtemParser::Empty_declare_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclarator_name(AtemParser::Declarator_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclaration_expression(AtemParser::Declaration_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTest_declaration(AtemParser::Test_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTest_name(AtemParser::Test_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitStruct_declaration(AtemParser::Struct_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitClass_declaration(AtemParser::Class_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExtension_declaration(AtemParser::Extension_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUdt_parameter_clause(AtemParser::Udt_parameter_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFinal_specifier(AtemParser::Final_specifierContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_specifier(AtemParser::Member_specifierContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_specifiers(AtemParser::Member_specifiersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExtension_list(AtemParser::Extension_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExtension_item(AtemParser::Extension_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_clause(AtemParser::Inherit_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_list(AtemParser::Inherit_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_item(AtemParser::Inherit_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_items(AtemParser::Inherit_itemsContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_member_list(AtemParser::Inherit_member_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_member(AtemParser::Inherit_memberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_members(AtemParser::Inherit_membersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_type_override(AtemParser::Inherit_type_overrideContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_variable_override(AtemParser::Inherit_variable_overrideContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_constant_override(AtemParser::Inherit_constant_overrideContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_function_override(AtemParser::Inherit_function_overrideContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_initializer_override(AtemParser::Inherit_initializer_overrideContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_deinitializer_override(AtemParser::Inherit_deinitializer_overrideContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_declarator(AtemParser::Inherit_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEmpty_inherit_declarator(AtemParser::Empty_inherit_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInherit_name(AtemParser::Inherit_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_clause(AtemParser::Impl_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_list(AtemParser::Impl_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_item(AtemParser::Impl_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_items(AtemParser::Impl_itemsContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_with_clause(AtemParser::Impl_with_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_member_list(AtemParser::Impl_member_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_member(AtemParser::Impl_memberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImpl_members(AtemParser::Impl_membersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDefault_clause(AtemParser::Default_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_type_impl(AtemParser::Associated_type_implContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_variable_impl(AtemParser::Associated_variable_implContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_constant_impl(AtemParser::Associated_constant_implContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_function_impl(AtemParser::Associated_function_implContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_initializer_impl(AtemParser::Associated_initializer_implContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_deinitializer_impl(AtemParser::Associated_deinitializer_implContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_declarator(AtemParser::Associated_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEmpty_associated_declarator(AtemParser::Empty_associated_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssociated_name(AtemParser::Associated_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInitializer_list(AtemParser::Initializer_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInitializer_member_list(AtemParser::Initializer_member_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInitializer_member(AtemParser::Initializer_memberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInitializer_type(AtemParser::Initializer_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInitializer_members(AtemParser::Initializer_membersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinitializer_list(AtemParser::Deinitializer_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinitializer_member_list(AtemParser::Deinitializer_member_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinitializer_member(AtemParser::Deinitializer_memberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinitializer_type(AtemParser::Deinitializer_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinitializer_members(AtemParser::Deinitializer_membersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_list(AtemParser::Member_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember(AtemParser::MemberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMembers(AtemParser::MembersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_nested_type(AtemParser::Member_nested_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNested_class(AtemParser::Nested_classContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNested_struct(AtemParser::Nested_structContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNested_protocol(AtemParser::Nested_protocolContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNested_union(AtemParser::Nested_unionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNested_enum(AtemParser::Nested_enumContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_type(AtemParser::Member_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_variable(AtemParser::Member_variableContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_constant(AtemParser::Member_constantContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_function(AtemParser::Member_functionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_declarator(AtemParser::Member_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_name(AtemParser::Member_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitGetter_and_setter_list(AtemParser::Getter_and_setter_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitGetter_list(AtemParser::Getter_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitGetter_and_setter_item(AtemParser::Getter_and_setter_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitGetter_and_setter_items(AtemParser::Getter_and_setter_itemsContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitGetter_declaration(AtemParser::Getter_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitGetter_type(AtemParser::Getter_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSetter_declaration(AtemParser::Setter_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSetter_type(AtemParser::Setter_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSetter_parameter_clause(AtemParser::Setter_parameter_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSetter_parameter(AtemParser::Setter_parameterContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSetter_parameter_name(AtemParser::Setter_parameter_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_declaration(AtemParser::Protocol_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_extend_list(AtemParser::Protocol_extend_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_list(AtemParser::Protocol_requirement_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_item(AtemParser::Protocol_requirement_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_items(AtemParser::Protocol_requirement_itemsContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_type(AtemParser::Protocol_requirement_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_function(AtemParser::Protocol_requirement_functionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_variable(AtemParser::Protocol_requirement_variableContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_constant(AtemParser::Protocol_requirement_constantContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_initializer(AtemParser::Protocol_requirement_initializerContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProtocol_requirement_deinitializer(AtemParser::Protocol_requirement_deinitializerContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequirement_declarator(AtemParser::Requirement_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEmpty_requirement_declarator(AtemParser::Empty_requirement_declaratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequirement_name(AtemParser::Requirement_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequirement_default_clause(AtemParser::Requirement_default_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequirement_getter_and_setter(AtemParser::Requirement_getter_and_setterContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequirement_getter(AtemParser::Requirement_getterContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequirement_getter_and_setter_item(AtemParser::Requirement_getter_and_setter_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInitializer_declaration(AtemParser::Initializer_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinitializer_declaration(AtemParser::Deinitializer_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnion_declaration(AtemParser::Union_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnum_declaration(AtemParser::Enum_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_list(AtemParser::Enumerator_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumeration_item(AtemParser::Enumeration_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator(AtemParser::EnumeratorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_associated_value_clause(AtemParser::Enumerator_associated_value_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_associated_value_list(AtemParser::Enumerator_associated_value_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_associated_value(AtemParser::Enumerator_associated_valueContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_associated_value_name(AtemParser::Enumerator_associated_value_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_representation(AtemParser::Enumerator_representationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_name(AtemParser::Enumerator_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_expression(AtemParser::Import_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_path_expression_list(AtemParser::Import_path_expression_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_path_expression(AtemParser::Import_path_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_path_expression_element(AtemParser::Import_path_expression_elementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_element_list(AtemParser::Import_element_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_kind(AtemParser::Import_kindContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitProject_declaration(AtemParser::Project_declarationContext* ctx)
			-> std::any override
		{
			auto aggr_init_ctx = ctx->aggregate_initialization_expression();
			auto aggr_init_ast_ptr = std::any_cast<std::shared_ptr<AggregateInitializationExprAST>>
				(this->visitAggregate_initialization_expression(aggr_init_ctx));
			return std::make_shared<ProjectDeclarationExprAST>(aggr_init_ast_ptr);
		}
		auto visitPackage_declaration(AtemParser::Package_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPackage_member_list(AtemParser::Package_member_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPackage_member(AtemParser::Package_memberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitModule_declaration(AtemParser::Module_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNamespace_declaration(AtemParser::Namespace_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAlias_declaration(AtemParser::Alias_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAlias_kind(AtemParser::Alias_kindContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAccess_level_specifier(AtemParser::Access_level_specifierContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_declaration(AtemParser::Function_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_body(AtemParser::Function_bodyContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitContract_list(AtemParser::Contract_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitContract(AtemParser::ContractContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitContract_precondition(AtemParser::Contract_preconditionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitContract_postcondition(AtemParser::Contract_postconditionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReturn_value_name(AtemParser::Return_value_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_name(AtemParser::Function_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_type(AtemParser::Function_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_specifier(AtemParser::Function_specifierContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_specifiers(AtemParser::Function_specifiersContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_result(AtemParser::Function_resultContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_parameter_clause(AtemParser::Function_parameter_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_parameter_list(AtemParser::Function_parameter_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_parameter(AtemParser::Function_parameterContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_parameter_label(AtemParser::Function_parameter_labelContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_parameter_name(AtemParser::Function_parameter_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDefault_argument_clause(AtemParser::Default_argument_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitType_annotation(AtemParser::Type_annotationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitVariable_declaration(AtemParser::Variable_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitConstant_declaration(AtemParser::Constant_declarationContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitStorage_level_specifier(AtemParser::Storage_level_specifierContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitClosure_expression(AtemParser::Closure_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCapture_list(AtemParser::Capture_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCapture_list_items(AtemParser::Capture_list_itemsContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCapture_list_item(AtemParser::Capture_list_itemContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDefer_kind(AtemParser::Defer_kindContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCode_block_no_label(AtemParser::Code_block_no_labelContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCode_block(AtemParser::Code_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCode_block_name(AtemParser::Code_block_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAttribute(AtemParser::AttributeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAttributes(AtemParser::AttributesContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAttribute_name(AtemParser::Attribute_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_call_operator(AtemParser::Function_call_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_call_argument_clause(AtemParser::Function_call_argument_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_call_argument_list(AtemParser::Function_call_argument_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_call_argument(AtemParser::Function_call_argumentContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArgument_name(AtemParser::Argument_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArgument_names(AtemParser::Argument_namesContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTrailing_closures(AtemParser::Trailing_closuresContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitLabeled_trailing_closure(AtemParser::Labeled_trailing_closureContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitLabeled_trailing_closures(AtemParser::Labeled_trailing_closuresContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitOperator(AtemParser::OperatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAdd_operator(AtemParser::Add_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSubtract_operator(AtemParser::Subtract_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMultiply_operator(AtemParser::Multiply_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDivide_operator(AtemParser::Divide_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPower_operator(AtemParser::Power_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArithmetic_operator(AtemParser::Arithmetic_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNegation_operator(AtemParser::Negation_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssignment_operator(AtemParser::Assignment_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitComparison_operator(AtemParser::Comparison_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBinary_boolean_operator(AtemParser::Binary_boolean_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnary_boolean_operator(AtemParser::Unary_boolean_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBinary_bit_operator(AtemParser::Binary_bit_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnary_bit_operator(AtemParser::Unary_bit_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPointer_operator(AtemParser::Pointer_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReflect_operator(AtemParser::Reflect_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReify_operator(AtemParser::Reify_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInject_operator(AtemParser::Inject_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRange_operator(AtemParser::Range_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBinary_optional_unwrapping_operator(AtemParser::Binary_optional_unwrapping_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnary_optional_unwrapping_operator(AtemParser::Unary_optional_unwrapping_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArrow_operator(AtemParser::Arrow_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTry_operator(AtemParser::Try_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitType_casting_operator(AtemParser::Type_casting_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAwait_operator(AtemParser::Await_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAsync_operator(AtemParser::Async_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPipeline_operator(AtemParser::Pipeline_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArray_index_operator(AtemParser::Array_index_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_index_operator(AtemParser::Tuple_index_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBuiltin_function_operator(AtemParser::Builtin_function_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBuiltin_function_name(AtemParser::Builtin_function_nameContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCapture_operator(AtemParser::Capture_operatorContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUsing_expression_(AtemParser::Using_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFor_expression_(AtemParser::For_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitContinue_expression_(AtemParser::Continue_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWildcard_expression_(AtemParser::Wildcard_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAggregate_initialization_expression_(AtemParser::Aggregate_initialization_expression_Context* ctx)
			-> std::any override
		{
			auto type = std::any_cast<TypeExprAST>(this->visit(ctx->type_expression()));
			return std::make_shared<AggregateInitializationExprAST>(
					type,
					std::any_cast<std::map<ExprAST, ExprAST>>(
						this->visitAggregate_initialization_list(ctx->aggregate_initialization_expression()->aggregate_initialization_list())
					)
				);
		}
		auto visitCatch_expression_(AtemParser::Catch_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitThrow_expression_(AtemParser::Throw_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssembly_expression_(AtemParser::Assembly_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBinary_optional_unwrapping_expression_(AtemParser::Binary_optional_unwrapping_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitImport_expression_(AtemParser::Import_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitComma_expression_(AtemParser::Comma_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitLiteral_expression_(AtemParser::Literal_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSelf_expression_(AtemParser::Self_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitComptime_expression_(AtemParser::Comptime_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitLeft_sided_range_expression_(AtemParser::Left_sided_range_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnary_optional_unwrapping_expression_(AtemParser::Unary_optional_unwrapping_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnreachable_expression_(AtemParser::Unreachable_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_index_expression_(AtemParser::Tuple_index_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArray_index_expression_(AtemParser::Array_index_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWith_expression_(AtemParser::With_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitType_expression_(AtemParser::Type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIf_expression_(AtemParser::If_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMatch_expression_(AtemParser::Match_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAnonymous_deinit_expression_(AtemParser::Anonymous_deinit_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitObject_address_expression_(AtemParser::Object_address_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBit_expression_(AtemParser::Bit_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNegation_expression_(AtemParser::Negation_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReify_expression_(AtemParser::Reify_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDereference_expression_(AtemParser::Dereference_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPlaceholder_expression_(AtemParser::Placeholder_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssignment_expression_(AtemParser::Assignment_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitField_expression_(AtemParser::Field_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRepeat_while_expression_(AtemParser::Repeat_while_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitComparison_expression_(AtemParser::Comparison_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBreak_expression_(AtemParser::Break_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPath_expression_(AtemParser::Path_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBuiltin_function_call_expression_(AtemParser::Builtin_function_call_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInplace_inject_expression_(AtemParser::Inplace_inject_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTry_expression_(AtemParser::Try_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBoolean_expression_(AtemParser::Boolean_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArithmetic_expression_(AtemParser::Arithmetic_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFallthrough_expression_(AtemParser::Fallthrough_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMember_function_call_expression_(AtemParser::Member_function_call_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInject_expression_(AtemParser::Inject_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRight_sided_range_expression_(AtemParser::Right_sided_range_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInit_expression_(AtemParser::Init_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeinit_expression_(AtemParser::Deinit_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssume_expression_(AtemParser::Assume_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAwait_expression_(AtemParser::Await_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPipeline_expression_(AtemParser::Pipeline_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_call_expression_(AtemParser::Function_call_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDouble_sided_range_expression_(AtemParser::Double_sided_range_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWhile_expression_(AtemParser::While_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDeclaration_expression_(AtemParser::Declaration_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitParentheses_expression_(AtemParser::Parentheses_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDefer_expression_(AtemParser::Defer_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFragment_expression_(AtemParser::Fragment_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAsync_expression_(AtemParser::Async_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitType_cast_expression_(AtemParser::Type_cast_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAnonymous_field_expression_(AtemParser::Anonymous_field_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAnonymous_init_expression_(AtemParser::Anonymous_init_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReturn_expression_(AtemParser::Return_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReflect_expression_(AtemParser::Reflect_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCapture_expression_(AtemParser::Capture_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAssert_expression_(AtemParser::Assert_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitClosure_expression_(AtemParser::Closure_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUse_in_expression_(AtemParser::Use_in_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCode_block_expression_(AtemParser::Code_block_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAggregate_initialization_list(AtemParser::Aggregate_initialization_listContext* ctx)
			-> std::any override
		{
			std::map<ExprAST, ExprAST> aggregate_members;
			for(auto aggregate_member : ctx->aggregate_initialization_member())
			{
				auto [k, v] = std::any_cast<std::tuple<ExprAST, ExprAST>>(this->visitAggregate_initialization_member(aggregate_member));
				aggregate_members.at(k) = v;
			}
			return aggregate_members;
		}
		auto visitAggregate_initialization_member(AtemParser::Aggregate_initialization_memberContext* ctx)
			-> std::any override
		{
			if(auto init = ctx->aggregate_initialization_list())
			{
				this->visitAggregate_initialization_list(init);
			}
			auto expr = std::any_cast<ExprAST>(this->visit(ctx->expression()));
			auto member = std::any_cast<ExprAST>(this->visit(ctx->aggregate_member()->expression()));
			return std::make_tuple(member, expr);
		}
		auto visitAggregate_member(AtemParser::Aggregate_memberContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCode_block_expression(AtemParser::Code_block_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRequire_clause(AtemParser::Require_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitThen_expression_or_block(AtemParser::Then_expression_or_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitThen_expression_or_then_block(AtemParser::Then_expression_or_then_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExpression_or_block(AtemParser::Expression_or_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitThen_type_expression_or_block(AtemParser::Then_type_expression_or_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitType_expression_or_block(AtemParser::Type_expression_or_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitThen_type_expression_or_then_block(AtemParser::Then_type_expression_or_then_blockContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUsing_clause(AtemParser::Using_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIn_clause(AtemParser::In_clauseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIf_expression(AtemParser::If_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWhile_expression(AtemParser::While_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRepeat_while_expression(AtemParser::Repeat_while_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFor_expression(AtemParser::For_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIf_type_expression(AtemParser::If_type_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWhile_type_expression(AtemParser::While_type_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRepeat_while_type_expression(AtemParser::Repeat_while_type_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFor_type_expression(AtemParser::For_type_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMatch_case(AtemParser::Match_caseContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMatch_case_label(AtemParser::Match_case_labelContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMatch_item_list(AtemParser::Match_item_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWhile_type_expression_(AtemParser::While_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitRepeat_while_type_expression_(AtemParser::Repeat_while_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitThrow_type_expression_(AtemParser::Throw_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReify_type_expression_(AtemParser::Reify_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitOptional_type_type_expression_(AtemParser::Optional_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWildcard_type_expression_(AtemParser::Wildcard_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitReturn_type_expression_(AtemParser::Return_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIf_type_expression_(AtemParser::If_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBuiltin_function_call_type_expression_(AtemParser::Builtin_function_call_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_type_type_expression_(AtemParser::Tuple_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnreachable_type_expression_(AtemParser::Unreachable_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCapture_type_expression_(AtemParser::Capture_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSome_type_type_expression_(AtemParser::Some_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFunction_call_type_expression_(AtemParser::Function_call_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBreak_type_expression_(AtemParser::Break_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCode_block_type_expression_(AtemParser::Code_block_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArray_index_type_expression_(AtemParser::Array_index_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPointer_type_type_expression_(AtemParser::Pointer_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCollection_type_type_expression_(AtemParser::Collection_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAny_type_type_expression_(AtemParser::Any_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitContinue_type_expression_(AtemParser::Continue_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFallthrough_type_expression_(AtemParser::Fallthrough_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_index_type_expression_(AtemParser::Tuple_index_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPath_type_expression_(AtemParser::Path_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBasic_type_type_expression_(AtemParser::Basic_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitConst_type_type_expression_(AtemParser::Const_type_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitComptime_type_expression_(AtemParser::Comptime_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitParentheses_type_expression_(AtemParser::Parentheses_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFor_type_expression_(AtemParser::For_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIdentifier_type_expression_(AtemParser::Identifier_type_expression_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBasic_type(AtemParser::Basic_typeContext *ctx) -> std::any override
		{
			if(auto ctx_ptr = ctx->boolean_type())
			{
				return std::make_shared<TypeExprAST>(
					std::dynamic_pointer_cast<AbstractType>(
						std::make_shared<BooleanType>()
					)
				);
			}
			if(auto ctx_ptr = ctx->integer_type())
			{
				auto width = [&]()
					{
						if(auto ptr = ctx_ptr->KeywordInt())
						{
							std::string str = ptr->getText();
							str.erase(str.begin());
							str.erase(str.begin());
							str.erase(str.begin());
							return std::stoull(str);
						}
						if(auto ptr = ctx_ptr->KeywordUInt())
						{
							std::string str = ptr->getText();
							str.erase(str.begin());
							str.erase(str.begin());
							str.erase(str.begin());
							str.erase(str.begin());
							return std::stoull(str);
						}
						if(auto ptr = ctx_ptr->KeywordUsize())
						{
							return sizeof(size_t);
						}
						return sizeof(size_t);
					}();
				if(auto ptr = ctx_ptr->KeywordInt())
				{
					return std::make_shared<TypeExprAST>(
						std::dynamic_pointer_cast<AbstractType>(
							std::make_shared<SignedIntegerType>(
								width
							)
						)
					);
				}
				if(auto ptr = ctx_ptr->KeywordUInt())
				{
					return std::make_shared<TypeExprAST>(
						std::dynamic_pointer_cast<AbstractType>(
							std::make_shared<UnsignedIntegerType>(
								width
							)
						)
					);
				}
				if(auto ptr = ctx_ptr->KeywordUsize())
				{
					return std::make_shared<TypeExprAST>(
						std::dynamic_pointer_cast<AbstractType>(
							std::make_shared<SizeIntegerType>()
						)
					);
				}
			}
			return this->visitChildren(ctx);
		}
		auto visitCollection_type(AtemParser::Collection_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNever_type(AtemParser::Never_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_type(AtemParser::Tuple_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_type_element(AtemParser::Tuple_type_elementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitOptional_type(AtemParser::Optional_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAny_type(AtemParser::Any_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSome_type(AtemParser::Some_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitStatic_array_type(AtemParser::Static_array_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDynamic_array_type(AtemParser::Dynamic_array_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitMap_type(AtemParser::Map_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSet_type(AtemParser::Set_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitConst_type(AtemParser::Const_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitSimple_type(AtemParser::Simple_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInteger_type(AtemParser::Integer_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFloating_point_type(AtemParser::Floating_point_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBoolean_type(AtemParser::Boolean_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitByte_type(AtemParser::Byte_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUnit_type(AtemParser::Unit_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitCharacter_type(AtemParser::Character_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitString_type(AtemParser::String_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitComptime_type(AtemParser::Comptime_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitType_type(AtemParser::Type_typeContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_literal(AtemParser::Tuple_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_element(AtemParser::Tuple_elementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPath_expression(AtemParser::Path_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitPath_expression_element(AtemParser::Path_expression_elementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitLiteral_expression(AtemParser::Literal_expressionContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitLiteral(AtemParser::LiteralContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNumeric_literal(AtemParser::Numeric_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInteger_literal(AtemParser::Integer_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitFloating_point_literal(AtemParser::Floating_point_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitBoolean_literal(AtemParser::Boolean_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitNull_literal(AtemParser::Null_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitUndefined_literal(AtemParser::Undefined_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitDefault_literal(AtemParser::Default_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitArray_literal(AtemParser::Array_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitString_literal(AtemParser::String_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExtended_string_literal(AtemParser::Extended_string_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitStatic_string_literal(AtemParser::Static_string_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitInterpolated_string_literal(AtemParser::Interpolated_string_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitChar_literal(AtemParser::Char_literalContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitOptional_pattern_(AtemParser::Optional_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIs_pattern_(AtemParser::Is_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitAs_pattern_(AtemParser::As_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitValue_binding_pattern_(AtemParser::Value_binding_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIdentifier_pattern_(AtemParser::Identifier_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExpression_pattern_(AtemParser::Expression_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_pattern_(AtemParser::Enumerator_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWildcard_pattern_(AtemParser::Wildcard_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_pattern_(AtemParser::Tuple_pattern_Context *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_pattern_element_list(AtemParser::Tuple_pattern_element_listContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_pattern_element(AtemParser::Tuple_pattern_elementContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitWildcard_pattern(AtemParser::Wildcard_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitIdentifier_pattern(AtemParser::Identifier_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitValue_binding_pattern(AtemParser::Value_binding_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitTuple_pattern(AtemParser::Tuple_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitEnumerator_pattern(AtemParser::Enumerator_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitOptional_pattern(AtemParser::Optional_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
		auto visitExpression_pattern(AtemParser::Expression_patternContext *ctx) -> std::any override { return this->visitChildren(ctx); }
	};
}
