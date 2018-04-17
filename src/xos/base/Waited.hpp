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
///   File: Waited.hpp
///
/// Author: $author$
///   Date: 4/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_WAITED_HPP
#define _XOS_BASE_WAITED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

typedef int WaitStatus;
enum {
    ContinueSuccess,
    WaitSuccess,
    WaitFailed,
    ContinueFailed,
    WaitBusy,
    WaitInterrupted,
    WaitInvalid,
    ContinueBusy,
    ContinueInterrupted,
    ContinueInvalid
};
template <class TString>
inline const char* WaitStatusToString(WaitStatus status) {
    switch (status) {
    case ContinueSuccess: return TString("ContinueSuccess");
    case WaitSuccess: return TString("WaitSuccess");
    case WaitFailed: return TString("WaitFailed");
    case ContinueFailed: return TString("ContinueFailed");
    case WaitBusy: return TString("WaitBusy");
    case WaitInterrupted: return TString("WaitInterrupted");
    case WaitInvalid: return TString("WaitInvalid");
    case ContinueBusy: return TString("ContinueBusy");
    case ContinueInterrupted: return TString("ContinueInterrupted");
    case ContinueInvalid: return TString("ContinueInvalid");
    default: break;
    }
    return TString("Unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: WaitExceptionT
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = WaitStatus, 
 class TString = String, 
 class TImplements = Exception::Implements, 
 class TExtends = ExceptionT<TStatus, TString, TImplements> >

class _EXPORT_CLASS WaitExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef WaitExceptionT Derives;

    typedef TStatus status_t;
    typedef TString string_t;
    
    WaitExceptionT(const status_t& status): Extends(status) {
    }
    WaitExceptionT(const Derives &copy): Extends(copy.Status()) {
    }
    WaitExceptionT(): Extends(WaitFailed) {
    }
    virtual ~WaitExceptionT() {
    }

    virtual string_t StatusToString() const {
        return ExceptionStatusToString<string_t>(this->Status());
    }
};
typedef WaitExceptionT<> WaitException;

typedef ImplementBase WaiterTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: WaiterT
///////////////////////////////////////////////////////////////////////
template <class TImplements = WaiterTImplements>
class _EXPORT_CLASS WaiterT: virtual public TImplements {
public:
    typedef TImplements Implements;
};
typedef WaiterT<> Waiter;

typedef Waiter WaitedTImplements;
typedef WaitedExtend WaitedTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: WaitedT
///////////////////////////////////////////////////////////////////////
template <class TImplements = WaitedTImplements, class TExtends = WaitedTExtends>
class _EXPORT_CLASS WaitedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    WaitedT(const WaitedT &copy) {
    }
    WaitedT() {
    }
    virtual ~WaitedT() {
    }
};
typedef WaitedT<> Waited;

} /// namespace xos

#endif /// _XOS_BASE_WAITED_HPP 
