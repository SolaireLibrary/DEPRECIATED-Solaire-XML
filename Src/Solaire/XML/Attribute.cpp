//Copyright 2015 Adam Smith
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.

// Contact :
// Email             : solairelibrary@mail.com
// GitHub repository : https://github.com/SolaireLibrary/SolaireCPP

#include "Solaire/XML/Attribute.hpp"

namespace Solaire {

    // Attribute

    Attribute::Attribute() throw() :
        mName(),
        mValue()
    {}

    Attribute::Attribute(Allocator& aAllocator) throw() :
        mName(aAllocator),
        mValue(aAllocator)
    {}

    Attribute::Attribute(const StringConstant<char>& aName) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {}

    Attribute::Attribute(const StringConstant<char>& aName, const StringConstant<char>& aValue) throw() :
        mName(aName),
        mValue(aValue)
    {}

    Attribute::Attribute(const StringConstant<char>& aName, char aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, bool aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        if(aValue) {
            mValue += "true";
        } else {
            mValue += "false";
        }
    }

    Attribute::Attribute(const StringConstant<char>& aName, uint8_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, uint16_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, uint32_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, uint64_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, int8_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, int16_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, int32_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, int64_t aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, float aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    Attribute::Attribute(const StringConstant<char>& aName, double aValue) throw() :
        mName(aName),
        mValue(aName.getAllocator())
    {
        mValue += aValue;
    }

    String<char>& Attribute::getName() throw() {
        return mName;
    }

    const String<char>& Attribute::getName() const throw() {
        return mName;
    }

    void Attribute::setName(const StringConstant<char>& aName) throw() {
        mName = aName;
    }

    String<char>& Attribute::getValue() throw() {
        return mValue;
    }

    const String<char>& Attribute::getValue() const throw() {
        return mValue;
    }

    void Attribute::setValue(const StringConstant<char>& aValue) throw() {
        mValue = aValue;
    }

    Allocator& Attribute::getAllocator() const throw() {
        return mName.getAllocator();
    }

}
