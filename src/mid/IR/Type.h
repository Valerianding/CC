//
// Created by Valerian on 2023/8/29.
//

#ifndef CC_TYPE_H
#define CC_TYPE_H
#include <memory>
#include <vector>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <optional>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include <string_view>


namespace cc::mid{
class BaseType;
using TypePtr = std::shared_ptr<BaseType>;
using TypePtrList = std::vector<TypePtr>;

enum class TypeRank{
    Void,
    Integer,
    FloatingPoint,
    Pointer,
    Array,
    Function,
    Invalid,
};

class BaseType {
public:
    virtual ~BaseType() = default;
    template<typename T>
    [[nodiscard]] const T* as() const{
        //must transform to types
        static_assert(std::is_base_of_v<BaseType, T>);

        //dynamic_cast to subclass
        const auto ptr = dynamic_cast<const T*>(this);

        //maybe a nullptr
        return ptr;
    }

    //Tips: pure virtual function should be over write by subclass if the subclass need to

    [[nodiscard]] virtual TypeRank rank() const noexcept = 0;

    // return true if is void type
    [[nodiscard]] bool IsVoid() const noexcept{
        return rank() == TypeRank::Void;
    }

    // return ture if is pointer type
    [[nodiscard]] bool IsPointer() const noexcept{
        return rank() == TypeRank::Pointer;
    }

    // return true if is integer
    [[nodiscard]] bool IsInteger() const noexcept{
        return rank() == TypeRank::Integer;
    }

    [[nodiscard]] bool IsFloatingPoint() const noexcept{
       return rank() == TypeRank::FloatingPoint;
   }


    // return true if is function type
    [[nodiscard]]bool IsFunction() const noexcept{
        return rank() == TypeRank::Function;
    }

    // return true if is array type
    [[nodiscard]] virtual bool IsArray() const noexcept{
        return false;
    }

    // return true if current type can be cast to specific type
//    virtual bool CanCastTo(const TypePtr &type) const = 0;

    // return the size of current type
    [[nodiscard]] virtual std::size_t GetSize() const = 0;

    // return the length of current type, return
//    virtual std::size_t GetLength() const = 0;



private:
//    std::size_t ptr_size()
    };


class VoidType final : public BaseType {
public:
    [[nodiscard]] TypeRank rank() const noexcept override{
        return TypeRank::Void;
    }

    static const VoidType* Get();

    void DumpName(std::ostream& out) const;

    [[nodiscard]] std::size_t GetSize() const override{
        return 0;
    }

};


class IntegerType final : public BaseType {
private:
    int bitWidth;
public:
    [[nodiscard]] TypeRank rank() const noexcept override{
        return TypeRank::Integer;
    }

    [[nodiscard]] bool IsBoolean() const noexcept{ return bitWidth == 1; }

    [[nodiscard]] int GetBitWidth() const noexcept{ return bitWidth; }

    [[nodiscard]] std::size_t GetSize() const override{
        return 4;
    }

};

//class FloatingPointType final : public BaseType {
//public:
//    [[nodiscard]] TypeRank rank() const noexcept override{
//        return TypeRank::FloatingPoint;
//    }
//
//};
//
//
//class PointerType final : public BaseType{
//    const BaseType* Pointee;
//public:
//    [[nodiscard]] TypeRank rank() const noexcept override{
//        return TypeRank::Pointer;
//    }
//};
//
//class ArrayType final : public BaseType {
//private:
//    const BaseType *elementType;
//    int elementCount;
//    //bool isLast; -> indicates the last
//public:
//    [[nodiscard]] TypeRank rank() const noexcept override{
//        return TypeRank::Array;
//    }
//
//};
//
//
//
//class FunctionType final : public BaseType {
//private:
//    const BaseType *retType;
//    std::vector<const BaseType *> argsTypes;
//public:
//    [[nodiscard]] TypeRank rank() const noexcept override{
//        return TypeRank::Function;
//    }
//
//};

} //namespace cc
#endif //CC_TYPE_H
