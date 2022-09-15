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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/14/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPT_HPP

#include "xos/app/console/protocol/xttp/base/main.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPT "request"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG "[string]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTUSE "Send " \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_name " request"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_QUERY_OPTARG \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_QUERY_OPTUSE \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTUSE
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_QUERY_OPTVAL_S "q::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_QUERY_OPTVAL_C 'q'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_QUERY_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_QUERY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPT "method"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTARG "[{ GET | POST | ...}]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTUSE \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_Name " request method"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPT "parameter"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTARG "[{ / | ...}]"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTUSE \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_PROTOCOL_Name " request parameter"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_XTTP_BASE_MAIN_OPTIONS_OPTIONS

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_ARGS 0
#define XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace xttp {
namespace client {

/// class main_optt
template 
<class TExtends = xos::app::console::protocol::xttp::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

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
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_request_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_request_run(argc, argv, env))) {
            int err2 = 0;
            err = request_run(argc, argv, env);
            if ((err2 = after_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_request_run;
        return err;
    }
    
    /// ...method_run
    virtual int method_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_method_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_method_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_method_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_method_run(argc, argv, env))) {
            int err2 = 0;
            err = method_run(argc, argv, env);
            if ((err2 = after_method_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_method_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_method_run;
        return err;
    }
    
    /// ...parameter_run
    virtual int parameter_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }
    virtual int before_parameter_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int after_parameter_run(int argc, char_t** argv, char** env) {
        int err = 0;
        return err;
    }
    virtual int all_parameter_run(int argc, char_t** argv, char** env) {
        int err = 0;
        if (!(err = before_parameter_run(argc, argv, env))) {
            int err2 = 0;
            err = parameter_run(argc, argv, env);
            if ((err2 = after_parameter_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_parameter_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_parameter_run;
        return err;
    }
    
    /// ...option...
    virtual int on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
                    if (!(err = set_request_run(argc, argv, env))) {
                    }
                }
            }
        } else {
            if (!(err = set_request_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_set_method_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_method_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_method_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_method_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_method_option_set(optarg, optind, argc, argv, env))) {
                    if (!(err = set_method_run(argc, argv, env))) {
                    }
                }
            }
        } else {
            if (!(err = set_method_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* method_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_set_parameter_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_parameter_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_parameter_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_parameter_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_parameter_option_set(optarg, optind, argc, argv, env))) {
                    if (!(err = set_parameter_run(argc, argv, env))) {
                    }
                }
            }
        } else {
            if (!(err = set_parameter_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual const char_t* parameter_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTARG;
        return chars;
    }

    /// ...option...
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTVAL_C:
            err = this->on_method_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTVAL_C:
            err = this->on_parameter_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_REQUEST_OPTVAL_C:
            chars = this->request_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_METHOD_OPTVAL_C:
            chars = this->method_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_PARAMETER_OPTVAL_C:
            chars = this->parameter_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace client
} /// namespace xttp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_XTTP_CLIENT_MAIN_OPT_HPP
