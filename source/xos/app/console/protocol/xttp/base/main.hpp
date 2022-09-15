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
///   File: main.hpp
///
/// Author: $author$
///   Date: 9/14/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_HPP

#include "xos/app/console/protocol/xttp/base/main_opt.hpp"

#include "xos/protocol/xttp/content/json/node.hpp"
#include "xos/protocol/xttp/content/json/array.hpp"
#include "xos/protocol/xttp/content/json/object.hpp"

#include "xos/protocol/http/content/encoding/name.hpp"
#include "xos/protocol/http/content/encoding/nameof.hpp"
#include "xos/protocol/http/content/encoding/which.hpp"

#include "xos/protocol/http/content/type/name.hpp"
#include "xos/protocol/http/content/type/nameof.hpp"
#include "xos/protocol/http/content/type/which.hpp"

#include "xos/protocol/http/text/plain/content/type.hpp"
#include "xos/protocol/http/text/json/content/type.hpp"
#include "xos/protocol/http/text/content.hpp"

#include "xos/protocol/http/message/body/content.hpp"
#include "xos/protocol/http/message/header/content/encoding.hpp"
#include "xos/protocol/http/message/header/content/type.hpp"
#include "xos/protocol/http/message/header/content/length.hpp"
#include "xos/protocol/http/message/header/fields.hpp"

#include "xos/protocol/http/protocol/name.hpp"
#include "xos/protocol/http/protocol/version.hpp"
#include "xos/protocol/http/protocol/identifier.hpp"

