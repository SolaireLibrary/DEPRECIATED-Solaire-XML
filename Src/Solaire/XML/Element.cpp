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

#include "Solaire/XML/Element.hpp"

namespace Solaire {
    // Element

    Element::Element() throw() :
        mName(),
        mBody(),
        mAttributes(),
        mElements()
    {}

    Element::Element(Allocator& aAllocator) throw() :
        mName(aAllocator),
        mBody(aAllocator),
        mAttributes(aAllocator),
        mElements(aAllocator)
    {}

    Element::Element(const StringConstant<char>& aName) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {}

    Element::Element(const StringConstant<char>& aName, const StringConstant<char>& aBody) throw() :
        mName(aName),
        mBody(aBody),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {}

    Element::Element(const StringConstant<char>& aName, char aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, bool aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        if(aBody) {
            mBody += "true";
        } else {
            mBody += "false";
        }
    }

    Element::Element(const StringConstant<char>& aName, uint8_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, uint16_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, uint32_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, uint64_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, int8_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, int16_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, int32_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, int64_t aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, float aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    Element::Element(const StringConstant<char>& aName, double aBody) throw() :
        mName(aName),
        mBody(aName.getAllocator()),
        mAttributes(aName.getAllocator()),
        mElements(aName.getAllocator())
    {
        mBody += aBody;
    }

    String<char>& Element::getName() throw() {
        return mName;
    }

    const String<char>& Element::getName() const throw() {
        return mName;
    }

    void Element::setName(const StringConstant<char>& aName) throw() {
        mName = aName;
    }

    String<char>& Element::getBody() throw() {
        return mBody;
    }

    const String<char>& Element::getBody() const throw() {
        return mBody;
    }

    void Element::setBody(const StringConstant<char>& aBody) throw() {
        mBody = aBody;
    }

    bool Element::hasBody() const throw() {
        return mBody.size() != 0;
    }

    List<Attribute>& Element::getAttributes() throw() {
        return mAttributes;
    }

    const List<const Attribute>& Element::getAttributes() const throw() {
        return mAttributes;
    }

    List<Element>& Element::getElements() throw() {
        return mElements;
    }

    const List<const Element>& Element::getElements() const throw() {
        return mElements;
    }

    Allocator& Element::getAllocator() const throw() {
        return mAttributes.getAllocator();
    }

}
