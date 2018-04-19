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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 4/18/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_GETOPT_MAIN_HPP
#define _XOS_CONSOLE_GETOPT_MAIN_HPP

#include "xos/console/Main.hpp"
#include "xos/console/getopt/MainOpt.hpp"

namespace xos {
namespace console {
namespace getopt {

typedef MainOpt MainTImplements;
typedef console::MainT<console::MainImplement, MainTImplements> MainTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = MainTImplements, class TExtends = MainTExtends>

class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    typedef typename Implements::option_t option_t;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const typename Implements::endchar_t endchar = Implements::endchar;

    MainT(): _didOptions(false) {
    }
    virtual ~MainT() {
    }
private:
    MainT(const MainT &copy): _didOptions(false) {
    }
    
protected:
    virtual bool SetDidOptions(bool to = true) {
        _didOptions = to;
        return _didOptions;
    }
    virtual bool DidOptions() const {
        return _didOptions;
    }

protected:
    bool _didOptions;
};
typedef MainT<> Main;

} /// namespace getopt
} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_GETOPT_MAIN_HPP 
