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
///   File: nameof.hpp
///
/// Author: $author$
///   Date: 5/6/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_CONTENT_ENCODING_NAMEOF_NAMEOF_HPP
#define XOS_PROTOCOL_HTTP_CONTENT_ENCODING_NAMEOF_NAMEOF_HPP

#include "xos/protocol/http/content/encoding/name.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace content {
namespace encoding {
namespace nameof {

/// class none
class exported none: public encoding::name {
public:
    typedef encoding::name extends;
    typedef name derives;
    /// constructor / destructor
    none(const none& copy): extends(copy) {}
    none(): extends(encoding::none) {}
    virtual ~none() {}
}; /// class none

} /// namespace nameof
} /// namespace encoding
} /// namespace content
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_CONTENT_ENCODING_NAMEOF_NAMEOF_HPP
