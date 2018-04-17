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
};
typedef MainArgT<> MainArg;

} /// namespace console
} /// namespace xos

#endif /// _XOS_CONSOLE_MAINARG_HPP 
