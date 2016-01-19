#ifndef SOLAIRE_XML_ELEMENT_HPP
#define SOLAIRE_XML_ELEMENT_HPP

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

/*!
	\file Element.hpp
	\brief
	\author
	Created			: Adam Smith
	Last modified	: Adam Smith
	\version 1.0
	\date
	Created			: 19th January 2016
	Last Modified	: 19th January 2016
*/

#include "Solaire/XML/Attibute.hpp"

namespace Solaire {

    class Element {
    private:
        CString mName;
        CString mBody;
        ArrayList<Attibute> mAttributes;
        ArrayList<Element> mElements;
    public:
        Attribute() throw();

        String<char>& getName() throw();
        const String<char>& getName() const throw();
        void setName(const StringConstant<char>&) throw();

        String<char>& getBody() throw();
        const String<char>& getBody() const throw();
        void setBody(const StringConstant<char>&) throw();
        bool hasBody() const throw();

        Container<Attribute>& getAttributes() throw();
        const Container<const Attribute>& getAttributes() const throw();

        Container<Element>& getElements() throw();
        const Container<const Element>& getElements() const throw();

        Allocator& getAllocator() const throw();
    };
}

#endif
