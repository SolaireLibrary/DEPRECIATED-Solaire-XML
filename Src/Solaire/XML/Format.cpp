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
    static CString writeObject(const StringConstant<char>& aName, const GenericObject& aValue) throw();

    static CString writeArray(const StringConstant<char>& aName, const GenericArray& aValue) throw() {
        CString tmp;

        tmp += '<';
        tmp += aName;
        if(aValue.size() > 0) {
            tmp += '>';
            const auto end = aValue.end();
            for(auto i = aValue.begin(); i != end; ++i) {
                switch(i->getType()) {
                    case GenericValue::NULL_T:
                        tmp += "<null/>";
                        break;
                    case GenericValue::CHAR_T:
                        tmp += "<char>";
                        tmp += i->getChar();
                        tmp += "</char>";
                        break;
                    case GenericValue::BOOL_T:
                        tmp += "<bool>";
                        if(i->getBool()) {
                            tmp += "true";
                        }else {
                            tmp += "false";
                        }
                        tmp += "</bool>";
                        break;
                    case GenericValue::UNSIGNED_T:
                        tmp += "<unsigned>";
                        tmp += i->getUnsigned();
                        tmp += "</unsigned>";
                        break;
                    case GenericValue::SIGNED_T:
                        tmp += "<signed>";
                        tmp += i->getSigned();
                        tmp += "</signed>";
                        break;
                    case GenericValue::DOUBLE_T:
                        tmp += "<double>";
                        tmp += i->getDouble();
                        tmp += "</double>";
                        break;
                    case GenericValue::STRING_T:
                        tmp += "<string>";
                        tmp += i->getString();
                        tmp += "</string>";
                        break;
                    case GenericValue::ARRAY_T:
                        tmp += writeArray(CString("array"), i->getArray());
                        break;
                    case GenericValue::OBJECT_T:
                        tmp += writeObject(CString("object"), i->getObject());
                        break;
                    default:
                        break;
                }
            }

            tmp += '<';
            tmp += '/';
            tmp += aName;
            tmp += '>';
        }else {
            tmp += '/';
            tmp += '>';
        }
    }

    static CString writeObject(const StringConstant<char>& aName, const GenericObject& aValue) throw() {
        //! \todo Implement writeObject
        throw std::runtime_error("Not implemented");
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
                aStream << writeArray(CString("array"), aValue.getArray());
                return true;
            case GenericValue::OBJECT_T:
                aStream << writeObject(CString("object"), aValue.getObject());
                return false;
            default:
                return false;
            }
        }catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }

}
