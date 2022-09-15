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
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_HPP

#include "xos/app/console/protocol/xttp/server/main_opt.hpp"

#include "xos/protocol/http/response/status/codeof.hpp"
#include "xos/protocol/http/response/status/reason.hpp"
#include "xos/protocol/http/response/line.hpp"
#include "xos/protocol/http/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::protocol::xttp::server::main_opt, 
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
    : run_(0), status_(ok_), reason_(status_), response_line_(this->protocol_, status_, reason_),
      response_headers_(&this->content_type_header_, &this->content_length_header_, null),
      response_(response_line_, response_headers_, this->content_) {
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

    typedef xos::protocol::http::response::status::code response_status_t;
    typedef xos::protocol::http::response::status::reason response_reason_t;
    typedef xos::protocol::http::response::line response_line_t;
    typedef xos::protocol::http::response::message response_t;
    typedef xos::protocol::http::response::message::string_t response_string_t;

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

    /// ...respond_run
    virtual int respond_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        out_writer_t& writer = this->out_writer();
        response_t& response = this->response();
        ssize_t amount = 0;
        err = all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }

    /// ...status_run
    virtual int status_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        response_status_t& status = this->response_status();
        if ((chars = status.has_chars(length))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...write_response
    virtual int write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        response.write(amount, writer);
        return err;
    }
    virtual int before_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_response(ssize_t& amount, writer_t& writer, response_t& response, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_response(amount, writer, response, argc, argv, env))) {
            int err2 = 0;
            err = write_response(amount, writer, response, argc, argv, env);
            if ((err2 = after_write_response(amount, writer, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...set_response_content
    virtual int set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        response_line_t& response_line = this->response_line();
        response_t& response = this->response();
        int err = 0;
        response.set(response_line, headers, content);
        return err;
    }
    virtual int before_set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_response_content(headers_t& headers, content_t& content, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_set_response_content(headers, content, argc, argv, env))) {
            int err2 = 0;
            err = set_response_content(headers, content, argc, argv, env);
            if ((err2 = after_set_response_content(headers, content, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...option...
    int (derives::*on_set_respond_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int on_set_respond_option(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (on_set_respond_option_) {
            err = (this->*on_set_respond_option_)(optarg, optind, argc, argv, env);
        } else {
            err = file_on_set_respond_option(optarg, optind, argc, argv, env);
        }
        return err;
    }
    virtual int file_on_set_respond_option
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
                    response_string_t& response_literal = this->response_literal();
                    response_t& response = this->response();
                    
                    response_literal.clear();
                    do {
                        response_string_t::char_t cc = ((response_string_t::char_t)c);
                        response_literal.append(&cc, 1);
                        count += amount;
                    } while (0 < (amount = source.read(&c, 1)));
                    LOGGER_IS_LOGGED_INFO("response.set(response_literal = \"" << response_literal << "\")...");
                    response.set(response_literal);
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
    virtual int string_on_set_respond_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        char_t c = 0;
        const char_t* chars = 0;
        if ((chars = optarg) && (0 != (c = chars[0]))) {
            response_string_t& response_literal = this->response_literal();
            response_t& response = this->response();
            
            LOGGER_IS_LOGGED_INFO("chars = \"" << chars << "\"...");
            response_literal.clear();
            do {
                response_string_t::char_t cc = ((response_string_t::char_t)c);
                response_literal.append(&cc, 1);
            } while (0 != (c = (++chars)[0]));
            LOGGER_IS_LOGGED_INFO("response.set(response_literal = \"" << response_literal << "\")...");
            response.set(response_literal);
        } else {
        }
        return err;
    }
    virtual int set_file_on_set_respond_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_respond_option_ = &derives::file_on_set_respond_option;
        return err;
    }
    virtual int set_string_on_set_respond_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_respond_option_ = &derives::string_on_set_respond_option;
        return err;
    }

    /// ...option...
    virtual int on_set_status_ok_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_response_status(optarg);
        } else {
            set_response_status_ok();
        }
        return err;
    }

    /// ...option...
    virtual int on_set_status_not_found_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_response_status(optarg);
        } else {
            set_response_status_not_found();
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
            headers_t& response_headers = this->response_headers();
            content_t& response_content = this->content();

            content_length_header.set_length(response_content.length());
            response_headers.is_setl(&content_type_header, &content_length_header, null);
            err = all_set_response_content(response_headers, response_content, argc, argv, env);
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
            headers_t& response_headers = this->response_headers();
            content_t& response_content = this->content();

            response_headers.is_setl(&content_type_header, &content_length_header, null);
            err = all_set_response_content(response_headers, response_content, argc, argv, env);
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
            headers_t& response_headers = this->response_headers();
            content_t& response_content = this->content();

            response_headers.is_setl(&content_encoding_header, &content_type_header, &content_length_header, null);
            err = all_set_response_content(response_headers, response_content, argc, argv, env);
        } else {
        }
        return err;
    }
    virtual int on_file_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_file_on_set_respond_option(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_string_input_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_string_on_set_respond_option(argc, argv, env))) {
        }
        return err;
    }

    /// response...
    virtual response_string_t& response_literal() const {
        return (response_string_t&)response_literal_;
    }
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual headers_t& response_headers() const {
        return (headers_t&)response_headers_;
    }
    virtual response_line_t& response_line() const {
        return (response_line_t&)response_line_;
    }
    virtual response_reason_t& response_reason() const {
        return (response_reason_t&)reason_;
    }
    virtual response_status_t& set_response_status_ok() {
        return set_response_status(response_status_ok());
    }
    virtual response_status_t& response_status_ok() const {
        return (response_status_t&)ok_;
    }
    virtual response_status_t& set_response_status_not_found() {
        return set_response_status(response_status_not_found());
    }
    virtual response_status_t& response_status_not_found() const {
        return (response_status_t&)not_found_;
    }
    virtual response_status_t& set_response_status(const response_status_t& to) {
        return set_response_status(to.chars());
    }
    virtual response_status_t& set_response_status(const char_t* to) {
        response_status_t& status_ = this->response_status();
        response_reason_t& reason_ = this->response_reason();
        response_line_t& response_line_ = this->response_line();
        response_t& response_ = this->response();
        status_.set(to);
        reason_.set(status_);
        response_line_.set_status(status_);
        response_line_.set_reason(reason_);
        response_.set_status(status_);
        response_.set_reason(reason_);
        response_.set_line(response_line_);
        return (response_status_t&)status_;
    }
    virtual response_status_t& response_status() const {
        return (response_status_t&)status_;
    }

    /// ...content
    virtual content_t& request_content() const {
        return (content_t&)request_content_;
    }

protected:
    xos::protocol::http::response::status::codeof::OK ok_;
    xos::protocol::http::response::status::codeof::Not_Found not_found_;
    xos::protocol::http::response::status::code status_;
    xos::protocol::http::response::status::reason reason_;

    xos::protocol::http::response::line response_line_;
    xos::protocol::http::message::header::fields response_headers_;
    xos::protocol::http::response::message response_;
    xos::protocol::http::response::message::string_t response_literal_;

    xos::protocol::http::message::body::content request_content_;
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_XTTP_SERVER_MAIN_HPP
