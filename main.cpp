#include <iostream>
#include <memory>

#include "antlr4-runtime.h"
#include "parser/grootLexer.h"
#include "parser/grootParser.h"
#include "visitorimpl.h"

#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"

using namespace antlr4;
using namespace llvm;
using namespace llvm::orc;

ExitOnError check;

int main(int argc, char *argv[])
{
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    grootLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    grootParser parser(&tokens);

    tree::ParseTree *tree = parser.program();

    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();

    // 1. Create the context and module
    auto context = std::make_unique<LLVMContext>();
    auto module = std::make_unique<Module>("hg2galaxy", *context);

    std::unique_ptr<grootVisitor> v = std::make_unique<visitor_impl>(context.get(), module.get());

    auto result = v->visit(tree); 

    // module->print(errs(), nullptr);

    auto tsmodule = ThreadSafeModule(std::move(module), std::move(context));

    // 6. Create JIT compiler and add the module we prepared
    auto jitc = check(LLJITBuilder().create());
    check(jitc->addIRModule(std::move(tsmodule)));

    // 7. Lookup the prepared  function
    auto mainFunSym = check(jitc->lookup("main"));
    auto mainFunc = (int (*)(int, int))mainFunSym.getAddress();

    // 8. Call the function
    int retVal = mainFunc(1, 2);
    std::cout << "Result " << retVal << std::endl;
    
    return 0;
}
