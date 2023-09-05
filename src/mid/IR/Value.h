//
// Created by Valerian on 2023/8/29.
//

#ifndef CC_VALUE_H
#define CC_VALUE_H
#include "Type.h"
#include <list>
#include <any>

namespace cc::mid{
class Use;
class User;
class PassBase;

enum class ValueRank { Constant, Global, Argument, Instruction};

class Value{
public:
//    virtual void RunPass(opt::)
    //
    void AddUse(Use *use){ uses.push_back(use); }
    //
    void RemoveUse(Use *use){ uses.remove(use); }

    void replaceAllUsesWith(Value *v);

    void RemoveFromParent();

private:
    std::any metadata;
    std::list<Use *> uses;
    const BaseType* type;
};

}
#endif //CC_VALUE_H
