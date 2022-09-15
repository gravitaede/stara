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
///   File: type.hpp
///
/// Author: $author$
///   Date: 5/5/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_TEXT_JSON_CONTENT_TYPE_HPP
#define XOS_PROTOCOL_HTTP_TEXT_JSON_CONTENT_TYPE_HPP

#include "xos/protocol/xttp/message/part.hpp"
#include "xos/protocol/http/content/type/json_name.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace text {
namespace json {
namespace content {

/// class typet
template 
<class TTypeName = xos::protocol::http::content::type::json_name,
 class TExtends = xos::protocol::xttp::message::part, class TImplements = implement>

class exported typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typet derives; 
    
    typedef TTypeName type_name_t;

    typedef typename type_name_t::type_which_t type_which_t;
    enum { type_which = type_name_t::type_which };

    typedef typename type_name_t::subtype_which_t subtype_which_t;
    enum { sybtype_which = type_name_t::subtype_which };

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructors / destructor
    typet(const typet& copy): extends(copy) {
    }
    typet() {
        this->assign(value_chars());
    }
    virtual ~typet() {
    }

    /// value_chars
    const char_t* value_chars() const {
        return type_name_.chars();
    }

protected:
    type_name_t type_name_;
}; /// class typet
typedef typet<> type;

} /// namespace content
} /// namespace json
} /// namespace text
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_TEXT_JSON_CONTENT_TYPE_HPP
