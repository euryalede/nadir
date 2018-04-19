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
///   Date: 4/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_NADIR_MAIN_HPP
#define _XOS_APP_CONSOLE_NADIR_MAIN_HPP

#include "xos/console/getopt/Main.hpp"
#include "xos/lib/rostra/Version.hpp"
#include "xos/lib/nadir/Version.hpp"

namespace xos {
namespace app {
namespace console {
namespace nadir {

typedef xos::console::getopt::MainOpt MainTImplements;
typedef xos::console::getopt::Main MainTExtends;
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

private:
    MainT(const MainT &copy) {
    }
public:
    MainT() {
    }
    virtual ~MainT() {
    }

protected:
    virtual int Run(int argc, char_t**argv, char_t** env) {
        const ::xos::lib::Version& rostraVersion = ::xos::lib::rostra::Version::Which();
        const ::xos::lib::Version& nadirVersion = ::xos::lib::nadir::Version::Which();
        int err = 0;
        this->OutLLn(rostraVersion.Name().Chars(), " version = ", rostraVersion.ToString().Chars(), NULL);
        this->OutLLn(nadirVersion.Name().Chars(), " version = ", nadirVersion.ToString().Chars(), NULL);
        return err;
    }
};
typedef MainT<> Main;

} /// namespace nadir
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_NADIR_MAIN_HPP 
