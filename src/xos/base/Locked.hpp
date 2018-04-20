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
inline TString LockStatusToString(LockStatus status) {
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
        return LockStatusToString<string_t>(this->Status());
    }
};
typedef LockExceptionT<> LockException;

typedef ImplementBase LockedTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: LockedT
///////////////////////////////////////////////////////////////////////
template <class TImplements = LockedTImplements>
class _EXPORT_CLASS LockedT: virtual public TImplements {
public:
    typedef TImplements Implements;

    virtual bool Lock() { 
        return false; 
    }
    virtual LockStatus TryLock() { 
        return LockFailed; 
    }
    virtual LockStatus TimedLock(mseconds_t milliseconds) { 
        return LockFailed; 
    }
    virtual LockStatus UntimedLock() { 
        return LockFailed; 
    }
    virtual bool Unlock() { 
        return false; 
    }
};
typedef LockedT<> Locked;

typedef Locked UnlockedTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: UnlockedT
///////////////////////////////////////////////////////////////////////
template <class TImplements = UnlockedTImplements>
class _EXPORT_CLASS UnlockedT: virtual public TImplements {
public:
    typedef TImplements Implements;

    virtual bool Lock() { 
        return true; 
    }
    virtual LockStatus TryLock() { 
        return LockSuccess; 
    }
    virtual LockStatus TimedLock(mseconds_t milliseconds) { 
        return LockSuccess; 
    }
    virtual LockStatus UntimedLock() { 
        return LockSuccess; 
    }
    virtual bool Unlock() { 
        return true; 
    }
};
typedef UnlockedT<> Unlocked;

typedef ImplementBase LockerTImplements;
typedef Base LockerTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: LockerT
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = LockerTImplements, class TExtends = LockerTExtends>
class _EXPORT_CLASS LockerT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    LockerT(Locked& locked): _locked(locked) {
        if (!(_locked.Lock())) {
            const LockException e(LockFailed);
            throw (e);
        }
    }
    virtual ~LockerT() {
        if (!(_locked.Unlock())) {
            const LockException e(UnlockFailed);
            throw (e);
        }
    }
private:
    LockerT(const LockerT &copy) {
    }

protected:
    Locked& _locked;
};
typedef LockerT<> Locker;

} /// namespace xos

#endif /// _XOS_BASE_LOCKED_HPP 
