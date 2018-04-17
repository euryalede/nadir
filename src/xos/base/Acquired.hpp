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
///   File: Acquired.hpp
///
/// Author: $author$
///   Date: 4/17/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_BASE_ACQUIRED_HPP
#define _XOS_BASE_ACQUIRED_HPP

#include "xos/base/Exception.hpp"

namespace xos {

typedef int AcquireStatus;
enum {
    ReleaseSuccess,
    AcquireSuccess,
    AcquireFailed,
    ReleaseFailed,
    AcquireBusy,
    AcquireInterrupted,
    AcquireInvalid,
    ReleaseBusy,
    ReleaseInterrupted,
    ReleaseInvalid
};
template <class TString>
inline const char* AcquireStatusToString(AcquireStatus status) {
    switch (status) {
    case ReleaseSuccess: return TString("ReleaseSuccess");
    case AcquireSuccess: return TString("AcquireSuccess");
    case AcquireFailed: return TString("AcquireFailed");
    case ReleaseFailed: return TString("ReleaseFailed");
    case AcquireBusy: return TString("AcquireBusy");
    case AcquireInterrupted: return TString("AcquireInterrupted");
    case AcquireInvalid: return TString("AcquireInvalid");
    case ReleaseBusy: return TString("ReleaseBusy");
    case ReleaseInterrupted: return TString("ReleaseInterrupted");
    case ReleaseInvalid: return TString("ReleaseInvalid");
    default: break;
    }
    return TString("Unknown");
}
///////////////////////////////////////////////////////////////////////
///  Class: AcquireExceptionT
///////////////////////////////////////////////////////////////////////
template 
<typename TStatus = AcquireStatus, 
 class TString = String, 
 class TImplements = Exception::Implements, 
 class TExtends = ExceptionT<TStatus, TString, TImplements> >

class _EXPORT_CLASS AcquireExceptionT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef AcquireExceptionT Derives;

    typedef TStatus status_t;
    typedef TString string_t;
    
    AcquireExceptionT(const status_t& status): Extends(status) {
    }
    AcquireExceptionT(const Derives &copy): Extends(copy.Status()) {
    }
    AcquireExceptionT(): Extends(AcquireFailed) {
    }
    virtual ~AcquireExceptionT() {
    }

    virtual string_t StatusToString() const {
        return ExceptionStatusToString<string_t>(this->Status());
    }
};
typedef AcquireExceptionT<> AcquireException;

typedef ImplementBase AcquierTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: AcquierT
///////////////////////////////////////////////////////////////////////
template <class TImplements = AcquierTImplements>
class _EXPORT_CLASS AcquierT: virtual public TImplements {
public:
    typedef TImplements Implements;
};
typedef AcquierT<> Acquier;

typedef Acquier AcquiredTImplements;
typedef AcquiredExtend AcquiredTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: AcquiredT
///////////////////////////////////////////////////////////////////////
template <class TImplements = AcquiredTImplements, class TExtends = AcquiredTExtends>
class _EXPORT_CLASS AcquiredT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    AcquiredT(const AcquiredT &copy) {
    }
    AcquiredT() {
    }
    virtual ~AcquiredT() {
    }
};
typedef AcquiredT<> Acquired;

} /// namespace xos

#endif /// _XOS_BASE_ACQUIRED_HPP 
