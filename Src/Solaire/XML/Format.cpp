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

    static bool skipWhitespace(IStream& aStream) {
        if(aStream.end()) return true;
        char c;
        aStream >> c;
        while(std::isspace(c)) {
            if(aStream.end()) return true;
            aStream >> c;
        }
        aStream.setOffset(aStream.getOffset() - 1);
        return true;
    }

    static bool writeValue(const GenericValue& aValue, OStream& aStream) throw();

    static bool writeNull(OStream& aStream) throw() {
        return false;
    }

    static bool writeChar(const char aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeBool(const bool aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeUnsigned(const uint64_t aValue, OStream& aStream) throw() {
        /*CString tmp;
        tmp += aValue;
        aStream << tmp;
        return true;*/
        return false;
    }

    static bool writeSigned(const int64_t aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeDouble(const double aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeString(const StringConstant<char>& aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeArray(const GenericArray& aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeObject(const GenericObject& aValue, OStream& aStream) throw() {
        return false;
    }

    static bool writeValue(const GenericValue& aValue, OStream& aStream) throw() {
        switch(aValue.getType()) {
        case GenericValue::NULL_T:
            return writeNull(aStream);
        case GenericValue::CHAR_T:
            return writeChar(aValue.getChar(), aStream);
        case GenericValue::BOOL_T:
            return writeBool(aValue.getBool(), aStream);
        case GenericValue::UNSIGNED_T:
            return writeUnsigned(aValue.getUnsigned(), aStream);
        case GenericValue::SIGNED_T:
            return writeSigned(aValue.getSigned(), aStream);
        case GenericValue::DOUBLE_T:
            return writeDouble(aValue.getDouble(), aStream);
        case GenericValue::STRING_T:
            return writeString(aValue.getString(), aStream);
        case GenericValue::ARRAY_T:
            return writeArray(aValue.getArray(), aStream);
        case GenericValue::OBJECT_T:
            return writeObject(aValue.getObject(), aStream);
        default:
            return false;
        }
    }

    static GenericValue::ValueType getType(IStream& aStream) {
        const int32_t offset = aStream.getOffset();
        GenericValue::ValueType type = GenericValue::NULL_T;

        skipWhitespace(aStream);
        if(! aStream.end()) {
            char c;
            aStream >> c;

            switch(c){
            case 'n':
                type = GenericValue::NULL_T;
                break;
            case 't':
            case 'f':
                type = GenericValue::BOOL_T;
                break;
            case '-':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                type = GenericValue::DOUBLE_T;
                break;
            case '"':
                type = GenericValue::STRING_T;
                break;
            case '[':
                type = GenericValue::ARRAY_T;
                break;
            case '{':
                type = GenericValue::OBJECT_T;
                break;
            default:
                break;
            }
        }

        aStream.setOffset(offset);
        return type;
    }

    static GenericValue readValue(IStream& aStream);

    static GenericValue readNull(IStream& aStream) throw() {
        throw std::runtime_error("Xml::Null : Not implemented");
    }

    static GenericValue readBool(IStream& aStream) {
        throw std::runtime_error("Xml::Bool : Not implemented");
    }

    static GenericValue readDouble(IStream& aStream) throw() {
        throw std::runtime_error("Xml::Double : Not implemented");
    }

    static GenericValue readString(IStream& aStream) {
        throw std::runtime_error("Xml::String : Not implemented");
    }

    static GenericValue readArray(IStream& aStream) {
        throw std::runtime_error("Xml::Array : Not implemented");
    }

    static GenericValue readObject(IStream& aStream) {
        throw std::runtime_error("Xml::Object : Not implemented");
    }

    static GenericValue readValue(IStream& aStream) {
        switch(getType(aStream)) {
        case GenericValue::NULL_T:
            return readNull(aStream);
        case GenericValue::BOOL_T:
            return readBool(aStream);
        case GenericValue::DOUBLE_T:
            return readDouble(aStream);
        case GenericValue::STRING_T:
            return readString(aStream);
        case GenericValue::ARRAY_T:
            return readArray(aStream);
        case GenericValue::OBJECT_T:
            return readObject(aStream);
        default:
        throw std::runtime_error("Invalid json type");
        }
    }


    // JsonFormat

    SOLAIRE_EXPORT_CALL XmlFormat::~XmlFormat() {

    }

    GenericValue SOLAIRE_EXPORT_CALL XmlFormat::readValue(IStream& aStream) const throw() {
        try{
            return Solaire::readValue(aStream);
        }catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
            return GenericValue();
        }
    }

    bool SOLAIRE_EXPORT_CALL XmlFormat::writeValue(const GenericValue& aValue, OStream& aStream) const throw() {

        try{
            return Solaire::writeValue(aValue, aStream);
        }catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
            return false;
        }
    }

}
