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
///   File: Locked.hpp
///
/// Author: $author$
///   Date: 4/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_LOCKED_HPP
#define _XOS_BASE_LOCKED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

typedef int LockStatus;
enum {
    UnlockSuccess,
    LockSuccess = UnlockSuccess,
    LockFailed,
    UnlockFailed,

    LockBusy,
    LockInterrupted,
    LockInvalid,

    UnlockBusy,
    UnlockInterrupted,
    UnlockInvalid
};
template <class TString>
inline const char* LockStatusToString(LockStatus status) {
    switch (status) {
    case LockSuccess: return TString("LockSuccess");
    case LockFailed: return TString("LockFailed");
    case UnlockFailed: return TString("UnlockFailed");
    case LockBusy: return TString("LockBusy");
    case LockInterrupted: return TString("LockInterrupted");
    case LockInvalid: return TString("LockInvalid");
    case UnlockBusy: return TString("UnlockBusy");
    case UnlockInterrupted: return TString("UnlockInterrupted");
    case UnlockInvalid: return TString("UnlockInvalid");
    default: break;
    }
    return TString("Unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: LockExceptionT
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = LockStatus, 
 class TString = String, 
 class TImplements = Exception::Implements, 
 class TExtends = ExceptionT<TStatus, TString, TImplements> >

class _EXPORT_CLASS LockExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef LockExceptionT Derives;

    typedef TStatus status_t;
    typedef TString string_t;
    
    LockExceptionT(const status_t& status): Extends(status) {
    }
    LockExceptionT(const Derives &copy): Extends(copy.Status()) {
    }
    LockExceptionT(): Extends(LockFailed) {
    }
    virtual ~LockExceptionT() {
    }

    virtual string_t StatusToString() const {
        return ExceptionStatusToString<string_t>(this->Status());
    }
};
typedef LockExceptionT<> LockException;

typedef ImplementBase LockerTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LockerT
///////////////////////////////////////////////////////////////////////
template <class TImplements = LockerTImplements>
class _EXPORT_CLASS LockerT: virtual public TImplements {
public:
    typedef TImplements Implements;
};
typedef LockerT<> Locker;

typedef Locker LockedTImplements;
typedef Base LockedTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LockedT
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = LockedTImplements, class TExtends = LockedTExtends>
class _EXPORT_CLASS LockedT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    LockedT(const LockedT &copy) {
    }
    LockedT() {
    }
    virtual ~LockedT() {
    }
};
typedef LockedT<> Locked;

} /// namespace xos

#endif /// _XOS_BASE_LOCKED_HPP 
