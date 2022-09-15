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
///   Date: 9/15/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_XTTP_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_XTTP_CLIENT_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/xttp/client/main_opt.hpp"
#include "xos/protocol/http/response/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace xttp {
namespace client {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::xttp::client::main_opt, 
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
    maint(): run_(0) {
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

    typedef xos::protocol::xttp::message::body::content content_t;
    typedef xos::protocol::http::response::message response_t;
    typedef typename extends::request_method_t request_method_t;
    typedef typename extends::request_t request_t;

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

    /// send_request
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        request_t &rq = this->request();
        int err = 0;
        err = send_request(rq, cn, argc, argv, env);
        return err;
    }
    virtual int send_request(request_t &rq, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        xos::network::sockets::writer writer(cn);
        int err = 0;
        err = send_request(reader, writer, rq, argc, argv, env);
        return err;
    }
    virtual int send_request
    (xos::network::sockets::reader& reader, 
     xos::network::sockets::writer& writer, request_t &rq, int argc, char_t** argv, char_t**env) {
        ssize_t amount = 0;
        int err = 0;
        err = this->all_write_request(amount, writer, rq, argc, argv, env);
        return err;
    }

    /// recv_response
    virtual int recv_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        response_t &rs = this->response();
        int err = 0;
        err = recv_response(rs, cn, argc, argv, env);
        return err;
    }
    virtual int recv_response(response_t &rs, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        int err = 0;
        err = recv_response(rs, reader, argc, argv, env);
        return err;
    }
    virtual int recv_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        char_t c = 0; ssize_t count = 0;
        int err = 0;
        if ((rs.read_with_content(count, c, reader))) {
            const char_t* chars = 0; size_t length = 0;
            if ((chars = rs.has_chars(length)) && (!chars[length])) {
                LOGGER_IS_LOGGED_INFO("...response = \"" << chars << "\"");
            }
            if ((chars = rs.content_chars(length)) && (!chars[length])) {
                LOGGER_IS_LOGGED_INFO("...content = \"" << chars << "\"");
            }
            err = all_process_response(rs, reader, argc, argv, env);
        }
        return err;
    }

    /// ...process_response
    virtual int process_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        int err = 0;
        err = all_outout_response(rs, argc, argv, env);
        return err;
    }
    virtual int before_process_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response(response_t &rs, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response(rs, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response(rs, reader, argc, argv, env);
            if ((err2 = after_process_response(rs, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...outout_response
    virtual int outout_response(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_outout_response_headers(rs, argc, argv, env))) {
            if (!(err = all_outout_response_content(rs, argc, argv, env))) {
                this->outln();
                this->out_flush();
            }
        }
        return err;
    }
    virtual int before_outout_response(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_outout_response(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_outout_response(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_outout_response(rs, argc, argv, env))) {
            int err2 = 0;
            err = outout_response(rs, argc, argv, env);
            if ((err2 = after_outout_response(rs, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...outout_response_headers
    virtual int outout_response_headers(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        if ((chars = rs.has_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    virtual int before_outout_response_headers(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_outout_response_headers(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_outout_response_headers(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_outout_response_headers(rs, argc, argv, env))) {
            int err2 = 0;
            err = outout_response_headers(rs, argc, argv, env);
            if ((err2 = after_outout_response_headers(rs, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...outout_response_content
    virtual int outout_response_content(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        if ((chars = rs.content_chars(length))) {
            this->out(chars, length);
        }
        return err;
    }
    virtual int before_outout_response_content(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_outout_response_content(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_outout_response_content(response_t &rs, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_outout_response_content(rs, argc, argv, env))) {
            int err2 = 0;
            err = outout_response_content(rs, argc, argv, env);
            if ((err2 = after_outout_response_content(rs, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// response.. 
    virtual response_t& response() const {
        return (response_t&)response_;
    }
    virtual content_t& response_content() const {
        return (content_t&)response_content_;
    }
    virtual size_t& response_content_size() const {
        return (size_t&)response_content_size_;
    }

protected:
    xos::protocol::http::response::message response_;
    size_t response_content_size_;
    content_t response_content_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace xttp
} /// namespace protocol
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_XTTP_CLIENT_MAIN_HPP
