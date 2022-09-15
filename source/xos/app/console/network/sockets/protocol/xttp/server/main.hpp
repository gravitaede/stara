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
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_XTTP_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_XTTP_SERVER_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/xttp/server/main_opt.hpp"

#include "xos/protocol/http/request/method/nameof.hpp"
#include "xos/protocol/http/request/resource/identifier.hpp"
#include "xos/protocol/http/request/line.hpp"
#include "xos/protocol/http/request/message.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace xttp {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::xttp::server::main_opt, 
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

    typedef typename extends::response_status_t response_status_t;
    typedef typename extends::response_t response_t;
    typedef xos::protocol::http::request::method::name request_method_t;
    typedef xos::protocol::http::request::message request_t;
    typedef xos::protocol::http::message::body::content content_t;

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

    /// ...send_response
    virtual int send_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        return err;
    }

    /// recv_request
    virtual int recv_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        request_t &rq = this->recved_request();
        int err = 0;
        err = recv_request(rq, cn, argc, argv, env);
        return err;
    }
    virtual int recv_request(request_t &rq, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        xos::network::sockets::reader reader(cn);
        xos::network::sockets::writer writer(cn);
        int err = 0;
        err = recv_request(writer, rq, reader, argc, argv, env);
        return err;
    }
    virtual int recv_request
    (xos::network::sockets::writer& writer, 
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        response_t &rs = this->response();
        char_t c = 0; ssize_t count = 0;
        int err = 0;
        if ((rq.read(count, c, reader))) {
            err = all_process_request(writer, rs, rq, reader, argc, argv, env);
        }
        return err;
    }

    /// ...process_request
    virtual int process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char_t**env) {
        int err = 0;
        ssize_t amount = 0;
        if (!(err = this->all_process_response_to(writer, rs, rq, reader, argc, argv, env))) {
            err = this->all_write_response_to(amount, writer, rs, rq, reader, argc, argv, env);
        }
        return err;
    }
    virtual int before_process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        if ((chars = rq.has_chars(length)) && (!chars[length])) {
            this->errlln(__LOCATION__, "...request = \"", chars, "\"", null);
            if ((length = rq.content_length())) {
                content_t& content = this->request_content();
                size_t content_length = length;
                char_t c = 0;
                for (content.clear(); 0 < length; --length) {
                    if (0 <= (reader.read(&c, 1))) {
                        content.append(&c, 1);
                    }
                }
                this->errlln(__LOCATION__, "...content[", unsigned_to_string(content_length).chars(), "] = \"", content.chars(), "\"", null);
            }
        }
        return err;
    }
    virtual int after_process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request
    (xos::network::sockets::writer& writer, response_t &rs,
     request_t &rq, xos::network::sockets::reader& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_request(writer, rs, rq, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_request(writer, rs, rq, reader, argc, argv, env);
            if ((err2 = after_process_request(writer, rs, rq, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to...
    virtual int process_response_to(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        switch (request.line().method().which()) {

        case xos::protocol::http::request::method::GET:
            LOGGER_IS_LOGGED_INFO("all_process_response_to_GET(writer, response, request, reader, argc, argv, env)...");
            err = all_process_response_to_GET(writer, response, request, reader, argc, argv, env);
            LOGGER_IS_LOGGED_INFO("..." << err << " = all_process_response_to_GET(writer, response, request, reader, argc, argv, env)");
            break;
        
        case xos::protocol::http::request::method::POST:
            LOGGER_IS_LOGGED_INFO("all_process_response_to_POST(writer, response, request, reader, argc, argv, env)...");
            err = all_process_response_to_POST(writer, response, request, reader, argc, argv, env);
            LOGGER_IS_LOGGED_INFO("..." << err << " = all_process_response_to_POST(writer, response, request, reader, argc, argv, env)");
            break;
        
        case xos::protocol::http::request::method::restart:
            LOGGER_IS_LOGGED_INFO("all_process_response_to_restart(writer, response, request, reader, argc, argv, env)...");
            err = all_process_response_to_restart(writer, response, request, reader, argc, argv, env);
            LOGGER_IS_LOGGED_INFO("..." << err << " = all_process_response_to_restart(writer, response, request, reader, argc, argv, env)");
            break;
        
        case xos::protocol::http::request::method::stop:
            LOGGER_IS_LOGGED_INFO("all_process_response_to_stop(writer, response, request, reader, argc, argv, env)...");
            err = all_process_response_to_stop(writer, response, request, reader, argc, argv, env);
            LOGGER_IS_LOGGED_INFO("..." << err << " = all_process_response_to_stop(writer, response, request, reader, argc, argv, env)");
            break;
        
        case xos::protocol::http::request::method::unknown:
        default:
            LOGGER_IS_LOGGED_INFO("method = \"" << request.line().method() << "\" --> " << "all_process_response_to_unknown(writer, response, request, reader, argc, argv, env)...");
            err = all_process_response_to_unknown(writer, response, request, reader, argc, argv, env);
            LOGGER_IS_LOGGED_INFO("..." << err << " = " "method = \"" << request.line().method() << "\" --> " << "all_process_response_to_unknown(writer, response, request, reader, argc, argv, env)");
            break;
        } /// switch
        return err;
    }
    virtual int before_process_response_to(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_GET...
    virtual int process_response_to_GET(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("process_response_to_GET(writer, response, request, reader, argc, argv, env)...");
        err = this->all_process_response_to_any(writer, response, request, reader, argc, argv, env);
        LOGGER_IS_LOGGED_INFO("...process_response_to_GET(writer, response, request, reader, argc, argv, env)");
        return err;
    }
    virtual int before_process_response_to_GET(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_GET(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_GET(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_GET(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_GET(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_GET(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_POST...
    virtual int process_response_to_POST(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("process_response_to_POST(writer, response, request, reader, argc, argv, env)...");
        err = this->all_process_response_to_any(writer, response, request, reader, argc, argv, env);
        LOGGER_IS_LOGGED_INFO("...process_response_to_POST(writer, response, request, reader, argc, argv, env)");
        return err;
    }
    virtual int before_process_response_to_POST(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_POST(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_POST(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_POST(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_POST(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_POST(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_restart...
    virtual int process_response_to_restart(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("process_response_to_restart(writer, response, request, reader, argc, argv, env)...");
        this->set_accept_restart();
        LOGGER_IS_LOGGED_INFO("...process_response_to_restart(writer, response, request, reader, argc, argv, env)");
        return err;
    }
    virtual int before_process_response_to_restart(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_restart(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_restart(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_restart(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_restart(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_restart(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_stop...
    virtual int process_response_to_stop(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("process_response_to_stop(writer, response, request, reader, argc, argv, env)...");
        this->set_accept_done();
        LOGGER_IS_LOGGED_INFO("...process_response_to_stop(writer, response, request, reader, argc, argv, env)");
        return err;
    }
    virtual int before_process_response_to_stop(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_stop(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_stop(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_stop(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_stop(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_stop(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_unknown...
    virtual int process_response_to_unknown(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("process_response_to_unknown(writer, response, request, reader, argc, argv, env)...");
        err = this->all_process_response_to_any(writer, response, request, reader, argc, argv, env);
        LOGGER_IS_LOGGED_INFO("...process_response_to_unknown(writer, response, request, reader, argc, argv, env)");
        return err;
    }
    virtual int before_process_response_to_unknown(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_unknown(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_unknown(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_unknown(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_unknown(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_unknown(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...process_response_to_any...
    virtual int process_response_to_any(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("process_response_to_any(writer, response, request, reader, argc, argv, env)...");
        LOGGER_IS_LOGGED_INFO("...process_response_to_any(writer, response, request, reader, argc, argv, env)");
        return err;
    }
    virtual int before_process_response_to_any(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_to_any(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_to_any(writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_process_response_to_any(writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = process_response_to_any(writer, response, request, reader, argc, argv, env);
            if ((err2 = after_process_response_to_any(writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...write_response_to...
    virtual int write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        err = all_write_response(amount, writer, response, argc, argv, env);
        return err;
    }
    virtual int before_write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_write_response_to(ssize_t& amount, writer_t& writer, response_t& response, request_t& request, reader_t& reader, int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_write_response_to(amount, writer, response, request, reader, argc, argv, env))) {
            int err2 = 0;
            err = write_response_to(amount, writer, response, request, reader, argc, argv, env);
            if ((err2 = after_write_response_to(amount, writer, response, request, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
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

    /// request...
    virtual request_t& recved_request() const {
        return (request_t&)recved_request_;
    }

protected:
    xos::protocol::http::request::message recved_request_;
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace xttp
} /// namespace protocol
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_XTTP_SERVER_MAIN_HPP
