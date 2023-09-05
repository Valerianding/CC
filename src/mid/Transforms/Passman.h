//
// Created by Valerian on 2023/8/29.
//

#ifndef CC_PASSMAN_H
#define CC_PASSMAN_H

#include <vector>
#include <map>
#include <string_view>
#include <unordered_set>

#include "mid/Transforms/Pass.h"
#include "mid/IR/Type.h"

namespace cc::opt{

// stage of pass running
// represented as bit flags
enum class PassStage : unsigned {
    None    = 0,
    PreOpt  = 1 << 0,
    Promote = 1 << 1,
    Opt     = 1 << 2,
    Demote  = 1 << 3,
    PostOpt = 1 << 4,
};


class PassInfo{
private:
    PassPtr pass;
    std::string_view name;
    bool isAnalysis;
    std::size_t minOptLevel;
    PassStage stage;

public:
    using PassNameList = std::vector<std::string_view>;

    // Tips for functional programming benefits we return the PassInfo
    // add required pass by name for current pass
    PassInfo &Requires(std::string_view passName);


    // add invalidated pass by name for current pass
    // all invalidated pass should be run again after running current pass
    PassInfo &Invalidates(std::string_view passName);



};


class PassManager{
public:
    template <typename T>
    static PassInfo &RegisterPass(std::string_view name){
        static_assert(!std::is_base_of_v<HelperPass, T>,"helper pass can't be registered");
    }
};

}
#endif //CC_PASSMAN_H
