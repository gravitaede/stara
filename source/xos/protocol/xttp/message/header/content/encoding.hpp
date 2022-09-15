///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: encoding.hpp
///
/// Author: $author$
///   Date: 5/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_ENCODING_HPP
#define XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_ENCODING_HPP

#include "xos/protocol/xttp/message/header/field.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace message {
namespace header {
namespace content {

namespace extended {
/// class encodingt
template 
<class TType = message::part,
 class TExtends = header::field, class TImplements = typename TExtends::implements>

class exported encodingt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef encodingt derives; 
    
    typedef TType type_t;
    typedef typename extends::part_t part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructors / destructor
    encodingt(const string_t& chars) {
    }
    encodingt(const char_t* chars, size_t length) {
    }
    encodingt(const char_t* chars) {
    }
    encodingt(const encodingt& copy) {
    }
    encodingt() {
    }
    virtual ~encodingt() {
    }

    /// set_type
    virtual derives& set_type(const string& s) {
        this->set_name(name_chars());
        this->set_value(s);
        return *this;
    }
    virtual derives& set_type(const char* chars, size_t length) {
        this->set_name(name_chars());
        this->set_value(chars, length);
        return *this;
    }
    virtual derives& set_type(const char* chars) {
        this->set_name(name_chars());
        this->set_value(chars);
        return *this;
    }
    virtual derives& set_type() {
        this->set_name(name_chars());
        this->set_value();
        return *this;
    }
    
    /// name_chars
    const char_t* name_chars() const {
        return "Content-Encoding";
    }

}; /// class encodingt
typedef encodingt<> encoding;
} /// namespace extended

/// class encodingt
template <class TExtends = extended::encoding, class TImplements = typename TExtends::implements>
class exported encodingt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef encodingt derives; 
    
    typedef typename extends::type_t type_t;
    typedef typename extends::part_t part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructors / destructor
    encodingt(const string_t& chars) {
        this->set_type(chars);
    }
    encodingt(const char_t* chars, size_t length) {
        this->set_type(chars, length);
    }
    encodingt(const char_t* chars) {
        this->set_type(chars);
    }
    encodingt(const encodingt& copy) {
        this->set_type(copy.value());
    }
    encodingt() {
        this->set_type();
    }
    virtual ~encodingt() {
    }

}; /// class encodingt
typedef encodingt<> encoding;

} /// namespace content
} /// namespace header
} /// namespace message
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_ENCODING_HPP
