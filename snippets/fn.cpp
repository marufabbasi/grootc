// FROM: https://releases.llvm.org/2.2/docs/tutorial/JITTutorial1.html

#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/CallingConv.h>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/BasicBlock.h"


int main(int argc, char **argv)
{
    auto context = std::make_unique<llvm::LLVMContext>();
    auto module = std::make_unique<llvm::Module>("test.gt", *context);

    auto ptype = llvm::IntegerType::get(*context, 32);

    std::vector<llvm::Type *> parameter_types;

    parameter_types.push_back(llvm::IntegerType::get(*context, 32));
    parameter_types.push_back(llvm::IntegerType::get(*context, 32));
    parameter_types.push_back(llvm::IntegerType::get(*context, 32));

    auto ft = llvm::FunctionType::get(ptype, parameter_types, false);
    llvm::FunctionCallee c = module->getOrInsertFunction("mul_add", ft);

    llvm::Function *mul_add = llvm::cast<llvm::Function>(c.getCallee());
    mul_add->setCallingConv(llvm::CallingConv::C);

    llvm::Function::arg_iterator args = mul_add->arg_begin();
    llvm::Value *x = args++;
    x->setName("x");
    llvm::Value *y = args++;
    y->setName("y");
    llvm::Value *z = args++;
    z->setName("z");

    llvm::BasicBlock *block = llvm::BasicBlock::Create(*context, "entry", mul_add);
    llvm::IRBuilder<> builder(block);

    llvm::Value *tmp = builder.CreateBinOp(llvm::Instruction::Mul,
                                     x, y, "tmp");
    llvm::Value *tmp2 = builder.CreateBinOp(llvm::Instruction::Add,
                                      tmp, z, "tmp2");

    builder.CreateRet(tmp2);

    module->print(llvm::errs(), nullptr);

    return 0;
}
