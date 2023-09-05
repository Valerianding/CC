//
// Created by Valerian on 2023/8/29.
//

#include "Type.h"
using namespace std::literals;

namespace cc::mid{
//static function:
//1: define in class with "static"
//2: implemented outside the class without "static"
const VoidType* VoidType::Get(){
    static VoidType type;
    return &type;
}


void VoidType::DumpName(std::ostream& out) const{
    out << "void"sv;
}


}
