//
// Created by Valerian on 2023/8/29.
//

#ifndef CC_PASS_H
#define CC_PASS_H

#include <iostream>
namespace cc::opt{

class Pass{
public:
    virtual ~Pass() = default;

    virtual bool IsModulePass() const = 0;

    virtual bool RunOnModule() = 0;

    virtual bool IsFunctionPass() const = 0;

    virtual bool RunOnFunction() = 0;

    virtual bool IsBlockPass() const = 0;

    virtual bool RunOnBlock() = 0;

    virtual void Initialize() {}

    virtual void CleanUp() {}

    //visitor methods for running on IR


};

using PassPtr = std::unique_ptr<Pass>;


// helper pass
class HelperPass : public Pass{
public:
    bool IsModulePass() const override final{ return false; }

    bool IsFunctionPass() const override final { return false; }

    bool IsBlockPass() const override final { return false; }

};


}// namespace ends
#endif //CC_PASS_H