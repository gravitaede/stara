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
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_HPP

#include "xos/app/console/protocol/xttp/client/main_opt.hpp"

#include "xos/protocol/http/request/method/which.hpp"
#include "xos/protocol/http/request/method/name.hpp"
#include "xos/protocol/http/request/method/nameof.hpp"

#include "xos/protocol/http/request/resource/which.hpp"
#include "xos/protocol/http/request/resource/identifier.hpp"

#include "xos/protocol/http/request/line.hpp"
#include "xos/protocol/http/request/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace client {

/// class maint
template 
<class TExtends = xos::app::console::protocol::xttp::client::main_opt, 
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
      method_(get_), resource_(path_), request_line_(method_, resource_, this->protocol_),
      request_headers_(&this->content_type_header_, &this->content_length_header_, null),
      request_(request_line_, request_headers_, this->content_) {
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

    typedef typename extends::headers_t headers_t;
    typedef typename extends::content_encoding_header_t content_encoding_header_t;
    typedef typename extends::content_type_header_t content_type_header_t;
    typedef typename extends::content_length_header_t content_length_header_t;

    typedef typename extends::content_t content_t;
    typedef typename extends::text_content_type_t text_content_type_t;
    typedef typename extends::json_content_type_t json_content_type_t;
    typedef typename extends::text_content_t text_content_t;

    typedef xos::protocol::http::request::method::name request_method_t;
    typedef xos::protocol::http::request::resource::identifier request_resource_t;
    typedef xos::protocol::http::request::line request_line_t;
    typedef xos::protocol::http::request::message request_t;
    typedef xos::protocol::http::request::message::string_t request_string_t;

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

    /// ...request_run
    virtual int request_run(int argc, char_t** argv, char_t** env) {
        out_writer_t& writer = this->out_writer();
        request_t& request = this->request();
        ssize_t amount = 0;
        int err = 0;
        err = all_write_request(amount, writer, request, argc, argv, env);
        return err;
    }

    /// ...method_run
    virtual int method_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        request_method_t& method = this->request_method();
        if ((chars = method.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...parameter_run
    virtual int parameter_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        request_resource_t& resource = this->request_resource();
        if ((chars = resource.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...write_request
    virtual int write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        request.write(amount, writer);
        return err;
    }
    virtual int before_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_request(ssize_t& amount, writer_t& writer, request_t& request, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_request(amount, writer, request, argc, argv, env))) {
            int err2 = 0;
            err = write_request(amount, writer, request, argc, argv, env);
            if ((err2 = after_write_request(amount, writer, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...set_request_headers
    virtual int set_request_headers(headers_t& headers, int argc, char_t** argv, char** env) {
        request_line_t& request_line = this->request_line();
        content_t& content = this->content();
        request_t& request = this->request();
        int err = 0;
        request.set(request_line, headers, content);
        return err;
    }
    virtual int before_set_request_headers(headers_t& headers, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_request_headers(headers_t& headers, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_request_headers(headers_t& headers, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_request_headers(headers, argc, argv, env))) {
            int err2 = 0;
            err = set_request_headers(headers, argc, argv, env);
            if ((err2 = after_set_request_headers(headers, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...set_request_content
    virtual int set_request_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        request_line_t& request_line = this->request_line();
        request_t& request = this->request();
        int err = 0;
        request.set(request_line, headers, content);
        return err;
    }
    virtual int before_set_request_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_request_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_request_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_request_content(headers, content, argc, argv, env))) {
            int err2 = 0;
            err = set_request_content(headers, content, argc, argv, env);
            if ((err2 = after_set_request_content(headers, content, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...option...
    int (derives::*on_set_request_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_request_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (on_set_request_option_) {
                err = (this->*on_set_request_option_)(optarg, optind, argc, argv, env);
            } else {
                err = file_on_set_request_option(optarg, optind, argc, argv, env);
            }
        } else {
        }
        return err;
    }
    virtual int file_on_set_request_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
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
                    request_string_t& request_literal = this->request_literal();
                    request_t& request = this->request();
                    
                    request_literal.clear();
                    do {
                        request_string_t::char_t cc = ((request_string_t::char_t)c);
                        request_literal.append(&cc, 1);
                        count += amount;
                    } while (0 < (amount = source.read(&c, 1)));
                    LOGGER_IS_LOGGED_INFO("request.set(request_literal = \"" << request_literal << "\")...");
                    request.set(request_literal);
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
    virtual int string_on_set_request_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        const char_t* chars = 0;
        if ((chars = optarg) && (0 != (c = chars[0]))) {
            request_string_t& request_literal = this->request_literal();
            request_t& request = this->request();
            
            LOGGER_IS_LOGGED_INFO("chars = \"" << chars << "\"...");
            request_literal.clear();
            do {
                request_string_t::char_t cc = ((request_string_t::char_t)c);
                request_literal.append(&cc, 1);
            } while (0 != (c = (++chars)[0]));
            LOGGER_IS_LOGGED_INFO("request.set(request_literal = \"" << request_literal << "\")...");
            request.set(request_literal);
        } else {
        }
        return err;
    }
    virtual int set_file_on_set_request_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_request_option_ = &derives::file_on_set_request_option;
        return err;
    }
    virtual int set_string_on_set_request_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_request_option_ = &derives::string_on_set_request_option;
        return err;
    }

    /// ...option...
    virtual int on_set_method_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_request_method(optarg);
        } else {
        }
        return err;
    }

    /// ...option...
    virtual int on_set_parameter_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_request_resource(optarg);
        } else {
        }
        return err;
    }

    /// ...option...
    virtual int on_content_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            content_type_header_t& content_type_header = this->content_type_header();
            content_length_header_t& content_length_header = this->content_length_header();
            headers_t& request_headers = this->request_headers();
            content_t& request_content = this->content();

            content_length_header.set_length(request_content.length());
            request_headers.is_setl(&content_type_header, &content_length_header, null);
            err = all_set_request_content(request_headers, request_content, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int on_content_type_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            content_type_header_t& content_type_header = this->content_type_header();
            content_length_header_t& content_length_header = this->content_length_header();
            headers_t& request_headers = this->request_headers();

            request_headers.is_setl(&content_type_header, &content_length_header, null);
            err = all_set_request_headers(request_headers, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int on_content_encoding_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            content_encoding_header_t& content_encoding_header = this->content_encoding_header();
            content_type_header_t& content_type_header = this->content_type_header();
            content_length_header_t& content_length_header = this->content_length_header();
            headers_t& request_headers = this->request_headers();

            request_headers.is_setl(&content_encoding_header, &content_type_header, &content_length_header, null);
            err = all_set_request_headers(request_headers, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int on_file_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_file_on_set_request_option(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_string_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_string_on_set_request_option(argc, argv, env))) {
        }
        return err;
    }

    /// request...
    virtual request_string_t& request_literal() const {
        return (request_string_t&)request_literal_;
    }
    virtual request_t& request() const {
        return (request_t&)request_;
    }
    virtual headers_t& request_headers() const {
        return (headers_t&)request_headers_;
    }
    virtual request_line_t& request_line() const {
        return (request_line_t&)request_line_;
    }
    virtual request_method_t& set_request_method_get() {
        return set_request_method(request_method_get());
    }
    virtual request_method_t& request_method_get() const {
        return (request_method_t&)get_;
    }
    virtual request_method_t& set_request_method_post() {
        return set_request_method(request_method_post());
    }
    virtual request_method_t& request_method_post() const {
        return (request_method_t&)post_;
    }
    virtual request_method_t& set_request_method(const request_method_t& to) {
        return set_request_method(to.chars());
    }
    virtual request_method_t& set_request_method(const char_t* to) {
        request_method_t& method = this->request_method();
        request_line_t& line = this->request_line();
        request_t& request = this->request();
        method.set(to);
        line.set_method(method);
        request.set_method(method);
        return (request_method_t&)method;
    }
    virtual request_method_t& request_method() const {
        return (request_method_t&)method_;
    }
    virtual request_resource_t& set_request_resource(const string_t& to) {
        const char_t* to_chars = to.chars();
        return set_request_resource(to_chars);
    }
    virtual request_resource_t& set_request_resource(const char_t* to) {
        request_resource_t& resource = this->request_resource();
        request_line_t& line = this->request_line();
        request_t& request = this->request();
        resource.set(to);
        line.set_resource(resource);
        request.set_resource(resource);
        return (request_resource_t&)resource;
    }
    virtual request_resource_t& request_resource() const {
        return (request_resource_t&)resource_;
    }

protected:
    xos::protocol::http::request::method::nameof::GET get_;
    xos::protocol::http::request::method::nameof::POST post_;
    xos::protocol::http::request::method::name method_;

    xos::protocol::http::request::resource::absolute::path path_;
    xos::protocol::http::request::resource::absolute::identifier identifier_;
    xos::protocol::http::request::resource::identifier asterisk_, resource_;
    xos::protocol::http::request::line request_line_;
    xos::protocol::http::message::header::fields request_headers_;
    xos::protocol::http::request::message request_;
    xos::protocol::http::request::message::string_t request_literal_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_HPP
