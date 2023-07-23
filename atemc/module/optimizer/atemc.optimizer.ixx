module;

#include <llvm/Pass.h>

#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>

#include <llvm/Transforms/Utils.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>

export module atemc.optimizer;

import <memory>;

import atemc.basic;

export namespace atemc
{
	class Optimizer : public AtemcObject
	{
	public:
		static auto optimize(llvm::Module* optimize_module) -> void
		{
			using namespace llvm;

			auto fpm = std::make_unique<legacy::FunctionPassManager>(optimize_module);

			fpm->add(createPromoteMemoryToRegisterPass());
			fpm->add(createInstructionCombiningPass());
			fpm->add(createReassociatePass());
			fpm->add(createGVNPass());
			fpm->add(createCFGSimplificationPass());

			fpm->doInitialization();

			for(auto& func : optimize_module->getFunctionList()) 
			{
				fpm->run(func);
			}
		}
	};
}
