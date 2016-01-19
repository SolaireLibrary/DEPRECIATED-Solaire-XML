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

#include "Solaire/XML/Format.hpp"

namespace Solaire {

    /*static bool skipWhitespace(IStream& aStream) {
        if(aStream.end()) return true;
        char c;
        aStream >> c;
        while(std::isspace(c)) {
            if(aStream.end()) return true;
            aStream >> c;
        }
        aStream.setOffset(aStream.getOffset() - 1);
        return true;
    }*/
    static bool writeObject(const StringConstant<char>& aName, const GenericObject& aValue, OStream& aStream) throw();

    static bool writeArray(const StringConstant<char>& aName, const GenericArray& aValue, OStream& aStream) throw() {
        aStream << '<';
        aStream << aName;
        if(aValue.size() > 0) {
            aStream << '>';
            const auto end = aValue.end();
            for(auto i = aValue.begin(); i != end; ++i) {
                switch(i->getType()) {
                    case GenericValue::NULL_T:
                        aStream << "<solaire_array_element type=\"null\"/>";
                        break;
                    case GenericValue::CHAR_T:
                        aStream << "<solaire_array_element type=\"char\" value=\"";
                        aStream << i->getChar();
                        aStream << "\"/>";
                        break;
                    case GenericValue::BOOL_T:
                        aStream << "<solaire_array_element type=\"bool\" value=\"";
                        if(i->getBool()) {
                            aStream << "true";
                        }else {
                            aStream << "false";
                        }
                        aStream << "\"/>";
                        break;
                    case GenericValue::UNSIGNED_T:
                        aStream << "<solaire_array_element type=\"number\" value=\"";
                        aStream << i->getUnsigned();
                        aStream << "\"/>";
                        break;
                    case GenericValue::SIGNED_T:
                        aStream << "<solaire_array_element type=\"number\" value=\"";
                        aStream << i->getSigned();
                        aStream << "\"/>";
                        break;
                    case GenericValue::DOUBLE_T:
                        aStream << "<solaire_array_element type=\"number\" value=\"";
                        aStream << i->getDouble();
                        aStream << "\"/>";
                        break;
                    case GenericValue::STRING_T:
                        aStream << "<solaire_array_element type=\"string\" value=\"";
                        aStream << i->getString();
                        aStream << "\"/>";
                        break;
                    case GenericValue::ARRAY_T:
                        writeArray(CString("solaire_array_element"), i->getArray(), aStream);
                        break;
                    case GenericValue::OBJECT_T:
                        writeObject(CString("solaire_array_element"), i->getObject(), aStream);
                        break;
                    default:
                        break;
                }
            }

            aStream << '<';
            aStream << '/';
            aStream << aName;
            aStream << '>';
        }else {
            aStream << '/';
            aStream << '>';
        }
        return true;
    }

    static bool writeObject(const StringConstant<char>& aName, const GenericObject& aValue, OStream& aStream) throw() {
        if(aValue.size() == 0) {
            aStream << '<';
            aStream << aName;
            aStream << '/';
            aStream << '>';
            return true;
        }

        const auto entries = aValue.getEntries();
        const auto end = entries->end();

        aStream << '<';
        aStream << aName;

        // Write attributes
        aStream << ' ';
        for(auto i = entries->begin(); i != end; ++i) {
            switch(i->second.getType()) {
            case GenericValue::NULL_T:
                aStream << i->first;
                aStream << "=\"null\" ";
                break;
            case GenericValue::CHAR_T:
                aStream << i->first;
                aStream << "=\"";
                aStream << i->second.getChar();
                aStream << "\" ";
                break;
            case GenericValue::BOOL_T:
                aStream << i->first;
                if(i->second.getBool()) {
                    aStream << "=\"true\" ";
                }else {
                    aStream << "=\"false\" ";
                }
                break;
            case GenericValue::UNSIGNED_T:
                aStream << i->first;
                aStream << "=\"";
                aStream << i->second.getUnsigned();
                aStream << "\" ";
                break;
            case GenericValue::SIGNED_T:
                aStream << i->first;
                aStream << "=\"";
                aStream << i->second.getSigned();
                aStream << "\" ";
                break;
            case GenericValue::DOUBLE_T:
                aStream << i->first;
                aStream << "=\"";
                aStream << i->second.getDouble();
                aStream << "\" ";
                break;
            case GenericValue::STRING_T:
                aStream << i->first;
                aStream << "=\"";
                aStream << i->second.getString();
                aStream << "\" ";
                break;
            default:
                break;
            }
        }

        aStream << '>';

        // Write elements
        for(auto i = entries->begin(); i != end; ++i) {
            switch(i->second.getType()) {
            case GenericValue::ARRAY_T:
                writeArray(i->first, i->second.getArray(), aStream);
                break;
            case GenericValue::OBJECT_T:
                writeObject(i->first, i->second.getObject(), aStream);
                break;
            default:
                break;
            }
        }

        aStream << '<';
        aStream << '/';
        aStream << aName;
        aStream << '>';
        return true;
    }


    // JsonFormat

    SOLAIRE_EXPORT_CALL XmlFormat::~XmlFormat() {

    }

    GenericValue SOLAIRE_EXPORT_CALL XmlFormat::readValue(IStream& aStream) const throw() {
        try{
            //! \todo Implement XML read
            throw std::runtime_error("Not implemented");
        }catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
            return GenericValue();
        }
    }

    bool SOLAIRE_EXPORT_CALL XmlFormat::writeValue(const GenericValue& aValue, OStream& aStream) const throw() {

        try{
            switch(aValue.getType()) {
            case GenericValue::ARRAY_T:
                return writeArray(CString("array"), aValue.getArray(), aStream);
            case GenericValue::OBJECT_T:
                return writeObject(CString("object"), aValue.getObject(), aStream);
            default:
                return false;
            }
        }catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }

    Attribute XmlFormat::readAttribute(IStream& aStream) const throw() {
        //! \todo Implement readAttribute
        return Attribute();
    }

    bool XmlFormat::writeAttribute(const Attribute& aAttribute, OStream& aStream) const throw() {
        aStream << aAttribute.getName() << "=\"" << aAttribute.getValue() << '"';
        return true;
    }

    Element XmlFormat::readElement(IStream& aStream) const throw() {
        //! \todo Implement readElement
        return Element();
    }

    bool XmlFormat::writeElement(const Element& aElement, OStream& aStream) const throw() {
        aStream << '<' << aElement.getName();

        const StaticContainer<const Attribute>& attributes = aElement.getAttributes();
        if(attributes.size() > 0) {
            aStream << ' ';
            for(const Attribute& i : attributes) {
                writeAttribute(i, aStream);
                aStream << ' ';
            }
        }

        const int32_t bodySize = aElement.getBody().size();
        const int32_t elementCount = aElement.getElements().size();
        if(bodySize + elementCount == 0) {
            aStream << "/>";
        }else {
            aStream << '>';

            if(bodySize != 0) {
                if(elementCount != 0) return false;
                const StaticContainer<const Element>& elements = aElement.getElements();
                for(const Element& i : elements) {
                    writeElement(i, aStream);
                }
            }else {
                aStream << aElement.getBody();
            }

            aStream << "</";
            aStream << aElement.getName();
            aStream << '>';
        }
        return true;
    }

}