#include "xos/io/crt/file/reader.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_DEFAULT_CONTENT "hello\r\n"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::xttp::base::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0), 
      content_encoding_(none_), content_encoding_header_(content_encoding_),
      content_type_(text_), content_type_header_(content_type_),
      default_content_(XOS_APP_CONSOLE_PROTOCOL_XTTP_DEFAULT_CONTENT), 
      content_(default_content_), content_length_header_(content_),
      http_(http_name_, http_version_), protocol_(http_) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef xos::protocol::xttp::content::json::boolean json_boolean_t;
    typedef xos::protocol::xttp::content::json::number json_number_t;
    typedef xos::protocol::xttp::content::json::string json_string_t;
    typedef xos::protocol::xttp::content::json::node json_node_t;
    typedef xos::protocol::xttp::content::json::array json_array_t;
    typedef xos::protocol::xttp::content::json::object json_object_t;

    typedef xos::protocol::http::message::header::fields headers_t;
    typedef xos::protocol::http::message::header::content::length content_length_header_t;
    typedef xos::protocol::http::message::header::content::type content_type_header_t;

    typedef xos::protocol::http::content::media::subtype::which_t content_type_subtype_which_t;
    typedef xos::protocol::http::content::media::subtype::name content_type_subtype_t;
    enum { 
        content_type_subtype_plain = xos::protocol::http::content::media::subtype::plain,
        content_type_subtype_html = xos::protocol::http::content::media::subtype::html,
        content_type_subtype_xml = xos::protocol::http::content::media::subtype::xml,
        content_type_subtype_css = xos::protocol::http::content::media::subtype::css,
        content_type_subtype_javascript = xos::protocol::http::content::media::subtype::javascript,
        content_type_subtype_json = xos::protocol::http::content::media::subtype::json,
        content_type_subtype_form_data = xos::protocol::http::content::media::subtype::form_data,
        content_type_subtype_urlencoded_form_data = xos::protocol::http::content::media::subtype::urlencoded_form_data,
    };

    typedef xos::protocol::http::content::media::type::which_t content_type_type_which_t;
    typedef xos::protocol::http::content::media::type::name content_type_type_t;
    enum { 
        content_type_type_text = xos::protocol::http::content::media::type::text,
        content_type_type_application = xos::protocol::http::content::media::type::application, 
        content_type_type_multipart = xos::protocol::http::content::media::type::multipart, 
    };

    typedef xos::protocol::http::content::type::which_t content_type_which_t;
    typedef xos::protocol::http::content::type::name content_type_t;

    typedef xos::protocol::http::message::header::content::encoding content_encoding_header_t;
    typedef xos::protocol::http::content::encoding::which_t content_encoding_which_t;
    typedef xos::protocol::http::content::encoding::name content_encoding_t;

    typedef xos::protocol::http::text::plain::content::type text_content_type_t;
    typedef xos::protocol::http::text::json::content::type json_content_type_t;
    typedef xos::protocol::http::text::content text_content_t;
    typedef xos::protocol::http::message::body::content content_t;
    typedef xos::protocol::http::message::body::content::string_t content_string_t;
    typedef xos::protocol::http::protocol::identifier protocol_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...content_run
    virtual int content_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        content_t& content = this->content();
        
        if ((chars = content.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    /// ...content_type_run
    virtual int content_type_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        content_type_t& content_type = this->content_type();
        
        if ((chars = content_type.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }
    /// ...content_encoding_run
    virtual int content_encoding_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        content_encoding_t& content_encoding = this->content_encoding();
        
        if ((chars = content_encoding.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...option...
    int (derives::*on_set_content_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_content_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_content_option_) {
            err = (this->*on_set_content_option_)(optarg, optind, argc, argv, env);
        } else {
            err = string_on_set_content_option(optarg, optind, argc, argv, env);
        }
        return err;
    }
    virtual int file_on_set_content_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = optarg) && (chars[0])) {
            xos::io::crt::file::reader source;

            LOGGER_IS_LOGGED_INFO("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                xos::io::crt::file::reader::sized_t c = 0;
                ssize_t amount = 0, count = 0;

                LOGGER_IS_LOGGED_INFO("...source.open(chars = \"" << chars << "\")");
                if (0 < (amount = source.read(&c, 1))) {
                    content_string_t& content_literal = this->content_literal();
                    content_t& content = this->content();
                    
                    content_literal.clear();
                    do {
                        content_string_t::char_t cc = ((content_string_t::char_t)c);
                        content_literal.append(&cc, 1);
                        count += amount;
                    } while (0 < (amount = source.read(&c, 1)));
                    LOGGER_IS_LOGGED_INFO("content.set(content_literal = \"" << content_literal << "\")...");
                    content.set(content_literal);
                }
                LOGGER_IS_LOGGED_INFO("source.close() \"" << chars << "\"...");
                if ((source.close())) {
                    LOGGER_IS_LOGGED_INFO("...source.close() \"" << chars << "\"");
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed on source.close() \"" << chars << "\"");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on source.open(chars = \"" << chars << "\")");
            }
        } else {
        }
        return err;
    }
    virtual int string_on_set_content_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        char_t c = 0;
        const char_t* chars = 0;
        if ((chars = optarg) && (0 != (c = chars[0]))) {
            content_string_t& content_literal = this->content_literal();
            content_t& content = this->content();
            
            LOGGER_IS_LOGGED_INFO("chars = \"" << chars << "\"...");
            content_literal.clear();
            do {
                content_string_t::char_t cc = ((content_string_t::char_t)c);
                content_literal.append(&cc, 1);
            } while (0 != (c = (++chars)[0]));
            LOGGER_IS_LOGGED_INFO("content.set(content_literal = \"" << content_literal << "\")...");
            content.set(content_literal);
        } else {
        }
        return err;
    }
    virtual int set_file_on_set_content_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_content_option_ = &derives::file_on_set_content_option;
        return err;
    }
    virtual int set_string_on_set_content_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_content_option_ = &derives::string_on_set_content_option;
        return err;
    }

    /// ...option...
    virtual int on_set_content_type_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_content_type(optarg);
        } else {
        }
        return err;
    }
    virtual int on_set_content_encoding_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_content_encoding(optarg);
        } else {
        }
        return err;
    }

    /// ...option...
    virtual int on_set_file_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_file_on_set_content_option(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_set_string_input_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_string_on_set_content_option(argc, argv, env))) {
        }
        return err;
    }

    /// content_encoding...
    virtual content_encoding_header_t& content_encoding_header() const {
        return (content_encoding_header_t&)content_encoding_header_;
    }
    virtual content_encoding_t& content_encoding_none() const {
        return (content_encoding_t&)none_;
    }
    virtual content_encoding_t& set_content_encoding(const content_encoding_t& to) {
        const char_t* to_chars = to.chars();
        return set_content_encoding(to_chars);
    }
    virtual content_encoding_t& set_content_encoding(const char_t* to) {
        content_encoding_t& content_encoding = this->content_encoding();
        content_encoding_header_t& content_encoding_header = this->content_encoding_header();
        content_encoding.set(to);
        content_encoding_header.set_type(content_encoding);
        return (content_encoding_t&)content_encoding;
    }
    virtual content_encoding_t& content_encoding() const {
        return (content_encoding_t&)content_encoding_;
    }

    /// content_type...
    virtual content_type_header_t& content_type_header() const {
        return (content_type_header_t&)content_type_header_;
    }
    virtual content_type_t& content_type_text() const {
        return (content_type_t&)text_;
    }
    virtual content_type_t& content_type_html() const {
        return (content_type_t&)html_;
    }
    virtual content_type_t& content_type_xml() const {
        return (content_type_t&)xml_;
    }
    virtual content_type_t& content_type_css() const {
        return (content_type_t&)css_;
    }
    virtual content_type_t& content_type_json() const {
        return (content_type_t&)json_;
    }
    virtual content_type_t& content_type_javascript() const {
        return (content_type_t&)javascript_;
    }
    virtual content_type_t& set_content_type_text() {
        const content_type_t& content_type = this->content_type_text();
        return set_content_type(content_type);
    }
    virtual content_type_t& set_content_type_html() {
        const content_type_t& content_type = this->content_type_html();
        return set_content_type(content_type);
    }
    virtual content_type_t& set_content_type_xml() {
        const content_type_t& content_type = this->content_type_xml();
        return set_content_type(content_type);
    }
    virtual content_type_t& set_content_type_css() {
        const content_type_t& content_type = this->content_type_css();
        return set_content_type(content_type);
    }
    virtual content_type_t& set_content_type_json() {
        const content_type_t& content_type = this->content_type_json();
        return set_content_type(content_type);
    }
    virtual content_type_t& set_content_type_javascript() {
        const content_type_t& content_type = this->content_type_javascript();
        return set_content_type(content_type);
    }
    virtual content_type_t& set_content_type(const content_type_t& to) {
        const char_t* to_chars = to.chars();
        return set_content_type(to_chars);
    }
    virtual content_type_t& set_content_type(const char_t* to) {
        content_type_t& content_type = this->content_type();
        content_type_header_t& content_type_header = this->content_type_header();
        content_type.set(to);
        content_type_header.set_type(content_type);
        return (content_type_t&)content_type;
    }
    virtual content_type_t& content_type() const {
        return (content_type_t&)content_type_;
    }

    /// content_length...
    virtual content_length_header_t& content_length_header() const {
        return (content_length_header_t&)content_length_header_;
    }
    virtual size_t content_length() const {
        return content_.length();
    }

    /// content
    virtual content_t& set_content(const content_t& to) {
        const char_t* to_chars = to.chars();
        return set_content(to_chars);
    }
    virtual content_t& set_content(const char_t* to) {
        content_length_header_t& content_length_header = this->content_length_header();
        content_t& content = this->content();
        content.set(to);
        content_length_header.set_length(this->content_length());
        return content;
    }
    virtual content_t& content() const {
        return (content_t&)content_;
    }
    virtual content_string_t& content_literal() const {
        return (content_string_t&)content_literal_;
    }

    /// protocol
    virtual protocol_t& protocol() const {
        return (protocol_t&)protocol_;
    }

protected:
    xos::protocol::http::content::encoding::nameof::none none_;
    xos::protocol::http::content::encoding::name content_encoding_;
    xos::protocol::http::message::header::content::encoding content_encoding_header_;

    xos::protocol::http::content::type::nameof::text text_;
    xos::protocol::http::content::type::nameof::html html_;
    xos::protocol::http::content::type::nameof::xml xml_;
    xos::protocol::http::content::type::nameof::css css_;
    xos::protocol::http::content::type::nameof::json json_;
    xos::protocol::http::content::type::nameof::javascript javascript_;
    xos::protocol::http::content::type::name content_type_;
    xos::protocol::http::message::header::content::type content_type_header_;

    xos::protocol::http::message::body::content default_content_, content_;
    xos::protocol::http::message::body::content::string_t content_literal_;
    xos::protocol::http::message::header::content::length content_length_header_;

    xos::protocol::http::protocol::name http_name_;
    xos::protocol::http::protocol::version http_version_;
    xos::protocol::http::protocol::identifier http_, protocol_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_HPP
