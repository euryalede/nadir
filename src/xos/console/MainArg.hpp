///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   File: MainArg.hpp
///
/// Author: $author$
///   Date: 4/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MAINARG_HPP
#define _XOS_CONSOLE_MAINARG_HPP

#include "xos/console/Io.hpp"

namespace xos {
namespace console {

typedef Io MainArgTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainArgT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainArgTImplements>
class _EXPORT_CLASS MainArgT: virtual public TImplements {
public:
    typedef TImplements Implements;
    
    typedef TImplements io_t;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const typename Implements::endchar_t endchar = Implements::endchar;

protected:
    virtual int GetArguments(int argc, char_t**argv, char_t** env) {
        int err = 0;
        if (argc > (optind)) {
            for (int argind = optind; argind < argc; ++argind) {
                if ((err = OnArgument(argv[argind], argind-optind, argc, argv, env))) {
                    break;
                }
            }
        }
        SetDidArguments();
        return err;
    }
    virtual int BeforeGetArguments(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int AfterGetArguments(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }

    virtual int OnArgument
    (const char_t* arg, int argind,
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int MissingArgument(const char_t* arg) {
        int err = 1;
        return err;
    }
    virtual const char_t* Arguments(const char_t**& args) {
        args = 0;
        return 0;
    }

    virtual int Usage(int argc, char_t** argv, char_t** env) {
        int err = 0;

        if (!(DidUsage())) {
            err = UsageArgs(argc, argv, env);
            SetDidUsage();
        }
        return err;
    }
    virtual int UsageArgs(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        const char_t** args = 0;
        const char_t* argstring = Arguments(args);

        if ((argstring) && (args)) {
            this->OutLn();
            this->OutLn("Arguments:");

            while ((arg = (*args))) {
                this->OutLn(arg);
                args++;
            }
        }
        return err;
    }
    virtual const char_t* UsageName
    (int argc, char_t** argv, char_t** env) const {
        const char_t* arg0 = (0 < argc)?((argv)?(argv[0]):(0)):(0);
        if ((arg0)) {
            for (const char_t* i = arg0; *i; ++i) {
                char c = ((char)(*i));
                if (('/' == c) || ('\\' == c) || (':' == c)) {
                    arg0 = i + 1;
                }
            }
        }
        return arg0;
    }

    virtual bool SetDidArguments(bool to = true) {
        return DidArguments();
    }
    virtual bool DidArguments() const {
        return false;
    }
    virtual bool SetDidUsage(bool to = true) {
        return DidUsage();
    }
    virtual bool DidUsage() const {
        return false;
    }
};
typedef MainArgT<> MainArg;

typedef MainArg MainImplementTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MainImplementT
///////////////////////////////////////////////////////////////////////
template <class TImplements = MainImplementTImplements>
class _EXPORT_CLASS MainImplementT: virtual public TImplements {
public:
    typedef TImplements Implements;
    
    typedef MainImplementT main_t;
    typedef typename Implements::io_t io_t;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const typename Implements::endchar_t endchar = Implements::endchar;

    static int TheMain(int argc, char_t**argv, char_t** env) {
        int err = 1;
        main_t* theMain = 0;
        if ((theMain = TheMain())) {
            if (!(err = theMain->Before(argc, argv, env))) {
                int err2 = 0;
                err = (*theMain)(argc, argv, env);
                if ((err2 = theMain->After(argc, argv, env))) {
                    if (!err) err = err2;
                }
            }
        }
        return err;
    }
protected:
    static main_t*& TheMain() {
        static main_t* theMain = 0;
        return theMain;
    }

    virtual int operator()(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int Before(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int After(int argc, char_t**argv, char_t** env) {
        int err = 0;
        return err;
    }

};
typedef MainImplementT<> MainImplement;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_MAINARG_HPP 
